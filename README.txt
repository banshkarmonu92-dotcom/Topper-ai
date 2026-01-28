AI Tutor Raylib (REAL AI)

1) API KEY set karo:
export OPENROUTER_API_KEY=sk-or-xxxxxxxx

2) Compile:
clang main.c game.c tutor.c api.c subjects.c \
-o ai_tutor -lraylib -lcurl -lm -ldl -lpthread

3) Run:
./ai_tutor
