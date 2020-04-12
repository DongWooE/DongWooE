#include <stdio.h>
#include <stdlib.h>
#define Malloc(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "메모리가 충분하지않습니다");\
		exit(EXIT_FAILURE);\
	}

int** create_matrix(int row, int col);  //행렬을 만들어주는 함수
int free_matrix(int**matirx,int row, int col);  //동적할당 해제를 위한 함수
void print_matrix(int **matrix, int row, int col);  //행렬 출력을 위한 함수
int fill_data(int **matrix, int row, int col);  //행렬 원소를 0~19로 정해주는 함수
int addition_matrix(int**matrix_a, int**matrix_b, int**matrix_sum, int row, int col);  //두개의 행렬을 더해주는 함수
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col);  //두개의 행렬을 빼주는 함수
int transpose_matrix(int **matrix, int **matrix_t, int row, int col);  //한 개의 행렬을 전치시켜주는 함수
int multiply_matrix(int**matrix_a, int **matrix_t, int **matrix_axt, int row, int col);  //두개의 행렬을 곱해주는 함수
void func_return(int result);  //함수의 리턴값을 검사 후 문제발생 시 종료하는 함수
int main(void) {
	printf("=====[이동우]=====[2017038069]=====\n");  //이름과 학번 출력
	int row=0,col=0;  //행렬의 행과 열을 변수로 선언 뒤 초기화
	printf("행렬의 행과 열을 입력하세요:\n");  //안내 문구 출력
	int row_index=0,col_index=0;  //while문 반복을 위해 선언
	do{  //음수나 0입력을 거르기 위해 do ~while문을 사용
	printf("row:");
	scanf("%d", &row);  //행 입력
		if(row>0)
			break;  //while문 탈출
		else{
			printf("다시입력하세요(row>0)\n");
			row_index+=1;}//행이 음수나 0이면 안내문구 출력 후 row_index값을 하나 늘림
	}while(row_index<=5);  //5번 진행

	if(row_index>5){  //끝까지 입력이 잘못되면 에러문구 출력 후 함수 종료
		fprintf(stderr, "입력값이 조건을 만족하지 못하므로 함수를 종료합니다");
		return 0;
	}

	do{  //음수나 0, 실수입력을 거르기 위해 do ~while문을 사용
	printf("col:");
	scanf("%d", &col);  //열 입력
		if(col>0)
			break;  //while문 탈출
		else{
			printf("다시입력하세요(col>0)\n");
			 col_index+=1; //열이 음수나 0이면 안내문구 출력 후 col_index값을 하나 늘림
		}
	}while(col_index<=5);  //5번 진행

	if(col_index>5){  //끝까지 입력이 잘못되면 에러문구 출력 후 함수 종료
		fprintf(stderr, "입력값이 조건을 만족하지 못하므로 함수를 종료합니다");
		return 0;
	}
	printf("\n");
	int **pt_A=create_matrix(row,col);  //2차원 배열을 만들어서 이중 포인터 pt_A에 대입
	int **pt_B=create_matrix(row,col);  //2차원 배열을 만들어서 이중 포인터 pt_B에 대입
	func_return(fill_data(pt_A, row, col));  //2차원 배열을 가리키는 포인터 pt_A 안의 원소를 0~19까지의 수로 하는 함수호출 후 비정상적인 문제 검사
	func_return(fill_data(pt_B, row, col));  //2차원 배열을 가리키는 포인터 pt_B 안의 원소를 0~19까지의 수로 하는 함수호출 후 비정상적인 문제 검사
	printf("행렬 A\n");
	print_matrix(pt_A,row,col);  //pt_A가 가리키는 2차원 배열을 출력
	printf("행렬 B\n");
	print_matrix(pt_B,row,col);  //pt_B가 가리키는 2차원 배열을 출력

	printf("행렬 A+B\n");
	int **pt_add=create_matrix(row,col); //새로운 pt_add포인터 선언 후 2차원 배열로 생성
	func_return(addition_matrix(pt_A,pt_B,pt_add,row,col));  //pt_A와 pt_B의 2차원 배열을 더한 값을 pt_add에 대입
	print_matrix(pt_add,row,col);  //pt_add 출력
	printf("동적할당한 덧셈행렬을 공간할당해제합니다\n ");
	free_matrix(pt_add, row, col);  //뒤에서 더 쓸 일이 없으므로 pt_add가 가리키는 공간을 해제
	printf("\n");

	printf("행렬 A-B\n");
	int **pt_sub=create_matrix(row,col);  //새로운 pt_sub포인터 선언 후 2차원 배열로 생성
	func_return(subtraction_matrix(pt_A,pt_B,pt_sub,row,col));  //pt_A와 pt_B의 2차원 배열을 뺀 값을 pt_sub에 대입
	print_matrix(pt_sub,row,col);  //pt_sub 출력
	printf("동적할당한 뺄셈행렬을 공간할당해제합니다\n ");
	free_matrix(pt_sub, row, col);  //pt_sub가 가리키는 공간을 해제
	printf("\n");

	printf("A의 전치행렬\n");
	int **pt_tran=create_matrix(col,row);  //전치행렬을 가리킬 pt_tran포인터 선언 후 2차원 배열로 생성(전치행렬은 원래 행렬의 행과 열이 반대이기때문에 서로 바꿔서 호출)
	func_return(transpose_matrix(pt_A,pt_tran,row,col));  //pt_A의 전치 행렬 pt_tran생성
	print_matrix(pt_tran,col,row);  //pt_tran 출력(출력할 때도 서로 바꿔서 호출)
	printf("\n");

	printf("전치행렬 A의 곱\n");
	int **pt_mul=create_matrix(row,row);  //두 개의 행렬을 곱한 배열을 가리킬 pt_mul포인터 선언 후 2차원 배열로 생성(원래의 행렬과 전치행렬을 곱한 행렬은 결국에는 원래 행렬의 행만큼의 행과 열을 가지게 되기 때문에 row,row로 호출)
	func_return(multiply_matrix(pt_A,pt_tran,pt_mul,row,col));  //두 개의 2차원 배열을 곱한 연산을 pt_mul에 대입
	print_matrix(pt_mul,row,row);  //pt_mul 출력
	printf("\n");

	printf("동적할당한 행렬 A,B,전치,곱셈 의 공간할당해제합니다\n");
	free_matrix(pt_mul, row, row);  //pt_mul 가리키는 공간을 해제
	free_matrix(pt_A, row, col);  //pt_A 가리키는 공간을 해제
	free_matrix(pt_B,row,col);  //pt_B 가리키는 공간을 해제
	free_matrix(pt_tran, col,row );  //pt_tran 가리키는 공간을 해제

}

