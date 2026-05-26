/*
책에는 없지만, 함수를 call하는 것이 stack에 쌓는 것이니, 
stack을 이용하면 같은 방식으로 구현할 수 있지 않을까라는 생각에서 출발

stack을 이용하니, split 시기와 merge 시기의 구분이 필요함
이를 위해 stack의 node에 state를 넣어 구현
*/

#include <stdio.h>
#include <stdlib.h>

int mergesort(int a[], int n){
    typedef struct{
        int left; 
        int right; 
        int state; 
    }node; 
    node st[100]; int top =  -1;
    
    int* buff = calloc(n, sizeof(int)); 
    if(buff ==  NULL) return -1; 
    
    st[++top] = (node){0, n - 1, 0};
    
    while(top > -1){
        printf("top : %d\n", top); 
        node* curr = &st[top]; 
        
        if(curr->left >= curr->right){
            top--; continue; 
        }
        
        int center = (curr->right + curr->left) / 2; 
        
        if(curr->state == 0){
            curr->state = 1; 
            st[++top] = (node){curr->left, center, 0};
            st[++top] = (node){center + 1, curr->right, 0};
            continue;     
        }
        else{
            int i = curr->left, j = 0, p = 0, k = curr->left; 
            while(i <= center){
                buff[p++] = a[i++];
            }
            while(i <= curr->right && j < p){
                a[k++] = (buff[j] <= a[i]) ? 
                         buff[j++] : a[i++]; 
            }
            while(j < p){
                a[k++] = buff[j++];
            }
            top--; 
        }
    }
    
    free(buff);
    return 0; 
}

int main()
{
    int a[] = {5, 6, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3}; 
    int n = sizeof(a)/ sizeof(a[0]);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    
    mergesort(a, n); 
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}
