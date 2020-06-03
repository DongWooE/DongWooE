# DongWooE
ap1.c

#include <stdio.h>
#include <stdlib.h>

void main(){

    int list[5];  //5개의 인덱스를 가진 list선언
    int *plist[5]={NULL,};  //주소값을 가지는 5개의 인덱스를 가진 배열 포인터 선언, NULL값으로 초기화

    plist[0]=(int*)malloc(sizeof(int));  //0번째 plist를 4byte만큼 heap영역에 동적으로 할당
    list[0]=1;  //0번째 list배열에 1 대입
    list[1]=100;  //1번째 list배열에 100 대입

    *plist[0]=200;  //heap 영역에 할당했던 plist[0]가 가리키는 주소에 200대입

    printf("-----[이동우]-----[2017038069]-----\n");  //이름과 학번 출력
    printf("value of list[0]         = %d\n", list[0]);  //'1'출력
    printf("address of list[0]        = %p\n", &list[0]);  //list[0]의 주소 출력 (=list의 주소)
    printf("value of list          = %p\n", list);  //list 주소 출력(배열의 이름은 곧 배열의 주소)
    printf("address of list(&list)    = %p\n", &list);  //list 주소 출력

    printf("--------------------------------------------------\n\n");
    printf("value of list[1]    = %d\n", list[1]);  //'100' 출력
    printf("address of list[1] = %p\n", &list[1]);  //list[1]의 주소 출력(list주소에 +4byte한 값)
    printf("value of *(list+1) = %d\n", *(list+1));  //list+1에 들어있는 값이므로 '100'출력
    printf("address of list+1  = %p\n", list+1);  //list+1의 주소 출력(=list[1]의 주소 출력)

    printf("--------------------------------------------------\n\n");

    printf("value of *plist[0] =%d\n", *plist[0]);  //'200'출력
    printf("&plist[0]             = %p\n", &plist[0]);  //plist[0]의 주소출력(=plist의 주소)
    printf("&plist             = %p\n", &plist);  //plist의 주소 출력
    printf("plist                 = %p\n", plist);  //plist의 주소 출력(배열의 이름이 곧 배열의 주소)
    printf("plist[0]             = %p\n", plist[0]);  //plist 배열의 0번째 들어있는 주소 출력
    printf("plist[1]             = %p\n", plist[1]);  //NULL 값 출력(이전에 NULL값으로 초기화했으므로)
    printf("plist[2]             = %p\n", plist[2]);  //NULL 값 출력
    printf("plist[3]             = %p\n", plist[3]);  //NULL 값 출력
    printf("plist[4]             = %p\n", plist[4]);  //NULL 값 출력

    free(plist[0]);  //동적으로 할당되어있던 plist[0]의 공간을 돌려줌
}