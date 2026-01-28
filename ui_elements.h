#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H
#include "raylib.h"

// Simple Rounded Button
void DrawProButton(Rectangle bounds, const char* text, Color baseColor, Color hoverColor) {
    bool isHovered = CheckCollisionPointRec(GetMousePosition(), bounds);
    DrawRectangleRounded(bounds, 0.3f, 10, isHovered ? hoverColor : baseColor);
    int textWidth = MeasureText(text, 20);
    DrawText(text, bounds.x + (bounds.width/2) - (textWidth/2), bounds.y + (bounds.height/2) - 10, 20, RAYWHITE);
}

// Simple Text Input Box
void DrawProTextBox(Rectangle bounds, char* text, bool active) {
    DrawRectangleRounded(bounds, 0.2f, 10, active ? LIGHTGRAY : GRAY);
    DrawRectangleRoundedLines(bounds, 0.2f, 10, 2, BLACK);
    DrawText(text, bounds.x + 10, bounds.y + 15, 20, MAROON);
}
#endif
