#include "raylib.h"
#include "game.h"

int main(void) {
    InitWindow(1000, 600, "AI Tutor - Raylib");
    SetTargetFPS(60);

    InitGame();

    while (!WindowShouldClose()) {
        UpdateGame();
        BeginDrawing();
        DrawGame();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
