/*
보초법(sentinel)을 활용하여, insertion_sort의 논리를 간소화하시오. 
array의 0번 index는 데이터를 저장하지 않습니다. 
또한 이 과정을 시각화 하라
*/
#include <stdio.h>
#include <string.h>

void insertion_sort(int a[], int n);
void insertion_sort_sentinel(int a[], int n);
void print_progress(int i, int j);
void print_array(const int a[], int n); 

int main(void){
    int a[11] = {0,4,2,1,6,3,8,7,9,5,10}; 
    int n = 11; 
    insertion_sort_sentinel(a, n); 
    
    puts("sorted array");
    print_array(a, n); 
    return 0;
}


void insertion_sort_sentinel(int a[], int n){
    int i, j, tmp;
    for(int i = 2; i < n; i++){
        tmp = a[i]; 
        a[0] = tmp; 
        
        print_array(a,n); // for visualize
        
        j = i; 
        while(a[j - 1] > tmp){
            a[j] = a[j - 1]; 
            j--; 
        }
        
        print_progress(i, j); // for visualize
        
        a[j] = tmp; 
    }
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
        print_progress(i, j); // for visualize
    }
}


void print_array(const int a[], int n){
    for(int i = 0; i < n; i++) printf("% 3d", a[i]); 
    putchar('\n');
}

void print_progress(int i, int j){
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
    line[end + 1] = '\0';
    printf("%s\n", line); 
}
