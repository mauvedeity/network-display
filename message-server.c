/*
 _ __ ___   ___  ___ ___  __ _  __ _  ___       ___  ___ _ ____   _____ _ __ 
| '_ ` _ \ / _ \/ __/ __|/ _` |/ _` |/ _ \_____/ __|/ _ \ '__\ \ / / _ \ '__|
| | | | | |  __/\__ \__ \ (_| | (_| |  __/_____\__ \  __/ |   \ V /  __/ |   
|_| |_| |_|\___||___/___/\__,_|\__, |\___|     |___/\___|_|    \_/ \___|_|   
                               |___/                                         
*/

/*
This is the message server - it listens on the local IP over UDP on
port 7991. Incoming text gets pushed out to the local LCD screen to
notify anyone who's looking at it.

Runs as a server, so runs until killed.

Code based on examples from http://www.programminglogic.com/sockets-programming-in-c-using-udp-datagrams/

*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

#define LISTENPORT 7991

int main() {
  int udpSocket, nBytes;
  char buffer[1024], outbuf[1024];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(LISTENPORT);
  serverAddr.sin_addr.s_addr = inet_addr("0.0.0.0");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  addr_size = sizeof serverStorage;

  while(1){
    nBytes = recvfrom(udpSocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);

    // display output
    //for(i=0;i<nBytes-1;i++)
    //  buffer[i] = toupper(buffer[i]);

    strncpy(outbuf, buffer, (size_t)nBytes);	// may not nul-terminate
    outbuf[nBytes] = '\0';			// so nul-terminate yourself

    printf("output: ]%s[\n", outbuf);
  }

  return 0;
}






