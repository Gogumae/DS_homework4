#include <stdio.h>
#include <stdlib.h>

//제시된 함수들을 선언
void print_matirx(int *arr);
void addition_matrix(int *arr1, int *arr2);
void subtraction_matrix(int *arr1, int *arr2);
//int transpose_matrix(arr);
//int multiply_matrix(arr1, arr2);

int row, col;

void main() {

    printf("[----- [이찬희] [2019068057] -----]\n");

    //행렬의 행과 열의 수를 입력받음
    printf("행렬의 행 수를 입력하십시오. > ");
    scanf("%d", &row);
    printf("\n행렬의 열 수를 입력하십시오. > ");
    scanf("%d", &col);

    //행렬을 선언하고 동적으로 메모리 할당
    int* matrixA;
    matrixA = (int*)malloc(sizeof(int) * row * col);
    int* matrixB;
    matrixB = (int*)malloc(sizeof(int) * row * col);

    //행렬에 값을 입력 받음 (행의 수 * 열의 수 만큼 입력할 수 있으며 행 우선으로 취급)
    printf("A행렬의 값을 입력하십시오. (최대 %d개 값 입력)\n스페이스바를 통해 숫자를 구분합니다.\n(Ex: 2*3 행렬일때, 1 2 3 4 5 6 입력 시 {1, 2, 3}{4, 5, 6}인 행렬\n", row * col);
    for(int i = 0; i < row * col; i++) {
        scanf("%d", &matrixA[i]);
    }

    printf("B행렬의 값을 입력하십시오. (최대 %d개 값 입력)\n스페이스바를 통해 숫자를 구분합니다.\n", row * col);
    for(int i = 0; i < row * col; i++) {
        scanf("%d", &matrixB[i]);
    }

    print_matrix(matrixA);
    print_matrix(matrixB);
    addition_matrix(matrixA, matrixB);
}

void print_matrix(int *arr) {

    int fr, fc;

    for(int fr = 0; fr < row * col; fr += col) {
        for(int fc = 0; fc < col; fc++) {
            printf("%d ", arr[fr + fc]);
        }
        printf("\n");
    }
    printf("\n");
}

void addition_matrix(int *arr1, int *arr2) {
    int *addMatrix;
    addMatrix = (int*)malloc(sizeof(int) * row * col);

    for(int i = 0; i < row * col; i++) {
        addMatrix[i] = arr1[i] + arr2[i];
    }

    print_matrix(addMatrix);
}

void subtraction_matrix(int *arr1, int *arr2) {
    int *subMatrix;
    subMatrix = (int*)malloc(sizeof(int) * row * col);

    for(int i = 0; i < row * col; i++) {
        subMatrix[i] = arr1[i] - arr2[i];
    }

    print_matrix(subMatrix);
}