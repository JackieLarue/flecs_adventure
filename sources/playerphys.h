#pragma once

#include "main.h"

typedef struct player_parameter
{
	int jump2_timer;
	float pos_error;
	float lim_h_spd;
	float lim_v_spd;
	float max_x_spd;
	float max_psh_spd;
	float jmp_y_spd;
	float nocon_speed;
	float slide_speed;
	float jog_speed;
	float run_speed;
	float rush_speed;
	float crash_speed;
	float dash_speed;
	float jmp_addit;
	float run_accel;
	float air_accel;
	float slow_down;
	float run_break;
	float air_break;
	float air_resist_air;
	float air_resist;
	float air_resist_y;
	float air_resist_z;
	float grd_frict;
	float grd_frict_z;
	float lim_frict;
	float rat_bound;
	float rad;
	float height;
	float weight;
	float eyes_height;
	float center_height;
} player_parameter;

typedef struct spin_parameter 
{
	float jmp_dash_h_speed;
	float initial_spin_speed;
	float max_spin_speed;
	float spin_addit;
} spin_parameter;

typedef Vector3 speed;

typedef struct TimersAndSuch
{
	int jump_timer;
	float spring_timer;
	float dashpanel_timer;
	float dashring_timer;
	float rail_debounce;
	float rail_trick;
	float spindash_speed;
} TimersAndSuch;

//player phys entity
//speed
//pos
//ang
//dotp
//wall_normal
//floor_normal
//last_up
//grounded
//last_turn
//collider

extern ECS_COMPONENT_DECLARE(player_parameter);
extern ECS_COMPONENT_DECLARE(spin_parameter);
extern ECS_COMPONENT_DECLARE(TimersAndSuch);
