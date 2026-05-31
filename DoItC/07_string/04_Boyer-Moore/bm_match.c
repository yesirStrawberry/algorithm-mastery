/**
 * @file bm_match.c
 * @brief Boyer-Moore 알고리즘의 핵심 로직 및 유틸리티 구현부
 */

#include "bm_match.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>

int bm_match(const char txt[], const char pat[]) {
    int tx, px;
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int skip[UCHAR_MAX + 1];

    // skip array setting
    for (px = 0; px < UCHAR_MAX + 1; px++) {
        skip[px] = pat_len;
    }
    
    // last letter은 pat_len - px - 1 제외
    for (px = 0; px < pat_len - 1; px++) {
        skip[(unsigned char)pat[px]] = pat_len - px - 1;
    }
    
    // match start
    tx = pat_len - 1;
    while (tx < txt_len) {
        px = pat_len - 1;
        print_progress(txt, pat, tx, px);
        while (txt[tx] == pat[px]) {
            if (px == 0) return tx; 
            px--;
            tx--; 
            print_progress(txt, pat, tx, px);
        }
        int skip_dist = skip[(unsigned char)txt[tx]];
        int match_dist = pat_len - px;
        
        tx += (skip_dist > match_dist) ? skip_dist : match_dist;
    }
    return -1;
}

char* str_str(const char txt[], const char pat[]){
    int tx, px;
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int skip[UCHAR_MAX + 1];
    if(pat_len == 0) return (char*)txt;

    // skip array setting
    for(px = 0; px < UCHAR_MAX + 1; px++){
       skip[px] = pat_len;
    }
    // last letter은 pat_len - px - 1 제외
    for(px = 0; px < pat_len - 1; px++){
        skip[(unsigned char)pat[px]] = pat_len - px - 1;
    }
    
    // match start
    tx = pat_len - 1;
    while(tx < txt_len){
        px = pat_len - 1;
        while(txt[tx] == pat[px]){
            if(px == 0) return (char*)&txt[tx]; 
            px--;
            tx--; 
        }
        
        if(tx < 0) break; 
        
        int skip_dist = skip[(unsigned char)txt[tx]];
        int match_dist = pat_len - px;
        
        tx += (skip_dist > match_dist) ? skip_dist : match_dist;
    }
    return NULL;
}


int print_progress(const char txt[], const char pat[], int t_idx, int p_idx) {
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
    
    for (idx = 0; pat[idx] != '\0'; idx++) {
        pat_line[t_idx - p_idx + idx + 3] = pat[idx];
    }
    pat_line[t_idx - p_idx + idx + 3 + 1] = '\0';
    printf("%s\n\n", pat_line); 
    return 0;
}
