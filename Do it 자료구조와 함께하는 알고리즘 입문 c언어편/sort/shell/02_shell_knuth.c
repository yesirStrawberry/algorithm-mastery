/*
shell sort adjust h version
기존의 h를 n/2 부터 h /= 2 로 지우는 방식의 문제 
>> 이전에 했던 정렬을 추가로 더 수행하게 됨
>> h를 서로 배수관계로 두지 않으면 됨

shell이 초기에 낸 알고리즘은 h /= 2 로 update하지만, 
knuth가 서로 배수관계로 설정하지 않은 알고리즘을 제안함 

knuth version은 시간복잡도가 O(n^1.3)라 길래, 이를 실험하기 위한 main 함수 작성
*/

/* 실행결과
n (Size)   | cnt (Comp)      | Time(s)    | k (log_n cnt)
------------------------------------------------------------
1000       | 9655            | 0.0001     | 1.3283    
10000      | 163040          | 0.0016     | 1.3031    
100000     | 3030908         | 0.0261     | 1.2963    
1000000    | 58323070        | 0.3573     | 1.2943    
10000000   | 973131795       | 5.2023     | 1.2840    
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // log 계산을 위해 추가

long long shell_sort_knuth(int a[], int n) {
    long long cnt = 0;
    int i, j, h, tmp;
    for (h = 1; h < n / 9; h = h * 3 + 1); 

    for (; h > 0; h /= 3) {
        for (i = h; i < n; i++) {
            tmp = a[i]; 
            for (j = i; j >= h && a[j - h] > tmp; j -= h) {
                a[j] = a[j - h];
                cnt++; 
            }
            a[j] = tmp; 
        }
    }
    return cnt; 
}

int main() {
    // 데이터 크기를 10배씩 늘려가며 지수 k 변화 관찰
    int test_sizes[] = {1000, 10000, 100000, 1000000, 10000000};
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);

    srand(time(NULL));

    printf("%-10s | %-15s | %-10s | %-10s\n", "n (Size)", "cnt (Comp)", "Time(s)", "k (log_n cnt)");
    printf("------------------------------------------------------------\n");

    for (int t = 0; t < num_tests; t++) {
        int n = test_sizes[t];
        int *arr = (int *)malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++) arr[i] = rand() % 1000000;

        clock_t start = clock();
        long long cnt = shell_sort_knuth(arr, n);
        clock_t end = clock();

        double duration = (double)(end - start) / CLOCKS_PER_SEC;
        
        // k = log(cnt) / log(n) 계산
        double k = log((double)cnt) / log((double)n);

        printf("%-10d | %-15lld | %-10.4f | %-10.4f\n", n, cnt, duration, k);

        free(arr);
    }

    return 0;
}
