#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fun(int sig);

int main() {

	int r1=0, r2=0;

	signal(SIGUSR2,fun);
	if (fork()==0)  /* Proceso hijo */
	{
		sleep(3);
		printf("Envio de senal a mi padre.\n");
		kill(getppid(),SIGUSR2 );
		
	}
	else /* Proceso padre */
	{
		r1=sleep(7);
		r2=sleep(1);
		printf("\n r1=%d r2=%d",r1,r2);
	}

}

void fun( int sig) {
	sleep(1);
	printf("\n Recibo señal de mi hijo.");

}
