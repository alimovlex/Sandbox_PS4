#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <orbis/libkernel.h>

#include "../../_common/log.h"
#include "util.hpp"
#include "text_drawer.hpp"

#define PORT 9025

void echoServer(int &sockfd)
{
    std::string buff = "";
    for(;;) {
    // bzero(buff, MAX);
    read(sockfd, &buff[0], sizeof(buff));
    Notify("From client: %s\n", buff.c_str());
    //drawSampleText(buff);
    // system(buff);
    if (!buff.compare("exit")) 
    {
        Notify("Server Exit...");
        buff = "Press Enter to terminate server connection";
        write(sockfd, buff.c_str(), buff.size());
        write(sockfd, "\n", 2);
        close(sockfd);
        buff.clear();
        break;
    }
    else
    {
        write(sockfd, buff.c_str(), sizeof(buff));
        buff.clear();
        //bzero(buff, MAX);
        //strcpy(buff, "***end***");
        //write(sockfd, buff, sizeof(buff));
    }
    }
}

void start_tcp_server()
{
    int sockfd;
    int connfd;
    socklen_t addrLen;

    struct sockaddr_in serverAddr, clientAddr;

    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    // Create a server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        Notify("Failed to create socket: %s", strerror(errno));
        // for (;;);
    }
    else
    {
        // Bind to 0.0.0.0:PORT
        memset(&serverAddr, 0, sizeof(serverAddr));
        // bzero(&servaddr, sizeof(servaddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        serverAddr.sin_port = htons(PORT);

        if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) != 0)
        {
            Notify("Failed to bind to 0.0.0.0: %d %s", PORT, strerror(errno));
            for (;;)
                ;
        }
        else
        {
            // Listen and accept clients
            addrLen = sizeof(clientAddr);

            if (listen(sockfd, 5) != 0)
            {
                Notify("Failed to listen: %s", strerror(errno));
                for (;;)
                    ;
            }
            else
            {
                for (;;)
                {
                    connfd = accept(sockfd, (struct sockaddr *)&clientAddr, &addrLen);

                    if (connfd < 0)
                    {
                        Notify("Failed to accept client: %s", strerror(errno));
                        for (;;);
                    } else {
                    //Notify("Accepted client %d and from port %d", clientAddr.sin_addr.s_addr, clientAddr.sin_port);
                    // Write a "hello" message then terminate the connection
                    std::string msg = "***WELCOME to echo server!!!***";
                    write(connfd, msg.c_str(), msg.size());
                    write(connfd, "\n", 2);
                    //close(connfd);
                    echoServer(connfd);
                    //Notify("Closed client %d", connfd);
                    }
                    
                }
            }
        }
    }
}
