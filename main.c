#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_WORD_LENGTH 100
#define ARRAY_SIZE 17005210
#define UNIQUE_ARRAY_SIZE 255000

typedef struct Node{

    char word[MAX_WORD_LENGTH];
    int occurrences;

}Node;

int exist_in_array(Node* array,int size, char word[]){
    for(int i=0;i<size;i++){
        if(strcmp(array[i].word,word)==0){
            return i;
        }
    }
    return -1;
}

Node* count_occurrences_naive (Node *array){
    
    Node *new_array = (Node*)malloc(UNIQUE_ARRAY_SIZE * sizeof(Node));
    
    for(int i=0,k =0;i<ARRAY_SIZE;i++){
        int index = exist_in_array(new_array,UNIQUE_ARRAY_SIZE,array[i].word);
        if(index != -1){
            new_array[index].occurrences ++;
        }else{
            strcpy(new_array[k].word,array[i].word);
            new_array[k].occurrences = 1;
            k++;
        }
    }
    return new_array;
}

void NaiveApproach(){

    Node *array = (Node*)malloc(ARRAY_SIZE * sizeof(Node));
    if(array == NULL){
        printf("\nNo enough memory\n");
    }

    FILE *file = fopen("homo.txt","r");

    clock_t start_time = clock();

    char word[MAX_WORD_LENGTH];
    int i = 0;
    while(fscanf(file,"%99s",word) == 1 && i < ARRAY_SIZE){
        strcpy(array[i].word,word);
        array[i].occurrences = 1;
        i++;
    }

    Node *new_array = count_occurrences_naive(array);

    
    for (int i=0;i<10;i++){
        int max =0;
        int index = 0;
        for (int j=0;j<UNIQUE_ARRAY_SIZE;j++){
            if(max < new_array[j].occurrences){
                max = new_array[j].occurrences;
                index = j;
            }
        }
        printf("%d- %s (%d)\n",i,new_array[index].word,new_array[index].occurrences);
        new_array[index].occurrences = -1;
    }

    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.6f seconds\n", elapsed_time);
    

    fclose(file);
}
void Multiprocessing(){
// printf("hey");
}
void Multithreading(){
// printf("hey");
}

void printMenu (){

    printf("\n<========= Operating System First Project =========>\n");
    
    int choice = 0;

    while (choice != 4){
        printf("\n1. Naive approach\n2. Multiprocessing\n3. Multithreading\n4. Exit\n");
        printf("\nChoose your approach -> ");
        scanf("%d",&choice);
        switch (choice){
            case 1 : NaiveApproach();
                break;
            case 2 : Multiprocessing();
                break;
            case 3 : Multithreading();
                break;
            case 4 : 
                break;
            default : printf("\nWrong operation try again !\n");
                break;
        }
    }
    printf("\nThank you for using my program !\n\n");
}

int main (){
    printMenu();
    return 0;
}