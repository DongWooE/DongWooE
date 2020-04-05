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

padding
#include <stdio.h>
#include <stdlib.h>

struct student {  //구조체 student 선언
    char lastName[13];  //구조체 멤버변수로 char형 13개의 인덱스를 가진 lastName배열 선언 (1(char형)*13(13개의 인덱스)이므로 13bytes)
    int studentID;  //구조체 멤버변수로 int형 studentID 선언 (int형이므로 4byte)
    short grade;  //구조체 멤버변수로 short형 grade 선언 (short형이므로 2byte)
};

int main(){
    struct student pst;  //구조체 변수로 pst선언

    printf("-----[이동우]-----[2017038069]-----\n");
    printf("size of student = %ld\n", sizeof(struct student));  //구조체 student의 크기 출력( 컴파일러에 따라 다르다 padding 허용이면 24byte, padding 허용이 안되면 값이 깨짐)
    printf("size of int = %ld\n", sizeof(int));  //int형의 크기 출력 -4bytes
    printf("size of short = %ld\n", sizeof(short));  //short형의 크기 출력 -2bytes

    return 0;
}
