//Perform the addition, subtraction, multiplication, and transpose operation on the
//Matrices. 


#include <stdio.h>
#define MAX 10
void printMatrix(int rows, int cols, int mat[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}
void addMatrix(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
}
void subtractMatrix(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] - B[i][j];
}
void multiplyMatrix(int r1, int c1, int A[MAX][MAX], int r2, int c2, int B[MAX][MAX], int result[MAX][MAX]) {
    if (c1 != r2) {
        printf("Matrix multiplication not possible! (c1 != r2)\n");
        return;
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void transposeMatrix(int rows, int cols, int mat[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);
    printf("\nEnter elements of Matrix A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);
    printf("\nEnter elements of Matrix B:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);
    if (r1 == r2 && c1 == c2) {
        addMatrix(r1, c1, A, B, result);
        printf("\nMatrix Addition:\n");
        printMatrix(r1, c1, result);
        subtractMatrix(r1, c1, A, B, result);
        printf("\nMatrix Subtraction:\n");
        printMatrix(r1, c1, result);
    } else {
        printf("\nAddition/Subtraction not possible (different dimensions).\n");
    }
    printf("\nMatrix Multiplication:\n");
    multiplyMatrix(r1, c1, A, r2, c2, B, result);
    if (c1 == r2)
        printMatrix(r1, c2, result);
    printf("\nTranspose of Matrix A:\n");
    transposeMatrix(r1, c1, A, result);
    printMatrix(c1, r1, result);
    printf("\nTranspose of Matrix B:\n");
    transposeMatrix(r2, c2, B, result);
    printMatrix(c2, r2, result);
    return 0;
}
