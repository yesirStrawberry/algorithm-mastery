#include "str_kmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kmp_match(const char txt[], const char pat[]){
    size_t px = 0; 
    size_t tx = 1; 
    int *skip = calloc(str_len(pat) + 1, sizeof(int)); 
    
    // skip 작성
    skip[0] = 0;
    while(pat[tx] != '\0'){
        if(pat[tx] == pat[px]){
            tx++; 
            px++; 
            skip[tx] = px; 
        }else if(px == 0){
            tx++;
            skip[tx] = 0; 
        }else{
            px = skip[px];
        }
    }
    
    // 검색 시작
    tx = px = 0; 
    while(txt[tx] != '\0' && pat[px] != '\0'){
        print_progress(txt, pat, tx, px);
        if(txt[tx] == pat[px]){
            tx++; px++;
        }else if(px == 0){
            tx++; 
        }else{
            px = skip[px];
        }
    }
    
    free(skip);
    if(pat[px] == '\0') return tx - px; 
    else return -1; 
}

int print_progress(const char txt[], const char pat[], int t_idx, int p_idx){
    int idx; 
    char mat_line[100]; 
    memset(mat_line, ' ', sizeof(mat_line));
    char pat_line[100]; 
    memset(pat_line, ' ', sizeof(pat_line));
    
    printf("%02d ", t_idx - p_idx);
    printf("%s\n", txt); 
    
    mat_line[t_idx + 3] = (txt[t_idx] == pat[p_idx]) ? '+' : '|';
    mat_line[t_idx + 3 + 1] = '\0';
    printf("%s\n", mat_line); 
    
    for(idx = 0; pat[idx] != '\0'; idx++){
        pat_line[t_idx - p_idx + idx + 3] = pat[idx];
    }
    pat_line[t_idx - p_idx + idx + 3 + 1] = '\0';
    printf("%s\n\n", pat_line); 
    return 0;
}

int str_len(const char *s){
    int idx = 0;
    while(s[idx] != '\0') idx++;
    return idx;
}
