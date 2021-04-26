#include <iostream>

#include "SocketAddressFactory.h"
#include "WinsockFunctions.h"

int main() {
    auto addr = SocketAddressFactory::Create("127.0.0.1");
    if (addr == nullptr) {
        std::cout << getErrorMessage(getLastSystemError()) << '\n';
    } else {
        std::cout << addr->getIp() << std::endl;
        std::cout << addr->getPort() << std::endl;
        std::cout << addr->getFamily() << std::endl;
    }

    return 0;
}