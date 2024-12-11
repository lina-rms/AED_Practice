//lista simplesmente encadeada com a função de inserção modificada
//para que os elementos sejam inseridos em ordem

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
void insere_crescente(Lista *lst, int num)
{
    //ponteiro para o começo da lista 
    ListaNo* p = lst->prim;
    //ponteiro para guardar o endereço do elemento anterior ao elemento a ser inserido
    ListaNo *ant = NULL;

    //aloca um espaço de memória para novo nó a ser inserido na lista
    ListaNo* novo = malloc(sizeof(ListaNo));
    novo->info = num; //atribui o novo valor ao campo da struct

    //enquanto não chegar no final da lista
    //enquanto o valor a ser inserido for maior do que os já existentes
    while(p != NULL && p->info < num)
    {
        //ponteiro ant recebe o endereço do elemento atual
        ant = p;
        //ponteiro p segue para o próximo elemento
        p = p->prox;
    }

    //se o valor encontrado é o primeiro
    if(ant == NULL)
    {
       //o novo elemento vira o primeiro da lista
        novo->prox = lst->prim;
        lst->prim = novo;  
    }
    //se não for o primeiro
    else
    {
        //prox do novo elemento aponta para o elemento encontrado(que é maior)
        //isso faz um diagrama assim: (ant) -> (maior) <- (novo)
        //levando em consideração que ant < novo < prox 
        novo->prox = ant->prox;
        //prox do anterior ao valor que é maior que o valor inserido aponta para o valor inserido
        //isso faz um diagrama assim: (ant) -> (novo) -> (maior)
        ant->prox = novo; 
    } 
}

//-----> as outras funções são exatamente iguais <-------------
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
        insere_crescente(lst, num); 
    }

    //imprimindo a lista
    printf("A lista ordenada eh: ");
    imprime(lst);
    printf("\n");

}


