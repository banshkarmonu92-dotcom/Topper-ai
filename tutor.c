#include "tutor.h"
#include "subjects.h"
#include "api.h"
#include <string.h>

void InitTutor(char *response) {
    strcpy(response,
        "Namaste 😊\n"
        "Main tumhara AI Multi-Method Tutor hoon.\n"
        "Sawal likho aur ENTER dabao.\n"
        "AI real model se jawab dega.");
}

void GetTutorResponse(const char *input, char *response) {
    if (strlen(input) == 0) {
        strcpy(response, "Pehle sawal likho 😊");
        return;
    }

    // REAL AI CALL
    strcpy(response, "AI soch raha hai... 🤖");
    GetAIResponse(input, response);
}
