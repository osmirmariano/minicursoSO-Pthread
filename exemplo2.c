#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *helloWorld(){
    printf("\nHello World\n");
}

int main (){
    pthread_t threads[NUM_THREADS];
    int flag, i;

    for(i = 0; i < NUM_THREADS; i++){
        flag = pthread_create(&threads[i], NULL, helloWorld, NULL);
        if (flag != 0) 
	 		printf("Erro na criação da nova thread\n");
    }
    printf("Thread principal a esperar a terminação das threads criadas \n");

    for(i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL); /* Esperara a junção das threads */
    pthread_exit(NULL); /* Encerrar a thread*/
    return 0; 
}