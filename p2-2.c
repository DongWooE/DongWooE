#include <stdio.h>
#include <stdlib.h>

void print1 (int *ptr, int rows);  // int형 포인터 ptr과 int형 변수 rows를 받는 힘수 print1선언

int main() {
    int one[]={0,1,2,3,4};  // 5개의 원소를 가지는 정수형 배열 one 선언
    printf("-----[이동우]-----[2017038069]-----\n"); //이름과 학번 출력
    printf("one = %p\n", one);  //배열의 이름은 곧 배열의 주소, one의 주소 출력
    printf("&one = %p\n", &one);  //one의 주소 출력
    printf("&one[0]=%p\n", &one[0]);  //배열의 첫번째 원소의 주소는 곧 배열의 주소, one의 주소 출력
    printf("\n");

    print1(&one[0],5);  //배열의 첫번째 원소의 주소(곧 배열의 주소)와 배열의 인덱스를 넘김

    return 0;
}
void print1 (int *ptr, int rows){
    int i;  //int형 i 선언
    printf("Address \t Contents\n");
    for(i=0;i<rows;i++)  //i가 0부터 rows(5)까지 도는 반복문
        printf("%p \t %5d\n", ptr+i, (*ptr+i));  //ptr[i]의 주소(i가 늘수록 4bytes씩 증가)와 그 인덱스의 원소 출력, call by reference이므로 one의 주소와 원소 출력
    printf("\n");
}
