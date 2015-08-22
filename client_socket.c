#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
int main()
{
int sockfd,n;
char send[100],recv[100];
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(5008);
inet_pton(AF_INET,"localhost",&(servaddr.sin_addr));
connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
while(1)
{
bzero(send,100);
bzero(recv,100);
fgets(send,100,stdin);
write(sockfd,send,strlen(send)+1);
read(sockfd,recv,100);
if(strncmp(send,"bye",3)==0)
{
break;
}
printf("%s",recv);
}
}
