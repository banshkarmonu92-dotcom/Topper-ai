#include "tutor.h"
#include "subjects.h"
#include <string.h>

static int lastTopic = 0;

void InitTutor(char *response) {
    strcpy(response,
        "Namaste 😊\nMain tumhara AI Teaching Agent hoon.\n"
        "Maths, Science, Computer pooch sakte ho.\n"
        "Samajh na aaye to likho: samajh nahi aa raha 👍");
}

void GetTutorResponse(const char *input, char *response) {
    if (strlen(input) == 0) {
        strcpy(response, "Koi baat nahi 😊\nPehle sawal likho.");
        return;
    }

    if (strstr(input, "samajh")) {
        ExplainAgain(lastTopic, response);
        return;
    }

    if (strstr(input, "math") || strstr(input, "jod") || strstr(input, "addition")) {
        lastTopic = 1;
        ExplainMaths(response);
    }
    else if (strstr(input, "science") || strstr(input, "heat") || strstr(input, "garmi")) {
        lastTopic = 2;
        ExplainScience(response);
    }
    else if (strstr(input, "computer")) {
        lastTopic = 3;
        ExplainComputer(response);
    }
    else {
        strcpy(response,
            "Abhi padhai par focus karte hain 😊\n"
            "Maths, Science, Computer likho.");
    }
}
