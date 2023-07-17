// 백준 1027
/*
착각했던거: 제일 큰 빌딩에서 좌우 순으로 작은 빌딩이 순서대로 있으면 접하지 않는거라고 생각함 
그래서 예제를 계속 이해못함

-> 그림 그려서 확인하니 기울기 이용해야 할 것 같다 
근데 기울기는 좌표 필요한데 2차원 동적할당 이용하나?
 
 기울기 = y증가량 / x증가량 

 왼쪽에서 셀 수 있는거 오른쪽에서 셀 수 있는거 따로 나누자 

 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int left(int i, int* arr) {
    int count = 0;
    double min = 1000000000; //틀려서 마지막 테스트 케이스를 보니 숫자가 커서 max,min,m을 double로 바꾸니까 됨 
    int x = i - 1;
    for (int j = i - 1; j >= 0; j--) { // 평소하던대로 0부터 ~까지 로 반복문쓰면 안된다 
        double m = (double)(arr[i] - arr[j]) / (i - j);
        if (m < min) {
            min = m;
            count++;
        }
    }
    return count;
}

int right(int i, int* arr, int n) { // 여기 같은 경우에는 끝이 필요해서 매개변수 n이 쓰임 
    int count = 0;
    double max = -1000000000;
    int x = i + 1;
    for (int j = i + 1; j < n; j++) {
        double m = (double)(arr[j] - arr[i]) / (j - i);
        if (m > max) {
            max = m;
            count++;
        }
    }
    return count;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = -1;
    for (int i = 0; i < n; i++) {
        int c1 = left(i, arr);
        int c2 = right(i, arr, n);
        int total = c1 + c2;
        if (total > max)
            max = total;
    }
    printf("%d", max);

    free(arr);
    return 0;
}
