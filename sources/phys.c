#include "playerphys.h"

void UpdatePosition(ecs_iter_t* it) 
{
    // Get fields from system query
    position* p = ecs_field(it, position, 0);
    velocity* v = ecs_field(it, velocity, 1);

    // Iterate matched entities
    for (int i = 0; i < it->count; i++) {
        p[i].x += v[i].x * it->delta_time;
        p[i].y += v[i].y * it->delta_time;
        p[i].z += v[i].z * it->delta_time;
    }
}