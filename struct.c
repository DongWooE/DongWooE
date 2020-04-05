#include <stdio.h>
#include <stdlib.h>

struct student1{  //구조체 studen1 타입 선언
    char lastName;  //멤버변수 char형 lastName 선언
    int studentId;  //멤버변수 int형 studentId 선언
    char grade;  //멤버 변수 char형 grade 선언
};

typedef struct{  //tydef 사용해서 구조체 student2 타입 선언
    char lastName;  //멤버변수 char형 lastName 선언
    int studentId;  //멤버변수 int형 studentId 선언
    char grade;  //멤버변수 char형 grade 선언
} student2;

int main(void) {
    printf("-----[이동우]-----[2017038069]-----\n"); //이름과 학번 출력
    struct student1 st1 = {'A', 100, 'A'};  //구조체 st1 선언하고  각 멤버변수에 값 대입
    printf("st1.lastName = %c\n", st1.lastName);  //student1의 멤버변수 lastName 값 출력( 'A' 출력)
    printf("st1.studentId = %d\n", st1.studentId);  //student1의 멤버변수 studentId 값 출력('100' 출력)
    printf("st1.grade = %c\n", st1.grade);  //student1의 멤버변수 grade 값 출력('A' 출력)

    student2 st2 = {'B', 200, 'B'};  //구조체 st2 선언하고 각 멤버변수에 값 대입
    printf("\nst2.lastName = %c\n", st2.lastName);  //student2의 멤버변수 lastName 값 출력('B' 출력)
    printf("st2.studentId = %d\n", st2.studentId);  //student2의 멤버변수 studentId 값 출력('100' 출력)
    printf("st2.grade = %c\n", st2.grade);  //student2의 멤버변수 grade 값 출력('B' 출력)

    student2 st3;  //student2 타입의 st3 선언

    st3=st2;  //st2의 값을 st3에 대입

    printf("\nst3.lastName = %c\n", st3.lastName);  //st2.lastName의 값 출력('B' 출력)
    printf("st3.studentId = %d\n", st3.studentId);  //st2.studentId의 값 출력('100' 출력)
    printf("st3.grade = %c\n", st3.grade);  //st2.grade의 값 출력('B' 출력)
    /*
    if(st3 == st2)  //전체 구조체의 동등성 비교는 불가능
        printf("equal\n");
    else
        printf("not equal\n");
    */
    return 0;
}
