/*
삽입정렬을 수행하는 insertion_sort 함수를 작성하라
또한 이 과정을 시각화 하라
*/
#include <stdio.h>
#include <string.h>

void insertion_sort(int a[], int n);
void print_progress(int i, int j);
void print_progress_repectoring(int i, int j);
void print_array(const int a[], int n); 

int main()
{
    int a[10] = {4,2,1,6,3,8,7,9,5,10}; int n = 10; 
    insertion_sort(a, n); 
    
    puts("sorted array");
    print_array(a, n); 
    return 0;
}


void insertion_sort(int a[], int n){
    int i, j, tmp; 
    for(i = 1; i < n; i++){
        print_array(a,n); // for visualize
        tmp = a[i];
        for(j = i; j > 0 && a[j - 1] > tmp; j--){
            a[j] = a[j - 1]; 
        }
        a[j] = tmp; 
        print_progress_repectoring(i, j); // for visualize
    }
}

void print_array(const int a[], int n){
    for(int i = 0; i < n; i++) printf("% 3d", a[i]); 
    putchar('\n');
}
void print_progress(int i, int j){
    if(i == j){
        for(int k = 0; k < i; k++){
            printf("   "); 
        }
        printf("  +");
        putchar('\n');
        return; 
    }
    
    for(int k = 0; k < j; k++)printf("   "); 
    printf("^--"); 
    for(int k = j + 1; k < i; k++){
        printf("---");
    }
    printf("--+");
    putchar('\n');
}

void print_progress_repectoring(int i, int j){
    char line[100]; 
    memset(line, ' ', sizeof(line)); 
    int start = 3 * j + 2; 
    int end = 3 * i + 2; 
    
    if(i == j){
        line[end] = '+'; 
    }
    else{
        line[start] = '^'; 
        for(int k = start + 1; k < end; k++) line[k] = '-'; 
        line[end] = '+';
    }
    printf("%s\n", line); 
}
