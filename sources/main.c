#include "main.h"

#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)

#define WINDOW_TITLE "SONK REWRITE"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    ecs_world_t* world = ecs_init();

    ECS_IMPORT(world, PlayerState);

    ecs_entity_t player = ecs_entity(world, { .name = "SONK" });
    ecs_add_pair(world, player, playerState, IDLE);

    //ecs_query_t* q = ecs_query(world, { .terms = { { .id = ecs_pair(playerState, IDLE) } } });

    while (!WindowShouldClose())
    {
        
        ecs_progress(world, GetFrameTime());
        BeginDrawing();
			ClearBackground(RAYWHITE);
        EndDrawing();
    }

    ecs_fini(world);
    CloseWindow();

    return 0;
}
