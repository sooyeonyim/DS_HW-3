#include<stdio.h>
 
 #define MAX_SIZE 100

 float sum(float [], int);
 float input[MAX_SIZE], answer;
 int i;
 void main(void){
     for(i=0;i<MAX_SIZE;i++)
        input[i]=i;

        printf("--------[SooYeon Yim]   [2020039017]--------\n");

        /*for checking call by reference*/
        printf("address of input =%p\n", input);    //input의 주소
        

       answer=sum(input, MAX_SIZE);
       printf("The sum is: %f\n", answer);  //4950
 }

 float sum(float list[], int n){
     
     printf("value of list = %p\n",list);   //input의 주소와 동일
     printf("address of list = %p\n\n",&list);  //list의 주소
     

    int i;
    float tempsum =0;
    for(i=0;i<n;i++)
        tempsum+=list[i];
    return tempsum;
 }