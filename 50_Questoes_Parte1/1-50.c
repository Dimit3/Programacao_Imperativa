#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
1. Defina um programa que le (usando a funcao scanf uma sequencia de numeros inteiros
terminada com o n´umero 0 e imprime no ecran o maior elemento da sequencia.
*/




void maximo1 () {
    int max = 0;
    int x;
    while (x != 0) {
        scanf("%d", &x );
        if (x > max) max = x;
    }

    printf (" \n MAX: %d", max );
}



/*
2. Defina um programa que le (usando a func˜ao scanf uma sequencia
de numeros inteiros terminada com o n´umero 0 e imprime no ecran a media da sequencia.
*/


void mean2() {
    int array[1024];
    int i = 0;
    do {
        scanf("%d" , &array[i]);
        i++;
    } while (array[i - 1] != 0);
    float soma = 0;
    for (int j = 0; j < i; j++) {
        soma = soma + array[j];
          }
    printf("%f ", soma / (i-1) );
}




/*
3. Defina um programa que le (usando a func˜ao scanf uma sequenciade numeros
inteiros terminada com o numero 0 e imprime no ecran o segundo maior elemento.
*/





int maximo2 () {
    int m, sm, num;
    scanf("%d", &m);
    scanf("%d", &num);
    if(num > m) {
        sm = m;
        m = num;
    } else sm = num;
    while(1) {
        scanf("%d", &num);
        if(num == 0) break;
        if(num > m) {
            sm = m;
            m = num;
        } else if (num > sm) sm = num;
    }
    printf("Segundo maior numero: %d\n",sm);
}






/*
4. Defina uma func˜ao int bitsUm (unsigned int n) que calcula o numero de bits iguais a 1
usados na representac˜ao binaria de um dado numero n.
*/


int bitsum4 (unsigned int n)
{
    int cont = 0;
    int rest;
    while (n != 0)
   {
        rest = n % 2;
        n = n / 2;
        cont = cont + rest;
   }
    return  cont;
}





/*5
Defina uma func˜ao int trailingZ (unsigned int n) que calcula o numero de bits a 0 no
final da representac˜ao binaria de um numero(i.e., o expoente da maior potencia de 2 que e
divisor desse numero).
*/


int trailingz5 (int n)
{
int zeros = 0;

while  ( n > 0) {
            if (n%2 == 0) zeros ++;
            else break;
            n = n/2;
}
    return zeros;
}




/*
6  Defina uma func˜ao int qDig (unsigned int n) que calcula o numero de dıgitos necessarios
para escrever o inteiro n em base decimal. Por exemplo, qDig (440) deve retornar 3.
*/


int qDig6 (unsigned int n)
{
    int digitos = 0;
    while (n > 0)
    {
        n = n / 10;
        digitos ++;
    }

    return digitos;
}


// tamanho de uma string ajuda nas proximas funçoes

int mystrlen (char str[])             // ola = 3
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}



// 7    Apresente uma definic˜ao da func˜ao pre-definida em C char *strcat (char s1[], char
//s2[]) que concatena a string s2 a s1 (retornando o endere¸co da primeira).

char* mystrcat (char s1[], char s2[])
{
    int i = 0;
    for (i = 0; s1[i] != '\0' ; i++);             // tamanho s1 = i

    for ( int j = 0 ; s2[j] != '\0' ;j++,i++ )
    {
        s1[i] = s2[j];
    }
    s1[i]='\0';
    return s1;
}







// 8 Apresente uma definic˜ao da func˜ao pre-definida em C char *strcpy (char *dest, char
//source[]) que copia a string source para dest retornando o valor desta ´ultima




char *mystrcpy (char *dest, char source[])
{
    int i;
    for (i = 0; source[i] != '\0' ; i++)
    {
        *(dest+i) = source[i];
    }
    *(dest+i) = '\0';
    return dest;

}


/*  9
Apresente uma definic˜ao da func˜ao pre-definida em C int strcmp (char s1[], char s2[])
que compara (lexicograficamente) duas strings. O resultado devera ser
• 0 se as strings forem iguais
• <0 se s1 < s2
• >0 se s1 > s2
*/



int mystrcmp (char s1[], char s2[])
{
    for ( int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++ )
    {
        if (s1[i] > s2[i] ) return 1;
        if (s1[i] < s2[i] ) return -1;
    }
    return 0;
}



