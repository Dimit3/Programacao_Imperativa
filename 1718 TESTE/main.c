#include <stdio.h>
#include <stdlib.h>


typedef struct slist {
        int valor;
        struct slist *prox;
    } *LInt;


typedef struct nodo {
        int valor;
        struct nodo *esq, *dir;
    } *ABin;



int retiraNeg (int v[], int N)
{
    int i = 0;
    int j = 0;

    while (i<N)
    {
        if (v[i] < 0) i++;
        else {
            v[j] = v[i];
            i++;
            j++;
        }
    }
    return j;
}


int difConsecutivos (char s[]){
    int answer = 0;
    for(int i = 0; s[i]; i++) {
        int len = 0;
        for(int j = i; s[j]; j++) {
            int in_prev = 0;
            for(int k = i; k < j; k++) {
                if(s[k] == s[j]) in_prev = 1;
            }
            if(!in_prev) len++;
            else break;
        }
        if(len > answer) answer = len;
    }
    return answer;
}




int maximo (LInt l)
{
    int max = l->valor;
    while (l)
    {
        if (l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}



int removeAll (LInt *l, int x) {
    int r = 0;
    while (*l) {
        if ((*l)->valor == x) {
            (*l) = ((*l)->prox);
            r++;
        } else
            l = &((*l)->prox);
    }
    return r;
}


LInt arrayToList (int v[], int N)
{
    int i = 0;
    LInt new;
    LInt * newp = &new;
    while (i < N)
    {
        (*newp) = malloc(sizeof(struct slist));
        (*newp)->valor = v[i];
        (*newp)->prox  = NULL;
        newp = &((*newp)->prox);
        i++;
    }

    (*newp) = NULL;
    return new;

}




int minheapOK (ABin a)
{
    if (a == NULL) return 1;
    int l = a->esq ? minheapOK(a->esq) && a->valor < a->esq->valor : 1;
    int r = a->dir ? minheapOK(a->dir) && a->valor < a->dir->valor : 1;
    return l && r;


}


int max(int a, int b) {return a > b ? a : b; }

int maxHeap (ABin a) {
    int l = a->esq ? maxHeap(a->esq) : a->valor;
    int r = a->dir ? maxHeap(a->dir) : a->valor;
    return max(l,r);
}