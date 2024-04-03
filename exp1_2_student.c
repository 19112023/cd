#include<stdio.h>

#define MAX_NAME_SIZE 50
#define FILE_NAME "students_records.txt"
struct STUDENT{
char Name[MAX_NAME_SIZE];
int marks;
};
int main(){
int n;
printf("Enter the no.of students:\n");
scanf("%d",&n);
    struct STUDENT students[n];
FILE* file;
file= fopen(FILE_NAME,"w");

if(file==NULL) printf("File does not exist here");

for(int i=0;i<n;i++){
    printf("Enter the name of the student: %d\n", i+1);
    scanf("%s", &students[i].Name);
    printf("Enter the marks of the student: %d\n", i+1);
    scanf("%d", &students[i].marks);

}
fprintf(file,"Name\t Marks\n");
for(int i=0;i<n;i++){
fprintf(file,"%s\t %d\n", students[i].Name,students[i].marks);
}

}
