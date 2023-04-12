#include <stdio.h>
#include <stdlib.h>

//제시된 함수 선언
void print_matrix(int **input, int row, int col);
void addition_matrix(int **input1, int **input2, int **output);
void subtraction_matrix(int **input1, int **input2, int **output);
void transpose_matrix(int **input, int **output);
void multiply_matrix(int **input1, int **input2, int **output);
void free_matrix(int **arr, int row);

//행렬의 행과 열의 수를 저장할 변수 선언
int row, col;

void main() {

    printf("[----- [이찬희] [2019068057] -----]\n");

    //행렬의 행과 열의 수를 입력받음
    printf("행렬의 행 수를 입력하십시오. > ");
    scanf("%d", &row);
    printf("\n행렬의 열 수를 입력하십시오. (행의 수와 같지 않으면 Multiply matrix를 구할 수 없습니다.)> ");
    scanf("%d", &col);

    //모든 행렬 선언 및 이차원 배열 메모리 동적 할당
    int ma;
    
    int** matrixA;  //A행렬
    matrixA = (int**)malloc(sizeof(int) * row);
    for(ma = 0; ma < row; ma++) {
        matrixA[ma] = (int*)malloc(sizeof(int) * col);
    }

    int** matrixB;  //B행렬
    matrixB = (int**)malloc(sizeof(int) * row);
    for(ma = 0; ma < row; ma++) {
        matrixB[ma] = (int*)malloc(sizeof(int) * col);
    }

    int** matrixAdd;  //Add matrix A+B
    matrixAdd = (int**)malloc(sizeof(int) * row);
    for(ma = 0; ma < row; ma++) {
        matrixAdd[ma] = (int*)malloc(sizeof(int) * col);
    }

    int** matrixSub;  //Subtract matrix A-B
    matrixSub = (int**)malloc(sizeof(int) * row);
    for(ma = 0; ma < row; ma++) {
        matrixSub[ma] = (int*)malloc(sizeof(int) * col);
    }

    int** matrixT;  //Transpose matrix T
    matrixT = (int**)malloc(sizeof(int) * col);  //전치행렬은 m*n 행렬을 n*m행렬로 위치를 바꾸는 행렬이기에 동적 메모리 할당에서 row와 col 위치 변경
    for(ma = 0; ma < row; ma++) {
        matrixT[ma] = (int*)malloc(sizeof(int) * row);
    }

    if(row==col) {
        int** matrixMul;  //Multiply matrix A×B
        matrixMul = (int**)malloc(sizeof(int) * row);
        for(ma = 0; ma < row; ma++) {
            matrixMul[ma] = (int*)malloc(sizeof(int) * col);
        }
    }
    
    //반복문을 통해 A행렬, B행렬에 값을 입력 받음
    //매 행과 열을 표시하며 하나씩 값을 입력 받음
    int ir, ic;  //값을 입력받는 반복문에 사용할 변수
    for(ir = 0; ir < row; ir++) {  //매 행마다
        for(ic = 0; ic < col; ic++) {  //매 열마다
            printf("A행렬 %d행 %d열의 값을 입력하십시오.\n", ir + 1, ic + 1);
            scanf("%d", &matrixA[ir][ic]);
        }
    }

    for(ir = 0; ir < row; ir++) {  //매 행마다
        for(ic = 0; ic < col; ic++) {  //매 열마다
            printf("B행렬 %d행 %d열의 값을 입력하십시오.\n", ir + 1, ic + 1);
            scanf("%d", &matrixB[ir][ic]);
        }
    }

    //주어진 행렬들을 구현 및 출력
    printf("\nA행렬:\n");
    print_matrix(matrixA, row, col);
    printf("B행렬:\n");
    print_matrix(matrixB, row, col);
    printf("A+B\n");
    addition_matrix(matrixA, matrixB, matrixAdd);
    print_matrix(matrixAdd, row, col);
    printf("A-B\n");
    subtraction_matrix(matrixA, matrixB, matrixSub);
    print_matrix(matrixSub, row, col);
    printf("A행렬의 전치행렬 T\n");
    transpose_matrix(matrixA, matrixT);
    print_matrix(matrixT, col ,row);
    if(row==col) {
        //printf("A×B\n");
        //multiply_matrix(matrixA, matrixB, matrixMul);
        //print_matrix(matrixMul, row, col);
    }

    //행렬들을 생성하기 위해 할당된 메모리를 반환
    free_matrix(matrixA, row);
    free_matrix(matrixB, row);
    free_matrix(matrixAdd, row);
    free_matrix(matrixSub, row);
    free_matrix(matrixT, col);
    //free_matrix(matrixMul, row);
}

//행렬을 출력하는 함수
//각 행마다 각 열을 순서대로 출력
//한 행의 모든 열이 출력되면 줄바꿈
void print_matrix(int **input, int row, int col) {
    int or, oc;  //반복문에 사용될 변수 선언
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            printf("%d ", input[or][oc]);
        }
        printf("\n");
    }
    printf("\n\n");
}

//Add matrix A+B를 구현하는 함수
//input1과 input2의 같은 위치에 있는 성분을 더하여 output의 같은 위치에 저장
void addition_matrix(int **input1, int **input2, int **output) {
    int or, oc;
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            output[or][oc] = input1[or][oc] + input2[or][oc];
        }
    }
}

//Subtract matrix A-B를 구현하는 함수
//input1과 input2의 같은 위치에 있는 성분을 빼서 output의 같은 위치에 저장
void subtraction_matrix(int **input1, int **input2, int **output) {
    int or, oc;
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            output[or][oc] = input1[or][oc] - input2[or][oc];
        }
    }
}

//Transpose matrix T를 구현하는 함수
//input의 m행의 n열의 값을 output의 n행과 m열에 대입한다
void transpose_matrix(int **input, int **output) {
    int or, oc;
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            output[oc][or] = input[or][oc];
        }
    }
}

void multiply_matrix(int **input1, int **input2, int **output) {
    int or, oc;
    int sum = 0;
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            sum += input1[or][oc] * input2[oc][or];
        }
    }
}

//할당했던 메모리를 해제하는 함수
//input의 row마다 할당했던 메모리를 먼저 반환하고, input의 메모리를 반환한다
void free_matrix(int **input, int row) {
    for(int i = 0; i < row; i++) {
        free(input[i]);
    }
    
    free(input);
}