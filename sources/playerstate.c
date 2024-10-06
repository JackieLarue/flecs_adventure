#include "playerstate.h"

ECS_ENTITY_DECLARE(playerState);
ECS_TAG_DECLARE(IDLE);
ECS_TAG_DECLARE(WALK);
ECS_TAG_DECLARE(SKID);
ECS_TAG_DECLARE(SPINDASH);
ECS_TAG_DECLARE(ROLL);
ECS_TAG_DECLARE(AIRBORNE);
ECS_TAG_DECLARE(HURT);

void PrintPlayerState(ecs_iter_t* it)
{
	ecs_world_t* world = it->world;
	ecs_id_t state_pair = ecs_field_id(it, 0);
	ecs_entity_t pl_state = ecs_pair_second(world, state_pair);

	for (int i = 0; i < it->count; i++) {
		DrawText(TextFormat("%s: State: %s", ecs_get_name(world, it->entities[0]), ecs_get_name(world, pl_state)), 10, GetScreenHeight() - 20, 20, BLACK);
	}
};

void PlayerStateComponentImport(ecs_world_t* world)
{
	ECS_MODULE(world, PlayerStateComponent);
	
	ECS_ENTITY_DEFINE(world, playerState, Union);
	ECS_TAG_DEFINE(world, IDLE);
	ECS_TAG_DEFINE(world, WALK);
	ECS_TAG_DEFINE(world, SKID);
	ECS_TAG_DEFINE(world, SPINDASH);
	ECS_TAG_DEFINE(world, ROLL);
	ECS_TAG_DEFINE(world, AIRBORNE);
	ECS_TAG_DEFINE(world, HURT);

	ecs_system(world, {
		.entity = ecs_entity(world, {
			.name = "PrintPlayerState",
			.add = ecs_ids(ecs_dependson(EcsOnUpdate)) }),
		.query.terms = {
			{.id = ecs_pair(playerState, EcsWildcard) }
		},
		.callback = PrintPlayerState
		});
}