// 10    apresenta a parte que se repete em s2 da s1

 char * mystrstr (char s1[], char s2[])
 {
    int i,j;
    j = 0;
    for (i = 0; s1[i] != '\0' && s2[j] != '\0' ; ++i)
    {
        if (s1[i] == s2[j]) j++;
        else j = 0;
    }
    if (s2[j] == '\0') return &s1[(i-j)];
    else return NULL;
 }



// 11 Defina uma func˜ao void strrev (char s[]) que inverte uma string


void mystrrev (char s[]){
    char acomulador;
    int n = strlen(s) -1;          // porque o indice é lenght - 1
    int i;
    for (i = 0; i < n; i++, n--){
        acomulador = s[i];
        s[i] = s[n];
        s[n]=acomulador;
    }
}




//12 Defina uma func˜ao void strnoV (char s[]) que retira todas as vogais de uma string.

int isvowel (char c){      // se for vogal return 1(T) se nao return 0 (F)

    if ((c == 'a') || (c== 'e') || (c == 'i') || (c== 'o') || (c == 'u') ||
        (c== 'A') || (c== 'E') || (c == 'I') || (c == 'O') || (c == 'U')){
        return 1;
    } else
        return 0;
}


void strnoV (char s[]){
    int i = 0, j = 0;
    while (s[j] != '\0') {                  // percorrer a string
        while (isvowel(s[j])) j++;           //continuar se for vogal
        s[i] = s[j];                         //se nao for vogal s[i] vai tomar o valor da nao vogal
        i++;
        j++;

    }
    s[i] = '\0';

}




/*   13
Defina uma func˜ao void truncW (char t[], int n) que dado um texto t com v´rias palavras
(as palavras est˜ao separadas em t por um ou mais espa¸cos) e um inteiro n, trunca todas as
palavras de forma a terem no maximo n caracteres. Por exemplo, se a string txt contiver
"liberdade, igualdade e fraternidade", a invoca¸c˜ao de truncW (txt, 4) deve fazer
com que passe a estar la armazenada a string "libe igua e frat".
*/


void truncW (char t[], int n){
    int i, j = 0,x;
    for (i = 0; t[i] != '\0'; i++, j++)
    {
        for ( x = n; (x > 0) && (t[i] != ' ') && (t[i] != '\0'); x--,i++,j++)
            t[j] = t[i];
        while ((t[i] != '\0') && (t[i] != ' '))
            i++;
        t[j] = t[i];
    }
    t[j] = '\0';
}






/*
14
Defina uma func˜ao char charMaisfreq (char s[]) que determina
qual ocaracter mais frequente numa string. A fun¸c˜ao dever´a
retornar 0 no caso de s ser a string vazia
*/



char charMaisfreq (char s[]){
    int i;
    int aux[256] = {0};
    char res = 0;
    for (i = 0; s[i] != '\0'; i++)
        aux [s[i]] +=1;
    for (i = 0; i < 256; i++)
        if (aux[i] > aux [(int) res])
            res = i;
    return res;
}




/* 15
 *
Defina uma fun¸c˜ao int iguaisConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres iguais. Por exemplo, iguaisConsecutivos
("aabcccaac") deve dar como resultado 3, correspondendo `a repeti¸c˜ao "ccc".

*/


int iguaisConsecutivos (char s[]){
    int i;
    int max = 0, now = 0;

    for ( i= 0; s[i] != '\0'; i++)
    {
        if (i==0) now = 1;
        else {
            if (s[i] == s[i -1])
                now ++;
            else
            {
                if (max < now)
                    max = now;
                now = 1;
            }
        }
    }
    if (max < now)     // tem de fazer denovo caso o caso mais longo seja no final da string
        max = now;
    return max;
}




/* 16
 * Defina uma fun¸c˜ao int difConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres diferentes. Por exemplo, difConsecutivos
        ("aabcccaac") deve dar como resultado 3, correspondendo `a string "abc".
        */


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

/*
17
Defina uma func˜ao int maiorPrefixo (char s1 [], char s2 [])
que calcula o comprimento do maior prefixo comum entre as duas strings.
 */



int maiorPrefixo (char s1 [], char s2 []){
    int i = 0;
    while ((s1[i] != '\0') && (s2[i] != '\0' && (s1[i]) == s2[i]))
        i++;
    return i;
}




/*18
 * Defina uma fun¸c˜ao int maiorSufixo (char s1 [], char s2 [])
que calcula o comprimento do maior sufixo comum entre as duas strings.
 */




