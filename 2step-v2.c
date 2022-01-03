#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct relation{
    int source; // etat source
    char gram[2]; // grammaire de la transition
    int dest; // etat de destination
};

struct automate{
    char X[256]; // alphabet
    int Q[256]; // états 
    int* I; // états initiaux
    int F[50]; // états finaux 
    struct relation R[50]; 

    // int nb_states; // nombre d'états
    // int *initial; // les états initiaux
    // int *final; // Les états finaux
    // int nb_transitions; // Le nombre de transitions
    // struct transition *table; // La table de transition
};

void afficherAutomate(struct automate aef){
    printf("X={");
    for (int i = 0; i < sizeof aef.X / sizeof aef.X[0]; i++){
        if(aef.X[i]!=""){
            printf("%c,\n", aef.X[i]);
        }
    }
    printf("}");
}

int main(int argc, char *argv[]){

    char ch,file_name[30]="../AEF.txt";
        FILE *fp;
        fp = fopen(file_name, "r"); // read mode
        if (fp == NULL){
            perror("Error while opening the file.\n");
            exit(EXIT_FAILURE);
        }

    struct automate aef;

    char *res;
    res = malloc(sizeof(int)*10);
    char curr='\0';
    bool read = false;
    int count=0, countR=0;

    // printf("%s\n", aef.X);
    // strcpy(aef.X, "");
    // printf("%s\n", aef.X);

    // Mode read=true permet de concataner tous les charactères courants 
    while((ch = fgetc(fp)) != EOF){
        if(ch=='X'){
            strcpy(aef.X, "");
            count=0;
            curr = 'X';
            read=false;
        }else if(ch=='Q'){
            count=0;
            curr = 'Q';
            read=false;
        }else if(ch=='I'){
            count=0;
            curr = 'I';
            read=false;
        }else if(ch=='R'){
            count=0;
            curr = 'R';
            read=false;
        }else if(ch=='F'){
            count=0;
            curr = 'F';
            read=false;
        }

        if(ch==',' | ch==')' | ch=='}'){
            read=false;
            memset(res, 0, strlen(res));
        }

        if(read==true && ch!='{'){
            char copy[2]={ch, '\0'};
            strcat(res,copy);
            if(curr=='X'){
                strcat(aef.X,res);
                count++;
            }else if(curr=='Q'){
                aef.Q[count]=atoi(res);
                count++;
            }else if(curr=='I'){
                aef.I=atoi(res);
            }else if(curr=='F'){
                aef.F[count]=atoi(res);
                count++;
            }else if(curr == 'R'){
                if(countR==0){
                    aef.R[count].source=atoi(res);
                    printf("source: %d\n", aef.R[count].source);
                    countR++;
                }else if(countR==1){
                    strcpy(aef.R[count].gram,res);
                    printf("gram: %s\n", aef.R[count].gram);
                    countR++;
                }else if(countR==2){
                    aef.R[count].dest=atoi(res);
                    printf("gram: %d\n", aef.R[count].dest);
                    countR++;
                    count++;
                }else if(countR==3){
                    countR=0;
                    printf("\n");
                }
                // printf("%d\n", aef.R[0].source);
                // printf("%c\n", aef.R[0].gram);
                // printf("%d\n", aef.R[0].dest);
            }
        }
        if(ch=='(' | ch=='{' | ch==',' | ch=='\0' | ch==' ' | ch == '='){
            memset(res, 0, strlen(res));
            read=true;
        }
    }
    fclose(fp);
    afficherAutomate(aef);
    return 0;
}