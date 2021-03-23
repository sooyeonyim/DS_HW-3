#include<stdio.h>
#include<stdlib.h>

void main(){
    int list[5];
    int *plist[5];

    list[0]=10; //리스트 0번에 10 저장
    list[1]=11; //리스트 1번에 11 저장

    plist[0]=(int*)malloc(sizeof(int));

    printf("--------[SooYeon Yim]   [2020039017]--------\n");

    printf("list[0] \t= %d\n", list[0]);    //list[0]의 값(10)
    printf("address of list \t= %p\n", list);   //list의 주소
    printf("address of list[0] \t=%p\n", &list[0]); //list[0]의 주소
    printf("adress of list+0 \t= %p\n",list+0);    //list[0]의 주소
    printf("adress of list+1 \t= %p\n",list+1);     //list[1]의 주소(base에서 4바이트 이동)
    printf("adress of list+2 \t= %p\n",list+2);     //list[2]의 주소(base에서 8바이트 이동)
    printf("adress of list+3 \t= %p\n",list+3);     //list[3]의 주소(base에서 12바이트 이동)
    printf("adress of list+4 \t= %p\n",list+4);     //list[4]의 주소(base에서 16바이트 이동)
    printf("adress of list[4] \t= %p\n",&list[4]);  //list[4]의 주소

    free(plist[0]); //메모리 해제
}