#include "State.hpp"
#include "Context.hpp"

// 实现ChangeState方法
void TCPState::ChangeState(TCPConnection* connection, TCPState* state) {
    std::cout << "Switch state to >> " << typeid(*state).name() << std::endl;
    connection->ChangeState(state);
}
