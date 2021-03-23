#include<stdio.h>

struct student{
    char lastName[13];  /* 13 bytes */
    int studentId;      /* 4bytes */
    short grade;        /* 2bytes */
};  //구조체 선언, 총 구조체 크기는 19bytes.

int main(){

    struct student pst;

    printf("--------[SooYeon Yim]   [2020039017]--------\n");

    printf("size of student = %ld\n", sizeof(struct student));  //sturct 꼭 붙여야한다. ,24[(4+4+4+1)(13bytes)+3(padding)+4+2+2(padding)]
    printf("size of int = %ld\n", sizeof(int)); //4
    printf("size of short = %ld\n", sizeof(short)); //2

//gcc컴파일러는 padding을 하고 있다.

    return 0;
}