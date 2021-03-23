#include<stdio.h>
#include<stdlib.h>

void main(){
    int list[5];    //정수형 5개 저장할 수 있는 배열 선언
    int *plist[5]={NULL,};      //정수형 포인터 5개 저장할 수 있는 배열 선언하고 모두 NULL로 초기화


    plist[0]=(int *)malloc(sizeof(int));      //정수형만큼의 사이즈(4바이트)를 heap영역에서 할당받음.   

    list[0]=1;      //리스트 0번에 1 저장
    list[1]=100;        //리스트 1번에 100저장

    *plist[0]=200;      //plist의 0번째가 가리키는 곳에 200저장

    printf("--------[SooYeon Yim]   [2020039017]--------\n");

    printf("value of list[0]= %d\n",list[0]);   //list[0]의 값(1)
    printf("address of list[0]      = %p\n",&list[0]);  //list[0]의 주소
    printf("value of list           = %p\n",list);  //list의 값(list[0]의 주소와 동일)
    printf("address of list(&list)  = %p\n",&list); //리스트의 주소(list[0]의 주소도 동일)
//리스트라는 배열의 이름 자체가 리스트가 위치하고 있는 곳의 주소가 된다.
    printf("--------------------------------------\n\n");

    printf("value of list[1]    = %d\n",list[1]);   //list[1]의 값(100)
    printf("address of list[1]  = %p\n",&list[1]);  //list[1]의 주소
    printf("value of *(list+1)  = %d\n",*(list+1));  //list+1에 대한 값(list[1]의 값과 동일 (list의 주소에서 4바이트(+1,int 형)이동한 곳의 값과 동일))
    printf("address of list+1   = %p\n",list+1);    //list+1의 주소(list[1]의 주소와 동일)

    printf("--------------------------------------\n\n");
    
    printf("value of *plist[0]= %d\n",*plist[0]);   //plist의 0번이 가리키고 있는 곳의 값(200)
    printf("&plist[0]         = %p\n",&plist[0]);   //plist의 0번의 주소   
    printf("&plist            = %p\n",&plist);      //plist의 주소(plist의 0번의 주소와 동일)
    printf("plist             = %p\n",plist);       //plist(plist의 주소와 동일)
    printf("plist[0]          = %p\n",plist[0]);    //plist의 0번(plist의 0번이 가지고 있는 주소,heap영역에 malloc으로 할당받은 곳의 주소)
    printf("plist[1]          = %p\n",plist[1]);    //plist의 1번(NULL)
    printf("plist[2]          = %p\n",plist[2]);    //plist의 2번(NULL)
    printf("plist[3]          = %p\n",plist[3]);    //plist의 3번(NULL)
    printf("plist[4]          = %p\n",plist[4]);    //plist의 4번(NULL)
    

    free(plist[0]); //메모리해제
}