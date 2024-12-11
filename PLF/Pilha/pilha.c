//PARANDO PRA PENSAR, 
//Uma lista simplesmente encadeada com inserção no começo 
//e remoção no começo é uma PILHA

#include <stdio.h>
#include <stdlib.h>

typedef struct pilhano PilhaNo;
struct pilhano{
    int info;
    PilhaNo *prox; //ponteiro para o próximo "nó" da pilha
};

typedef struct pilha Pilha;
struct pilha
{
    PilhaNo *prim; //ponteiro para o topo da pilha
};

/* -------> OPERAÇÕES BÁSICAS <------- */

//criação da pilha
Pilha* pilha_cria(void)
{
    //alocação do ponteiro que aponta para o topo da pilha
    Pilha *p = malloc(sizeof(Pilha));

    //inicia uma pilha vazia que não tem nenhum elemento
    p->prim = NULL;

    //retorna a pilha
    return p; 
}

//inserção na pilha(push)
void pilha_push(Pilha *p, int num)
{
    //ponteiro do novo elemento a ser inserido na pilha
    PilhaNo *novo = malloc(sizeof(Pilha));
    novo->info = num; //atribui o novo valor ao campo da struct

    //ponteiro prox do novo aponta para onde o topo da pilha está apontando
    novo->prox = p->prim; 
    //agora o topo da pilha aponta para o novo
    p->prim = novo; 
}

//verifica se a pilha está vazia
int verifica_pilha(Pilha *p)
{
    //returna true se a pilha está vazia
    //se p->prim for nulo quer dizer que a pilha está vazia
    return(p->prim == NULL);
}

//remoção da pilha(pop)
int pilha_pop(Pilha *p)
{
    //verifica se a pilha já está vazia
    if(verifica_pilha(p))
    {
        printf("A pilha já está vazia");
        exit(1);
    }

    //Ponteiro auxiliar para o elemento do topo da pilha
    //auxilia na visualização do valor removido
    PilhaNo *temp = p->prim;
    int num = temp->info; //num tem o valor do topo

    //faz o topo apontar para o segundo elemento da lista
    p->prim = temp->prox; //agora o segundo elemento é o topo da lista

    free(temp); //libera o topo que foi retirado
    return num; //retorna o valor que foi retirado da pilha
}

//impressão da pilha
void imprime(Pilha *p)
{
    //ponteiro do tipo nó para percorrer a pilha
    PilhaNo *q;

    //do primeiro elemento até NULL(base da pilha)
    //"pulando" de prox em prox (de elemento em elemento) "descendo" a pilha
    for(q = p->prim; q != NULL; q = q->prox)
    {
        printf("%d\n", q->info); //imprime cada elemento
    }
}

int main(void)
{
    int num;

    //cria a pilha vazia
    Pilha *p = pilha_cria();

    printf("Insira 5 numeros:\n");
    //insere 5 elementos na pilha
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        pilha_push(p, num); //insere o numero lido na pilha
    }

    printf("A pilha eh:\n");
    imprime(p);

    printf("Vamos retirar um elemento da pilha:\n");
    pilha_pop(p);
    imprime(p);

}



