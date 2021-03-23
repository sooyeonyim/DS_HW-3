#include<stdio.h>

struct student1{
    char lastName;
    int studentId;
    char grade;
};  //구조체 선언

typedef struct{
    char lastName;
    int studentId;
    char grade;
}student2;  //typedef 문장을 사용한 구조체 선언

int main(){
    struct student1 st1 ={'A',100,'A'}; //struct를 사용해 선언한 구조체의 경우 struct가 없으면 에러.

    printf("--------[SooYeon Yim]   [2020039017]--------\n");

    printf("st1.lastName=%c\n",st1.lastName); //각각의 멤버변수 출력,A
    printf("st1.studentId=%d\n",st1.studentId); //100
    printf("st1.grade=%c\n",st1.grade); //A
    
    student2 st2={'B',200,'B'};

    printf("\nst2.lastName = %c\n",st2.lastName);   //B
    printf("st2.studentId = %d\n",st2.studentId);   //200
    printf("st2.grade = %c\n",st2.grade);   //B

    student2 st3;

    st3=st2;    //구조치환 가능

    printf("\nst3.lastName = %c\n",st3.lastName);   //B
    printf("st3.studentId = %d\n",st3.studentId);   //200
    printf("st3.grade = %c\n",st3.grade);   //B

    /* equality test */         
    /*
    if(st3==st2)        //불가능
        printf("equal\n");
    else
        printf("not equal\n");
    */

   return 0;

}