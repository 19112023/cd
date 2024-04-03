#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

void f(char stopWord[],char inputFile[],char outputFile[]){
    FILE* stopWordPtr= fopen(stopWord,"r");
    FILE* inputFilePtr= fopen(inputFile,"r");
    FILE* outputFilePtr= fopen(outputFile,"w");

    char words[100];
    char words_line[100]="";
    while(fscanf(stopWordPtr,"%s", words)==1){
    strcat(words_line,words);
    strcat(words_line," ");
    }
  char buffer[1000];
    while(fgets(buffer,1000,inputFilePtr)!= NULL){
        char* token= strtok(buffer," \n\t");
        while(token!= NULL){
            if(strstr(words_line,token)==NULL){
                fprintf(outputFilePtr,token);
            }
            token= strtok(NULL," \n\t");
        }
    }
    
}

int main(){
    char stopWord[]="stop_word.txt";
    char inputFile[]="story.txt";
    char outputFile[]="story_without_stop.txt";
    f(stopWord,inputFile,outputFile);
}
