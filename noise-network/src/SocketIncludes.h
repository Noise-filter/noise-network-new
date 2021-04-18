#ifndef WINSOCK_INCLUDES_H
#define WINSOCK_INCLUDES_H

#ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#endif

#ifdef _WIN32
#    include <winsock2.h>
#    include <ws2tcpip.h>

#    pragma comment(lib, "ws2_32.lib")
#else
#    include <arpa/inet.h>
#    include <netdb.h> /* Needed for getaddrinfo() and freeaddrinfo() */
#    include <netinet/in.h>
#    include <sys/socket.h>
#    include <sys/types.h>
#    include <unistd.h> /* Needed for close() */

using SOCKET = int;
constexpr int INVALID_SOCKET = -1;

#endif

#endif