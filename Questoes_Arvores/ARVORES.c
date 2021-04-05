#include <stdio.h>
#include <stdlib.h>



typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;



typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;






LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

// 1
/*presente uma definic˜ao n˜ao recursiva da fun¸c˜ao int length (LInt) que calcula o comprimento de uma lista ligada. (https://codeboard.io/projects/16161)
*/


int length (LInt l)
{
    int comp = 0;
    while (l != NULL)  {l = l->prox; comp++;}
    return comp;
}
// 2
/*Apresente uma defini¸c˜ao n˜ao recursiva da fun¸c˜ao void freeL (LInt) que liberta o espa¸co
        ocupado por uma lista.*/


void freeL (LInt l) {
    LInt ant = l;
    LInt now = l;
    while (now != NULL)
    {
        ant = now;
        now = now->prox;
        free(ant);
    }
}


// 3
/*Apresente uma defini¸c˜ao n˜ao recursiva da fun¸c˜ao void imprimeL (LInt) que imprime no
        ecran os elementos de uma lista (um por linha).*/


void imprimeL (LInt l)
{
    while (l != NULL) {
        printf("%d\n" , l->valor);
        l = l->prox;
    }
}


/*
 * 4
 * Apresente uma definic˜ao n˜ao recursiva da fun¸c˜ao LInt reverseL (LInt) que inverte uma
lista (sem criar uma nova lista).*/


