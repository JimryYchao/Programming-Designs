namespace Behavioral.State;
    /// <summary>
    /// TCP 状态的缺省行为
    /// </summary>
    internal abstract class TCPState {
        public virtual void Connect(TCPConnection connection) { }
        public virtual void Receive(TCPConnection connection, out byte[]? buffer) => buffer = null;
        public virtual void Close(TCPConnection connection) { }
        public virtual void SendMessage(TCPConnection connection, byte[] buffer) { }
        protected virtual void ChangeState(TCPConnection connection, TCPState state) {
            Console.WriteLine($"Switch state to >> {state}");
            connection.ChangeState(state);
        }
}
