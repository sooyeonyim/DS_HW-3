 #include<stdio.h>

 void print1(int *ptr, int rows);

 int main(){
     int one[]={0,1,2,3,4}; //배열의 이름 자체가 주소다.

    printf("--------[SooYeon Yim]   [2020039017]--------\n");

    printf("one     =%p\n",one);   //one의 주소
    printf("&one    =%p\n",&one);   //one의 주소
    printf("&one[0] =%p\n",&one[0]);    //one[0]의 주소(one의 주소와 동일)
    printf("\n");

    print1(&one[0], 5);

    return 0;
 }

 void print1(int *ptr, int rows){
     /* print out a one-dimensional array using a pointer */

     int i;
     printf("Address \t Contets\n");
     for(i=0;i<rows;i++)
        printf("%p \t %5d\n",ptr+i,*(ptr+i));   // one[0],one[1],one[2],one[3],one[4]의 주소와 값을 차례대로 출력한다.
    printf("\n");
 }