#ifndef SOCKET_ADDRESS_IPV6_H
#define SOCKET_ADDRESS_IPV6_H

#include "SocketAddressInterface.h"

/*
        Inherits from sockaddr_in6 and works with IPv6 only.
*/
class SocketAddressIPv6 : public SocketAddressInterface, sockaddr_in6 {
  public:
    SocketAddressIPv6();
    SocketAddressIPv6(const sockaddr& addr);
    SocketAddressIPv6(const sockaddr_in6& addr);
    SocketAddressIPv6(const std::string& ip, unsigned short port = 0);

    [[nodiscard]] std::string getIp() const override;
    [[nodiscard]] unsigned short getPort() const override;

    // Returns the ip family being used, either AF_INET or AF_INET6
    [[nodiscard]] unsigned short getFamily() const override;

    void setPort(unsigned short port) override;
    void setIp(const std::string& ip) override;

    virtual SocketAddressIPv6& operator=(const sockaddr& addr);
    virtual SocketAddressIPv6& operator=(const sockaddr_in6& addr);

    // virtual operator sockaddr();
    // virtual operator LPSOCKADDR();
    // virtual operator LPSOCKADDR_IN6();
};

#endif