#include <stdio.h>
#include <stdlib.h>

void main() {
    int list[5];  //5개의 인덱스를 가진 list배열 선언
    int *plist[5];  //5개의 주소를 가진 plist 포인터 선언

    list[0]=10;  //0번째 list원소에 10대입
    list[1]=11;  //1번째 list원소에 11대입

    plist[0] = (int*)malloc(sizeof(int));  //plist[0]의 공간을 heap영역에서 4byte할당받음

    printf("-----[이동우]-----[2017038069]-----\n");  //이름과 학번 출력
    printf("list[0]\t = %d\n", list[0]);  //list[0]의 값 출력 - '10'출력
    printf("address of list \t=%p\n", list);  //list의 주소 출력
    printf("address of list[0] \t=%p\n", &list[0]);  //list[0]의 주소 출력( = list의 주소)
    printf("address of list+0 \t=%p\n", list+0);  //list+0의 주소 출력( = list의 주소)
    printf("address of list+1 \t=%p\n", list+1);  //list+1의 주소 출력( = list의 주소+4byte(int형이므로) 값 출력)
    printf("address of list+2 \t=%p\n", list+2);  //list+2의 주소 출력( = list의 주소+8byte(int형이므로) 값 출력)
    printf("address of list+3 \t=%p\n", list+3);  //list+3의 주소 출력( = list의 주소+12byte(int형이므로) 값 출력)
    printf("address of list+4 \t=%p\n", list+4);  //list+4의 주소 출력( = list의 주소+16byte(int형이므로) 값 출력)
    printf("address of list[4] \t=%p\n", &list[4]);  //list[4]의 주소 출력 ( = list+4의 주소와 같음)

    free(plist[0]);  //heap영역에 동적할당되었던 plist[0]의 공간할당을 해체함
}
