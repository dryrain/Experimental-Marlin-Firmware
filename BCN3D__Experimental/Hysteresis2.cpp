/*
  Hysteresis.cpp - A class that manages hysteresis by inserting extra plan_buffer_line when necessary
 
  Copyright (c) 2012 Neil James Martin
 
 Grbl is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 Grbl is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Hysteresis2.h"
#include "Configuration.h"
#include "Marlin.h"
#include "planner.h"
#include "stepper.h"
#include "temperature.h"
#include "ultralcd.h"
#include "language.h"
//#include "MarlinSerial.h"

float menu_hysteresis_correction=Y_DEFAULT_HYSTERESIS_MM;

//===========================================================================

Hysteresis hysteresis( DEFAULT_HYSTERESIS_MM );
float axis_shift[ NUM_AXIS ] = { 0.0f, 0.0f, 0.0f, 0.0f };

//===========================================================================
//Constructor
Hysteresis::Hysteresis( float x_mm, float y_mm, float z_mm, float e_mm )
{
  m_prev_direction_bits = 0;
  Set( x_mm, y_mm, z_mm, e_mm );
  done=0;
}

//===========================================================================
void Hysteresis::Set( float x_mm, float y_mm, float z_mm, float e_mm )
{
  m_hysteresis_mm[X_AXIS] = x_mm;
  m_hysteresis_mm[Y_AXIS] = y_mm;
  m_hysteresis_mm[Z_AXIS] = z_mm;
  m_hysteresis_mm[E_AXIS] = e_mm;
  //m_hysteresis_bits = 1 if any hysteresis is set
  m_hysteresis_bits = ((m_hysteresis_mm[X_AXIS]!=0.0f)?(1<<X_AXIS):0)
                    | ((m_hysteresis_mm[Y_AXIS]!=0.0f)?(1<<Y_AXIS):0)// We always have Y correction so m_hysteresis is "10"
                    | ((m_hysteresis_mm[Z_AXIS]!=0.0f)?(1<<Z_AXIS):0)
                    | ((m_hysteresis_mm[E_AXIS]!=0.0f)?(1<<E_AXIS):0);
}

//===========================================================================
//Not Used
void Hysteresis::SetAxis( int axis, float mm )
{
  m_hysteresis_mm[axis] = mm;
  if( mm != 0.0f )
  {
    m_hysteresis_bits |= (1<<axis);
  }
  else
  {
    m_hysteresis_bits &= ~(1<<axis);
  }
}

//===========================================================================
// Not Used
void Hysteresis::ReportToSerial()
{
  SERIAL_PROTOCOLPGM("H=X");
  SERIAL_PROTOCOL(m_hysteresis_mm[X_AXIS]);
  SERIAL_PROTOCOLPGM(" Y");
  SERIAL_PROTOCOL(m_hysteresis_mm[Y_AXIS]);
  SERIAL_PROTOCOLPGM(" Z");
  SERIAL_PROTOCOL(m_hysteresis_mm[Z_AXIS]);
  SERIAL_PROTOCOLPGM(" E");      
  SERIAL_PROTOCOL(m_hysteresis_mm[E_AXIS]);
  SERIAL_PROTOCOLPGM(" SHIFTS:x=");      
  SERIAL_PROTOCOL(axis_shift[X_AXIS]);
  SERIAL_PROTOCOLPGM(" y=");      
  SERIAL_PROTOCOL(axis_shift[Y_AXIS]);
  SERIAL_PROTOCOLPGM(" z=");      
  SERIAL_PROTOCOL(axis_shift[Z_AXIS]);
  SERIAL_PROTOCOLPGM(" e=");      
  SERIAL_PROTOCOL(axis_shift[E_AXIS]);
  
  SERIAL_PROTOCOLLN("");
}





//===========================================================================
unsigned char calc_direction_bits( const float* current_position, const float* destination )
{
	// Checks for direction change, uses direction_bits = 1,2,4,8 (1,10,100,1000)
	//{X_AXIS=0, Y_AXIS=1, Z_AXIS=2, E_AXIS=3}
  unsigned char direction_bits = 0;
  if (destination[X_AXIS] < current_position[X_AXIS] ) { 
    direction_bits |= (1<<X_AXIS); 
  }
  if (destination[Y_AXIS] < current_position[Y_AXIS] ) { 
    direction_bits |= (1<<Y_AXIS); 
  }
  if (destination[Z_AXIS] < current_position[Z_AXIS] ) { 
    direction_bits |= (1<<Z_AXIS); 
  }
  if (destination[E_AXIS] < current_position[E_AXIS] ) { 
    direction_bits |= (1<<E_AXIS); 
  }
  return direction_bits;
}


unsigned char calc_move_bits( const long* current_position, const long* destination )
{
	unsigned char move_bits = 0;
	if (destination[X_AXIS] != current_position[X_AXIS]) {
		move_bits |= (1<<X_AXIS);
	}
	if (destination[Y_AXIS] != current_position[Y_AXIS]) {
		move_bits |= (1<<Y_AXIS);
	}
	if (destination[Z_AXIS] != current_position[Z_AXIS]) {
		move_bits |= (1<<Z_AXIS);
	}
	if (destination[E_AXIS] != current_position[E_AXIS]) {
		move_bits |= (1<<E_AXIS);
	}
	return move_bits;
}


//===========================================================================
// calculate the slowest max feedrate for the axis directions being used
float calc_best_feedrate( const float* current_position, const float* destination )
{
  float best_feedrate = max(max_feedrate[X_AXIS],max(max_feedrate[Y_AXIS],max(max_feedrate[Z_AXIS],max_feedrate[E_AXIS])));
  for(int axis=0;axis<NUM_AXIS;++axis)
  {
    if (destination[axis] != current_position[axis]) 
    { 
		//Picks the minimum feedrate of all axis.
      best_feedrate = min( best_feedrate, max_feedrate[axis] );
    }
  }
  return best_feedrate;  
}

//===========================================================================
// insert a plan_buffer_line if required to handle any hysteresis
void Hysteresis::InsertCorrectionV2(const float &x, const float &y, const float &z, const float &e)
{
	//Set Hysteresis correction using menu settings
	Set(0,menu_hysteresis_correction,0,0);
	//NUM_AXIS 4
	//current_position in Marlin_main.c
	float destination[NUM_AXIS] = {x,y,z,e};
	//Destination calculus changed to get absolute position
	//float destination[NUM_AXIS] = {x*axis_steps_per_unit[X_AXIS],y*axis_steps_per_unit[Y_AXIS],z*axis_steps_per_unit[Z_AXIS],e*axis_steps_per_unit[E_AXIS]};
	unsigned char direction_bits = calc_direction_bits( current_position, destination );
	unsigned char move_bits = calc_move_bits(current_position, destination );
	
	SERIAL_PROTOCOLLN("");
	
	SERIAL_PROTOCOL("Destination X: ");
	SERIAL_PROTOCOL(destination[0]); //X_AXIS=0
	SERIAL_PROTOCOL("    Current position X: ");
	SERIAL_PROTOCOLLN(current_position[X_AXIS]);
	SERIAL_PROTOCOLLN("");
	
	SERIAL_PROTOCOL("Destination Y: ");
	SERIAL_PROTOCOL(destination[1]); //Y_AXIS=1
	SERIAL_PROTOCOL("    Current positionY: ");
	SERIAL_PROTOCOLLN(current_position[Y_AXIS]);
	SERIAL_PROTOCOLLN("");
	SERIAL_PROTOCOLLN("");
	
	SERIAL_PROTOCOL("Direction Bits: ");
	SERIAL_PROTOCOLLN((int)direction_bits);
	

	
  // if the direction has changed in any of the axis that need hysteresis corrections...
  //Binary XOR "^" puts 1 if differences between bits!
	unsigned char direction_change_bits = (direction_bits ^ m_prev_direction_bits)& move_bits;//Result -> 1,10,100,1000
	SERIAL_PROTOCOLLN("");
	SERIAL_PROTOCOL("Prev. Direction Bits:");
	SERIAL_PROTOCOLLN((int)m_prev_direction_bits);
	SERIAL_PROTOCOL(" Direction Change Bits: ");
	SERIAL_PROTOCOLLN((int)direction_change_bits);
	SERIAL_PROTOCOLLN("");

  if( (direction_change_bits & m_hysteresis_bits) != 0 )
  {
	 //MSerial.println(" Direction Changed!!!!!");
    // calculate the position to move to that will fix the hysteresis
    float fixed_pos[NUM_AXIS];
    for(int axis=0;axis<NUM_AXIS;++axis)
    {
      fixed_pos[axis] = current_position[axis];
      // if this axis changed direction...
      if( direction_change_bits & (1<<axis) )
      {
        float fix = (((direction_bits&(1<<axis))!=0)?-m_hysteresis_mm[axis]:m_hysteresis_mm[axis]);
        //... add the hysteresis
		SERIAL_PROTOCOL("Axis: ");
		SERIAL_PROTOCOLLN((int)axis);
		
		if (fix<0)
		{			
			SERIAL_PROTOCOLLN("Correction Down");
		}
		else if (fix>0)
		{
			SERIAL_PROTOCOLLN("Correction Up");
		}
		
        fixed_pos[axis] += fix;
        axis_shift[axis] += fix;
      }
    }
    float best_feedrate = calc_best_feedrate( current_position, destination );

		
		

        //// debug output to display any hysteresis corrections.
        //SERIAL_PROTOCOLPGM("From=X");
        //SERIAL_PROTOCOL(current_position[X_AXIS]);
        //SERIAL_PROTOCOLPGM(" Y");
        //SERIAL_PROTOCOL(current_position[Y_AXIS]);
        //SERIAL_PROTOCOLPGM(" Z");
        //SERIAL_PROTOCOL(current_position[Z_AXIS]);
        //SERIAL_PROTOCOLPGM(" E");      
        //SERIAL_PROTOCOL(current_position[E_AXIS]);
		//
		//
//
        //SERIAL_PROTOCOLLN("");
//
        //SERIAL_PROTOCOLPGM("  To=X");
        //SERIAL_PROTOCOL(fixed_pos[X_AXIS]);
        //SERIAL_PROTOCOLPGM(" Y");
        //SERIAL_PROTOCOL(fixed_pos[Y_AXIS]);
        //SERIAL_PROTOCOLPGM(" Z");
        //SERIAL_PROTOCOL(fixed_pos[Z_AXIS]);
        //SERIAL_PROTOCOLPGM(" E");      
        //SERIAL_PROTOCOL(fixed_pos[E_AXIS]);
        //
        //SERIAL_PROTOCOLPGM(" F");      
        //SERIAL_PROTOCOL(best_feedrate);
        //
//
        //SERIAL_PROTOCOLLN("");

  
    float position_before_correction[NUM_AXIS];
    copy_position( position_before_correction );
	//Print position
	//m_prev_direction_bits = calc_direction_bits( current_position, fixed_pos ); // need to set these now to avoid recursion as plan_buffer_line calls this function	
	//Change max_xy_jerk to allow clean hysteresis correction
	//max_xy_jerk=1.0;
	done=1;
    plan_buffer_line(fixed_pos[X_AXIS], fixed_pos[Y_AXIS], fixed_pos[Z_AXIS], fixed_pos[E_AXIS], best_feedrate, active_extruder);   
	//Set again max_xy_jerk to default value
	//max_xy_jerk=DEFAULT_XYJERK;
	set_position( position_before_correction );
  }
  m_prev_direction_bits = direction_bits;
  done=0;
  SERIAL_PROTOCOLLN("");
  SERIAL_PROTOCOLLN("");
}



//Extra functions for LCD menu
void update_hysteresis_circles()
{
	menu_hysteresis_correction=0.1;
	max_xy_jerk=1;
}


void update_hysteresis_off()
{
	menu_hysteresis_correction=0;
	max_xy_jerk=5;
}