int maiorsufixo (char s1 [], char s2 []){
    int i = strlen(s1) - 1;
    int j = strlen(s2) - 1;
    int res = 0;
    while ((i >= 0) && (j >= 0) && (s1[i] == s2[j]))
    {
        i--;
        j--;
        res++;
    }
    return res;
}


/* 19
 * Defina a fun¸c˜ao int sufPref (char s1[], char s2[]) que calcula o tamanho do maior
sufixo de s1 que ´e um prefixo de s2. Por exemplo sufPref("batota","totalidade") deve
dar como resultado 4, uma vez que a string "tota" ´e um sufixo de "batota" e um prefixo de
"totalidade"
 */

int sufPref (char s1[], char s2[]) {
    int i1,i2,count = 0, size1;
    i1 = strlen(s1)-1;
    i2 = strlen(s2)-1;
    size1 = i1;
    for (; i1 >=0 && i2 >=0;i2--)
    {
        if (s1[i1] == s2[i2])
        {
            count++;
            i1 --;
        }
        else
        {
            i1=size1;
            count=0;
        }
    }
    return count;
}


/* 20
Defina uma fun¸c˜ao int contaPal (char s[]) que conta as palavras de uma string. Uma
palavra ´e uma sequˆencia de caracteres (diferentes de espa¸co) terminada por um ou
maisespa¸cos. Assim se a string p tiver o valor "a a bb a", o resultado de contaPal (p)
deve ser  4
*/



int contaPal (char s[])
{
    int i;
    int count = 0;
    if (!isspace(s[0]) && s[0] != '\0') {(count = 1);};
    for ( i = 0; s[i] != '\0'; i++)
    {
        if (isspace(s[i]) && !isspace(s[i+1]) && (s[i+1] != '\0')) {count++;}
    }
    return count;
}




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
 pal?ndrome, i.e., le-se de igual forma nos dois sentidos.
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
}




/*
 * 27
Defina uma func˜ao void merge (int r [], int a[], int b[], int na, int nb) que,
 dados vectores ordenados a (com na elementos) e b (com nb elementos),
 preenche o vector r (com na+nb elementos) com os elementos de a e b ordenados.
*/

void merge (int r [], int a[], int b[], int na, int nb) {
    int i = 0,j;
    while (i < na){
        r[i] = a[i];
        i++;
    }
    for (j = 0; j < nb; j++ ) {
        insere(r,i,b[j]);
        i++;
    }
}



/*
28
Defina uma fun¸c˜ao int crescente (int a[], int i, int j) que testa se os elementos do
vector a, entre as posi¸c˜oes i e j (inclusiv´e) est˜ao ordenados por ordem crescente.
A func˜aodeve retornar 1 ou 0 consoante o vector esteja ou n˜ao ordenado.
*/


int crescente (int a[], int i, int j)
{
    int res = 1;
    for (  ; (i < j && res == 1) ; i++ ) {
        if ( a[i] > a[i+1]) res = 0;
    }
    return res;
}



/*
 * 29.
Defina uma func˜ao int retiraNeg (int v[], int N) que retira os numeros
negativos de um vector com N inteiros. A func˜ao deve retornar o numero
de elementos que n˜ao foram retirados.
 */

int retiraNeg (int v[], int N){
    int i = 0,j = 0;
    while (i < N){
        if (v[i] < 0) (i++);
        else {(v[j] = v[i]); j++;i++;}
    }
    return j;
}




/*
30.
 Defina uma func˜ao int menosFreq (int v[], int N) que recebe um vector v com N
elementos ordenado por ordem crescente e retorna o menos frequente dos elementos do
vector. Se houver mais do que um elemento nessas condic˜oes deve retornar o
que comeca por aparecer no ?ndice mais baixo.


*/

int conta ( int valor , int v1[] , int size){
    int i;
    int r = 0;

    for ( i = 0; i < size ; i++){
        if (v1[i] == valor) r++;
    }
    return r;
}


int menosFreq (int v[], int N) {
    int i , j;
    int res;
    int x = v[0];
    res = (conta(v[0],v,N));
    for (i = 0; i < N; i++) {
        if ((conta(v[i],v,N)) < res) { res = (conta(v[i],v,N)); x = v[i];};
    }
    return x;

}



/* 31
Defina uma fun¸c˜ao int maisFreq (int v[], int N) que recebe um vector v com N elementos
ordenado por ordem crescente e retorna o mais frequente dos elementos do vector.
Se houver mais do que um elemento nessas condi¸c˜oes deve retornar o que comeca por aparecer
no ındice mais baixo.
*/

