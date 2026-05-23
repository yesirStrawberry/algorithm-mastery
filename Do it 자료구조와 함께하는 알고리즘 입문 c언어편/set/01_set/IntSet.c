#include <stdlib.h>
#include <stdio.h>
#include "IntSet.h"

// typedef struct{
//     int max; // 배열의 크기
//     int num; // 현재 크기
//     int *set; // 배열
// }IntSet;

int init_IntSet(IntSet *s, int max){
    s->set = calloc(max, sizeof(int)); 
    if(s->set == NULL) return -1; 
    s->num = 0; 
    s->max = max; 
    return 1; 
}

/* n이 s에 들어있는지 확인
* return : idx, 검색 실패시 -1 
*/
int is_member(const IntSet *s, int n){
    for(int idx = 0; idx < s->num; idx++){
        if(s->set[idx] == n) return idx; 
    }
    return -1; 
}

int is_full(const IntSet *s){
    return s->num == s->max; 
}

void clear_set(IntSet *s){
    s->num = 0;  
}


int add_ele(IntSet *s, int n){
    if(s->num >= s-> max) return -1; 
    if(is_member(s, n) != -1) return -1; 
    
    s->set[s->num++] = n; 
    
    return 1; 
}

void remove_ele(IntSet *s, int n){
    int idx = is_member(s, n); 
    if(idx != -1){
        // last ele을 삭제할 ele의 idx로 옮김
        s->set[idx] = s->set[--(s->num)]; 
    }
}

int capacity(const IntSet *s){
    return s->max; 
}

int size(const IntSet *s){
    return s->num; 
}

// set s2를 s1에 대입
void assign(IntSet *s1, const IntSet *s2){
    int n = (s1->max < s2->num) ? s1->max : s2->num; 
    for(int i = 0; i < n; i++){
        s1->set[i] = s2->set[i]; 
    }
    s1->num = n; 
}

int is_equal(const IntSet *s1, const IntSet *s2){
    if(s1->num != s2->num) return 0; 
    int s1_idx;
    int s2_idx;
    
    for(s1_idx = 0; s1_idx < s1->num; s1_idx++){
        for(s2_idx = 0; s2_idx < s2->num; s2_idx++){
            if(s1->set[s1_idx] == s2->set[s2_idx]) break; 
        }
        if(s2_idx == s2->num) return 0; 
    }
    return 1; 
}

IntSet* union_set(IntSet *s1, const IntSet *s2, const IntSet *s3){
    assign(s1, s2); 
    for(int s3_idx = 0; s3_idx < s3->num; s3_idx++){
        add_ele(s1, s3->set[s3_idx]); 
    }
    return s1; 
}

// s1에 s2의 모든 원소를 추가하는 함수
IntSet* to_union_set(IntSet *s1, const IntSet *s2){
    for(int s2_idx = 0; s2_idx < s2->num; s2_idx++){
        add_ele(s1, s2->set[s2_idx]); 
    }
    return s1; 
}

IntSet* intersect_set(IntSet* s1, const IntSet *s2, const IntSet *s3){
    assign(s1, s2);  
    
    for(int s3_idx = 0; s3_idx < s3->num; s3_idx++){
        int s3_ele = s3->set[s3_idx];
        remove_ele(s1, s3_ele); 
    }
}

// s1에서 s2에 들어있지 않은 원소를 모두 삭제하는 함수
IntSet* to_intersect_set(IntSet *s1, const IntSet *s2){
    for(int s2_idx; s2_idx < s2->num; s2_idx++){
        int s2_ele = s2->set[s2_idx]; 
        remove_ele(s1, s2_ele); 
    }
    
    return s1; 
}

// s1 = s2-s3
IntSet* difference_set(IntSet *s1, const IntSet *s2, const IntSet *s3){
    assign(s1, s2); 
    for(int s3_idx = 0; s3_idx < s3->num; s3_idx++){
        int s3_ele = s3->set[s3_idx];
        remove_ele(s1, s3_ele); 
    }
    return s1; 
}

IntSet* to_difference_set(IntSet *s1, IntSet *s2){
    for(int s2_idx = 0; s2_idx < s2->num; s2_idx++){
        int s2_ele = s2->set[s2_idx]; 
        remove_ele(s1, s2_ele); 
    }
    return s1; 
}

IntSet* symetric_difference_set(IntSet *s1, const IntSet *s2, const IntSet *s3){
    union_set(s1, s2, s3); 
    for(int s2_idx = 0; s2_idx < s2->num; s2_idx++){
        int s2_ele = s2->set[s2_idx];
        if(is_member(s3, s2_ele) != -1){
            remove_ele(s1, s2_ele); 
        }
    }
    return s1; 
}

// s1이 s2의 부분집합인지 검사
int is_subset(const IntSet *s1, const IntSet *s2){
    if(s1->num > s2->num) return 0; 
    for(int s1_idx; s1_idx < s1->num; s1_idx++){
        if(is_member(s2, s1->set[s1_idx]) == -1) return 0; 
    }
    return 1; 
}

// s1이 s2의 진부분집합인지 검사
int is_subset_proper(const IntSet *s1, const IntSet *s2){
    if(s1->num >= s2->num) return 0; 
    for(int s1_idx; s1_idx < s1->num; s1_idx++){
        if(is_member(s2, s1->set[s1_idx]) == -1) return 0; 
    }
    return 1; 
}


void print_set(const IntSet *s){
    putchar('{');
    for(int i = 0; i < s->num; i++){
        printf(" %d", s->set[i]); 
    }
    putchar('}');
    putchar('\n');
}

void terminate_intSet(IntSet *s){
    if(s->set != NULL){
        free(s->set); 
        s->set = NULL; 
        s->num = s->max = 0; 
    }
}
