#include <stdlib.h>
#include <stdio.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

int length (LInt l){
	int i=0;
	while (l){
		++i;
		l=l->prox;
	}
	return i;
}

void freeL (LInt l){
	LInt * l1;
	while(l)
	{	
		l1=&(l->prox);
		free(l);
		l=*l1;
	}
}

void imprimeL (LInt x){
	while(x){
	
	printf("%d\n",x->valor);
	x=x->prox;
	}

}

LInt reverseL (LInt l){
	LInt l2,l1=NULL;
	while(l){
		l2=l->prox;
		l->prox=l1;
		l1=l;
		l=l2;
	}
	return l1;
}

void insertOrd (LInt *l, int x){
   LInt new;
   while(*l && (*l)->valor<x)
       l=&((*l)->prox);
   new = (LInt) malloc (sizeof (struct lligada));
   new->valor = x;
   new->prox  = *l;
   *l=new;
}

int removeOneOrd (LInt *l, int x){
    LInt p;
    int t=1;
    while(*l && (*l)->valor!=x)
       l=&((*l)->prox);
       if(*l){
           p=(*l)->prox;
           free(*l);
           *l=p;
           t=0;
       }
       return t;
}
//criando uma nova lista
void merge (LInt *r, LInt l1, LInt l2){
   LInt new;
   while(l1 || l2){
       if((!l1)||(l2 && l1->valor>l2->valor))
       {
          new=(LInt)malloc(sizeof(struct lligada));
          new->valor=l2->valor;
          new->prox=NULL;
          *r=new;
          r=&(new->prox);
          l2=l2->prox;
          
       }else{
          new=(LInt)malloc(sizeof(struct lligada));
          new->valor=l1->valor;
          new->prox=NULL;
          *r=new;
          r=&(new->prox);
          l1=l1->prox;
       }
   }
}
//sem criar uma nova lista esta acho que e a que querem na codeboard
void merge1 (LInt *r, LInt l1, LInt l2){
   while(l1 || l2){
       if((!l1)||(l2 && l1->valor>l2->valor))
       {
          *r=l2;
          r=&(l2->prox);
          l2=l2->prox;
          
       }else{
          *r=l1;
          r=&(l1->prox);
          l1=l1->prox;
       }
   }
}


void splitMS (LInt l, int x, LInt *mx, LInt *Mx){
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
    *mx=0;
    *Mx=0;
}
//Deve haver uma maneira melhor de fazer
LInt parteAmeio (LInt *l){
    int i=length(*l)/2,j;
    LInt * p=l,u=*l;
    for(j=0;j<i;++j)
        p=&((*p)->prox);
    *l=*p;
    *p=NULL;
    if (i==0) {
    	*l=u;
    	return NULL;
    }
    else return u;
 }

int removeAll (LInt *l, int x){
   int i=0;
   LInt p;
    while(*l){
        if((*l)->valor==x){
            p=(*l)->prox;
            free(*l);
            *l=p;
            ++i;
        } else
        l=&((*l)->prox);
    }
    return i;
}

int removeDups (LInt *l){
    int i=0;
    while(*l){
        i=+removeAll(&((*l)->prox),(*l)->valor);
        l=&((*l)->prox);
    }
    return i;
}

void init (LInt * l){
	while(*l && (*l)->prox)
		l = &((*l)->prox);
	if (*l) 
	{
		free(*l);
		*l = NULL;
	}

}

void concat (LInt * a, LInt b){
	while(*a)
		a=&((*a)->prox);
	*a=b;
}

int removeMaiorL (LInt *l){
   int maior;
   LInt * p,t;
   for (p = l;*p; p=&((*p)->prox))
       if((*l)->valor<(*p)->valor)
           l=p;
   maior=(*l)->valor;
   t=(*l)->prox;
   free(*l);
   *l=t;
   return maior;
}