LInt reverseL (LInt l)
{

    LInt prev = NULL, next, current = l;

    while (current != NULL)
    {
        next = current -> prox;
        current -> prox = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/*
5
Apresente uma definic˜ao n˜ao recursiva da fun¸c˜ao void insertOrd (LInt *, int)
que insere ordenadamente um elemento numa lista ordenada
*/




void insertOrd (LInt *l, int x){
    LInt new;
    while((*l)!=NULL && (*l)->valor<x)
        l=&((*l)->prox);
    new = malloc (sizeof (struct lligada));
    new->valor = x;
    new->prox  = *l;
    *l=new;
}



/*
6. Apresente uma defini¸c˜ao n˜ao recursiva da fun¸c˜ao int removeOneOrd (LInt *, int) que
remove um elemento de uma lista ordenada. Retorna 1 caso o elemento a remover n˜ao exista,
0 no outro caso.*/



int removeOneOrd (LInt *l, int x){
    LInt temp;

    while ((*l) && x != (*l)->valor)
        l = &((*l)->prox);

    if (*l == NULL) return 1;

    else
        {
        temp = (*l) -> prox;
        free(*l);
        (*l) = temp;
        }
    return 0;
}





/*
7. Defina uma fun¸c˜ao merge (LInt *r, LInt a, LInt b) que junta duas listas ordenadas (a
e b) numa unica lista ordenada (r).

*/


void merge (LInt *r, LInt l1, LInt l2){
    while (l1 && l2)

        if(l1->valor < l2->valor)
        {
            *r=l1;
            r=&((*r)->prox);
            l1=l1->prox;

        }
        else

        {
            *r=l2;
            r=&((*r)->prox);
            l2=l2->prox;
        }

    if (l1) (*r) = l1;
    if (l2) (*r) = l2;

}




/*
8. Defina uma fun¸c˜ao void splitQS (LInt l, int x, LInt *mx, LInt *Mx) que, dada uma
lista ligada l e um inteiro x, parte a lista em duas (retornando os endere¸cos dos primeiros
elementos da lista em *mx e *Mx): uma com os elementos de l menores do que x e a outra com
os restantes. Note que esta fun¸c˜ao n˜ao dever´a criar copias dos elementos da lista.
*/



void splitMS (LInt l, int x, LInt *mx, LInt *Mx)
{
    while(l){
        if (l->valor<x)
        {
            *mx=l;
            mx=&((*mx)->prox);
        }
        else{
            *Mx=l;
            Mx=&((*Mx)->prox);
        }
        l=l->prox;
    }
    *mx=NULL;
    *Mx=NULL;
}




/*
9. Defina uma fun¸c˜ao LLig parteAmeio (LLig *l) que, parte uma lista n˜ao vazia *l a meio.
Se x contiver os elementos {1,2,3,4,5}, ap´os a invoca¸c˜ao y=parteAmeio(&x) a lista y devera
conter os elementos {1,2} e a lista x os restantes {3,4,5}
*/

LInt parteAmeio (LInt *l){
    int i = length(*l) / 2, j;
    LInt r = *l;
    LInt * p = l;
    for (j = 0 ; j < i; ++j)
        p=&((*p)->prox);
    *l = *p;
    *p = NULL;
    if (i == 0)
    {
        *l = r;
        return NULL;
    }
    else return r;
}






/*
 * 10. Apresente uma definic˜ao n˜ao recursiva da func˜ao int removeAll (LInt *, int) que remove
todas as ocorrencias de um dado inteiro de uma lista, retornando o numero de celulas removidas.
 */


int removeAll (LInt *l, int x){
    int i = 0;
    LInt p;
    while(*l != NULL)
    {
        if ((*l)->valor == x)
        {
            p = (*l)->prox;
            free (*l);
            *l = p;
            ++i;
        } else
            l = &((*l)->prox);
    }
    return i;
}





/*
11
Apresente uma definic˜ao da func˜ao int removeDups (LInt *) que remove os
valores repetidos de uma lista (deixando apenas a primeira ocorrencia).
*/



int removeDups (LInt *l){
    int i = 0;
    while (*l){
        i = i + removeAll ( &((*l)->prox), (*l)->valor);
        l= &((*l)->prox);
    }
    return i;
}

/*
 * 12
Apresente uma definic˜ao da func˜ao int removeMaiorL (LInt *) que remove (a primeira
ocorrencia) o maior elemento de uma lista n˜ao vazia, retornando o valor desse elemento.
 */


int removeMaiorL (LInt *l){
    int maior = (*l)->valor;
    LInt * m = l;
    LInt aux = NULL ;
    while (*l)
    {
        if ((*l)->valor > maior)
        {
            maior = (*l)->valor;
            m = l;
        }
        l = &((*l)->prox);
    }


    aux = (*m)->prox;
    free(*m);
    (*m) = aux;
    return maior;
}


/*
13
Apresente uma definic˜ao n˜ao recursiva da func˜ao void init (LInt *) que remove o ultimo
elemento de uma lista n˜ao vazia (libertando o correspondente espaco).
*/


void init (LInt *l){

    while ((*l)->prox)
        l = &((*l)->prox);

    free(*l);
    *l = NULL;
}



/*
14
Apresente uma definic˜ao n˜ao recursiva da func˜ao void appendL (LInt *, int)
que acrescenta um elemento no fim da lista.
*/


void appendL (LInt * l, int x){
    while (*l)
        l = &((*l)->prox);

    *l = malloc(sizeof(struct lligada));
    (*l) -> valor = x;
    (*l) -> prox;
}




/*
15. Apresente uma definic˜ao da func˜ao void concatL (LInt *a, LInt b) que acrescenta a lista
b a lista *a.
*/


void concatL (LInt *a, LInt b)
{
    while ((*a) != NULL) { a = &((*a)->prox);}
    (*a) = b;

}




/*
16
Apresente uma definic˜ao da func˜ao LInt cloneL (LInt) que cria uma nova lista ligada com
os elementos pela ordem em que aparecem na lista argumento.
*/




LInt cloneL (LInt l)
{
    LInt r,* e = &r;
    while(l)
    {
        *e = malloc(sizeof(struct lligada));
        (*e) -> valor = l->valor;
        l = l ->prox;
        e = &((*e)->prox);
    }
    *e=NULL;
    return r;
}



/*
17
Apresente uma definic˜ao n˜ao recursiva da func˜ao LInt cloneRev (LInt) que cria uma nova
lista ligada com os elementos por ordem inversa.

Por exemplo, se a lista l tiver 5 elementos com os valores {1,2,3,4,5} por esta ordem, a
invoca¸c˜ao cloneRev(l) deve corresponder a uma nova lista com os elementos {5,4,3,2,1}
por esta ordem.
*/



LInt cloneRev (LInt l){
    LInt r = 0,v = 0;
    while(l){
        r = (LInt) malloc (sizeof (struct lligada));
        r -> valor = l -> valor;
        r -> prox = v;
        v = r;
        l = l -> prox;
    }
    return r;
}


/*
18
Defina uma func˜ao int maximo (LInt l) que calcula qual o maior valor armazenado numa
lista n˜ao vazia
*/


int maximo (LInt l)
{
    int max = l->valor;
    l = l->prox;
    while (l)
    {
        if (l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}


/*
19
Apresente uma definic˜ao iterativa da func˜ao int take (int n, LInt *l) que, dado um inteiro n e uma lista ligada de inteiros l,
apaga de l todos os nodos para alem do n-esimo
(libertando o respectivo espaco). Se a lista tiver n ou menos nodos, a func˜ao n˜ao altera a lista.
A func˜ao deve retornar o comprimento final da lista.

*/

int take (int n, LInt *l){
    LInt p;
    int i;
    for(i = 0; *l && n > i; ++i)
        l = &((*l)->prox);
    while(*l)
    {
        p = (*l)->prox;
        free(*l);
        *l = p;
    }
    return i;
}



/*
 * 20
Apresente uma definic˜ao iterativa da func˜ao int drop (int n, LInt *l) que, dado um inteiro n e uma lista ligada de inteiros l,
 apaga de l os n primeiros elementos da lista (libertando o respectivo espaco). Se a lista tiver n ou menos nodos, a func˜ao liberta a totalidade da lista.
A func˜ao deve retornar o numero de elementos removidos.
*/


int drop (int n, LInt *l)
{
    LInt p;
    int i;
    for(i = 0;*l && n > i; ++i)
    {
        p = (*l) -> prox;
        free (*l);
        *l = p;
    }
    return i;
}







/*
21
O tipo LInt pode ser usado ainda para implementar listas circulares. Defina uma func˜ao LInt
Nforward (LInt l, int N) que, dada uma lista circular da como resultado o endereco do
elemento da lista que esta N posic˜oes a frente.
 */


LInt Nforward (LInt l, int N)
{
    Lint p;
    while (l!=NULL && N>0)
    {
        l = l->prox;
        p = l;
        N--;
    }
    return p;
}









/*
22. Defina uma func˜ao int listToArray (LInt l, int v[], int N) que, dada uma lista l,
preenche o array v com os elementos da lista.
A func˜ao devera preencher no maximo N elementos e retornar o numero de elementos preenchidos.
*/


int listToArray (LInt l, int v[], int N)
{
    int i = 0;
    while (l && N > i)
    {
        v[i] = l -> valor;
        ++i;
        l = l -> prox;
    }
    return i;
}





/*
23.
Defina uma func˜ao LInt arrayToList (int v[], int N) que constroi uma lista com os
elementos de um array, pela mesma ordem em que aparecem no array..
*/



LInt arrayToList (int v[], int N)
{
    int i = 0;
    LInt l, * pl;
    pl = &l;
    while (i < N)
    {
        (*pl) = malloc(sizeof(struct lligada));
        (*pl) -> valor = v[i];
        (*pl) -> prox  = NULL;
        pl = &((*pl)->prox);
        i++;
    }
    *pl=NULL;
    return l;

}






/*
24.
Defina uma func˜ao LInt somasAcL (LInt l) que, dada uma lista de inteiros, constroi uma
nova lista de inteiros contendo as somas acumuladas da lista original (que devera permanecer
inalterada).
Por exemplo, se a lista l tiver os valores [1,2,3,4] a lista contruıda pela invocac˜ao de
somasAcL (l) devera conter os valores [1,3,6,10].
*/




LInt somasAcL (LInt l)
{
    int acc = 0;
    LInt nova, * pnova;
    pnova = &nova;
    while (l)
    {
        (*pnova) = malloc(sizeof(struct lligada));
        acc = acc + (l -> valor);
        (*pnova) -> valor = acc;
        (*pnova) -> prox = NULL;
        l = l->prox;
        pnova = &((*pnova) -> prox);
    }
    *pnova = NULL;
    return nova;
}







/*
 * 25. Defina uma func˜ao void remreps (LInt l) que, dada uma lista ordenada de inteiros, elimina
dessa lista todos os valores repetidos assegurando que o espaco de memoria correspondente
aos n removidos e correctamente libertado.
 */




void remreps (LInt l){
    LInt proximo,aux;
    while (l != NULL)
    {
        proximo = l -> prox;

        while ((proximo != NULL) && (l -> valor == proximo -> valor))
        {
            aux = proximo -> prox;
            free(proximo);
            proximo = aux;
        }

        l = l -> prox = proximo;

    }
}





/*
26.
Defina uma func˜ao LInt rotateL (LInt l) que coloca o primeiro elemento de uma lista no
fim. Se a lista for vazia ou tiver apenas um elemento, a func˜ao n˜ao tem qualquer efeito pratico
(i.e., devolve a mesma lista que recebe como argumento).
Note que a sua func˜ao n˜ao deve alocar nem libertar memoria. Apenas re-organizar as celulas da lista
*/





LInt rotateL (LInt l) {
    if(!l || !(l->prox)) return l;
    LInt temp = l;
    LInt list = l->prox;
    while(temp->prox) temp = temp->prox;
    temp->prox = l;
    l->prox = NULL;
    return list;
}






/*
27
Defina uma func˜ao LInt parte (LInt l) que parte uma lista l em duas: na lista l ficam
apenas os elementos das posic˜oes impares; na lista resultante ficam os restantes elementos.

Assim, se a lista x tiver os elementos {1,2,3,4,5,6} a chamada y = parte (x), coloca na
lista y os elementos {2,4,6} ficando em x apenas os elementos {1,3,5}

*/



LInt parte (LInt l) {
    LInt  l2, f=NULL;
    int n = 0;

    if (l) {l2 = f = l->prox;}

    while (l && l2)
    {
        if (n%2 == 0)
        {
            l->prox = l2->prox;
            l = l2 ->prox;
            n++;
        }
        else
        {
            l2->prox = l->prox;
            l2 = l1->prox;
            n++;
        }
    }
    return f;
}







//28. Apresente uma definic˜ao da func˜ao int altura (ABin) que calcula a altura de uma arvore
//      binaria. (https://codeboard.io/projects/16220)


int altura (ABin a)
{
    int r=0,c,b;
    if (a!=NULL)
    {
        c=altura(a->esq);
        b=altura(a->dir);
        r+=1+(c>b?c:b);
    }
    return r;
}










//29. Defina uma func˜ao ABin cloneAB (ABin) que cria uma copia de uma arvore. (https://
//codeboard.io/projects/16267)





ABin cloneAB (ABin a) {
    ABin p;
    if (a==NULL) p=NULL;
    else
    {
        p=(ABin)malloc(sizeof(struct nodo));
        p->valor=a->valor;
        p->esq=cloneAB(a->esq);
        p->dir=cloneAB(a->dir);
    }
    return p;
}






//30. Defina uma fun¸c˜ao void mirror (ABin *) que inverte uma arvore (sem criar uma nova
//´arvore). (https://codeboard.io/projects/16268)





void mirror (ABin *a) {
    ABin p;
    if (*a)
    {
        p=(*a)->dir;
        (*a)->dir=(*a)->esq;
        (*a)->esq=p;

        mirror(&((*a)->dir));
        mirror(&((*a)->esq));

    }
}











//31. Defina a fun¸c˜ao void inorder (ABin , LInt *) que cria uma lista ligada de inteiros a partir
// de uma travessia inorder de uma arvore binaria. (https://codeboard.io/projects/16269)




void inorder (ABin a, LInt * l) {
    LInt p;
    if(a)
    {
        inorder(a->dir,l);
        p=*l;
        *l=malloc(sizeof(struct lligada));
        (*l)->valor=a->valor;
        (*l)->prox=p;
        inorder(a->esq,l);
    }
}




//32. Defina a fun¸c˜ao void preorder (ABin , LInt *) que cria uma lista ligada de inteiros a
//partir de uma travessia preorder de uma ´arvore bin´aria. (https://codeboard.io/projects/
//16270)





void preorder (ABin a, LInt * l) {
    LInt p;
    if(a)
    {

        preorder(a->dir,l);
        preorder(a->esq,l);
        p=*l;
        *l=malloc(sizeof(struct lligada));
        (*l)->valor=a->valor;
        (*l)->prox=p;
    }
}














//33. Defina a func˜ao void posorder (ABin , LInt *) que cria uma lista ligada de inteiros a
//partir de uma travessia posorder de uma ´arvore bin´aria. (https://codeboard.io/projects/
//16272)









void posorder (ABin a, LInt * l) {
    LInt p;
    if(a)
    {
        p=*l;
        *l=malloc(sizeof(struct lligada));
        (*l)->valor=a->valor;
        (*l)->prox=p;
        posorder(a->dir,l);
        posorder(a->esq,l);
    }
}














//34. Apresente uma definic˜ao da func˜ao int depth (ABin a, int x) que calcula o nıvel (menor)
//a que um elemento esta numa arvore binaria (-1 caso n˜ao exista). (https://codeboard.io/
//projects/16273)




int depth (ABin a, int x) {
    int m=-1,a1,a2;
    if(a)
    {
        if(a->valor==x)
            m=1;
        else
        {
            a1=depth(a->esq,x);
            a2=depth(a->dir,x);
            if (a1>0 && a2>0) m=1+((a1<a2)?a1:a2);
            else if (a1<0 && a2>0) m=a2+1;
            if (a2<0 && a1>0) m=a1+1;
        }

    }
    return m;
}









//35. Defina uma func˜ao int freeAB (ABin a) que liberta o espa¸co ocupado por uma ´arvore
//        binaria, retornando o numero de nodos libertados. (https://codeboard.io/projects/16274)





int freeAB (ABin a)
{
    int r = 0;
    if (a)
    {
        r = r + freeAB(a -> esq);
        r = r + freeAB(a -> dir);
        free(a);
        r++;
    }
    return r;
}










//36. Defina uma func˜ao int pruneAB (ABin *a, int l) que remove (libertando o espco respectivo) todos os elementos da arvore *a
// que est˜ao a uma profundidade superior a l, retornando
//   o numero de elementos removidos.

//Assuma que a profundidade da raız da arvore e 1, e por isso a invocac˜ao pruneAB(&a,0)
//corresponde a remover todos os elementos da ´arvore a. (https://codeboard.io/projects/
//16275)







int pruneAB (ABin *a, int l) {
    int n;
    if(!(*a)) return 0;

    if(l == 0) {
        n = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL;
    }
    else n = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir),l - 1);

    return n;
}








//37. Defina uma func˜ao int iguaisAB (ABin a, ABin b) que testa se duas arvores s˜ao iguais
//        (tem os mesmos elementos e a mesma forma). (https://codeboard.io/projects/16276)








int iguaisAB (ABin a, ABin b) {
    int verd=0;
    if(a && b)
    {
        verd=(a->valor==b->valor) && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
    }
    if (!a && !b)
        verd=1;
    return verd;
}






//38. Defina uma fun¸c˜ao LInt nivelL (ABin a, int n) que, dada uma arvore binaria, constRoi
//        uma lista com os valores dos elementos que est˜ao armazenados na ´arvore ao n´ıvel n (assuma
//        que a raiz da arvore esta ao nıvel 1). (https://codeboard.io/projects/16277)





LInt concat(LInt a, LInt b) {
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox;
    temp->prox = b;
    return a;
}

LInt nivelL (ABin a, int n) {
    if(!a || n < 1) return NULL;
    if(n == 1) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
}






//39. Defina uma func˜ao int nivelV (ABin a, int n, int v[]) que preenche o vector v com os
//        elementos de a que se encontram no nıvel n.
//Considere que a raız da arvore se encontra no nıvel 1.
//A func˜ao devera retornar o numero de posi¸c˜oes preenchidas do array. (https://codeboard.
//io/projects/16278)





int nivelV (ABin a, int n, int v[]) {
    if(!a || n < 1) return 0;
    if(n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq,n - 1,v);
        int d = nivelV(a->dir,n - 1,v+e);
        return e + d;
    }
}





//40. Defina uma func˜ao int dumpAbin (ABin a, int v[], int N) que dada uma arvore a, preenche
//o array v com os elementos da arvore segundo uma travessia inorder. A func˜ao devera
//        preencher no maximo N elementos e retornar o numero de elementos preenchidos. (https:
//codeboard.io/projects/16279)




int dumpAbin (ABin a, int v[], int N) {
    int li=0;
    if(a && li<N)
    {
        li+=dumpAbin(a->esq,v,N);
        if(li<N)
        {
            v[li]=a->valor;
            ++li;
        }
        li+=dumpAbin(a->dir,v+li,N-li);
    }
    return li;
}







//41. Defina uma func˜ao ABin somasAcA (ABin a) que, dada uma arvore de inteiros, calcula a
//´arvore das somas acumuladas dessa arvore.
//A ´arvore calculada deve ter a mesma forma da ´arvore recebida como argumento e em cada
//        nodo deve conter a soma dos elementos da sub-´arvore que a´ı se inicia. (https://codeboard.
//io/projects/16280)


ABin somasAcA (ABin a) {
    if(!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    new->valor = a->valor + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0);
    return new;
}


//42. Apresente uma definic˜ao da func˜ao int contaFolhas (ABin a) que dada uma ´arvore bin´aria
//        de inteiros, conta quantos dos seus nodos s˜ao folhas, i.e., que n˜ao tˆem nenhum descendente.
//(https://codeboard.io/projects/16281)




int contaFolhas (ABin a)
{
    int r = 0;

    if (a) {
        if (a->dir == NULL && a->esq == NULL) {
            r++;
        } else {
            r = r + contaFolhas(a->esq);
            r = r + contaFolhas(a->dir);
        }
    }
    return r;

}










//43. Defina uma fun¸c˜ao ABin cloneMirror (ABin a) que cria uma arvore nova, com o resultado
//de inverter a arvore (efeito de espelho). (https://codeboard.io/projects/16282)


ABin cloneMirror (ABin a) {
    ABin clone=NULL;
    if(a)
    {
        clone=(ABin)malloc(sizeof(struct nodo));
        clone->valor=a->valor;
        clone->esq=cloneMirror(a->dir);
        clone->dir=cloneMirror(a->esq);
    }
    return clone;
}




//44. Apresente uma definic˜ao n˜ao recursiva da func˜ao int addOrd (ABin *a, int x) que adiciona um elemento a uma ´arvore bin´aria de procura.
// A func˜ao devera retornar 1 se o elemento
//a inserir ja existir na arvore ou 0 no outro caso. (https://codeboard.io/projects/16283)


// recursiva só teste

int addOrd (ABin *a, int x)
{
    int r = 0;

    if ((*a) != NULL)
    {
        if ( x == ((*a)->valor)) return 1;
        else if ( x < ((*a)->valor)) r= addOrd(&(*a)->esq,x);
        else if ( x > ((*a)->valor)) r= addOrd(&(*a)->dir,x);

    }


    if ((*a) == NULL)
    {
        (*a) = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = (*a)->dir = NULL;

    }

    return r;

}


// nao recursiva que pede


int addOrd (ABin *a, int x) {
    int r = 0;
    while(*a && r == 0)
    {
        if      ((*a)->valor > x)          a=&((*a)->esq);
        else if ((*a)->valor < x)          a=&((*a)->dir);
        else                               r=1;                    //((*a)->valor == x)
    }
    if(r == 0)
    {
        *a=malloc(sizeof(struct nodo));
        (*a)->valor=x;
        (*a)->esq=NULL;
        (*a)->dir=NULL;
    }
    return r;
}




//45. Apresente uma definic˜ao n˜ao recursiva da func˜ao int lookupAB (ABin a, int x) que testa
//se um elemento pertence a uma arvore binaria de procura. (https://codeboard.io/projects/
//16284)

int lookupAB (ABin a, int x)
{
    while (a!= NULL)
    {
        if (x < a->valor) a = a->esq;
        else if (x > a->valor)  a = a->dir;
        else if (x == a->valor) return 1;
    }
    if (a == NULL)
        return 0;
}




//46. Apresente uma definic˜ao da func˜ao int depthOrd (ABin a, int x) que calcula o nıvel a que
//        um elemento esta numa arvore binaria de procura (-1 caso n˜ao exista). (https://codeboard.
//io/projects/16285)


int depthOrd (ABin a, int x) {
    int i=0,j=0;
    while(a != NULL && i == 0)
    {
        if(a->valor > x)      a = a->esq;

        else if(a->valor < x) a = a->dir;

        else i=1;       // parar loop pois a->valor == x

        ++j;

    }
    if(i==0) j=-1;
    return j;
}






//47. Apresente uma definic˜ao n˜ao recursiva da func˜ao int maiorAB (ABin) que calcula o maior
//elemento de uma arvore binaria de procura n˜ao vazia. (https://codeboard.io/projects/
//16286)



int maiorAB (ABin a)
{
    ABin ant = NULL;

    while (a != NULL)
    {
        ant = a;
        a = a -> dir;
    }

    if (a==NULL) return ant->valor;


}





//48. Defina uma func˜ao void removeMaiorA (ABin *) que remove o maior elemento de uma
//arvore binaria de procura. (https://codeboard.io/projects/16287)


void removeMaiorA (ABin *a)
{
    ABin l;
    if(a)                    // so se por acaso alguem utilza-se com uma arvore vazia para nao dar segmentation fault
    {
        while((*a)->dir)
            a=&((*a)->dir);         // pegar no mais á direira
        l=(*a)->esq;                // pegar no ramo á esquerda
        free(*a);                  // remover o maior que é o mais á direita
        *a=l;                      // esse da direita vai ficar a ser o da esq
    }
}







//49. Apresente uma definic˜ao da func˜ao int quantosMaiores (ABin a, int x) que, dada uma
//arvore binaria de procura de inteiros e um inteiro, conta quantos elementos da arvore s˜ao
//        maiores que o inteiro dado. (https://codeboard.io/projects/16288)


//funciona mais eficiente

int quantosMaiores (ABin a, int x) {
    int r = 0;
    if(a)
    {
        if(a->valor >= x)
        {
            if(a->valor > x) ++r;
            r + = quantosMaiores(a->esq,x);
            r + = quantosMaiores(a->dir,x);
        }
        else
        {
            r + = quantosMaiores(a->dir,x);
        }
    }
    return r;
}





// funciona mas menos eficiente

int quantosMaiores (ABin a, int x)
{
    int r = 0;
    if (a)
    {
        if (a->valor > x) ++r;
        r = r + quantosMaiores(a->esq,x);
        r = r + quantosMaiores(a->dir,x);
    }
    return r;

}





//50. Apresente uma defini¸c˜ao da func˜ao void listToBTree (LInt l, ABin *a) que constroi uma
//arvore binaria de procura a partir de uma lista ligada ordenada. (https://codeboard.io/
//projects/16289)




void insertOrd (ABin p,ABin * a)
{
    while(*a)
    {
        if((*a)->valor > p->valor)
            a=&((*a)->esq);
        else if((*a)->valor<p->valor)
            a=&((*a)->dir);

    }
    *a=p;
}

void listToBTree (LInt l, ABin *a) {
    ABin p;
    while(l)
    {
        p=malloc(sizeof(struct nodo));
        p->valor=l->valor;
        p->esq=NULL;
        p->dir=NULL;
        insertOrd(p,a);
        l=l->prox;
    }

}







//51. Apresente uma definic˜ao da fun¸c˜ao int deProcura (ABin a) que testa se uma arvore e de
//procura. (https://codeboard.io/projects/16290)


int isProcura(ABin a,int min,int max)
{   int i=1;
    if(a)
    {
        i=isProcura(a->esq,min,a->valor) && isProcura(a->dir,a->valor,max) && (a->valor>=min && a->valor<=max);

    }
    return i;
}

int deProcura (ABin a)
{   int i=1;
    ABin min=a,max=a;
    if(a)
    {
        while(min->esq)
            min=min->esq;
        while(max->dir)
            max=max->dir;
        i=isProcura(a,min->valor,max->valor);
    }
    return i;

}











int removeAll (LInt *l, int x){
    int r=0;
    LInt p;
    while(*l)
    {
        if((*l)->valor==x){
            p=(*l)->prox;
            free(*l);
            *l=p;
            ++r;
        } else
            l=&((*l)->prox);
    }
    return r;
}


