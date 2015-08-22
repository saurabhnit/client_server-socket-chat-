#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
int main()
{
char str[100],send[100];
int listen_fd,comm_fd;
struct sockaddr_in servaddr;
listen_fd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htons(INADDR_ANY);
servaddr.sin_port=htons(5008);
bind(listen_fd,(struct sockaddr *)&servaddr,sizeof(servaddr));
listen(listen_fd,1);
comm_fd=accept(listen_fd,(struct sockaddr*) NULL,NULL);
while(1)
{
bzero(str,100);
read(comm_fd,str,100);
printf("%s",str);
bzero(send,100);
fgets(send,100,stdin);
if(strncmp(str,"bye",3)==0)
{
write(comm_fd,send,strlen(send)+1);
break;
}
write(comm_fd,send,strlen(send)+1);
}
}
