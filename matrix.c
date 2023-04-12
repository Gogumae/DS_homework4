#include <stdio.h>
#include <stdlib.h>

//제시된 함수 선언
void print_matrix(int **arr);
void addition_matrix(int **arr1, int **arr2);
void subtraction_matrix(int **arr1, int **arr2);
void transpose_matrix(int **arr);
void multiply_matrix(int **arr1, int **arr2);

//행렬의 행과 열의 수를 저장할 변수 선언
int row, col;

void main() {

    printf("[----- [이찬희] [2019068057] -----]");

    //행렬의 행과 열의 수를 입력받음
    printf("행렬의 행 수를 입력하십시오. > ");
    scanf("%d", &row);
    printf("\n행렬의 열 수를 입력하십시오. > ");
    scanf("%d", &col);

    //행렬 선언 및 이차원 배열 메모리 동적 할당
    int** matrixA;
    matrixA = (int**)malloc(sizeof(int) * row);
    for(int a = 0; a < row; a++) {
        matrixA[a] = (int*)malloc(sizeof(int) * col);
    }

    int** matrixB;
    matrixB = (int**)malloc(sizeof(int) * row);
    for(int b = 0; b < row; b++) {
        matrixB[b] = (int*)malloc(sizeof(int) * col);
    }


}
