import socket
import time

# 状态接口
class TCPState:
    def connect(self, connection):
        pass
    
    def receive(self, connection):
        return None
    
    def close(self, connection):
        pass
    
    def send_message(self, connection, buffer):
        pass
    
    def change_state(self, connection, state):
        print(f"Switch state to >> {type(state).__name__}")
        connection.change_state(state)

# 具体状态：TCP已建立
class TCPEstablished(TCPState):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(TCPEstablished, cls).__new__(cls)
        return cls._instance
    
    def send_message(self, connection, buffer):
        if connection.is_connected():
            connection.connector.send(buffer.encode())
        else:
            self.change_state(connection, TCPUnconnected())
            return
        self.change_state(connection, TCPListen())
    
    def close(self, connection):
        if connection.connector:
            connection.connector.close()
            connection.connector = None
        self.change_state(connection, TCPUnconnected())

# 具体状态：TCP监听
class TCPListen(TCPState):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(TCPListen, cls).__new__(cls)
        return cls._instance
    
    def receive(self, connection):
        if not connection.is_connected():
            self.change_state(connection, TCPUnconnected())
            return None
        
        try:
            buffer = connection.connector.recv(1024)
            if buffer:
                self.change_state(connection, TCPEstablished())
                return buffer
            else:
                connection.connector.close()
                connection.connector = None
                self.change_state(connection, TCPUnconnected())
                return None
        except:
            if connection.connector:
                connection.connector.close()
                connection.connector = None
            self.change_state(connection, TCPUnconnected())
            return None

# 具体状态：TCP未连接
class TCPUnconnected(TCPState):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(TCPUnconnected, cls).__new__(cls)
        return cls._instance
    
    def connect(self, connection):
        addr = f"{connection.ip_address}:{connection.port}"
        while True:
            try:
                connector = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                connector.connect((connection.ip_address, connection.port))
                connection.connector = connector
                print(f"Connect to >>> {addr}")
                self.change_state(connection, TCPEstablished())
                break
            except Exception as e:
                print(f"Cannot connect to >>> {addr}: {e}")
                time.sleep(1)
                continue

# 上下文类
class TCPConnection:
    def __init__(self):
        self.tcp_state = TCPUnconnected()
        self.connector = None
        self.ip_address = "127.0.0.1"
        self.port = 7777
    
    def connect(self):
        self.tcp_state.connect(self)
    
    def receive(self):
        return self.tcp_state.receive(self)
    
    def close(self):
        self.tcp_state.close(self)
    
    def send_message(self, buffer):
        self.tcp_state.send_message(self, buffer)
    
    def is_connected(self):
        return self.connector is not None
    
    def change_state(self, state):
        self.tcp_state = state
