#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREAD 10
#define N 1000
#define MAX 10

typedef struct ARGS{
    int id;
}ARGS;

pthread_mutex_t meu_mutex = PTHREAD_MUTEX_INITIALIZER;
int somatotal = 0;

void *realiza_soma(void *p){
    int resultado = 0, x;
    int meu_id = ((ARGS *)p)->id;

    for(x = 0; x < N; x++)
        resultado += rand()%MAX;

    pthread_mutex_lock(&meu_mutex);
    somatotal += resultado;
    pthread_mutex_unlock(&meu_mutex);
    printf("\n Thread %d: parcial %d\n", meu_id, resultado);
    pthread_exit((void *)0);
}

int main(){
    int x, rc, status;
    pthread_t id[N_THREAD];
    pthread_attr_t atributo;
    ARGS args[N_THREAD];

    pthread_attr_init(&atributo);
    pthread_attr_setdetachstate(&atributo, PTHREAD_CREATE_JOINABLE);

    printf("\nCriando Thread\n");

    for(x = 0; x < N_THREAD; x++){
        args[x].id = x;
        rc = pthread_create(&id[x], &atributo, realiza_soma, &args[x]);
        if(rc){
            printf("\nErro ao criar a thread\n");
        }
        printf("[%d]", x);
    }


    printf ("\nJuntando threads\n");
    for(x = 0; x < N_THREAD; x++){
        args[x].id = x;
        rc = pthread_join(id[x], (void**)&status);
        if(rc){
            printf("\nErro na junção\n");
            exit(-1);
        }
    }

    printf("\nSoma total: %d\n", somatotal);
    pthread_exit(NULL);
}