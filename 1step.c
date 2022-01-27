#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct alphabet{
    char a1[1];
    char b1[1];
    char c1[1];
};


bool appartient(char str[], struct alphabet alphabet){
    for(int i=0; i<strlen(str); i++){
        if(str[i]!=*alphabet.a1 && str[i]!=*alphabet.b1 && str[i]!=*alphabet.c1){
            return false;
        }
    }
    return true;
}

bool vide(char str[]){if(strcmp(str, "\0")==0){return true;}else{return false;}}

char* puis(char string[], int m){
    //abc
    char* result="";
    char string1[100]="";
    if (m==0){
        return result;
    }else{
        strcpy(string1, string);
        for (int i=0; i<m-1; i++){
            result = strcat(string1, string);
        }
        return result;
    }
}

bool estFini(char str[]){
    for(int i=0; i<strlen(str); i++){
        if(str[i]=='*'){
            return false;
        }
    }
    return true;
}

char* miroir(char m[]){
    char *result;
    char a[100]="";
    int i=0; 
    for(int j=strlen(m)-1; j>=0; j--){
        a[i] = m[j];
        i++;
    }
    result=a;
    return result;
}

int main(int argc, char *argv[]){
    //   1er étape, mise en jambe
    struct alphabet alphabet={"d","g","a"};
    printf("%d\n", appartient("dag", alphabet)); 
    printf("%s\n", puis("abc",3));
    printf("%s\n", miroir("hello"));
    printf("%d\n", vide("abc"));
    printf("%d\n", estFini("abc"));
}
