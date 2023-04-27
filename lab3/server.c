#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <stdlib.h>

void server(void)
{
int rcvid;  //komu otvet
int chid;   // kanal ID
char message[30];
chid = ChannelCreate(0);             //sozdanie kanala
printf("Chanel id : %d \n", chid);
printf("Pid: %d \n", getpid());
//dolgo
while (1)
{
//polychit i vivesti soobshenie	
rcvid = MsgReceive(chid, message, sizeof(message), NULL);
printf("Polychili soobshenie, rcid %X \n", rcvid);
printf("Soobshenie takoe : \"%s\".\n", message);
if (!strcmp(message, "I992 Volganov AP"))
printf(message,"Identification succes");
else sprintf(message,"Something went wrong");
//OTVET
MsgReply(rcvid, EOK, message, sizeof(message));
printf("\"%s\". \n", message);
}
}
int main(void)
{
printf("prog server \n");
sleep(5);
return (1);
}