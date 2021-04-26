#ifndef WINSOCK_FUNCTIONS_H
#define WINSOCK_FUNCTIONS_H

#include <string>

bool initWinSock();
bool shutdownWinSock();

int getLastSystemError();
std::string getErrorMessage(int errorCode);

#endif