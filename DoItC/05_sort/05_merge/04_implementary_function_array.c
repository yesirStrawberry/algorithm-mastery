#include <stdio.h>
#include <stdlib.h>

typedef struct frame {
    int left, right;
    void (*task)(struct frame* self, int a[], int* buff, struct frame* stack, int* top);
} Frame;

// 함수 원형 선언
void task_split(Frame* self, int a[], int* buff, Frame* stack, int* top);
void task_merge(Frame* self, int a[], int* buff, Frame* stack, int* top);

// 1. 분할 작업 (Split)
void task_split(Frame* self, int a[], int* buff, Frame* stack, int* top) {
    int l = self->left;
    int r = self->right;

    if (l < r) {
        int center = (l + r) / 2;

        // 주의: 스택은 LIFO이므로, 실행하고 싶은 역순으로 Push
        // [3] 병합 작업 예약
        stack[++(*top)] = (Frame){l, r, task_merge};
        // [2] 오른쪽 분할 예약
        stack[++(*top)] = (Frame){center + 1, r, task_split};
        // [1] 왼쪽 분할 예약
        stack[++(*top)] = (Frame){l, center, task_split};
    }
}

// 2. 병합 작업 (Merge)
void task_merge(Frame* self, int a[], int* buff, Frame* stack, int* top) {
    int left = self->left;
    int right = self->right;
    int center = (left + right) / 2;

    int i = left, j = 0, k = left, p = 0;

    // 왼쪽 복사
    while (i <= center) buff[p++] = a[i++];
    
    // 병합 (i는 이미 center + 1)
    while (i <= right && j < p) {
        a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
    }
    while (j < p) a[k++] = buff[j++];
}

int mergesort(int a[], int n) {
    int* buff = (int*)calloc(n, sizeof(int));
    if (!buff) return -1;

    // 스택 준비 (충분한 크기)
    Frame stack[200];
    int top = -1;

    // 최초 작업: 전체 범위에 대한 분할 요청
    stack[++top] = (Frame){0, n - 1, task_split};

    while (top > -1) {
        Frame curr = stack[top--];
        if (curr.task) {
            curr.task(&curr, a, buff, stack, &top);
        }
    }

    free(buff);
    return 0;
}

int main() {
    int a[] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);

    mergesort(a, n);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
