#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct relation{
    int source;   // etat source
    char gram[2]; // grammaire de la transition
    int dest;     // etat de destination
};

struct AEF
{
    char *X;
    int *Q;
    int *I;
    int *F;
    struct relation *R;
};

// void rendComplet(struct AEF aef){
//     if(AEFcomplet(aef)==0){
//         int nb=0; int nbX=0; int nbR; int countR;
//     printf("hello\n");
//         for (int i = 0; i <= sizeof aef.X; i++){
//         if (aef.X[i]!='\0'){
//             nbX++;       
//         }
//     }
//     for (int i = 0; i <= sizeof aef.R; i++){
//         if (strlen(aef.R[i].gram) != 0){
//             nbR++;
//         }
//     }
//         for (int i = 0; i < sizeof aef.R; i++){
//             for (int j = 0; j < sizeof aef.R; j++){
//                 //printf("%d , %d\n",aef.R[i].source,aef.R[j].source);
//                 if (aef.R[i].source==aef.R[j].source){
//                     nb++;
//                 }
//             }
//             if(nb!=nbX && aef.R[i].source!=0){
//                 //printf("%d---%d\n", aef.R[i].source, nb);
//                 for (int k = 0; k < sizeof aef.X; k++){
//                     if (aef.X[k]!=aef.R[i].gram){
//                         //printf("%s&\n",aef.R[i].gram);
//                         //C'est ici qu'il va falloir traiter l'etat non complet
//                     }
//                 }
                
//             }
//             nb=0;
//         }
//     }
// }

bool AEFcomplet(struct AEF aef){
    int countQ = 0;
    int nbQ = 0;
    int nbR = 0;
    int nbX = 0;
    for (int i = 0; i < sizeof aef.Q; i++){
        if (aef.Q[i] != 0 | countQ == 0){
            nbQ++;
            countQ = 1;
        }
    }
    for (int i = 0; i <= sizeof aef.R; i++){
        if (strlen(aef.R[i].gram) != 0){
            nbR++;
        }
    }
    for (int i = 0; i <= sizeof aef.X; i++){
        if (aef.X[i]!='\0'){
            nbX++;            
        }
    }
    if (nbQ*nbX==nbR){
        return true;
    }
    return false;
}


bool appartientAEFF(struct AEF aef, char string[]){
    int currState = aef.I;
    int a = 0; // in string
    while (a!=strlen(string)){
        for (int i = 0; i < sizeof aef.R; i++){
            if(string[a]==aef.R[i].gram[0] && currState==aef.R[i].source ){
                currState=aef.R[i].dest;
                for (int j = 0; j < sizeof aef.F/sizeof aef.F[0]; j++){
                if(currState == aef.F[j]){
                    if (a+1 == strlen(string)){
                        return true;
                        }
                    }
                }
                a++;
            }
        }
    } 
    return false;
} 

bool appartientAEF(struct AEF aef, char string[]){
    int currState = aef.I;
    int a = 0; // in string
    printf("%d\n",currState);
    while (a!=strlen(string)){
        for (int i = 0; i < sizeof aef.R; i++){
        // printf("%c----%c,,, %d-----%d\n", string[a], aef.R[i].gram[0],currState,aef.R[i].source);
            if(string[a]==aef.R[i].gram[0] && currState==aef.R[i].source ){
                                printf("%d\n", currState);

                currState=aef.R[i].dest;
                printf("%d---%d---%c\n", currState,aef.R[i].dest,aef.R[i].gram[0]);
                for (int j = 0; j < sizeof aef.F/sizeof aef.F[0]; j++){
                if(currState == aef.F[j]){
                    if (a+1 == strlen(string)){
                        return true;
                        }
                    }
                }
                a++;
            }
        }
    } 
    return false;
} 

void afficherAEF(struct AEF aef)
{
    printf("X={");
    for (int i = 0; i < sizeof aef.X; i++)
    {
        if ((char)aef.X[i] != NULL)
        {
            printf("%c,", aef.X[i]);
        }
    }
    printf("}\n");
    printf("Q={");
    for (int i = 0; i < sizeof aef.Q; i++)
    {
        if ((int)aef.Q[i] != NULL)
        {
            printf("%d,", aef.Q[i]);
        }
    }
    printf("}\n");
    printf("I=%d\n", aef.I);
    for (int i = 0; i < sizeof aef.R; i++){
        if(strlen(aef.R[i].gram)!=0){
            printf("R(%d,%s)=%d\n", aef.R[i].source, aef.R[i].gram, aef.R[i].dest);
        }
    }
    printf("F={");
    for (int i = 0; i < sizeof aef.F; i++){
        if((int)aef.F[i]!=NULL){
            printf("%d,", aef.F[i]);
        }
    }
    printf("}\n");
}

int main(int argc, char *argv[]){
    char ch, file_name[30] = "AEF.txt";
    FILE *fp;
    fp = fopen(file_name, "r"); // read mode
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    struct AEF aef;
    aef.X = malloc(sizeof(char) * 30);
    aef.Q = malloc(sizeof(int) * 30);
    aef.I = malloc(sizeof(int) * 5);
    aef.F = malloc(sizeof(int) * 10);
    aef.R = malloc(sizeof(struct relation) * 15);

    char *res;
    res = malloc(sizeof(int) * 10);
    char curr = '\0';
    bool read = false;
    int count = 0, countR = 0;
    int test = 0;
    // Mode read permet de concatainer tous les charactères courants
    // read=false 
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == 'X')
        {
            strcpy(aef.X, "");
            count = 0;
            curr = 'X';
            read = false;
        }
        else if (ch == 'Q')
        {
            count = 0;
            curr = 'Q';
            read = false;
        }
        else if (ch == 'I')
        {
            count = 0;
            curr = 'I';
            read = false;
        }
        else if (ch == 'R')
        {
            int count = 0;
            curr = 'R';
            read = false;
        }
        else if (ch == 'F')
        {
            count = 0;
            curr = 'F';
            read = false;
        }

        if (ch == ',' | ch == ')' | ch == '}')
        {
            read = false;
            memset(res, 0, strlen(res));
        }

        if (read == true && ch != '{')
        {
            char copy[2] = {ch, '\0'};
            strcat(res, copy);
            if (curr == 'X')
            {
                strcat(aef.X, res);
                count++;
            }
            else if (curr == 'Q')
            {
                aef.Q[count] = atoi(res);
                count++;
            }
            else if (curr == 'I')
            {
                aef.I = atoi(res);
            }
            else if (curr == 'F')
            {
                aef.F[count] = atoi(res);
                count++;
            }
            else if (curr == 'R')
            {
                if (countR == 0)
                {
                    aef.R[count].source = atoi(res);
                    countR++;
                }
                else if (countR == 1)
                {
                    strcpy(aef.R[count].gram, res);
                    countR++;
                }
                else if (countR == 2)
                {
                    aef.R[count].dest = atoi(res);
                    countR++;
                }
                else if (countR == 3)
                {
                    countR = 0;
                    count++;
                }
            }
        }
        if (ch == '(' | ch == '{' | ch == ',' | ch == '\0' | ch == ' ' | ch == '=')
        {
            memset(res, 0, strlen(res));
            read = true;
        }
    }

    afficherAEF(aef);
    printf("%d\n", appartientAEFF(aef, "aba"));
    printf("%d\n", AEFcomplet(aef));
    //rendComplet(aef);
    fclose(fp);
    return 0;
}