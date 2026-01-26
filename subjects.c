#include "subjects.h"
#include <string.h>

void ExplainMaths(char *response) {
    strcpy(response,
        "📘 ADDITION (Maths)\n\n"
        "Definition: Addition matlab milaana.\n"
        "Example: 2 + 3 = 5\n\n"
        "Trip style:\n"
        "2 stop + 3 stop = 5 stop.\n\n"
        "One line: Addition = jodna.");
}

void ExplainScience(char *response) {
    strcpy(response,
        "🔬 HEAT (Science)\n\n"
        "Heat matlab garmi.\n"
        "Baraf → Paani → Bhaap\n\n"
        "One line: Heat cheezon ko garam karti hai.");
}

void ExplainComputer(char *response) {
    strcpy(response,
        "💻 COMPUTER\n\n"
        "Computer ek smart machine hai.\n"
        "Input → Process → Output\n\n"
        "One line: Computer humari baat maanta hai.");
}

void ExplainAgain(int topic, char *response) {
    if (topic == 1)
        strcpy(response, "Addition aur simple:\n1 🍎 + 1 🍎 = 2 🍎");
    else if (topic == 2)
        strcpy(response, "Heat simple:\nDhoop me garmi lagti hai ☀");
    else if (topic == 3)
        strcpy(response, "Computer simple:\nTum bolo, wo kare 💻");
    else
        strcpy(response, "Koi baat nahi 😊\nTopic batao.");
}
