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

    printf("[----- [������] [2019068057] -----]\n");

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
    
    //�ݺ����� ���� ��Ŀ� ���� �Է� ����
    //i[a/b][r/c] = Input [matrixA/matrixB] [Row/Column]
    for(int iar = 0; iar < row; iar++) {  //�� �ึ��
        for(int iac = 0; iac < col; iac++) {  //�� ������
            printf("A��� %d�� %d���� ���� �Է��Ͻʽÿ�.\n", iar + 1, iac + 1);
            scanf("%d", &matrixA[iar][iac]);
        }
    }

    for(int ibr = 0; ibr < row; ibr++) {  //�� �ึ��
        for(int ibc = 0; ibc < col; ibc++) {  //�� ������
            printf("B��� %d�� %d���� ���� �Է��Ͻʽÿ�.\n", ibr + 1, ibc + 1);
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
