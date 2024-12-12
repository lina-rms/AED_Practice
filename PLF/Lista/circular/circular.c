//Uma lista circular segue o mesmo padrão de uma lista simples
//a diferença é na inserção / remoção

#include <stdio.h>
#include <stdlib.h>

typedef struct listano ListaNo;
struct listano //cada nó sempre guarda um valor e um ponteiro pro proximo
{
    int info;
    ListaNo *prox; 
};

typedef struct lista Lista;
struct lista 
{
    ListaNo *prim; //ponteiro que indica o começo da lista
};

//cria uma lista vazia
Lista *cria(void)
{
    Lista *lst = malloc(sizeof(Lista));
    lst->prim = NULL; // inicia uma lista vazia

    return lst; //retorna a lista
}

//verifica se a lista está vazia
int verifica_lista(Lista *lst)
{
    //0 se não estiver vazia, 1 se estiver vazia
    return (lst->prim == NULL);
}

//insere na lista(no começo)
void insere(Lista *lst, int val)
{
    //aloca um nó para o elemento a serinserido da lista
    ListaNo *novo = malloc(sizeof(ListaNo)); 
    novo->info = val; //atribui o valor ao campo da struct

    //se a lista estiver vazia
    if(lst->prim == NULL)
    {
        novo->prox = novo; //novo elemento aponta para ele mesmo
        lst->prim = novo; //prim aponta pro novo elemento
    }
    //se não estiver vazia vamos percorrer a lista até achar o "ultimo" elemento 
    else
    {
        ListaNo *aux = lst->prim;

        //enquanto não encontrar o elemento que aponta pra prim
        //percorrer até encontrar o elemento  que aponta pra prim
        while(aux->prox != lst->prim)
        {
           aux = aux->prox; // guarda o elemento encontrado
        }
        aux->prox = novo; //o ultimo elemento aponta para o novo primeiro
        novo->prox = lst->prim; //novo primeiro aponta pro antigo primeiro
        lst->prim = novo; //atualiza o ponteiro que indica o inicio (agora ele aponta para o novo elemento) 
    }
}

//imprime a lista
void imprime(Lista *lst)
{
    //no para parcorrer a lista
    ListaNo *p = lst->prim; 

    //se a lista não for vazia
    if(p != NULL)
    {
        do
        {
            printf("%d ", p->info); //imprime o elemento
            p = p->prox; //pula para o proximo elemento
        } while (p != lst->prim); //percorre a lista enquanto p for diferente do prim
    }
    else
    {
        printf("Lista vazia\n");
    }
}



