#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void) {
	struct sockaddr_in direcciónServidor;
	direcciónServidor.sin_family = AF_INET;
	direcciónServidor.sin_addr.s_addr = INADDR_ANY;
	direcciónServidor.sin_port = htons(8080);

	int servidor = socket(AF_INET, SOCK_STREAM, 0);

	if (bind(servidor, (void*) &direcciónServidor, sizeof(direcciónServidor)) != 0) {
		perror("Falló el bind");
		return 1;
	}

	printf("Estoy escuchando\n");
	listen(servidor, 100);

	for(;;);
	return 0;
}
