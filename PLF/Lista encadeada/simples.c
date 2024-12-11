#include <stdio.h>
#include <stdlib.h>

typedef struct listano ListaNo;
struct listano
{
    int info;
    ListaNo* prox; //ponteiro para o próximo nó da lista
};

typedef struct lista Lista;
struct lista
{
    ListaNo* prim; //ponteiro para o primeiro nó da lista
};

/* -------> OPERAÇÕES BÁSICAS <------- */

//criação da lista
Lista *lst_cria(void)
{
    //alocando um ponteiro para representar a lista
    Lista *lst = malloc(sizeof(Lista));

    //inicia uma lista vazia que não tem nenhum nó
    lst->prim = NULL;

    //retorna a lista
    return lst; 
}

//inserção na lista
void insere_inicio(Lista *lst, int num)
{
    //ponteiro do novo nó a ser inserido na lista
    ListaNo* novo = malloc(sizeof(ListaNo));
    novo->info = num; //atribui o novo valor ao campo da struct

    //na primeira inserção faz com que o prox do primeiro elemento aponte pra NULL
    //nas outras inserções faz com que o prox do novo elemento aponte pro elemento anteriormente inserido
    novo->prox = lst->prim;

    //lista aponta para o novo nó inserido
    lst->prim = novo;
}

//impessão da lista(pecorrer a lista)
void imprime(Lista *lst)
{
    //ponteiro do tipo nó para percorrer a lista
    ListaNo *p; 

    //do primeiro nó até NULL(final da lista)
    //"pulando" de prox em prox (de nó em nó)
    for(p = lst->prim; p != NULL; p = p->prox)
    {
        printf("%d ", p->info);
    }
}

int main(void)
{
    int num;

    //criando a lista
    Lista *lst = lst_cria();

    //inserindo 5 elementos
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        insere_inicio(lst, num); 
    }

    //imprimindo a lista
    imprime(lst);
}