int conta ( int valor , int v1[] , int size){
    int i;
    int r = 0;

    for ( i = 0; i < size ; i++){
        if (v1[i] == valor) r++;
    }
    return r;
}


int maisFreq (int v[], int N) {
    int i , j;
    int res;
    int x = v[0];
    res = (conta(v[0],v,N));
    for (i = 0; i < N; i++) {
        if ((conta(v[i],v,N)) > res) { res = (conta(v[i],v,N)); x = v[i];};
    }
    return x;

}







/*
 * 32.
Defina uma func˜ao int maxCresc (int v[], int N) que calcula o comprimento da maior
sequencia crescente de elementos consecutivos num vector v com N elementos. Por exemplo,
se o vector contiver 10 elementos pela seguinte ordem: 1, 2, 3, 2, 1, 4, 10, 12, 5, 4, a
func˜ao devera retornar 4, correspondendo ao tamanho da sequencia 1, 4, 10, 12. */


int maxCresc (int v[], int N) {
    int r = 1;
    int max = 0;
    int i;
    for ( i = 0; i < N; i++){
        if (v[i] <= v[i+1]) {r++; if (r > max) max = r; }
        else (r = 1);
    }
    return max;
}





/*
33.
 Defina uma func˜ao int elimRep (int v[], int n) que recebe um vector v com n inteiros e
elimina as repetic˜oes. A func˜ao devera retornar o numero de elementos do vector resultante.
Por exemplo, se o vector v contiver nas suas primeiras 10 posic˜oes os numeros

                            {1, 2, 3, 2, 1, 4, 2, 4, 5, 4}
a invocac˜ao elimRep (v,10) devera retornar 5 e colocar nas primeiras 5 posic˜oes do vector
os elementos {1,2,3,4,5}.
*/



int elimRep (int v[], int n) {
    int i = 0;
    int repetido = 0;
    while (i < n)
    {
        for(int j = 0; j < i; j++)
        {
            if(v[j] == v[i]) repetido= 1;
        }
        if (repetido)
        {
            for(int j = i; j < n; j++)
            {
                v[j] = v[j + 1];
            }
            n--;
            repetido = 0;
        }
        else i++;
    }
    return n;
}





/*34.
Defina uma func˜ao int elimRepOrd (int v[], int n) que recebe um vector v com n inteiros ordenado por ordem crescente e
 elimina as repetic˜oes. A func˜ao devera retornar o numero de elementos do vector resultante.*/



int elimRepOrd (int v[], int n) {return elimRep(v,n);}




/*35.
Defina uma func˜ao int comunsOrd (int a[], int na, int b[], int nb) que calcula quantos elementos os
vectores a (com na elementos) e b (com nb elementos) tem em comum.
Assuma que os vectores a e b est˜ao ordenados por ordem crescente.
 */

int comunsOrd (int a[], int na, int b[], int nb)
{
    int i = 0, j = 0, conta = 0;
    while(i < na && j < nb)
    {
        if(a[i] == b[j])
        {
            conta++;
            i++;
            j++;
        }
        else if(a[i] > b[j]) j++;
        else i++;
    }
    return conta;
}




/*36.
 * Defina uma func˜ao int comuns (int a[], int na, int b[], int nb) que calcula quantos
    elementos os vectores a (com na elementos) e b (com nb elementos) tem em comum. Assuma
    que os vectores a e b n˜ao est˜ao ordenados e defina a func˜ao sem alterar os vectores.
*/


int comuns (int a[], int na, int b[], int nb)
{
    int i , j,conta = 0;
    for (i = 0; i < na; i++)
    {
        for(j = 0; j < nb; j++)
            if(a[i] == b[j]) conta++;
    }

    return conta;
}






/*37.
 * Defina uma func˜ao int minInd (int v[], int n) que, dado um vector v com n inteiros,
retorna o ındice do menor elemento do vector.
 */


int minInd (int v[], int n)
{
    int i;
    int min = v[0];
    int indicemin = 0;
    for ( i = 0; i < n; i++)
    {
        if ( min > v[i]) { min = v[i]; indicemin = i;};
    }
    return indicemin;
}



/*
38. Defina uma func˜ao void somasAc (int v[], int Ac [], int N) que preenche o vector
Ac com as somas acumuladas do vector v. Por exemplo, na posic˜ao Ac[3] deve ser calculado como v[0]+v[1]+v[2]+v[3].
*/


