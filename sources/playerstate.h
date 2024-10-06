#pragma once

#include "main.h"

extern ECS_ENTITY_DECLARE(playerState);
extern ECS_TAG_DECLARE(IDLE);
extern ECS_TAG_DECLARE(WALK);
extern ECS_TAG_DECLARE(SKID);
extern ECS_TAG_DECLARE(SPINDASH);
extern ECS_TAG_DECLARE(ROLL);
extern ECS_TAG_DECLARE(AIRBORNE);
extern ECS_TAG_DECLARE(HURT);

void PrintPlayerState(ecs_iter_t* it);
extern ECS_SYSTEM_DECLARE(PrintPlayerState);

void PlayerStateComponentImport(ecs_world_t* world);