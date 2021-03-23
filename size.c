#include<stdio.h>
#include<stdlib.h>

 void main(){
     int **x;       //정수형 더블 포인터 선언

     printf("--------[SooYeon Yim]   [2020039017]--------\n");

     printf("sizeof(x) = %lu\n",sizeof(x)); //x의 사이즈(주소를 저장, 64bit 머신 :8bytes/ 32bit 머신: 4bytes)
     printf("sizeof(*x) = %lu\n",sizeof(*x));   //싱글 포인터 x의 사이즈(주소를 저장, 64bit 머신 :8bytes/ 32bit 머신: 4bytes)
     printf("sizeof(**x) = %lu\n",sizeof(**x)); //더블 포인터 x의 사이즈(int 값을 저장, 4bytes)
 }