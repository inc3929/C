// 230703 백준11497
/*
맨처음에 정렬하고 i랑 i+1 비교하는 방법 선택했다 -> 

그런데 그러면 주어진 통나무를 가지고 만들 수 있는 배열들을 모두 생각해 그것들의 최대값들을 구하기가 힘들다 ->

찾아보니 정렬하고 i랑 i+2랑 비교하면 만들 수 있는 배열들을 고려하지않아도 된다!!!
{2 5 9 7 4} 를 생각해보면 가운데 가장 큰 수가 오고 양쪽에 번갈아 그다음 큰 수들이 오게하니 이 배열의 경우가 난이도가
가장 작은 배열이 된다 

-> 그래서 i랑 i+2를 비교한다~~~~
*/

//  그런데 bubble정렬하니까 시간초과 뜬다 , quickSort쓰니까 바로 되긴함 
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
            if (A[i + 2] - A[i] > max) // 바보니 이러면 max가 맨처음에 10이여서 의미가 없잖아 if (A[i + 2] - A[i] > max) 
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
