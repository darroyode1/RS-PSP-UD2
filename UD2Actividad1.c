#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handler(int sig);

int main() {

	signal(SIGUSR1,SIG_IGN);
	signal(SIGUSR2,handler);
	printf("\nMensaje\n");
	pause();
		

}

void handler( int sig) {
	printf("\n Señal %s capturada\n", strsignal(sig));

}
