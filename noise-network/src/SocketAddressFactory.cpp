#include "SocketAddressFactory.h"

#include "SocketAddressIPv4.h"
#include "SocketAddressIPv6.h"

auto SocketAddressFactory::Create(unsigned short family)
    -> std::unique_ptr<SocketAddressInterface> {
    switch (family) {
        case AF_INET:
            return std::make_unique<SocketAddressIPv4>();
        case AF_INET6:
            return std::make_unique<SocketAddressIPv6>();
        default:
            return nullptr;
    }
}

auto SocketAddressFactory::Create(const std::string& ip, unsigned short port)
    -> std::unique_ptr<SocketAddressInterface> {
    addrinfo* addrResult = nullptr;

    int result = getaddrinfo(ip.c_str(), nullptr, nullptr, &addrResult);
    if (result == 0) {
        // Check what family the ip address corresponds to
        switch (addrResult->ai_family) {
            case AF_INET: {
                sockaddr_in sa;
                sa = *reinterpret_cast<sockaddr_in*>(addrResult->ai_addr);
                sa.sin_port = htons(port);
                return std::make_unique<SocketAddressIPv4>(sa);
            }
            case AF_INET6: {
                sockaddr_in6 sa6;
                sa6 = *reinterpret_cast<sockaddr_in6*>(addrResult->ai_addr);
                sa6.sin6_port = htons(port);
                return std::make_unique<SocketAddressIPv6>(sa6);
            }
        }
    }

    // Did not match either IPv4 or IPv6
    return nullptr;
}

auto SocketAddressFactory::Create(const sockaddr& addr) -> std::unique_ptr<SocketAddressInterface> {
    switch (addr.sa_family) {
        case AF_INET:
            return std::make_unique<SocketAddressIPv4>(addr);
        case AF_INET6:
            return std::make_unique<SocketAddressIPv6>(addr);
        default:
            return nullptr;
    }
}

auto SocketAddressFactory::Create(const sockaddr_in& addr)
    -> std::unique_ptr<SocketAddressInterface> {
    switch (addr.sin_family) {
        case AF_INET:
            return std::make_unique<SocketAddressIPv4>(addr);
        default:
            return nullptr;
    }
}

auto SocketAddressFactory::Create(const sockaddr_in6& addr)
    -> std::unique_ptr<SocketAddressInterface> {
    switch (addr.sin6_family) {
        case AF_INET6:
            return std::make_unique<SocketAddressIPv6>(addr);
        default:
            return nullptr;
    }
}

auto SocketAddressFactory::CreateFromSocket(SOCKET socket)
    -> std::unique_ptr<SocketAddressInterface> {
    if (socket != INVALID_SOCKET) {
        struct sockaddr_storage addr;

        socklen_t len = sizeof(addr);
        int result = getpeername(socket, reinterpret_cast<struct sockaddr*>(&addr), &len);

        if (result == 0) {
            switch (addr.ss_family) {
                case AF_INET:
                    return std::make_unique<SocketAddressIPv4>(
                        *reinterpret_cast<struct sockaddr_in*>(&addr));
                case AF_INET6:
                    return std::make_unique<SocketAddressIPv6>(
                        *reinterpret_cast<struct sockaddr_in6*>(&addr));
                default:
                    return nullptr;
            }
        }
    }
    return nullptr;
}