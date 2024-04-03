#include<stdio.h>

#define MAX_FILENAME_SIZE 100
#define MAX_BUFFER_SIZE 1024

int main(){

    char filename[MAX_FILENAME_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    FILE* file;
printf("Enter file name:");
scanf("%s", &filename);
    file= fopen(filename,"r");
   if(file==NULL) printf("File does not exist\n");
    int wordCount=0,lineCount=0,charCount=0;

    while(fgets(buffer,MAX_BUFFER_SIZE,file)!= NULL){
        lineCount++;
       int i=0;
        for(i=0;buffer[i]!='\0';i++){
            charCount++;
            if(buffer[i]==' ' || buffer[i]=='\t' || buffer[i]=='\n') wordCount++;

        }
    }


}
