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

//nao funciona na codeboard pelos testes que fiz aqui funciona com a mesma arvore que na codeboard da erro
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


//nao funciona na codeboard pelos testes que fiz aqui funciona com a mesma arvore que na codeboard da erro

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

int freeAB (ABin a) {
    int c=0;
    if(a)
    {
        c+=freeAB(a->esq);
        c+=freeAB(a->dir);
        free(a);
        c++;
    }
    return c;
}

 int pruneAB (ABin *a, int l) {

     int c=0;
     if(*a)
     {
         
          c+=pruneAB(&((*a)->esq),l-1);
          c+=pruneAB(&((*a)->dir),l-1);
          if(l<=0)
         {
            free(*a);
            *a=0;
            ++c;
         }
     }
     return c;
 }

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

/*rever ou assim porque tem que haver uma maneira melhor digo eu...*/
LInt nivelL (ABin a, int n) {
    LInt l1=NULL,l2=NULL,start;
    if(a)
    {
        if(n==1)
        {
           l2=malloc(sizeof(struct lligada));
           l2->valor=a->valor;
           l2->prox=NULL;
        }
        else
        {   
            l1=nivelL(a->dir,n-1);
            l2=nivelL(a->esq,n-1);
            if(l2)
            {   start=l2;
                for(;start && start->prox;start=start->prox);
                start->prox=l1;
            }
            else if(l1)
                l2=l1;
        }
    }
    return l2;
}

int nivelV (ABin a, int n, int v[]) {
  int li=0;
  if(a)
  {   
      if(n>1)
      {
      li+=nivelV(a->esq,n-1,v);
      li+=nivelV(a->dir,n-1,v+li);
      }
      if(n==1)
      {
          v[li]=a->valor;/*tem o valor li so para se entender melhor acho eu mas podia tar la 0 no indice*/
          ++li;
      }
  }
  return li;
}

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
/*funciona aqui mas na codeboard nao...*/
int somasAcA2 (ABin a){
    int res = 0;
	if(a!=NULL) {
	    res = a->valor;
	    res += somasAcA2(a->esq) + somasAcA2(a->dir);
	    a->valor = res;
	}
    return res;
}

ABin somasAcA (ABin a) {
    if(a)
    {
    a->valor=somasAcA2(a);    
    }
    
    return a;
}

int contaFolhas (ABin a) {
	int i=0;
 	if(a)
 	{
     	if(a->esq==0 && a->dir==0)
        	 ++i;
     	else
     	{
             i+=contaFolhas(a->esq);
             i+=contaFolhas(a->dir);
     	}
 	}	
 	return i;
}

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




int addOrd (ABin *a, int x) {
    int i=0;
    while(*a && !i)
    {
        if((*a)->valor>x)
            a=&((*a)->esq);
        else if((*a)->valor<x)
             a=&((*a)->dir);
        else i=1;
    }
    if(!i)
    {
        *a=(ABin)malloc(sizeof(struct nodo));
        (*a)->valor=x;
        (*a)->esq=NULL;
        (*a)->dir=NULL;
    }
    return i;
}

int lookupAB (ABin a, int x) {
    int i=0;
    while(a && !i)
    {
        if(a->valor>x)
            a=a->esq;
        else if(a->valor<x)
             a=a->dir;
        else i=1;
    }
    return i;
}

int depthOrd (ABin a, int x) {
     int i=0,j=0;
    while(a && !i)
    {
        if(a->valor>x)
            a=a->esq;
        else if(a->valor<x)
             a=a->dir;
        else i=1;
        ++j;
    }
    if(!i) j=-1;
    return j;
}

int maiorAB (ABin a) {
   while(a->dir)
        a=a->dir;
    return a->valor;
}

void removeMaiorA (ABin *a)
{
    ABin l;
    /* so se por acaso alguem utilza-se com uma arvore vazia;*/
    if(a)
    {
    while((*a)->dir)
        a=&((*a)->dir);
        l=(*a)->esq;
        free(*a);
        *a=l;
    }
}

int quantosMaiores (ABin a, int x) {
    int i=0;
   if(a)
   { 
    if(a->valor>=x)
    {
        if(a->valor>x) ++i;
        i+=quantosMaiores(a->esq,x);
        i+=quantosMaiores(a->dir,x);
    }
    else
    {
        i+=quantosMaiores(a->dir,x);
    }
   }
    return i;
}

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

void insertOrd (ABin p,ABin * a)
{
    while(*a)
    {
        if((*a)->valor>p->valor)
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


void printAb(ABin p)
{
	if (p)
	{
		printf("%d  ",p->valor);
		printAb(p->esq);
		printAb(p->dir);
	}
}

ABin create()
{
    ABin p;
    int x,less;
    printf("Enter data(-1 for no data):");
    less=scanf("%d",&x);
    ++less;
    if(x==-1)
        return NULL;
    
    p=(ABin)malloc(sizeof(struct nodo));
    p->valor=x;
    
    printf("Enter left child of %d:\n",x);
    p->esq=create();
 
    printf("Enter right child of %d:\n",x);
    p->dir=create();
    
    return p;
}

void printLL(LInt l)
{
	while(l)
	{
		printf("%d==>",l->valor);
		l=l->prox;
	}
	printf("NULL\n");
}

int main()
{
	ABin p;
	LInt list=NULL, * l=&list;
	p=create();
	printAb(p);
	printf("\n\nLista: \n");
	posorder(p,l);
	printLL(*l);
	return 0;
}
