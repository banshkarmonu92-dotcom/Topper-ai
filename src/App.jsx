import React, { useState } from "react";
import Header from "./components/Header";
import ChatBox from "./components/ChatBox";
import InputBox from "./components/InputBox";
import { askAI } from "./services/aiService";

export default function App() {
  const [messages, setMessages] = useState([]);

  async function handleAsk(question, apiKey) {
    setMessages(prev => [...prev, { role: "user", text: question }]);

    const reply = await askAI(question, apiKey);

    setMessages(prev => [...prev, { role: "ai", text: reply }]);
  }

  return (
    <div className="app">
      <Header />
      <ChatBox messages={messages} />
      <InputBox onAsk={handleAsk} />
    </div>
  );
}
