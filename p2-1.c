#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100  //매크로 함수 MAX_SIZE 를 100으로 정의

float sum(float [], int);  //float배열과 int형 변수를 인수로 받는 float형 sum함수 선언
float input[MAX_SIZE], answer;  //전역변수로 MAX_SIZE크기를 가진 float형 input배열, float형 변수 answer 선언
int i;  //전역변수로 int형 변수 i 선언

void main() {
    printf("-----[이동우]-----[2017038069]-----\n");  //이름과 학번 출력
    for(i=0; i<MAX_SIZE; i++)  //i를 0부터 100까지 반복하는 for문
        input[i]=i;  //input배열에서 i번째 인덱스에 i대입
    printf("address of input = %p\n", input);  //input배열의 주소 출력
    answer=sum(input, MAX_SIZE);  //answer에 sum함수에 input과 MAX_SIZE를 대입한 결괏값을 대입(input배열이 전역변수이므로 함수에서 나온 후 값이 변경된다(call by reference))
    printf("The sum is: %f\n", answer);  //answer값을 출력
}

float sum(float list[], int n){
    printf("value of list = %p\n", list);  //list의 주소 출력(전달받은 배열의 주소 출력, 여기에서는 input배열의 주소 출력)
    printf("address of list = %p\n\n", &list);  //list의 주소 출력(함수 내의 매개변수 list의 주소 출력)

    int i;  //전역변수 int형 i
    float tempsum=0;  //지역변수 float형 tempsum에 0값 대입
    for(i=0;i<n;i++) //i를 부터 n까지 반복
        tempsum+=list[i];  //tempsum에 배열 원소값을 계속 더해감
    return tempsum;  //tempsum을 반환함
}
