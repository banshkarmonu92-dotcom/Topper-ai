export default function ChatBox({ messages }) {
  return (
    <div className="chat-box">
      {messages.map((m, i) => (
        <div key={i} className={m.role}>
          {m.text}
        </div>
      ))}
    </div>
  );
}
