#include <stdio.h>
#include <stdlib.h>
//Nguyen Duc Hieu -5370-732833
int main() {
    int n;
    printf("Size: ");
    scanf("%d", &n);
    int **matrix1 = (int **)malloc(n * sizeof(int *));//Capphat bonho
    int **matrix2 = (int **)malloc(n * sizeof(int *));//Capphat bonho
    int **sum_matrix = (int **)malloc(n * sizeof(int *));
    int **product_matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
        matrix2[i] = (int *)malloc(n * sizeof(int));
        sum_matrix[i] = (int *)malloc(n * sizeof(int));
        product_matrix[i] = (int *)malloc(n * sizeof(int));
    }
    //Nhập dữ liệu
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    // Tính tổng hai ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    // Tính tích hai ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int element = 0;
            for (int k = 0; k < n; k++) {
                element += matrix1[i][k] * matrix2[k][j];
            }
            product_matrix[i][j] = element;
        }
    }
    printf("Nguyen Duc Hieu -5370-732833\n");
    printf("Tong 2 matran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", sum_matrix[i][j]);
        }
        printf("\n");
    }
    printf("Tich 2 matran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", product_matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(matrix1[i]);        free(matrix2[i]);        free(sum_matrix[i]);        free(product_matrix[i]);
    }
    free(matrix1);    free(matrix2);    free(sum_matrix);    free(product_matrix);
    return 0;
}
