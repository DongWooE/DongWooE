#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int **x;  //int형 더블 포인터 x 선언
    printf("-----[이동우]-----[2017038069]------\n");  //이름과 학번 출력
    printf("sizeof(x)=%lu\n", sizeof(x));  //주소이므로 64비트이면 8byte, 32비트면 4byte출력
    printf("sizeof(*x=%lu\n", sizeof(*x));  //주소이므로 64비트이면 8byte, 32비트면 4byte출력
    printf("sizeof(**x)=%lu\n", sizeof(**x));  //int형 변수이므로 4byte출력
    }
