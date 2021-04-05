#include <stdio.h>
#include <string.h>


/*
21
Defina uma func˜ao int contaVogais (char s[]) que retorna o numero de vogais da
 string s. N˜ao se esqueca de considerar tanto maiusculas como minusculas.
*/


int isvogal (char n)                // funcao auxiliar vai dar 1 se for vogal e 0 se nao for
{
    if ((n == 'a') || (n == 'e') ||(n == 'i') ||(n == 'o') ||(n == 'u') ||(n == 'A') ||
        (n == 'E') || (n == 'I') ||(n == 'O') ||(n == 'U'))  { return 1;}
    else return 0;
}

int contaVogais (char s[])                      // cada vez que for vogal vai adicionar 1 ao res
{
    int i,res = 0;
    for (i = 0; s[i]; ++i)
    {
        if (isvogal(s[i])) {res++;}
    }
    return res;
}



/*
22
Defina uma func˜ao int contida (char a[], char b[]) que testa se todos os caracteres da
primeira string tambem aparecem na segunda. Por exemplo, contida "braga" "bracara
augusta" deve retornar verdadeiro enquanto que contida "braga" "bracarense"
 deve retornar falso.
*/

int elem (char c, char s[])                                // ve se um carater aparece na string
{
    int i;
    int r = 0;
    for (i = 0; s[i] && r != 1; ++i)
        if (s[i] == c) (r =1);
    return r;
}


int contida (char a[], char b[])                          // vai ver carater a carater se aparecem na string
{                                                         // se nao aparecerem r = 0 e contida vai parar e dar r = 0
    int i;
    int r = 1;
    for (i = 0; a[i] && r != 0; i++)
    {
        if  (!(elem (a[i],b))) (r = 0);
    }
    return r;
}



/*

23. Defina uma func˜ao int palindorome (char s[]) que testa se uma palavra e
 palındrome, i.e., le-se de igual forma nos dois sentidos.
*/


int palindorome (char s[])                              // ideia é ver as posiçoes simetricas das letras da palavra
{                                                       // passando o I de frente para tras e o k de tras para a frente
    int i;
    int k = strlen(s) -1;
    int res = 1;
    for (i = 0; s[i] && res != 0; i++ , k--)
    {
        if (s[i] != s[k]) (res = 0);
    }
    return res;
}





/*
24
Defina uma func˜ao int remRep (char x[]) que elimina de uma string todos os caracteres
que se repetem sucessivamente deixando la apenas uma copia. A func˜ao devera retornar o
comprimento da string resultante. Assim, por exemplo, ao invocarmos a func˜ao com uma
vector contendo "aaabaaabbbaaa", o vector deve passar a conter a string "ababa" e a func˜ao
devera retornar o valor 5.
*/




int remRep (char s[])
{
    int r , i;
    r = i = 0 ;
    while (s[i]){
        if (s[i] == s[i+1]) i++;
        else {  s[r] = s[i]; r++ ; i++ ; }
    }
    s[r] ='\0';
    return r;


}




/*
25. Defina uma fun¸c˜ao int limpaEspacos (char t[]) que elimina repetic˜oes
 sucessivas de espacos por um unico espaco. A fun¸c˜ao deve retornar o
comprimento da string resultante.
*/


int limpaEspacos (char s[])
{
    int i = 0;
    int n = 0;
    while (s[i])
    {
        if (s[i] == ' ' && s[i+1] == ' ') {i++;}
        else {s[n] = s[i];n++; i++; }
    }
    s[n] = '\0';
    return n;
}





/*
26. Defina uma func˜ao void insere (int v[], int N, int x) que insere um elemento (x) num
vector ordenado. Assuma que as N primeiras posic˜oes do vector est˜ao ordenadas e que por
isso, apos a inserc˜ao o vector ter a as primeiras N+1 posic˜oes ordenadas.
*/


void insere (int v[], int N, int x) // vetor[50] = {1,2,3,4,6,7,8,9};
{
  int i;
  int j;
  for (j = N, i = N-1; v[i] >= x && j != 0; j-- , i--) v[j] = v[i];
  v[j] = x;
  for (int k = 0;v[k] != '\0'; k++) printf("%d ",v[k]);
}






/*
 * 27
Defina uma func˜ao void merge (int r [], int a[], int b[], int na, int nb) que,
 dados vectores ordenados a (com na elementos) e b (com nb elementos),
 preenche o vector r (com na+nb elementos) com os elementos de a e b ordenados.
*/

/*
28
Defina uma fun¸c˜ao int crescente (int a[], int i, int j) que testa se os elementos do
vector a, entre as posi¸c˜oes i e j (inclusiv´e) est˜ao ordenados por ordem crescente.
A func˜aodeve retornar 1 ou 0 consoante o vector esteja ou n˜ao ordenado.
*/




/*
 * 29.
Defina uma func˜ao int retiraNeg (int v[], int N) que retira os numeros
negativos de um vector com N inteiros. A func˜ao deve retornar o numero
de elementos que n˜ao foram retirados.
 */



/*
30.
 Defina uma func˜ao int menosFreq (int v[], int N) que recebe um vector v com N
elementos ordenado por ordem crescente e retorna o menos frequente dos elementos do
vector. Se houver mais do que um elemento nessas condic˜oes deve retornar o
que comeca por aparecer no ındice mais baixo.


*/




int main ()

{
    char exemplo1[50] = {"Daniel"};
    char exemplo2[100] = {"braga"};
    char exemplo3[100] = {"bracara augusta"};
    char exemplo4[100] = {"ana"};
    char exemplo5[100] = {"aaabaaabbbaaa"};
    char exemplo6[100] = {"  a  a   a                 a   "};
    int  vetor[50] = {1,2,3,4,6,7,8,9};
    // printf("%d\n",contaVogais(exemplo1));
    // printf("%d\n",limpaEspacos (exemplo6));
    insere (vetor,8,5);
    return 0;
}