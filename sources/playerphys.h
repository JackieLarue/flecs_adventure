#pragma once

#include "main.h"
#include "basic_components.h"

//going to switch z and x values for all the code to translate it for z-forward axises
typedef struct player_parameter
{
	int jump2_timer;      //how long in frames can player character "hang" in air while jumping
	float pos_error;      //"collision resolution difference" - if player is within this measurement when going down slope, snap to ground
	float lim_h_spd;      //hard limit horizontal speed cap
	float lim_v_spd;      //hard limit vertical speed cap
	float max_z_spd;      //"soft" horizontal speed cap
	float max_psh_spd;    //max push object speed
	float jmp_y_spd;      //initial jump speed
	float nocon_speed;    //nocontrol i.e spring speed
	float slide_speed;    //slide speed (lost world slide?)
	float jog_speed;      //rolling cancel speed as well
	float run_speed;      //rolling end speed as well
	float rush_speed;     //(normal run speed methinks)
	float crash_speed;    //min speed to get knocked back when hitting wall, affects pushing speed too?
	float dash_speed;     //normally shouldn't be at this speed, but if you are, player character gets some top speed anim and steering is hard
	float jmp_addit;      //speed added when holding jump
	float run_accel;
	float air_accel;
	float slow_down;      //ground decel
	float run_break;      //ground brake speed
	float air_break;      //air brake speed
	float air_resist_air; //air decel coefficient
	float air_resist;     //rolling decel coefficient (in air too) (called air_resist. gosh, ain't that confusing naming?)
	float air_resist_y;   //air decel coefficient for y_spd
	float air_resist_x;   //air decel coefficient for x_spd
	float grd_frict;      //min speed before stopping, affects spindash charging and braking
	float grd_frict_x;    //affects movement on sloped surfaces
	float lim_frict;      //multiplied with gravity accel for air control/brake i think? - i think this is kinda grd_frict counterpart
	float rat_bound;      //unused???????
	float rad;            //collision radius
	float height;         //player collision height
	float weight;         //called "weight", technically gravity scales with this value, i.e "heavier" characters fall faster. kinda funny
	float eyes_height;    //camera y offset
	float center_height;  //center y offset of player
} player_parameter;

typedef struct spin_parameter 
{
	float jmp_dash_h_speed;
	float initial_spin_speed;
	float max_spin_speed;
	float spin_addit;
} spin_parameter;

typedef Vector3 wall_normal, floor_normal, last_up;

typedef struct player_counters
{
	int jump_timer;
	//float spring_timer;
	//float dashpanel_timer;
	//float dashring_timer;
	//float rail_debounce;
	//float rail_trick;
	float spindash_speed;
} player_counters;

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

void UpdatePosition(ecs_iter_t* it);

extern ECS_COMPONENT_DECLARE(player_parameter);
extern ECS_COMPONENT_DECLARE(spin_parameter);
extern ECS_COMPONENT_DECLARE(player_counters);

extern ECS_SYSTEM_DECLARE(UpdatePosition);