int** create_matrix(int row, int col){  //행과 열을 인수로 받아 2차원 배열을 만드는 함수

	int**p;  //이중포인터 p 선언
	Malloc(p, row*sizeof(*p));  //매크로함수 Malloc으로 2차원배열의 세로부분에 해당하는 공간을 동적할당
	for(int i =0; i< row; i++)
		Malloc(p[i], col*sizeof(**p));  //위에서 공간을 할당한 2차원배열의 세로부분에 각각 접근하여 2차원배열의 가로부분을 동적할당

	return p;  //2차원 배열을 가리키는 포인터 p 반환
}
int free_matrix(int**matrix,int row, int col){  //인수로 받은 더블 포인터를 동적할당 해제해주는 함수)
	int result=0;  //리턴을 위해 result 선언 후 0으로 초기화
	for(int i=0; i< row; i++)  //먼저 2차원 배열의 세로부분의 공간을  해제
		free(matrix[i]);

	free(matrix);  //전체 매트릭스 공간을 해제
	if(matrix==NULL)  //matrix가 null값을 가리킨다면
		result=-1;  //result 값을 -1로
	return result;  //result 리턴
}
int fill_data(int **matrix, int row, int col){  //2차원 배열을 가리키는 포인터로 각각의 원소에 접근하여 0~19까지의 값을 대입
	int result=0;  //리턴을 위해 result 선언 후 0으로 초기화
	for(int a=0; a<row;a++){
		for(int b=0;b<col;b++)
			matrix[a][b]=rand()%20;  //해당 원소에 rand()함수를 사용해 0~19까지의 무작위 수 대입
	}
	if(matrix==NULL){  //matrix가 null값을 가리킨다면
		result=-1;  //result 값을 -1로
	}
		return result;  //result 리넡
}
void print_matrix(int**matrix, int row, int col){  //2차원 배열을 가리키는 포인터로 2차원 배열을 출력하는 함수
	printf("\n===출력합니다===\n");
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			printf(" %3d ", matrix[a][b]);  //해당 원소를 3개의 칸에서 오른쪽 정렬하여 출력
		}
		printf("\n");
	}	printf("\n");
}
int addition_matrix(int**matrix_a, int**matrix_b, int**matrix_sum, int row, int col){  //2개의 2차원 배열의 각각의 원소를 더해서 새로운 2차원 배열에 대입하는 함수
int result=0;  //반환값을 위해 선언 후 0으로 초기화
	for(int a=0; a<row; a++){
		for(int b=0;b<col;b++){
			matrix_sum[a][b]=matrix_a[a][b]+matrix_b[a][b];  //matrix_a의 원소와 matrix_b의 원소를 더한 값을 matrix_sum의 해당 자리에 대입
		}
	}
	if(matrix_sum==NULL)  //matrix_sum이 null값을 가리킨다면
		result=-1;  //result 값을 -1로
	return result;  //result 리턴}
}
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col){  //2개의 2차원 배열의 각각의 원소를 빼서 새로운 2차원 배열에 대입하는 함수
int result=0;  //반환값을 위해 선언 후 0으로 초기화
for(int a=0; a<row; a++){
	for(int b=0;b<col;b++){
		matrix_sub[a][b]=matrix_a[a][b]-matrix_b[a][b];  //matrix_a의 원소와 matrix_b의 원소를 뺀 값을 matrix_sub의 해당 자리에 대입
	}
}
if(matrix_sub==NULL)  //matrix_sub가 null값을 가리킨다면
		result=-1;  //result 값을 -1로
	return result;  //result 리턴
}
int transpose_matrix(int **matrix, int **matrix_t, int row, int col){  //2차원 배열 한 개를 전치시켜주는 함수
int result=0;  //반환값을 위해 선언 후 0으로 초기화
	for(int a=0; a< col; a++)
		for(int b=0; b<row; b++)
			matrix_t[a][b]=matrix[b][a];  //각각의 원소의 자릿수를 서로 바꾸어 matrix_t에 대입

	if(matrix_t==NULL)  //matrix가 null값을 가리킨다면
			result=-1;  //result 값을 -1로
		return result;  //result 리턴
}
int multiply_matrix(int**matrix_a, int **matrix_t, int **matrix_axt, int row, int col){  //2개의 2차원 배열을 서로 곱해주는 함수
int result=0; //반환값을 위해 선언 후 0으로 초기화
	for(int i=0;i<row;i++){
		for(int j=0;j<row;j++){
			int sum=0;  //연산값을 잠시 저장해주는 sum 선언 후 초기화
			for(int k=0;k<col;k++){
				    sum+=matrix_a[i][k]*matrix_t[k][j]; //연산에서 앞에 있는 행렬의 행을 고정하고 열을 움직이고 뒤에 있는 행렬은 열을 고정하고 행을 움직이면서 서로 값을 곱한 값을 sum에 대입
			}
			matrix_axt[i][j]=sum; //일반적으로 두개의 행렬은 곱한 행렬은 앞(연산에서 앞에 있는 행렬) 행렬의 행과 뒷 행렬의 열을 각각 행과 열로 가짐 하지만 지금 경우는 전치행렬이므로 앞 행렬의 행같을 행과 열로 갖게 됨
		}
	}
	if(matrix_axt==NULL)  //matrix_axt가 null값을 가리킨다면
			result=-1;  //result 값을 -1로
		return result;  //result 리턴
}
void func_return(int result){  //함수 내부 포인터가 문제가 있는 지 여부를 확인해주는 함수
	if(result==-1){  //return 값이 -1이면 (함수 내부에서 포인터가 NULL값이면)
		fprintf(stderr, "함수 내에서 문제발생가 발생하여 비정상종료합니다");  //안내문구 출력
		exit(EXIT_FAILURE);  //비정상 죵료
	}
}


