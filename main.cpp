#include "raylib.h"
#include "ai_service.h"
#include "ui_elements.h"
#include <thread>

int main() {
    InitWindow(900, 650, "Pro AI Tutor - No Folders Version");
    SetTargetFPS(60);

    char inputBuf[255] = "\0";
    int letterCount = 0;
    std::string aiRes = "Namaste! Kuch puchiye...";
    bool thinking = false;

    while (!WindowShouldClose()) {
        // Input Logic
        if (!thinking) {
            int key = GetCharPressed();
            while (key > 0) {
                if (letterCount < 254) {
                    inputBuf[letterCount] = (char)key;
                    inputBuf[letterCount+1] = '\0';
                    letterCount++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE) && letterCount > 0) {
                inputBuf[--letterCount] = '\0';
            }
        }

        // Action Logic
        if (IsKeyPressed(KEY_ENTER) && letterCount > 0 && !thinking) {
            thinking = true;
            aiRes = "Tutor soch raha hai...";
            std::thread([&](){
                std::string raw = CallDeepSeek(inputBuf);
                // Pro tip: Raw JSON se text nikalne ka simple logic
                size_t pos = raw.find("content\":\"");
                if (pos != std::string::npos) {
                    aiRes = raw.substr(pos + 10);
                    aiRes = aiRes.substr(0, aiRes.find("\"}"));
                } else { aiRes = raw; }
                thinking = false;
                letterCount = 0; inputBuf[0] = '\0';
            }).detach();
        }

        BeginDrawing();
            ClearBackground(GetColor(0x202020FF)); // Dark Pro Look
            DrawText("PRO AI TUTOR", 350, 20, 30, SKYBLUE);
            
            // Output Area
            DrawRectangleRounded({40, 70, 820, 400}, 0.1f, 10, RAYWHITE);
            DrawText(aiRes.c_str(), 60, 90, 20, BLACK);

            // Input Area
            DrawProTextBox({40, 500, 700, 50}, inputBuf, true);
            DrawProButton({750, 500, 110, 50}, "SEND", DARKBLUE, BLUE);
            
            if(thinking) DrawText("AI is typing...", 40, 560, 15, YELLOW);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
