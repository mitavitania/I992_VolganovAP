#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>

int main()
{
char smsg[20] = "I992 Volganov AP";
char rmsg[200];
int coid;
long serv_pid;
printf("Prog client , Vvedite PID servera \n");
scanf("%ld", &serv_pid);
printf("Vveli %ld \n", serv_pid);
coid = ConnectAttach(0, serv_pid, 1, 0, 0);

printf("Connect res %d \n , vvedite soobshenie\n", coid);
printf("Vveli %s \n", smsg);
if (MsgSend(coid, smsg, strlen(smsg) + 1, rmsg, sizeof(rmsg)) == -
1)
{
printf("Error MsgSend\n");
}
printf("Otvet ot servera\n%s\n", rmsg);
ConnectDetach(coid);
return (1);
}
