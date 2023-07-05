// 230703 �̱Ը����� ����
/*
��ó���� �����ϰ� i�� i+1 ���ϴ� ��� �����ߴ� -> 

�׷��� �׷��� �־��� �볪���� ������ ���� �� �ִ� �迭���� ��� ������ �װ͵��� �ִ밪���� ���ϱⰡ ����� ->

ã�ƺ��� �����ϰ� i�� i+2�� ���ϸ� ���� �� �ִ� �迭���� ��������ʾƵ� �ȴ�!!!
{2 5 9 7 4} �� �����غ��� ��� ���� ū ���� ���� ���ʿ� ������ �״��� ū ������ �����ϴ� �� �迭�� ��찡 ���̵���
���� ���� �迭�� �ȴ� 

-> �׷��� i�� i+2�� ���Ѵ�~~~~
*/

//  �׷��� bubble�����ϴϱ� �ð��ʰ� ��� , quickSort���ϱ� �ٷ� �Ǳ��� 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h> 

int partition(int* A, int p, int r) { 
    int i, j; 
    int t;

    i = p - 1;
    for (j = p; j < r; j++) { 
        if (A[j] < A[r]) {
            i++;
         
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
  
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}

void quickSort(int* A, int p, int r) {

    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }

}

int main(void) {

    int num;
    int i,j;
    int n;
    int* A;
    int* result;

    scanf("%d", &num);

    if (num <= 0) {
        return 0;
    }

    result = (int*)malloc(sizeof(int) * num);

    if (result == NULL) {
        return 0;
    }

    for (j = 0; j < num; j++) {

        

        scanf("%d", &n);

        if (n <= 0) {
            return 0;
        }
        A = (int*)malloc(sizeof(int) * n);
        if (A == NULL) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }


        quickSort(A, 0, n - 1);

        int max=-9999;
       

        for (int i = 0; i < n - 2; i++) {
            if (A[i + 2] - A[i] > max) // �ٺ��� �̷��� max�� ��ó���� 10�̿��� �ǹ̰� ���ݾ� if (A[i + 2] - A[i] > max) 
                max = A[i + 2] - A[i];
        }



        
        result[j] = max;





      
        free(A);
    }

    for (j = 0; j < num; j++) {
        printf("%d\n", result[j]);
    }
    free(result);
    return 0;
}
