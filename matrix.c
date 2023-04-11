#include <stdio.h>
#include <stdlib.h>

//���õ� �Լ����� ����
void print_matirx(int *arr);
void addition_matrix(int *arr1, int *arr2);
void subtraction_matrix(int *arr1, int *arr2);
//int transpose_matrix(arr);
//int multiply_matrix(arr1, arr2);

int row, col;

void main() {

    printf("[----- [������] [2019068057] -----]\n");

    //����� ��� ���� ���� �Է¹���
    printf("����� �� ���� �Է��Ͻʽÿ�. > ");
    scanf("%d", &row);
    printf("\n����� �� ���� �Է��Ͻʽÿ�. > ");
    scanf("%d", &col);

    //����� �����ϰ� �������� �޸� �Ҵ�
    int* matrixA;
    matrixA = (int*)malloc(sizeof(int) * row * col);
    int* matrixB;
    matrixB = (int*)malloc(sizeof(int) * row * col);

    //��Ŀ� ���� �Է� ���� (���� �� * ���� �� ��ŭ �Է��� �� ������ �� �켱���� ���)
    printf("A����� ���� �Է��Ͻʽÿ�. (�ִ� %d�� �� �Է�)\n�����̽��ٸ� ���� ���ڸ� �����մϴ�.\n(Ex: 2*3 ����϶�, 1 2 3 4 5 6 �Է� �� {1, 2, 3}{4, 5, 6}�� ���\n", row * col);
    for(int i = 0; i < row * col; i++) {
        scanf("%d", &matrixA[i]);
    }

    printf("B����� ���� �Է��Ͻʽÿ�. (�ִ� %d�� �� �Է�)\n�����̽��ٸ� ���� ���ڸ� �����մϴ�.\n", row * col);
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