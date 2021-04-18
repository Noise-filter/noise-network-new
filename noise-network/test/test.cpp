#include <iostream>

#include "SocketAddressFactory.h"

int main() {
    auto addr = SocketAddressFactory::Create("127.0.0.1");

    std::cout << addr->getIp() << std::endl;
    std::cout << addr->getPort() << std::endl;
    std::cout << addr->getFamily() << std::endl;

    return 0;
}