void somasAc (int v[], int Ac [], int N)
{
    for (int i = 0; i < N; i++)
    {
        Ac[i] = 0;
        for ( int j = 0; j <= i; j++)
        {
            Ac[i] = Ac[i] + v[j];
        }
    }
}



void somasAc (int v[], int Ac [], int N)
{
    int ant = 0;
    for (int i = 0; i < N; i++)
    {
        Ac[i] = ant + v[i];
        ant = Ac[i];
    }

}

/*39.
 * Defina uma func˜ao int triSup (int N, float m [N][N]) que testa se uma matriz quadrada e triangular superior,
i.e., que todos os elementos abaixo da diagonal s˜ao zeros.*/


int triSup (int N, float m [N][N]) {
    int x = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(m[i][j] != 0) x = 0;
        }
    }
    return x;
}


/*
40. Defina uma func˜ao void transposta (int N, float m [N][N]) que transforma uma matriz na sua transposta
*/


void transposta (int N, float m[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

/*
41
Defina uma func˜ao void addTo (int N, int M, int a [N][M], int b[N][M])
que adiciona a segunda matriz a primeira.
*/


void addTo (int N, int M, int a [N][M], int b[N][M])
{
    int i,j ;
    for ( i = 0; i < N ; i++)
    {
        for ( j = 0; j < M ; j++)
        {
            a[i][j] += b[i][j];
        }
    }
}




/*
42
Uma forma de representar conjuntos de ındices consiste em usar um array de inteiros contendo
1 ou 0 consoante esse ındice pertenca ou n˜ao ao conjunto.
Assim o conjunto {1, 4, 7} seria representado por um array em que as primeiras 8 posic˜oes conteriam {0,1,0,0,1,0,0,1}.


 Apresente uma definic˜ao da func˜ao int unionSet (int N, int v1[N], int v2[N], int
r[N]) que coloca no array r o resultado da uni˜ao dos conjuntos v1 e v2
*/





int unionSet (int N, int v1[N], int v2[N], int r[N])
{
    int len = 0;
    for(int i = 0; i < N; i++)
    {
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
    return len;
}




/*
43.
Uma forma de representar conjuntos de ındices consiste em usar um array de inteiros contendo
1 ou 0 consoante esse ´ındice perten¸ca ou n˜ao ao conjunto. Assim o conjunto {1, 4, 7} seria
representado por um array em que as primeiras 8 posi¸c˜oes conteriam {0,1,0,0,1,0,0,1}.


 Apresente uma definc˜ao da fun¸c˜ao int intersectSet (int N, int v1[N], int v2[N],int r[N])
que coloca no array r o resultado da intersecc˜ao dos conjuntos v1 e v2.
*/



int intersectSet (int N, int v1[N], int v2[N], int r[N])
{
    int len = 0;
    for(int i = 0; i < N; i++)
    {
        r[i] = v1[i] && v2[i];
        len += r[i];
    }
    return len;
}




/*
44.
 Uma forma de representar multi-conjuntos de ındices consiste em usar um array de inteiros
contendo em cada posi¸c˜ao o numero de ocorrˆencias desse indice. Assim o multi-conjunto
{1, 1, 4, 7, 7, 7} seria representado por um array em que as primeiras 8 posic˜oes conteriam {0,2,0,0,1,0,0,3}.

Apresente uma definic˜ao da fun¸c˜ao int intersectMSet (int N, int v1[N], int v2[N],
int r[N]) que coloca no array r o resultado da intersecc˜ao dos multi-conjuntos v1 e v2.
*/



int intersectMSet (int N, int v1[N], int v2[N],int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
        len += r[i];
    }
    return len;
}

/*
45.
 Uma forma de representar multi-conjuntos de ındices consiste em usar um array de inteiros
contendo em cada posi¸c˜ao o numero de ocorrˆencias desse ındice. Assim o multi-conjunto
{1, 1, 4, 7, 7, 7} seria representado por um array em que as primeiras 8 posi¸c˜oes conteriam {0,2,0,0,1,0,0,3}.

 Apresente uma definic˜ao da func˜ao int unionMSet (int N, int v1[N], int v2[N], int
r[N]) que coloca no array r o resultado da uni˜ao dos multi-conjuntos v1 e v2.
*/


int unionMSet (int N, int v1[N], int v2[N],int r[N]) {
    int len = 0;
    for(int i = 0; i < N; i++) {
        r[i] = v1[i] + v2[i];
        len += r[i];
    }
    return len;
}





/*
46.
 Uma forma de representar multi-conjuntos de ındices consiste em usar um array de inteiros
contendo em cada posi¸c˜ao o numero de ocorrencias desse ındice. Assim o multi-conjunto
{1, 1, 4, 7, 7, 7} seria representado por um array em que as primeiras 8 posic˜oes conteriam {0,2,0,0,1,0,0,3}.
Apresente uma defini¸c˜ao da func˜ao int cardinalMSet (int N, int v[N]) que calcula a
numero de elementos do multi-conjunto v
*/


int cardinalMSet (int N, int v[N]) {
    int i;
    int res = 0;
    for (i = 0; i < N; i++)
    {
        res += v[i];
    }
    return res;
}






/*
47.
Considere as seguintes defini¸c˜oes para representar as posi¸c˜oes e movimentos de um robot.

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

Defina a func˜ao Posicao posFinal (Posicao inicial, Movimento mov[], int N) que,
dada uma posic˜ao inicial e um array com N movimentos, calcula a posic˜ao final do robot depois
de efectuar essa sequencia de movimentos.
*/


typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct
{
    int x, y;
} Posicao;


Posicao posFinal (Posicao inicial, Movimento mov[], int N)
{
    for(int i = 0; i < N; i++) {
        Movimento x;
        x = mov[i];
        if(x == Norte) inicial.y++;
        if(x == Este) inicial.x++;
        if(x == Sul) inicial.y--;
        if(x == Oeste) inicial.x--;
    }
    return inicial;
}






/*
48.
Considere as seguintes defini¸c˜oes para representar as posi¸c˜oes e movimentos de um robot.

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

Defina a func˜ao int caminho (Posicao inicial, Posicao final, Movimento mov[], int
N) que, dadas as posic˜oes inicial e final do robot, preenche o array com os movimentos suficientes para que o robot passe de uma posic˜ao para a outra.
A func˜ao devera preencher no maximo N elementos do array e retornar o numero de elementos
preenchidos. Se n˜ao for possıvel atingir a posi¸c˜ao final com N movimentos, a func˜ao devera
retornar um numero negativo.
 */



int caminho (Posicao inicial, Posicao final, Movimento mov[], int N)
{
    int* xi = &inicial.x;
    int* yi = &inicial.y;
    int xf = final.x, yf = final.y, i;
    for(i = 0; i < N; i++) {
        if((*xi) < xf) {
            (*xi)++;
            mov[i] = Este;
        }
        else if ((*xi) > xf) {
            (*xi)--;
            mov[i] = Oeste;
        }
        else if ((*yi) < yf) {
            (*yi)++;
            mov[i] = Norte;
        }
        else if ((*yi) > yf) {
            (*yi)--;
            mov[i] = Sul;
        }
        else break;
    }
    if(inicial.x != final.x || inicial.y != final.y) return -1;
    else return i;
}











/*
49.
Considere o seguinte tipo para representar a posi¸c˜ao de um robot numa grelha.

typedef struct posicao {
    int x, y;
} Posicao;

Defina a fun¸c˜ao int maisCentral (Posicao pos[], int N) que, dado um array com N
posi¸c˜oes, determina o ındice da posi¸c˜ao que est´a mais perto da origem (note que as coordenadas de cada ponto s˜ao n´umeros inteiros)
*/


int Dist(int x, int y, int x0, int y0) {return abs(x - x0) + abs(y - y0);}

int maisCentral (Posicao pos[], int N) {
    int minDist = Dist(pos[0].x,pos[0].y,0,0);
    int ans = 0, i;
    for(i = 1; i < N; i++) {
        if( Dist(pos[i].x,pos[i].y,0,0) < minDist)
        {
            ans = i;
            minDist = Dist(pos[i].x,pos[i].y,0,0);
        }
    }
    return ans;
}



/*
 * 50
Considere o seguinte tipo para representar a posic˜ao de um robot numa grelha.

typedef struct posicao {
    int x, y;
} Posicao;

Defina a func˜ao int vizinhos (Posicao p, Posicao pos[], int N) que, dada uma posic˜ao
e um array com N posic˜oes, calcula quantas dessas posic˜oes s˜ao adjacentes a posi¸c˜ao dada.
 */






int vizinhos (Posicao p, Posicao pos[], int N) {
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(Dist(pos[i].x,pos[i].y,p.x,p.y) == 1) ans++;
    }
    return ans;
}




