#include "playerstate.h"

ECS_ENTITY_DECLARE(playerState);
ECS_TAG_DECLARE(IDLE);
ECS_TAG_DECLARE(WALK);
ECS_TAG_DECLARE(SKID);
ECS_TAG_DECLARE(SPINDASH);
ECS_TAG_DECLARE(ROLL);
ECS_TAG_DECLARE(AIRBORNE);

ECS_SYSTEM_DECLARE(PrintState);

void PrintState(ecs_iter_t* it) 
{
	//ecs_entity_t* pl_state = ecs_field(it, playerState, 0);
	//const ecs_type_t* type = ecs_get_type();
}

void PlayerStateImport(ecs_world_t* world) 
{
	ECS_MODULE(world, PlayerState);
	
	ECS_ENTITY_DEFINE(world, playerState, Union);
	ECS_TAG_DEFINE(world, IDLE);
	ECS_TAG_DEFINE(world, WALK);
	ECS_TAG_DEFINE(world, SKID);
	ECS_TAG_DEFINE(world, SPINDASH);
	ECS_TAG_DEFINE(world, ROLL);
	ECS_TAG_DEFINE(world, AIRBORNE);

	ECS_SYSTEM_DEFINE(world, PrintState, EcsOnUpdate, playerState);
}