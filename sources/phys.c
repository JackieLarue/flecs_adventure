#include "playerphys.h"

void UpdatePosition(ecs_iter_t* it) 
{
    // Get fields from system query
    Position* p = ecs_field(it, Position, 0);
    Velocity* v = ecs_field(it, Velocity, 1);

    // Iterate matched entities
    for (int i = 0; i < it->count; i++) {
        p[i].x += v[i].x;
        p[i].y += v[i].y;
    }
}