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

    printf("[----- [이찬희] [2019068057] -----]\n");

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
    
    //반복문을 통해 행렬에 값을 입력 받음
    //i[a/b][r/c] = Input [matrixA/matrixB] [Row/Column]
    for(int iar = 0; iar < row; iar++) {  //매 행마다
        for(int iac = 0; iac < col; iac++) {  //매 열마다
            printf("A행렬 %d행 %d열의 값을 입력하십시오.\n", iar + 1, iac + 1);
            scanf("%d", &matrixA[iar][iac]);
        }
    }

    for(int ibr = 0; ibr < row; ibr++) {  //매 행마다
        for(int ibc = 0; ibc < col; ibc++) {  //매 열마다
            printf("B행렬 %d행 %d열의 값을 입력하십시오.\n", ibr + 1, ibc + 1);
            scanf("%d", &matrixB[ibr][ibc]);
        }
    }

    print_matrix(matrixA);
    print_matrix(matrixB);
}

void print_matrix(int **arr) {
    for(int or = 0; or < row; or++) {
        for(int oc = 0; oc <col; oc++) {
            printf("%d ", arr[or][oc]);
        }
        printf("\n");
    }
    printf("\n\n");
}
