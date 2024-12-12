#include <stdio.h>
#include <stdlib.h>

typedef struct filano FilaNo;
struct filano{
    int info;
    FilaNo *prox; //ponteiro para o próximo "nó" da fila
};

typedef struct fila Fila;
struct fila
{
    FilaNo *ini; //ponteiro para o inicio
    FilaNo *fim; //ponteiro para o fim
};

/* -------> OPERAÇÕES BÁSICAS <------- */

//criação da fila
Fila *fila_cria(void)
{
    //aloca um ponteiro para a fila
    Fila *fila = malloc(sizeof(Fila));

    //inicia a fila sem nenhum elemento
    fila->ini = NULL;
    fila->fim = NULL; 

    //retorna a fila
    return fila; 
}

//inserção na fila
void insere_fim(Fila *fila, int num)
{
    //ponteiro do novo nó a ser inserido na fila
    FilaNo* novo = malloc(sizeof(FilaNo));
    novo->info = num; //atribui o novo valor ao campo da struct
    novo->prox = NULL; //faz com que seja o ultimo elemento

    //se a fila não estiver vazia
    if(fila->fim != NULL)
        //ponteiro prox do fim da fila aponta para o novo elemento
        //assim o novo elemento passa a ser o ultimo
        fila->fim->prox = novo;
    //se a fila estiver vazia
    else
        //inicio da fila aponta para o novo elemento
        fila->ini = novo;
    //atualiza o ponteiro que indica o final da fila
    //agora ele aponta para o novo pois ele é o ultimo elemento da fila
    fila->fim = novo; 
}

//remoção de elementos da fila
int remove_inicio(Fila *fila)
{
    //ponteiro auxiliar para a remoção (aponta para o inicio da fila)
    FilaNo* temp = fila->ini;

    //serve para guardar o valor que vai ser retirado
    int num = temp->info; //basicamente para visualização do valor

    //inicio da fila vai apontar para o segundo elemento
    fila->ini = temp->prox;

    //verifica se a fila ficou vazia
    //pensar no caso em que a fila tinha somente 1 elemento antes da remoção
    if(fila->ini == NULL)
        //atualiza o ponteiro do fim
        fila->fim = NULL;

    //libera o elemento retirado
    free(temp); 

    return(num); //retorna o valor retirado
}

//verifica se a fila está vazia
int verifica_fila(Fila *fila)
{
    //retorna true se a fila estiver vazia
    //se o inicio da fila é NULL quer dizer que a fila está vazia
    return(fila->ini == NULL);
}

//libera a fila
void libera(Fila *fila)
{
    FilaNo *p = fila->ini;

    //enquanto não chegar no final
    while(p != NULL)
    {
        FilaNo* temp = p->prox;
        free(p); //libera os nós da fila
        p = temp;
    }
    //libera a fila
    free(fila);
}

void imprime(Fila *fila)
{
    //ponteiro do tipo nó para percorrer a fila
    FilaNo *q;

    //percorre a fila do inicio até o fim
    //vai de nó em nó até o NULL
    for(q = fila->ini; q != NULL; q = q->prox)
    {
        //imprime o conteudo
        printf("%d ", q->info);
    }
}

int main(void)
{
    int num; 
    
    //cria a fila
    Fila *fila = fila_cria(); 

    printf("Insira 5 numeros:\n");
    //insere 5 elementos na fila
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        insere_fim(fila, num); //insere o numero lido na fila
    }

    printf("A fila eh:\n");
    imprime(fila);

    printf("\nO primeiro elemento foi atendido!\nAgora a fila eh:\n");
    remove_inicio(fila);
    imprime(fila);

}


