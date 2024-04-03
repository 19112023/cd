#include<stdio.h>
#define MAX_BUFFER_SIZE 1000
int main(){
    FILE *sourceFile=fopen("source.txt","r");
    FILE *destinationFile=fopen("destination.txt","w");
char buffer[MAX_BUFFER_SIZE];
    while(fgets(buffer,MAX_BUFFER_SIZE,sourceFile) != NULL){
        fputs(buffer,destinationFile);
    }
    fclose(sourceFile);
    fclose(destinationFile);
}
