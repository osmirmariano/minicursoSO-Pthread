#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREAD 4

void delay(){
    int x, y, z;
    int valor = 500;
    for(x = 0; x < valor; x++){
        for(y = 0; y < valor; y++){
            for(z = 0; z < valor; z++){
                valor = valor;
            }
        }

    }
}

void *mostrarThread(void *arg){
    int *pvalor;
    pvalor = arg;
    printf("Thread %d executando \n", *pvalor);
    delay();
    printf("Thread %d finalizada \n", *pvalor);
}

int main(){
    pthread_t thread[N_THREAD];//Variável do tipo pthread_t
    int x, arg[N_THREAD];//Arg será o argumento que será passado para a função mostrarThread
    for(x = 0; x < N_THREAD; x++){
        arg[x] = x+1;
        pthread_create(&thread[x], NULL, mostrarThread, (void *)&arg[x]);//Criação de Thread
        //pthread_join(thread[x], NULL);
    }
    for(x = 0; x < N_THREAD; x++){
        pthread_join(thread[x], NULL);
    }
    printf("\n");
    return 0;
}