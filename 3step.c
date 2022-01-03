#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct arr {
    char arr[50][50];
};

struct arr transform(char str[]){
    struct arr L;
    char lang[100]="\0";
    int j=0; int num=0;
    for (int i = 0; i <= strlen(str); i++){
            if(str[i]=='+' | i==strlen(str)){
                strcpy(L.arr[num],lang);
                memset(lang, 0, strlen(lang));
                j=0; num++;
            }else{
                lang[j]=str[i];
                j++;
                }
            }
    return L;
}

bool appartientAutomate(char str[], char L[]){
    int a=0; // Permet d'indexer le str
    int i=0; // Permet d'indexer le Langage (L)
    while (a!=strlen(str)){
        if(str[a]!=L[i] && str[a]!='('){
            return false;
        }else{
            a++;
            if(L[i+1]=='*'){
                while(str[a]==L[i]){
                    printf("hello--%c\n",str[a]);
                    a++;
                }
                i++;
            }
            i++;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    char L[] = "aaa*b*ab+bb*"; // Equation de l'automate -> peut être traduit shématiquement 
    struct arr Lang=transform(L);
    char *string="ba";
    for (int i = 0; i < sizeof Lang.arr / sizeof Lang.arr[0]; i++){
        if(appartientAutomate(string, Lang.arr[i])==1){
            printf("Le string appartient à l'automate\n");
            return 0;
        }
    }
    printf("Le string n'appartient pas à l'automate\n");
    return 0;
}

// else if(L[i+1]=='('){
//     /* code */
//     i+=2;
//     int j=i;
//     char res[100]="";
//     while(L[i]!=')'){
//         //code

//     }
// }


// struct arr transform(char str[]){
//     // aaa*b*(ab+bb*)aa*"; // Equation de l'automate -> peut être traduit shématiquement 
//     //  aaa*b*ab + aaa*b*bb*
//     struct arr L;
//     char lang[100]="\0";
//     int j=0; int num=0;
//     for (int i = 0; i <= strlen(str); i++){
//         // Ne gère pas les paranthèses
//         // if(str[i]=='('){
//         //     int a=i+1; int p=0; char res[100]="\0"; int cmpt=0;
//         //     while(str[a]!=')'){
//         //         res[p]=str[a];
//         //         printf("%c\n", str[a]);
//                 // struct arr result;
//                 // // printf("---%d\n", a);
//                 // if(str[a+1]=='+'| str[a+1]==')'){
//                 //     strcpy(result.arr[cmpt],res);
//                 //     memset(res, 0, strlen(res));
//                 //     a++;cmpt++;
//                 // }
//                 // a++;p++;
//                 // a++;
//             // }
//             // i=a;
//         // }else{
//             if(str[i]=='+' | i==strlen(str)){
//                 strcpy(L.arr[num],lang);
//                 memset(lang, 0, strlen(lang));
//                 j=0; num++;
//             }else{
//                 lang[j]=str[i];
//                 j++;
//                 }
//         // }
//     }
//     return L;
// }