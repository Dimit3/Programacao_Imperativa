#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
1. Defina um programa que le (usando a funcao scanf uma sequencia de numeros inteiros
terminada com o n´umero 0 e imprime no ecran o maior elemento da sequencia.
*/


int maximo1 () {
    int array[1000];
    int i=0;
    while (scanf("%d", &array[i] )  && array[i] != 0) {
        i++;
    }
    for (int j = 0; j < i; j++) {
        printf("%d ", array[j]);
    }
    int max = array[0];
    for (int j = 1; j < i ; j++){
        if (array[j] > max ) {
            max = array[j];
        }
    }
    printf (" \n MAX: %d", max );
    return 0;
    }




/*
2. Defina um programa que le (usando a func˜ao scanf uma sequencia
de numeros inteiros terminada com o n´umero 0 e imprime no ecran a media da sequencia.
*/


int mean2() {
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
    int array[1024];
    int i = 0,maior,segmaior;
    while (array[i-1] != 0)
    {
        scanf("%d",&array[i]);
        i++;
    }
    if (array[0] >= array[1])
    {
        maior = array[0];
        segmaior = array[1];
    }
    else
    {
        maior = array[1];
        segmaior = array[0];
    }
    for (int j = 1; j < i ; j++)
    {
        if (array[j] > maior)
        {
            segmaior = maior;
            maior = array[j];
        }
    }
    printf("%d\n",segmaior);
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





/*
Defina uma func˜ao int trailingZ (unsigned int n) que calcula o numero de bits a 0 no
final da representac˜ao binaria de um numero(i.e., o expoente da maior potencia de 2 que e
divisor desse numero).
*/


int trailingz5 (int n)
{
    int count = 0;

    while (n > 0)
    {
        n = n/2;
        if (n > 0)
            count ++;
    }
    return count;
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





    int main()
    {
        char frase1[100],frase2[50];
        // maximo1();
        // mean2 ();
        //maximo2();
        //scanf("%d",&n);
        //printf("%d\n",bitsum4(n));
        //printf("%d\n",trailingz5(n));
        //printf("%d\n",qDig6(n));

       scanf("%s",frase1);
       scanf("%s",frase2);

        // fgets(frase1,100,stdin);
       /* fgets(frase2,50,stdin);
        mystrcat(frase1,frase2);
        printf("%s",frase1);
        */

      //  printf("%d\n",mystrlen(frase1));

        // mystrcpy(frase1,frase2);

        printf("%s\n",strstr (frase1,frase2));
        system("pause");
        return 0;

    }