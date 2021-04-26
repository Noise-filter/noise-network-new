#ifndef SOCKET_ADDRESS_IPV4_H
#define SOCKET_ADDRESS_IPV4_H

#include "SocketAddressInterface.h"

/*
        Inherits from sockaddr_in and works with IPv4 only.
*/
class SocketAddressIPv4 : public SocketAddressInterface, public sockaddr_in {
  public:
    SocketAddressIPv4();
    explicit SocketAddressIPv4(const sockaddr& addr);
    explicit SocketAddressIPv4(const sockaddr_in& addr);
    explicit SocketAddressIPv4(const std::string& ip, unsigned short port = 0);

    [[nodiscard]] std::string getIp() const override;
    [[nodiscard]] unsigned short getPort() const override;

    // Returns the ip family being used, either AF_INET or AF_INET6
    [[nodiscard]] unsigned short getFamily() const override;

    void setIp(const std::string& ip) override;
    void setPort(unsigned short port) override;

    SocketAddressIPv4& operator=(const sockaddr& addr);
    SocketAddressIPv4& operator=(const sockaddr_in& addr);

    // operator sockaddr();
    // virtual operator LPSOCKADDR();
    // virtual operator LPSOCKADDR_IN();
};

#endif