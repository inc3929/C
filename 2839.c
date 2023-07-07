// 백준2839  230705
/*
중복조합 문제 그래서 문해기 6주 과제 hw3 돈 문제 이용함 

고민했던거:
Q) 3과5로 만들 수 있는 수 인지 없는 수 인지를 어떻게 구하나?
A) 이걸 입력하자마자 판단해야 하나 고민했는데 그냥 min이 초기값과 같은지를 확인하면 그럴 필요가 없었다.

초기에 버킷사이즈와 k를 n/3으로했는데 디버깅 에러발생 

min은 새로뽑은 경우에서 빠뀔 수 있으니까 메인에서 포인터로 선언해서 사용 그러면 void여서 반환값없는
pick에서 구해도 메인에서 최종꺼만 출력가능하니까 

sum은 result랑 같은지 확인하려고 둔거 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int* min, int sum) {

    int i, lastIndex, smallest, result = 0, count = 0;

    lastIndex = bucketSize - k - 1;

    for (i = 0; i <= lastIndex; i++) // 지금까지 뽑은 금액 총 그램수 구하기
        result += items[bucket[i]];

    if (result == sum) {
        for (i = lastIndex; i >= 0; i--) {
            count++;
        }

        if (count < *min)
            *min = count;

        return;
    }
    else if (result > sum)
        return;

    if (bucketSize == k)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (i = smallest; i < itemSize; i++) {
        bucket[lastIndex + 1] = i;
        pick(items, itemSize, bucket, bucketSize, k - 1, min, sum);
    }
}

int main(void) {
    int items[2] = { 3, 5 };
    int n;
    int min = 9999;
    scanf("%d", &n);

    int* bucket = (int*)malloc(sizeof(int) * (n + 1));

    if (bucket == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 1;
    }

    for (int i = 0; i <= n; i++) {
        bucket[i] = 0; 
    }

    int sum = n;
    pick(items, 2, bucket, n + 1, n + 1, &min, sum);
    if (min == 9999)
        printf("-1");
    else
        printf("%d", min);

    free(bucket);

    return 0;
}
