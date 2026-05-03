/*
p.182 Q7
Tower of Hanoi를 비재귀적으로 구현하라. 
*/
#include <stdio.h>

typedef struct{
    int n; 
    int s; 
    int e; 
    int is_print_ready; 
}Node; 

void move(int n, int s, int e); 

void print_node(Node *x);

void move_iterative;

int main()
{
    int n; 
    printf("n : "); scanf("%d", &n); 
    move(n,1,3); 
    printf("-----------------------------\n");
    move_iterative(n,1,3);
    return 0;
}


void move(int n, int s, int e){
    int m = 6 - s - e; 
    if(n > 1) move(n - 1, s, m); 
    printf("원반[%d] : %d -> %d\n",n, s, e);
    if(n > 1) move(n - 1, m, e); 
}


void print_node(Node *x){
    printf("원반[%d] : %d -> %d\n",x->n, x->s, x->e); 
}



void move_iterative(int n, int s, int e){
    Node stack[100];
    int top = -1;
    int m; 
    stack[++top] = (Node){n, s, e, 0}; 
    while(top != -1){
        Node curr = stack[top--]; 
        if(curr.n == 1 || curr.is_print_ready == 1) {
            print_node(&curr);
            continue; 
        }
        
        m = 6 - curr.s - curr.e;
        stack[++top] = (Node){curr.n - 1, m, curr.e, 0};
        stack[++top] = (Node){curr.n, curr.s, curr.e, 1};
        stack[++top] = (Node){curr.n - 1, curr.s, m, 0};
    }
    
}
