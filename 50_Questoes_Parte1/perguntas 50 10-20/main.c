#include <stdio.h>
#include <string.h>
#include <ctype.h>



// 11 Defina uma func˜ao void strrev (char s[]) que inverte uma string


void mystrrev (char s[]){
    char acomulador;
    int n = strlen(s) -1;
    int i;
    for (i = 0; i < n; i++, n--){
        acomulador = s[i];
        s[i] = s[n];
        s[n]=acomulador;
    }
    printf("%s",s);
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
       s[i] = s[j];                         //se nao for vogal s[i] vai tomar o valor da vogal
       if (s[i] != '\0'){                   // se esse s[i] for o final acaba a funçao se nao i++ e j++
           i++;
           j++;
       }
    }
    s[i] = '\0';
    printf("%s",s);

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
    printf("%s",t);
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
    int i;
    int max = 0, now = 0;

    for ( i= 0; s[i] != '\0'; i++)
    {
        if (i==0) now = 1;
        else {
            if (s[i] != s[i -1])
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
        else if (i2 == 0)
            break;
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
    if (!isspace(s[0])) {(count = 1);};
    for ( i = 0; s[i] != '\0'; i++)
    {
        if (isspace(s[i]) && !isspace(s[i+1]) && (s[i+1] != '\0')) {count++;}
    }
    return count;
}





int main () {
    char exemplo1[50] = {"daniel"};
    char exemplo2[50] = {"liberdade, igualdade e fraternidade"};
    char exemplo3[50] = {"aabcccaac"};
    char exemplo4[50] = {"dani"};
    char exemplo5[50] = {"batota"};
    char exemplo6[50] = {"totalidade"};
    char exemplo7[50] = {"ab ba va c "};

    // mystrrev(exemplo1);
    //strnoV (exemplo1);
    //truncW(exemplo2,4);

    printf("%d",contaPal (exemplo7));
    return 0;
}