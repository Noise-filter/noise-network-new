#include "SocketAddressIPv6.h"

#include <cstring>

SocketAddressIPv6::SocketAddressIPv6() {
    sin6_family = AF_INET6;
    sin6_port = htons(0);
    inet_pton(AF_INET6, "::", &sin6_addr);
}

SocketAddressIPv6::SocketAddressIPv6(const sockaddr& addr) {
    memcpy((sockaddr_in6*)this, (sockaddr_in6*)&addr, sizeof(sockaddr_in6));
}

SocketAddressIPv6::SocketAddressIPv6(const sockaddr_in6& addr) {
    memcpy((sockaddr_in6*)this, &addr, sizeof(sockaddr_in6));
}

SocketAddressIPv6::SocketAddressIPv6(const std::string& ip, unsigned short port) {
    sin6_family = AF_INET6;
    sin6_port = htons(port);
    inet_pton(AF_INET6, ip.c_str(), &sin6_addr);
}

short SocketAddressIPv6::getFamily() const { return sin6_family; }

std::string SocketAddressIPv6::getIp() const {
    char str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &sin6_addr, str, INET6_ADDRSTRLEN);
    return str;
}

unsigned short SocketAddressIPv6::getPort() const { return ntohs(sin6_port); }

void SocketAddressIPv6::setPort(unsigned short port) { sin6_port = htons(port); }

void SocketAddressIPv6::setIp(const std::string& ip) {
    inet_pton(AF_INET6, ip.c_str(), &sin6_addr);
}

SocketAddressIPv6& SocketAddressIPv6::operator=(const sockaddr& addr) {
    memcpy((sockaddr*)this, &addr, sizeof(sockaddr));
    return *this;
}

SocketAddressIPv6& SocketAddressIPv6::operator=(const sockaddr_in6& addr) {
    memcpy((sockaddr_in6*)this, &addr, sizeof(sockaddr_in6));
    return *this;
}

SocketAddressIPv6::operator std::string() { return getIp(); }

// SocketAddressIPv6::operator sockaddr() { return *(LPSOCKADDR)(LPSOCKADDR_IN6)this; }
//
// SocketAddressIPv6::operator LPSOCKADDR() { return (LPSOCKADDR)(LPSOCKADDR_IN6)this; }
//
// SocketAddressIPv6::operator LPSOCKADDR_IN6() { return (LPSOCKADDR_IN6)this; }