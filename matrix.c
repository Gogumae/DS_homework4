#include <stdio.h>
#include <stdlib.h>

//���õ� �Լ� ����
void print_matrix(int **input, int row, int col);
void addition_matrix(int **input1, int **input2, int **output);
void subtraction_matrix(int **input1, int **input2, int **output);
void transpose_matrix(int **input, int **output);
void multiply_matrix(int **input1, int **input2, int **output);
void free_matrix(int **arr, int row);

//����� ��� ���� ���� ������ �������� ����
int row, col;

void main() {

    printf("[----- [������] [2019068057] -----]\n");

    //����� ��� ���� ���� �Է¹���
    //����� ������ ������ �ϱ� ���ؼ� A��İ� B����� ����� ���ƾ��ϱ⿡ ���� row, col ���� ���
    printf("����� �� ���� �Է��Ͻʽÿ�. > ");
    scanf("%d", &row);
    printf("\n����� �� ���� �Է��Ͻʽÿ�. (���� ���� ���� ������ Multiply matrix�� ���� �� �����ϴ�.)> ");
    scanf("%d", &col);

    //��� ��� ���� �� ������ �迭 �޸� ���� �Ҵ�
    int ma;
    
    int** matrixA;  //A���
    matrixA = (int**)malloc(sizeof(int) * row);
    for(ma = 0; ma < row; ma++) {
        matrixA[ma] = (int*)malloc(sizeof(int) * col);
    }

    int** matrixB;  //B���
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
    matrixT = (int**)malloc(sizeof(int) * col);  //��ġ����� m*n ����� n*m��ķ� ��ġ�� �ٲٹǷ� ���� �޸� �Ҵ翡�� row�� col ��ġ ����
    for(ma = 0; ma < row; ma++) {
        matrixT[ma] = (int*)malloc(sizeof(int) * row);
    }

    int** matrixMul;  //Multiply matrix A��B
    matrixMul = (int**)malloc(sizeof(int) * row);
    for(ma = 0; ma < row; ma++) {
        matrixMul[ma] = (int*)malloc(sizeof(int) * col);
    }
    
    //�ݺ����� ���� A���, B��Ŀ� ���� �Է� ����
    //�� ��� ���� ǥ���ϸ� �ϳ��� ���� �Է� ����
    int ir, ic;  //���� �Է¹޴� �ݺ����� ����� ����
    for(ir = 0; ir < row; ir++) {  //�� �ึ��
        for(ic = 0; ic < col; ic++) {  //�� ������
            printf("A��� %d�� %d���� ���� �Է��Ͻʽÿ�.\n", ir + 1, ic + 1);
            scanf("%d", &matrixA[ir][ic]);
        }
    }

    for(ir = 0; ir < row; ir++) {  //�� �ึ��
        for(ic = 0; ic < col; ic++) {  //�� ������
            printf("B��� %d�� %d���� ���� �Է��Ͻʽÿ�.\n", ir + 1, ic + 1);
            scanf("%d", &matrixB[ir][ic]);
        }
    }

    //�־��� ��ĵ��� ���� �� ���
    printf("\nA���:\n");
    print_matrix(matrixA, row, col);
    printf("B���:\n");
    print_matrix(matrixB, row, col);
    printf("A+B:\n");
    addition_matrix(matrixA, matrixB, matrixAdd);
    print_matrix(matrixAdd, row, col);
    printf("A-B:\n");
    subtraction_matrix(matrixA, matrixB, matrixSub);
    print_matrix(matrixSub, row, col);
    printf("A����� ��ġ��� T:\n");
    transpose_matrix(matrixA, matrixT);
    print_matrix(matrixT, col ,row);
    printf("A��B:\n");
    if(row==col) {
        multiply_matrix(matrixA, matrixB, matrixMul);
        print_matrix(matrixMul, row, col);
    }
    else {
        printf("A����� ���� ���� B����� ���� ���� ���� �ʾ� A��B�� ������ �� �����ϴ�.\n");
    }

    //��ĵ��� �����ϱ� ���� �Ҵ�� �޸𸮸� ��ȯ
    free_matrix(matrixA, row);
    free_matrix(matrixB, row);
    free_matrix(matrixAdd, row);
    free_matrix(matrixSub, row);
    free_matrix(matrixT, col);
    free_matrix(matrixMul, row);
}

//����� ����ϴ� �Լ�
//�� �ึ�� �� ���� ������� ���
//�� ���� ��� ���� ��µǸ� �ٹٲ�
void print_matrix(int **input, int row, int col) {
    int or, oc;  //�ݺ����� ���� ���� ����
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            printf("%d ", input[or][oc]);
        }
        printf("\n");
    }
    printf("\n\n");
}

//Add matrix A+B�� �����ϴ� �Լ�
//input1�� input2�� ���� ��ġ�� �ִ� ������ ���Ͽ� output�� ���� ��ġ�� ����
void addition_matrix(int **input1, int **input2, int **output) {
    int or, oc;
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            output[or][oc] = input1[or][oc] + input2[or][oc];
        }
    }
}

//Subtract matrix A-B�� �����ϴ� �Լ�
//input1�� input2�� ���� ��ġ�� �ִ� ���г��� ������ �Ͽ� output�� ���� ��ġ�� ����
void subtraction_matrix(int **input1, int **input2, int **output) {
    int or, oc;
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            output[or][oc] = input1[or][oc] - input2[or][oc];
        }
    }
}

//Transpose matrix T�� �����ϴ� �Լ�
//input�� m���� n���� ���� output�� n��� m���� �����Ѵ�
void transpose_matrix(int **input, int **output) {
    int or, oc;
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            output[oc][or] = input[or][oc];
        }
    }
}

//Multiply matrix A��B�� �����ϴ� �Լ�
//����� �� A��B�� ���� (m,n)�� A����� m���� ���а� B����� n���� ������ ���� ó������ ���ʴ�� ���� ���� ��� ���� ��
//�ٸ� �Լ��� ���������� or, oc ������ A��B����� ����� output�迭�� �� ������ ����
//input1 �迭���� ���� ����, input2 �迭���� ���� ������ ��, ���ο� ���� o�� ����Ͽ� ������� ��(����)�� ã�� ���Ѵ�
//o�� row���� ���������� (������ ������ �����ϱ� ���� A��İ� B����� ����� �����Ƿ�, ������ �����Ϸ��� row�� col�� ���ƾ��Ѵ�) �ݺ��ϸ鼭 ������ ���� ��� output[oc][or]�� ���Ѵ�
void multiply_matrix(int **input1, int **input2, int **output) {
    int or, oc, o;
    for(or = 0; or < row; or++) {
        for(oc = 0; oc < col; oc++) {
            output[or][oc] = 0;
            for(o = 0; o < row; o++) {
                output[or][oc] += input1[or][o] * input2[o][oc];
            }
        }
    }
}

//�Ҵ��ߴ� �޸𸮸� �����ϴ� �Լ�
//input�� row���� �Ҵ��ߴ� �޸𸮸� ���� ��ȯ�ϰ�, input�� �޸𸮸� ��ȯ�Ѵ�
void free_matrix(int **input, int row) {
    for(int i = 0; i < row; i++) {
        free(input[i]);
    }
    
    free(input);
}