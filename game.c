#include "game.h"
#include "tutor.h"
#include "raylib.h"
#include <string.h>

static char input[256] = "";
static char response[2048];

void InitGame() {
    InitTutor(response);
}

void UpdateGame() {
    int key = GetCharPressed();
    while (key > 0) {
        int len = strlen(input);
        if (len < 255 && key >= 32 && key <= 125) {
            input[len] = (char)key;
            input[len + 1] = '\0';
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        int len = strlen(input);
        if (len > 0) input[len - 1] = '\0';
    }

    if (IsKeyPressed(KEY_ENTER)) {
        GetTutorResponse(input, response);
        input[0] = '\0';
    }
}

void DrawGame() {
    ClearBackground(RAYWHITE);
    DrawText("AI Tutor Game (Raylib)", 360, 20, 26, DARKBLUE);

    DrawText("Your Question:", 50, 80, 20, BLACK);
    DrawRectangle(50, 110, 900, 40, LIGHTGRAY);
    DrawText(input, 60, 120, 20, BLACK);

    DrawText("AI Response:", 50, 180, 20, BLACK);
    DrawRectangle(50, 210, 900, 330, GRAY);
    DrawRectangle(55, 215, 890, 320, WHITE);
    DrawText(response, 70, 230, 18, DARKGRAY);

    DrawText("Press ENTER to ask | Teacher + Dost Mode 😊", 320, 560, 16, DARKGREEN);
}
