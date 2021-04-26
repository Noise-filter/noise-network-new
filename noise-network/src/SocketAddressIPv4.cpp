#include "SocketAddressIPv4.h"

#include <cstring>

SocketAddressIPv4::SocketAddressIPv4() {
    sin_family = AF_INET;
    sin_port = htons(0);
    inet_pton(AF_INET, "0.0.0.0", &sin_addr);
}

SocketAddressIPv4::SocketAddressIPv4(const sockaddr& addr) {
    memcpy(static_cast<sockaddr_in*>(this), &addr, sizeof(sockaddr_in));
}

SocketAddressIPv4::SocketAddressIPv4(const sockaddr_in& addr) {
    memcpy(static_cast<sockaddr_in*>(this), &addr, sizeof(sockaddr_in));
}

SocketAddressIPv4::SocketAddressIPv4(const std::string& ip, unsigned short port) {
    sin_family = AF_INET;
    sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &sin_addr);
}

unsigned short SocketAddressIPv4::getFamily() const { return sin_family; }

std::string SocketAddressIPv4::getIp() const {
    char str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &sin_addr, str, INET_ADDRSTRLEN);
    return str;
}

unsigned short SocketAddressIPv4::getPort() const { return ntohs(sin_port); }

void SocketAddressIPv4::setPort(unsigned short port) { sin_port = htons(port); }

void SocketAddressIPv4::setIp(const std::string& ip) { inet_pton(AF_INET, ip.c_str(), &sin_addr); }

SocketAddressIPv4& SocketAddressIPv4::operator=(const sockaddr& addr) {
    memcpy(static_cast<sockaddr_in*>(this), &addr, sizeof(sockaddr_in));
    return *this;
}

SocketAddressIPv4& SocketAddressIPv4::operator=(const sockaddr_in& addr) {
    memcpy(static_cast<sockaddr_in*>(this), &addr, sizeof(sockaddr_in));
    return *this;
}

// SocketAddressIPv4::operator sockaddr() { return *(sockaddr*)this; }

// SocketAddressIPv4::operator LPSOCKADDR() { return (LPSOCKADDR)(LPSOCKADDR_IN)this; }
//
// SocketAddressIPv4::operator LPSOCKADDR_IN() { return (LPSOCKADDR_IN)this; }