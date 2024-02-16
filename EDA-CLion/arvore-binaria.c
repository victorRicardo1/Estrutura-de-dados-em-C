#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
    TIPOCHAVE chave;
    struct aux *esq, *dir;
} NO;

typedef NO* PONT;

/* retorna o endereco do NO que contem chave=ch ou NULL caso a
chave nao seja encontrada. Utiliza busca binaria recursiva
*/

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){
    if (raiz == NULL) return NULL;
    if (raiz->chave == ch) return raiz;
    if (raiz->chave<ch)
        return buscaBinaria(ch,raiz->dir);
    return buscaBinaria(ch,raiz->esq);
}

/* cria um novo (aloca memoria e preenche valores) no com chave=ch e
retorna seu endereco */
PONT criarNovoNo(TIPOCHAVE ch){
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return novoNo;
}

/* funcao auxiliar (recursiva) para insercao */
bool inserirAux(PONT raiz, TIPOCHAVE ch){
    if (raiz->chave > ch) {
        if (raiz->esq == NULL) {
            raiz->esq = criarNovoNo(ch);
            return true;
        }else return inserirAux(raiz->esq, ch);
    }else{
        if (raiz->dir == NULL) {
            raiz->dir = criarNovoNo(ch);
            return true;
        }else return inserirAux(raiz->dir, ch);
    }
}

/* insere um novo no com chave=novaChave na arvore binaria apontada
por raiz */
bool inserirNo(PONT * raiz, TIPOCHAVE novaChave){
    if (*raiz == NULL){
        *raiz = criarNovoNo(novaChave);
        return true;
    }
    else return inserirAux(*raiz, novaChave);
}

// Busca binária não recursiva devolvendo o nó pai
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
    PONT atual = raiz;

    *pai = NULL;
    while (atual) {
        if(atual->chave == ch)
            return(atual);
        *pai = atual;
        if(ch < atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }
    return(NULL);
}

PONT maior_esquerdo(PONT p, PONT *ant){
    *ant = p;
    p = p->esq;
    while (p->dir) {
        *ant = p;
        p = p->dir;
    }
    return(p);
}

/*
bool excluirChave(PONT *raiz, TIPOCHAVE ch){
    PONT atual, no_pai, substituto, pai_substituto;
    substituto=NULL;
    atual = buscaNo(*raiz, ch, &no_pai);
    if(atual == NULL) return false;
    if((!atual->esq)||(!atual->dir)) { // tem zero ou um filho
        if((!atual->esq)) substituto = atual->dir;
        if((!atual->dir)) substituto = atual->esq;
        if(!no_pai) {// o excluido eh raiz
            *raiz = substituto;
        }else {
            if(no_pai->chave > ch) no_pai->esq = substituto;
            else no_pai->dir = substituto;
        }
        free(atual);
    }
    else { // tem dois filhos
        substituto = maior_esquerdo(atual,&pai_substituto);
        atual->chave = substituto->chave;
        if (pai_substituto->esq == substituto){
            pai_substituto->esq = substituto->esq;
        } else {
            pai_substituto->dir = substituto->esq;
        }
        free(substituto);
    }
}
 */

//Forma 2 pra remover

PONT remover(PONT raiz, int ch){
    if(!raiz) return NULL;
    if(raiz->chave == ch){
        //Remoção de folha
        if((!raiz->esq)&&(!raiz->dir)){
            free(raiz);
            return NULL;
        }else{
            //caso o nó tenha 1 filho
            if(raiz->esq != NULL || raiz->dir != NULL){
                PONT aux;
                if(raiz->esq != NULL)
                    aux = raiz->esq;
                else
                    aux = raiz -> dir;
                free(raiz);
                return aux;
            }else if(raiz->esq && raiz->dir){
                PONT auxPai;
            }

        }
    }else{
        if(ch < raiz->chave){
            printf("Passando pelo nodo de chave: %d\n", raiz->chave);
            raiz->esq = remover(raiz->esq, ch);
        }else{
            printf("Passando pelo nodo de chave: %d\n", raiz->chave);
            raiz->dir = remover(raiz->dir, ch);
        }
        return raiz;
    }
}

//Função


/* Exibe arvore Em Ordem */
void exibirArvoreEmOrdem(PONT raiz){
    if (raiz == NULL) return;
    exibirArvoreEmOrdem(raiz->esq);
    printf("%d ",raiz->chave);
    exibirArvoreEmOrdem(raiz->dir);
}