void appendL (LInt *l, int x){
    while(*l)
        l=&((*l)->prox);
    *l=(LInt)malloc(sizeof(struct lligada));
    (*l)->valor=x;
    (*l)->prox=0;
}

LInt cloneL (LInt l)
{
	LInt r,* e=&r;
	while(l)
	{
		*e=malloc(sizeof(struct lligada));
		(*e)->valor=l->valor;
		l=l->prox;
		e=&((*e)->prox);
	}
	*e=NULL;
	return r;
}

LInt cloneRev (LInt l){
    LInt r=0,v=0;
    while(l){
        r=(LInt) malloc (sizeof (struct lligada));
        r->valor=l->valor;
        r->prox=v;
        v=r;
        l=l->prox;
    }
    return r;
}

int maximo (LInt l){
    int max;
    for(max=l->valor;l;l=l->prox)
    if(max<l->valor) max=l->valor;
    return max;
}

int take (int n, LInt *l){
    LInt p;
    int i;
    for(i=0;*l && n>i;++i)
    l=&((*l)->prox);
    while(*l)
    {
        p=(*l)->prox;
        free(*l);
        *l=p;
    }
    return i;
}

int drop (int n, LInt *l){
    LInt p;
    int i;
    for(i=0;*l && n>i;++i)
    {
        p=(*l)->prox;
        free(*l);
        *l=p;
    }
    return i;
}

LInt NForward (LInt l, int N){
    for(;l && N>0;--N)
        l=l->prox;
    return l;
}

int listToArray (LInt l, int v[], int N){
    int i;
    for(i=0;l && i<N;++i,l=l->prox)
        v[i]=l->valor;
    return i;
}

LInt arrayToList1 (int v[], int N){
	int i=0;
	LInt r,* e=&r;
	while(i<N)
	{
		*e=malloc(sizeof(struct lligada));
		(*e)->valor=v[i];
		++i;
		e=&((*e)->prox);
	}
	*e=NULL;
	return r;
}

LInt arrayToList2 (int u[], int N){
    LInt r=0,v=0;
    while(N>0){
        r=(LInt) malloc (sizeof (struct lligada));
        r->valor=u[N-1];
        r->prox=v;
        v=r;
        N--;
    }
    return r;
}

LInt somasAcL (LInt l) 	{
    int i=0;
    LInt r,* e=&r;
	while(l)
	{
		*e=malloc(sizeof(struct lligada));
		i+=l->valor;
		(*e)->valor=i;
		l=l->prox;
		e=&((*e)->prox);
	}
	*e=NULL;
	return r;
}

void remreps (LInt l){
    LInt p,j;
    while(l)
    {   p=l->prox;
        while(p && l->valor==p->valor)
        {
            j=p->prox;
            free(p);
            p=j;
        }
        l->prox=p;
        l=l->prox;
    }
}

LInt rotateL (LInt l){
    LInt * p=&l,m=0;
    while(*p)
        p=&((*p)->prox);
    *p=l;
    if(l)
    {
    m=l->prox;
    l->prox=0;
    }
    return m;
}

//falta a parte (Tenho no caderno)

void main()

{

    LInt head, first, temp = 0;
    int count = 0;
    int choice = 1;
    first = 0;

    while (choice)
    {

        head  = (LInt)malloc(sizeof(struct lligada));
        printf("Enter the data item\n");
        scanf("%d", &head-> valor);
        if (first != 0)

        {

            temp->prox = head;

            temp = head;

        }

        else

        {
            first = temp = head;

        }
        fflush(stdin);
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &choice);

    }
    temp->prox = 0;
    /*  reset temp to the beginning */
    temp = first ;//"first" to make one or more length list, "0" if want empty list
    printf("\n status of the linked list is\n");
 
    temp=cloneLL(temp);
    while (temp != 0)
	{

        printf("%d=>", temp->valor);

        count++;

        temp = temp -> prox;

    }
    printf("NULL\n");
    printf("No. of nodes in the list = %d\n", count);
}
