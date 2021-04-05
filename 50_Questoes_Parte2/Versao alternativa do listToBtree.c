
/* Versao alternativa do listToBtree que esta no ficheiro:
(Faz uma arvore balanceada ou contrario da que esta no ficheiro)
*/

void recursiveLTB(LInt * l,ABin *a,int n)
{ ABin p;
if(n>0)
{
recursiveLTB(l,a,n/2);

p=malloc(sizeof(struct nodo));
p->valor=(*l)->valor;
p->esq=*a;
*a=p;

*l=(*l)->prox;

recursiveLTB(l,&((*a)->dir),n-n/2-1);
}
else
*a=NULL;
}

int length (LInt l)
{ int i=0;
while(l)
{
l=l->prox;
++i;
}
return i;
}

void listToBTree (LInt l, ABin *a) {
int n;
LInt head=l;
n=length(l);

recursiveLTB(&head,a,n);
}
