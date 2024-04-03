#include<stdio.h>
#define MAX_BUFFER_SIZE 100
void deleteLine(char filename[],int n){
    FILE* file= fopen(filename,"r");
    FILE* tempFile= fopen("temp.txt","w");
    char buffer[MAX_BUFFER_SIZE];
    int x=0;
    while(fgets(buffer,MAX_BUFFER_SIZE,file)!= NULL){
    x++;
    if(x!=n){
        fputs(buffer,tempFile);
    }
    }
    fclose(file);
    fclose(tempFile);
if(remove(filename)!=0 || rename("temp.txt",filename)!=0){
    printf("Error in modifying the file\n");
}
printf("Successfully removed\n");
}

int main(){
    char filename[]="exp.txt";
    int n;
    printf("Enter the line to be deleted:\n");
    scanf("%d",&n);

    deleteLine(filename,n);
      return 0;


}
