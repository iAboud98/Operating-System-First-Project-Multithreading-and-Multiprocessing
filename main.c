#include <stdio.h>
void NaiveApproach(){
    // printf("hey");
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