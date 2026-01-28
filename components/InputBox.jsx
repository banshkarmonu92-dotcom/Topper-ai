import { useState } from "react";

export default function InputBox({ onAsk }) {
  const [question, setQuestion] = useState("");
  const [key, setKey] = useState("");

  function submit() {
    if (!key || !question) return;
    onAsk(question, key);
    setQuestion("");
  }

  return (
    <div className="input-box">
      <input
        type="password"
        placeholder="OpenRouter API Key"
        value={key}
        onChange={e => setKey(e.target.value)}
      />

      <textarea
        placeholder="Apna sawal likho..."
        value={question}
        onChange={e => setQuestion(e.target.value)}
      />

      <button onClick={submit}>
        AI se poochho
      </button>
    </div>
  );
        }
