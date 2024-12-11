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

//busca na lista
int busca(Lista *lst, int num)
{
    //ponteiro do tipo nó para percorrer a lista
    ListaNo *p; 

    //do primeiro nó até NULL(final da lista)
    //"pulando" de prox em prox (de nó em nó)
    for(p = lst->prim; p != NULL; p = p->prox)
    {
        //se o valor quardado no nó for igual ao valor buscado
        if(p->info == num)
        {
            return 1;
        }
    }
    return 0;
}

//remoção de elementos da lista
void lst_remove(Lista *lst, int num)
{
    //ponteiro para guardar o endereço do elemento anterior ao elemento a ser excluído
    ListaNo *ant = NULL;
    //ponteiro para o começo da lista 
    ListaNo *p = lst->prim;

    //enquanto não chegar no final da lista
    //enquanto não encontrar o valor buscado
    while(p != NULL && p->info != num)
    {
        //ponteiro ant recebe o endereço do elemento atual
        ant = p;
        //ponteiro p segue para o próximo elemento
        p = p->prox;
    }

    //verifica se achou o elemento buscado
    //se P for NULL quer dizer que a busca chegou ao final da lista 
    //e não encontrou o elemento a ser retirado
    if(p != NULL)
    {
        //se o elemento a ser retirado é o primeiro
        if(ant == NULL)
            //o ponteiro que indica o começo da lista vai apontar para o próximo elemento(o segundo)
            lst->prim = p->prox;
        //se não for o primeiro
        else
            //o anterior ao elemento a ser retirado aponta para o posterior ao elemento a ser retirado
            ant->prox = p->prox;
        
        //retira o elemento da lista
        free(p); 
    }
}

int main(void)
{
    int num, resp;

    //criando a lista
    Lista *lst = lst_cria();

    printf("Insira 5 elementos a lista: \n");
    //inserindo 5 elementos
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        insere_inicio(lst, num); 
    }

    //imprimindo a lista
    printf("A lista eh: ");
    imprime(lst);
    printf("\n");

    //buscando na lista
    printf("Pesquise um elemento\n");
    scanf("%d", &num);
    resp = busca(lst, num);
    if(resp)
        printf("O elemento %d esta na lista :)\n", num);
    else
        printf("O elemento %d nao esta na lista ;-;\n", num);

    printf("Digite um elemento a ser retirado\n");
    scanf("%d", &num);
    lst_remove(lst, num);

    printf("Agora lista eh: ");
    imprime(lst);
    
    printf("\n");
}


