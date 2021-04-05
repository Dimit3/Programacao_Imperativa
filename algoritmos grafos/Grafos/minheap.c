#include <stdio.h>
#include <stdlib.h>


#define PARENT(i) (i-1)/2  // os indices do array começam em 0 
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2

typedef int Elem;  // elementos da heap.

typedef struct {
 int   size;
 int   used;
 Elem  *values;
} Heap;

//_____________________________________________________________________
void swap (Elem h[], int a, int b) {
    int t = h[a];
    h[a] = h[b];
    h[b] = t;
}

void initHeap (Heap *h, int size) {
    h->values = calloc(size , sizeof(Elem));
    h->size = size;
    h->used = 0;
}
//____________________________________________________________________
void bubbleUp_sol (Elem *a, int i) {
    
    while (i && a[i] < a[PARENT(i)]) {
        swap(a, i, PARENT(i));
        i = PARENT(i);
    }       
}

int  insertHeap (Heap *h, Elem x) {
    if (h->used == h->size) {
        h->values = realloc(h->values, 2*(h->size)*sizeof(Elem)); 
        h->size *= 2;
    }
    h->values[h->used] = x;
    (h->used)++;
    bubbleUp_sol(h->values, h->used-1);
    return 1;
}

//____________________________________________________________________
void bubbleDown_sol(Elem a[], int N) {
    int i = 0, min ;
    
    while (LEFT(i) < N) {
        min = LEFT(i);
        if (RIGHT(i) < N && a[RIGHT(i)] < a[LEFT(i)])
            min = RIGHT(i);
        if (a[min] < a[i]) {
            swap(a, i, min);
            i = min;
        }
        else break;
    }
    
}

int  extractMin (Heap *h, Elem *x) {
    if (h->used > 0) {
        *x = h->values[0];   
        h->values[0] = h->values[h->used-1]; 
        (h->used)--;
        bubbleDown_sol(h->values, h->used);
        return 1;
    }
    else return 0;
}

//___________________________________________________________________
int minHeapOK (Heap *h){
  int i = 0 , r = 1;
  
  while (i < h->used && r){
    
    if (LEFT(i) < h->used && r)  r = h->values[i] <= h->values[LEFT(i)];
    
    if (RIGHT(i) < h->used && r)  r = h->values[i] <= h->values[RIGHT(i)];
    
    i++; }
    
    return r;}
  
  
  
  
  
int main()
{

    Heap h;
    int i, x,z;

    initHeap(&h, 1);
    
    insertHeap(&h, 30);
    insertHeap(&h, 60);
    insertHeap(&h, 40);
    insertHeap(&h, 10);
    insertHeap(&h, 100);
    insertHeap(&h, 20);
    insertHeap(&h, 90);
    insertHeap(&h, 50);
    insertHeap(&h, 80);
    insertHeap(&h, 70);
    
    z = minHeapOK (&h);
    
  
    printf("Heap construída (capacidade %d):\n", h.size);
    for (i = 0; i < h.used; i++)
        printf("%d\n", h.values[i]);

    printf("Extracção de elementos:\n");
    while (extractMin(&h, &x)) 
        printf("%d\n", x);
    
}