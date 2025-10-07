//Create a program to calculate the grade acquired by the student by providing the
//marks in each subject.


#include <stdio.h>
int main() {
    int marks;
    printf("Enter your Marks=");
    scanf("%d", &marks);
    if (marks<30){
        printf("C(Fail)");
    }
    else if (marks>=30  &&  marks<=70){
        printf("B");
    }
    else if (marks>=70 &&  marks<90){
        printf("A");
    }
    else{
        printf("A+");
    }
    return 0;
}
