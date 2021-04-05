#include <stdio.h>
#include <stdlib.h>

#define WHITE 0       //nada feito
#define GRAY 1        //na queue
#define BLACK 2       // ja saiu da queue (ja meti filhos na queue)

#define MAX 100       //numero maximo de vertices = 100

int color[MAX];       // vetor global das cores
int parent[MAX];
struct edge {
  int dest;
  struct edge *next;
};

typedef struct edge *GraphL[MAX];

typedef int GraphM[MAX][MAX];



// graphMtol recebe uma matriz de um grafo GraphM gm, o numero de 
// vertices dessa matriz, matriz é quadrada (VxV) e recebe um
// GraphL g que é uma lista de adjacencia que vai ser criada

void graphMtol(GraphL g, GraphM gm, int n )
{
  int i,j;                         // para ciclos for
  struct edge * new,*head;         //apontadores para arestas

  for (i = 0; i < n; i++)          // percorrer linha a linha
  {
    head = NULL;
    for (j = n-1; j >= 0; j--)     // coluna a coluna nessa linha de tras para a frente para ficar por ordem
      {
       if (gm[i][j] == 1)
       {
         new  = malloc (sizeof (struct edge));
         new -> dest = j;
         new -> next = head;
         head = new;
         printf("added %d -> %d \n",i,j);
       }
      }
      g[i] = head;
  }
}





void df_visita (GraphL g, int s)   // recebe um grafo, e o numero do vertice s que quero visitar
                             // vertice é do tipo int 
{
    struct edge * p;                          // apontador nesta estrutura
    int q[MAX], first = 0, last = 0, u , v;   //queue em array, first e last queue , u é o que tiramos no dequeue 
                                              // v é o vertice a analizar no for 

    color [s] = GRAY;               //entrou na queue fica cinza 
    printf ("%d GRAY \n", s);
    parent[s] = -1;
    q[last ++] = s;                //q[last] = s ; last++;

  while (first < last)   // enquanto queue nao acabou
  {
    u = q[first++];  // tirar o primeiro da queue e incrementar o primeiro(proximo a sair)
    for (p = g[u]; p ; p = p -> next)
    {
      v = p->dest;
        if (color[v] == WHITE)
        { 
          color[v] = GRAY;
          printf("%d GRAY \n",v);
          parent[v] = u;
          q[last++] = v;
        }
    }
    color[u] = BLACK;
    printf("%d BLACK \n", u);
  }
}

void dfs(GraphL g, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (color[i] == WHITE)
      df_visita(g,i);
  }

}

void printgraph (GraphL g, int n)
{
  int i;
  struct edge *p = NULL;
  for (i = 0; i < n; i++)
  {
    p = g[i];
    printf("Destinos de %d: ",i);
    for (p ; p != NULL; p = p-> next)
      {
        printf("%d ",p->dest);
      }
      printf("\n");
  }
}


void dists (GraphL g, int s, int d[])
{
  struct edge * p;                          
  int q[MAX], first = 0, last = 0, u , v;   
  color [s] = GRAY;              
  parent[s] = -1;
  d[s] = 0;
  q[last ++] = s;               
    while (first < last)        
      {
        u = q[first++];       
        for (p = g[u]; p ; p = p -> next)
        {
          v = p->dest;
          if (color[v] == WHITE)
        { 
          color[v] = GRAY;
          parent[v] = u;
          d[v] = d[u]+1;
          q[last++] = v;
        }
      }
    color[u] = BLACK;

    }
   
}


void main ()
{
  int i;
  GraphM gm3 = {
      {0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 1, 0, 1, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 1, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 0, 1, 0, 0},
      }; 
      
  GraphL gl3;

  for (i = 0; i < MAX ; i++)
  {
  *(gl3+i)=NULL;
  }
  int n3 = 9;
  int d[MAX];
  
  // for (i=0; i<n3; i++)
  // parent[n3] = -1;
  for (i=0; i<MAX; i++)
  color[i] = 0; 

  printf("\ncriacao grafo: \n\n");
  graphMtol(gl3, gm3, n3); 
  
  printf("\n\nrepresentacao do grafo: \n\n");
  printgraph(gl3, n3);

  printf("\nBreadth-first transversal:\n");
  dfs(gl3,n3);


  printf("\nvetor parents: \n");
  for (i=0; i<n3; i++)
  printf("%d ",parent[i]);
  
  for (i=0; i<n3; i++)
  d[i] = -1; 
  
  printf("\n");
  
  for (i=0; i<MAX; i++)
  color[i] = 0; 

  printf("\nDistances from node 3:\n");
  dists (gl3, 3, d);
  for (i=0; i<n3; i++) 
      printf("to %d: %d\n", i, d[i]);

  for(int u = 0; u < 9; u++)
    if (d[u] == -1)
      printf ("\n %d nao e acessivel atravez do vertice 3", u);    
  
  }