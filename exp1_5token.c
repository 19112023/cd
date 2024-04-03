#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX_PROG_SIZE 100
int main(){
    printf("Enter C program\n");
    char inputFile[MAX_PROG_SIZE];
    fgets(inputFile,sizeof(inputFile),stdin);
    char *token = strtok(inputFile," \t\n;(){}");
    while(token!= NULL){
        printf("Token: %s", token);

        token= strtok(NULL," \t\n;(){}");
    }
    return 0;
}
