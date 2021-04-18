#ifndef SOCKET_ADDRESS_INTERFACE_H
#define SOCKET_ADDRESS_INTERFACE_H

#include <string>

#include "SocketIncludes.h"

/*
This is the interface used for socket address.
User can implement their own socket address class if they must
but the provided classes SocketAddressIPv4 and SocketAddressIPv6 should be enough in most cases.
*/
class SocketAddressInterface {
  public:
    virtual ~SocketAddressInterface() = default;

    // Returns the ip address in decimal dotted or hexadecimal format based on which family is used
    // (IPv4 or IPv6)
    [[nodiscard]] virtual std::string getIp() const = 0;
    [[nodiscard]] virtual unsigned short getPort() const = 0;

    // Returns the ip family being used
    [[nodiscard]] virtual short getFamily() const = 0;

    // Sets the ip address in decimal dotted or hexadecimal format based on which family is used
    // (IPv4 or IPv6)
    virtual void setIp(const std::string& ip) = 0;
    virtual void setPort(unsigned short port) = 0;

    // Returns the ip address in decimal dotted or hexadecimal format based on which family is used
    // (IPv4 or IPv6)
    virtual operator std::string() = 0;

    // virtual operator sockaddr() = 0;
    // virtual operator LPSOCKADDR() = 0;
};

#endif