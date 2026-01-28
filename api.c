#include "api.h"
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    strncat((char *)userp, (char *)contents, size * nmemb);
    return size * nmemb;
}

void GetAIResponse(const char *question, char *response) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        strcpy(response, "❌ CURL init failed");
        return;
    }

    char *apiKey = getenv("OPENROUTER_API_KEY");
    if (!apiKey) {
        strcpy(response, "❌ API key not found (OPENROUTER_API_KEY)");
        return;
    }

    char json[4096];
    snprintf(json, sizeof(json),
        "{"
        "\"model\":\"tngtech/deepseek-r1t2-chimera:free\","
        "\"messages\":["
          "{\"role\":\"system\",\"content\":\"You are an AI Multi-Method Education Tutor. Explain patiently in Hinglish.\"},"
          "{\"role\":\"user\",\"content\":\"%s\"}"
        "]"
        "}",
        question
    );

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    char auth[512];
    snprintf(auth, sizeof(auth), "Authorization: Bearer %s", apiKey);
    headers = curl_slist_append(headers, auth);

    response[0] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, "https://openrouter.ai/api/v1/chat/completions");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        strcpy(response, "❌ API request failed");
    }

    curl_easy_cleanup(curl);
}
