#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo{

    char nome[50];
    int numero;
    int nota;
    struct nodo *esq, *dir;

} *Alunos;


typedef struct strlist{

    char *string;
    struct strlist *prox;

} *StrList;


void print_array(int array[], int n){

    int i;

    for (i = 0; i < n; i++)
        printf("%d ", array[i]);

    putchar('\n');

}


void print_StrLit(StrList l){

    while (l){
        printf("%s\n", l->string);
        l = l->prox;
    }

    putchar ('\n');
}


int fnotass (Alunos a, int notas [21])
{
    int conta = 0;
    if (a)
    {
        notas[a->nota]++;
        conta = 1;
    }
    if (a == NULL){ return 0;}

    conta = conta + fnotass(a->esq,notas);
    conta = conta + fnotass(a->dir,notas);
    return conta;
}

int fnotas(Alunos a, int notas[21]){

    if (!a) return 0;

    notas[a->nota]++;

    return 1 + fnotas(a->esq, notas) + fnotas(a->dir, notas);
}



int rankAluno (Alunos a, int numero, int fnotas[21]) q
{

}



int main () {
    Alunos x = (Alunos) malloc(sizeof(struct nodo));
    Alunos y = (Alunos) malloc(sizeof(struct nodo));
    Alunos z = (Alunos) malloc(sizeof(struct nodo));
    Alunos w = (Alunos) malloc(sizeof(struct nodo));
    Alunos v = (Alunos) malloc(sizeof(struct nodo));
    Alunos j = (Alunos) malloc(sizeof(struct nodo));


    /*
                         _______ x(11) _______
                        /                     \
                       /                       \
                    y(3)                       z(12)
                   /    \                     /     \
                  /      \                   /       \
              NULL        j(6)           NULL         w(14)
                         /    \                      /     \
                        /      \                    /       \
                    NULL        NULL            v(13)        NULL
                                               /     \
                                              /       \
                                          NULL         NULL
    */

    strcpy(x->nome, "x");
    x->numero = 11;
    x->nota = 3;
    x->esq = y;
    x->dir = z;

    strcpy(y->nome, "y");
    y->numero = 3;
    y->nota = 12;
    y->esq = NULL;
    y->dir = j;

    strcpy(z->nome, "z");
    z->numero = 12;
    z->nota = 6;
    z->esq = NULL;
    z->dir = w;

    strcpy(w->nome, "w");
    w->numero = 14;
    w->nota = 3;
    w->esq = v;
    w->dir = NULL;

    strcpy(v->nome, "v");
    v->numero = 13;
    v->nota = 16;
    v->esq = NULL;
    v->dir = NULL;

    strcpy(j->nome, "j");
    j->numero = 6;
    j->nota = 18;
    j->esq = NULL;
    j->dir = NULL;

    Alunos *turma = &x;

    //TESTE DO EXE 1)

    int notas[21] = {0};
    printf("O numero de alunos e: %d\n", fnotas(*turma, notas));
    print_array(notas, 21);
    puts("\n");

    system("pause");
    return 0;
}