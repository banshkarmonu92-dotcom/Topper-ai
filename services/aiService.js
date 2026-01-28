export async function askAI(question, apiKey) {
  try {
    const res = await fetch(
      "https://openrouter.ai/api/v1/chat/completions",
      {
        method: "POST",
        headers: {
          "Authorization": "Bearer " + apiKey,
          "Content-Type": "application/json"
        },
        body: JSON.stringify({
          model: "tngtech/deepseek-r1t2-chimera:free",
          messages: [
            {
              role: "system",
              content:
                "You are an AI Multi-Method Education Tutor. " +
                "Explain in Hinglish, step-by-step, with examples. " +
                "If student is confused, explain again."
            },
            { role: "user", content: question }
          ]
        })
      }
    );

    const data = await res.json();
    return data.choices?.[0]?.message?.content || "No reply";

  } catch (e) {
    return "Error: " + e.message;
  }
}