/* Exibe arvore Pre Ordem */
void exibirArvorePreOrdem(PONT raiz){
    if (raiz == NULL) return;
    printf("%d ",raiz->chave);
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
}


/* Exibe arvore Pos Ordem */
void exibirArvorePosOrdem(PONT raiz){
    if (raiz == NULL) return;
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
    printf("%d ",raiz->chave);
}

/* Exibe arvore Em Ordem (com parenteses para os filhos) */
void exibirArvore(PONT raiz){
    if (raiz == NULL) return;
    printf("%d",raiz->chave);
    printf("(");
    exibirArvore(raiz->esq);
    exibirArvore(raiz->dir);
    printf(")");
}

/* funcao auxiliar na destruicao (liberacao da memoria) de uma
arvore */
void destruirAux(PONT subRaiz){
    if (subRaiz){
        destruirAux(subRaiz->esq);
        destruirAux(subRaiz->dir);
        free(subRaiz);
    }
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz
*/
void destruirArvore(PONT * raiz){
    destruirAux(*raiz);
    *raiz = NULL;
}


int contar(PONT raiz) {
    int contador;
    if (raiz == NULL) {
        return 0;
    } else {
        int e = contar(raiz->esq);
        int d = contar(raiz->dir);
        contador = 1 + e + d;
        return contador;
    }
}

int contarNoFolha(PONT raiz){
    if(raiz == NULL) return 0;
    if((!raiz -> esq)&&(!raiz->dir)) return 1; // its equal if(raiz -> esq == NULL && raiz-> dir == NULL);
    return contarNoFolha(raiz->esq) + contarNoFolha(raiz->dir);
}

int maiorChave(int A, int B){
    if(A>B){
        return A;
    }else return B;
}

int menorChave(int A, int B){
    if(A<B) return A;
    else return B;
}

int MaiorMenor(PONT raiz, int *max, int *min){
    if(!raiz) return 0;
    if(*max == -1 || *min == -1){
        *min = raiz->chave;
        *max = raiz ->chave;
    }
    *max = maiorChave(*max, raiz->chave);
    *min = menorChave(*min, raiz->chave);

    MaiorMenor(raiz->esq, max, min);
    MaiorMenor(raiz->dir, max, min);
}

int arvoreBinaria() {
    PONT raiz = NULL; // Inicializa a árvore
    int escolha;
    int max = -1;
    int min = -1;
    TIPOCHAVE chave;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Excluir elemento\n");
        printf("3 - Buscar elemento\n");
        printf("4 - Exibir arvore em Ordem\n");
        printf("5 - Exibir arvore em Pre-Ordem\n");
        printf("6 - Exibir arvore em Pos-Ordem\n");
        printf("7 - Exibir arvore com Parenteses\n");
        printf("8 - Contar elementos da arvore\n");
        printf("9 - Contar folhas da arvore\n");
        printf("10 - Exibir maior e menor da arvore\n");
        printf("11 - Sair\n");

        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Digite a chave a ser inserida: ");
                scanf("%d", &chave);
                inserirNo(&raiz, chave);
                break;
            case 2:
                printf("Digite a chave a ser excluida: ");
                scanf("%d", &chave);
                raiz = remover(raiz, chave);
                break;
            case 3:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &chave);
                PONT pai = NULL;
                PONT encontrado = buscaNo(raiz, chave, &pai);
                if (encontrado != NULL) {
                    printf("Chave %d encontrada. Pai: %d\n", encontrado->chave, (pai != NULL) ? pai->chave : -1);
                } else {
                    printf("Chave %d não encontrada.\n", chave);
                }
                break;
            case 4:
                printf("Arvore em Ordem: ");
                exibirArvoreEmOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Arvore em Pre-Ordem: ");
                exibirArvorePreOrdem(raiz);
                printf("\n");
                break;
            case 6:
                printf("Arvore em Pos-Ordem: ");
                exibirArvorePosOrdem(raiz);
                printf("\n");
                break;
            case 7:
                printf("Arvore com Parenteses: ");
                exibirArvore(raiz);
                printf("\n");
                break;
            case 8:
                printf("Quantidade de nos na arvore: %d\n", contar(raiz));
                break;
            case 9:
                printf("Quantidade de folhas na arvore: %d\n", contarNoFolha(raiz));
                break;
            case 10:
                MaiorMenor(raiz, &max, &min);
                printf("Maior valor: %d\n", max);
                printf("Menor valor: %d", min);
                break;
            case 11:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 11);

    // Destroi a árvore e libera a memória
    destruirArvore(&raiz);

    return 0;
}