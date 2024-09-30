#pragma once

#include "main.h"

extern ECS_ENTITY_DECLARE(playerState);
extern ECS_TAG_DECLARE(IDLE);
extern ECS_TAG_DECLARE(WALK);
extern ECS_TAG_DECLARE(SKID);
extern ECS_TAG_DECLARE(SPINDASH);
extern ECS_TAG_DECLARE(ROLL);
extern ECS_TAG_DECLARE(AIRBORNE);

extern ECS_SYSTEM_DECLARE(PrintState);

void PrintState(ecs_iter_t* it);
void PlayerStateImport(ecs_world_t* world);