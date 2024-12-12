#include <stdio.h>
#include <stdlib.h>

typedef struct listano ListaNo;
struct listano
{
    int info;
    ListaNo *prox; //ponteiro pro proximo elemento
    ListaNo *ant; //ponteiro pro elemento anterior
};

typedef struct lista Lista;
struct lista
{
    ListaNo *prim; //ponteiro para o primeiro nó
    ListaNo *ult; //ponteiro para o ultimo nó
};

Lista *cria()
{
    //aloca um ponteiro do tipo lista
    Lista *lst = malloc(sizeof(Lista));

    //cria uma lista vazia
    lst->prim = NULL;
    lst->ult = NULL;

    return lst; //retorna a lista vazia criada
}

//inserção na lista dupla
void insere_inicio(Lista *lst, int val)
{
    //aloca um no para o dado a ser inserido
    ListaNo *novo = malloc(sizeof(ListaNo));
    novo->info = val; //atribui o valor a ser inserido
    novo->prox = lst->prim; //prox do novo aponta para o atual primeiro elemento
    novo->ant = NULL; 

    if(lst->prim != NULL) //se a lista não estiver vazia
    {
        //o ant do primeiro elemento aponta para o novo elemento
        lst->prim->ant = novo; //isso insere o novo  a esqueda do prim
    }
    else //se estiver vazia
    {
        lst->ult = novo; //novo vai ser o primeiro então também será o ultimo
    }
    lst->prim = novo; //prim aponta pro novo elemento
}

void insere_final(Lista *lst, int val)
{
    //aloca um no para o dado a ser inserido
    ListaNo *novo = malloc(sizeof(ListaNo));
    novo->info = val; //atribui o valor a ser inserido
    novo->ant = lst->ult;//novo ant aponta para o atual ultimo elemento
    novo->prox = NULL; //novo aponta pra null

    if(lst->ult != NULL) //se a lista não estiver vazia
    {
        //o prox do ultim elemento aponta para o novo elemento
        lst->ult->prox = novo; //isso insere o novo a direita do ult
    }
    else //se estiver vazia
    {
        lst->prim = novo; //novo também será o primeiro
    }
    lst->ult = novo; //prim aponta pro novo elemento
}

//impressão na lista dupla
void imprime_comeco(Lista *lst)
{
    ListaNo *p = lst->prim; 

    //percorre do começo ao fim 
    //de nó em nó
    for(p; p != NULL; p = p->prox)
    {
        printf("%d", p->info);
    }
}

void imprime_fim(Lista *lst)
{
    ListaNo *p = lst->ult; 

    //percorre do começo ao fim 
    //de nó em nó
    for(p; p != NULL; p = p->ant)
    {
        printf("%d", p->info);
    }
}

//busca de elementos
ListaNo *busca(Lista *lst, int val)
{
    ListaNo *p = lst->prim;
    for(p; p != NULL; p = p->prox)
    {
        if(p->info == val)
        {
            return p;
        }
    }
    return NULL; 
}

//remoção de elementos
void lst_remove(Lista *lst, int num)
{
    //ponteiro para o buscar o elemento a ser retirado
    ListaNo *p = busca(lst, num);
    if(p == NULL) //se não encontrou
         return; 
    
    if(p = lst->prim) //se for o primeiro elemento 
        lst->prim = p->prox; // o ponteiro prim aponta para o segundo elemento
    else
        p->ant->prox = p->prox; //antecessor aponta para o sucessor do elemento que sai
    if(p = lst->ult) //se for o ultimo elemento 
        lst->ult = p->ant; //ponteiro que indica o ultimo elemento aponta para o penultimo
    else
        p->prox->ant = p->ant; //o sucessor aponta para o antecessor do elemento que sai
    
    free(p); //libero o elemento retirado

}

