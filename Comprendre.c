#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Compilation avec un pc ayant un noyau Unix : 
// gcc -Wall -o nom_du_fichier_objet  -c nom_du_fichier_source_C

// Bien comprendre les pointeurs (assignation à une addresse mémoire)
// void changepointeur(int* p){
//     *p=20;} 
    //Ne retourne rien mais change quand même la valeur de a, on change directement dans la mémoire
// int main(){
//     int a = 10;
//     int* pointeur = &a;
//     printf("%d\n", a);
//     changepointeur(pointeur);
//     printf("%d\n", a);
// }

//Fonctionne mais ne retourne rien, je préfère qu'elle retourne qlq chose (ne retourne pas parce que on copie la string transformé et est directement mémoirisé car pointeur )
// void puis(char* string[], int m){
//     char string1[100]="";
//     if (m==0){
//         strcpy(string, string1);
//     }else{
//         strcpy(string1, string);
//         for (int i=0; i<m-1; i++){
//             strcat(string1, string);
//         }
//         strcpy(string, string1);
//     }
// }


// int main(){
//     char names[50][50];
//     strcat(names[0], "lollll");
//     printf("%s", names[0]);
//     return 0;
// }

int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
    }
    // Print the elements of the array
    printf("The elements of the array are: ");
    for (i = 0; i < n; ++i) {
        printf("%d, ", ptr[i]);
    }
 
    return 0;
}