#include <stdio.h>

void shell_sort(int a[], int n){
    int i, j, h, tmp; 
    for(int h = n / 2; h > 0; h /= 2){
        for(i = h; i < n; i++){
            tmp = a[i]; 
            for(j = i; j >= h && a[j - h] > tmp; j -= h){
                a[j] = a[j - h]; 
            }
            a[j] = tmp;
        }
    }
}

int main() {
    int arr[] = {22, 5, 11, 32, 120, 68, 70, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    shell_sort(arr, n);

    printf("After sorting:  ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // 정렬 확인 로직
    int success = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            success = 0;
            break;
        }
    }

    if (success) printf("\nResult: Sorting Success!\n");
    else printf("\nResult: Sorting Failed.\n");

    return 0;
}
