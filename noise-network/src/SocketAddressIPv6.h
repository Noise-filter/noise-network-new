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

    virtual std::string getIp() const;
    virtual unsigned short getPort() const;

    // Returns the ip family being used, either AF_INET or AF_INET6
    virtual short getFamily() const;

    virtual void setPort(unsigned short port);
    virtual void setIp(const std::string& ip);

    virtual SocketAddressIPv6& operator=(const sockaddr& addr);
    virtual SocketAddressIPv6& operator=(const sockaddr_in6& addr);

    virtual operator std::string();
    // virtual operator sockaddr();
    // virtual operator LPSOCKADDR();
    // virtual operator LPSOCKADDR_IN6();
};

#endif