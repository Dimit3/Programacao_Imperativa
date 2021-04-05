#include <stdio.h>
#include <stdlib.h>
#define HSIZE 10

typedef struct bucket {
int key ;
int info;
struct bucket *next;
}*Bucket;

typedef Bucket HashTableChain  [HSIZE];

int hash (int k , int s){ return k%5;}




void initTab ( HashTableChain h ) {
int i;

for ( i=0; i<HSIZE ; h [i++]=NULL);}




int lookup (HashTableChain h, int k , int *i){
int p = hash ( k , HSIZE ) ;int found = 0 ;Bucket x;

for (x = h[p]; x!= NULL && !found; x = x->next){
  if (x->key == k ) {found = 1;*i = x->info;}
  }
return found;
}






int update ( HashTableChain h , int k , int i ){
int p = hash ( k , HSIZE ) ;int r ;Bucket x ;

for ( x = h[p]; x!= NULL && k!= x->key;x = x->next);

if ( x != NULL ) {
  x->info = i;
  r = 0;}
  
else {
x = malloc ( sizeof ( struct bucket ) ) ;
x->info = i;
x -> key = k;
x -> next = h[p];
h[p] = x;
r = 1;
}
return r ;
}

int removeKey ( HashTableChain h , int k) {
    int r = 0 , p = hash ( k , HSIZE); Bucket * x , tmp ;
    
for (x = &h[p] ;*x != NULL && (*x)->key != k ; x = &((*x)-> next));

if ( *x !=NULL ) {
   tmp = *x;
   *x = (*x)->next;
   free(tmp);
   r = 1;}
   
   return r; }


//__________________________________________________________________________________________


   typedef struct thash {
   	int size;
   	Bucket * tabela;
   } * THash;


THash createTable ( int N) {
     THash h;int i;
     h = malloc ( sizeof ( struct thash));
     h->size = N;
     h->tabela = malloc (N/2 * sizeof (struct bucket));
     for (i=0; i<N; i++) {h->tabela[i] = NULL;}

return h;}

int duplicateTable ( THash h ) {
  int r = 0, i;
  r = h->tabela = realloc ( h -> tabela ,  h->size * sizeof (struct bucket));
  for (i = h->size ; i < 2*h->size; i++ ) h->tabela[i] = NULL;
  h->size*= 2;
  return r;
  }










  
int main(){
  HashTableChain h;int x;int z;THash h2;
  
  initTab ( h );
  x = update (h , 5 , 0);
  x = update (h , 3 , 1);
  x = update (h , 10 , 4);
  x = update (h , 15 , 5);
  x = update (h , 20 , 6);
  x = update (h , 15 , 7);
  x = lookup (h , 20 , &z);
  x = lookup (h , 4 , &z);
  x = removeKey (h , 15);




  h2 = createTable ( 6);
  h2->tabela[0] = malloc (sizeof ( struct bucket));
  h2->tabela[0]->key = 2;
  h2->tabela[0]->info = 3;
  h2->tabela[0]->next = 0;
  x = duplicateTable ( h2 );
  
}