#ifndef AI_SERVICE_H
#define AI_SERVICE_H
#include <string>
#include <curl/curl.h>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    s->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string CallDeepSeek(std::string prompt) {
    CURL* curl = curl_easy_init();
    std::string response;
    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Authorization: Bearer YOUR_API_KEY"); // Yahan apni key daalein

        // Simple JSON string construction
        std::string data = "{ \"model\": \"deepseek-chat\", \"messages\": [ "
                           "{ \"role\": \"system\", \"content\": \"You are a Pro Hinglish Tutor. Use NCERT methods and journey stories.\" },"
                           "{ \"role\": \"user\", \"content\": \"" + prompt + "\" } ] }";

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.deepseek.com/chat/completions");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return response;
}
#endif
