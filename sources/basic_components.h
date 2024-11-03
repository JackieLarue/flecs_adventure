#pragma once 

#include <raylib.h>
#include <flecs.h>

typedef Vector3 velocity, position;

extern ECS_COMPONENT_DECLARE(velocity);
extern ECS_COMPONENT_DECLARE(position);
extern ECS_COMPONENT_DECLARE(Transform);

