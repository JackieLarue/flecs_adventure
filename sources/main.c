#include "main.h"

#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)

#define WINDOW_TITLE "SONK REWRITE"

void GraphicsBegin(ecs_iter_t *it) 
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void GraphicsEnd(ecs_iter_t* it)
{
    EndDrawing();
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    ecs_world_t* world = ecs_init();

    ECS_SYSTEM(world, GraphicsBegin, EcsOnUpdate, 0);
    ECS_IMPORT(world, PlayerStateComponent);
    ECS_SYSTEM(world, GraphicsEnd, EcsOnUpdate, 0);

    ecs_entity_t player = ecs_entity(world, { .name = "SONK" });
    ecs_add_pair(world, player, playerState, IDLE);

    while (!WindowShouldClose())
    {
        ecs_progress(world, GetFrameTime());
    }

    ecs_fini(world);
    CloseWindow();

    return 0;
}
