	#include <stdio.h>
	#include <pthread.h>

	void *helloWorld() {
		printf("\nHello World\n\n");
	}

	int main( ){
	 	pthread_t thread;
	 	int flag;
	 	//Criando uma thread
	 	flag = pthread_create(&thread, NULL, helloWorld, NULL);
	 	//Condição para para ocorra um erro ao criar a thread
	 	if (flag != 0) 
	 		printf("Erro na criação da nova thread\n");

	 	//Encerrando a thread
	 	pthread_exit(NULL);
	 	return 0; /* O programa não vai chegar aqui. */
	}