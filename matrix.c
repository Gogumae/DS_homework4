#include <stdio.h>
#include <stdlib.h>

//���õ� �Լ� ����
void print_matrix(int **arr);
void addition_matrix(int **arr1, int **arr2);
void subtraction_matrix(int **arr1, int **arr2);
void transpose_matrix(int **arr);
void multiply_matrix(int **arr1, int **arr2);

//����� ��� ���� ���� ������ ���� ����
int row, col;

void main() {

    printf("[----- [������] [2019068057] -----]");

    //����� ��� ���� ���� �Է¹���
    printf("����� �� ���� �Է��Ͻʽÿ�. > ");
    scanf("%d", &row);
    printf("\n����� �� ���� �Է��Ͻʽÿ�. > ");
    scanf("%d", &col);

    //��� ���� �� ������ �迭 �޸� ���� �Ҵ�
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
