#include <stdio.h>
#include <string.h>
#include "str_match.h"

int bf_match(const char txt[], const char pat[]){
    if(txt[0] == '\0' || pat[0] == '\0') return -1; 
    
    int t_idx = 0; 
    int p_idx = 0; 
    
    while(txt[t_idx] != '\0' && pat[p_idx] != '\0'){
        print_progress(txt, pat, t_idx, p_idx);
        
        if(txt[t_idx] == pat[p_idx]){
            t_idx++; 
            p_idx++; 
        }else{
            t_idx = t_idx - p_idx + 1; 
            p_idx = 0; 
        }
    }
    
    if(pat[p_idx] == '\0') return t_idx - p_idx; 
    else return -1; 
}

int bf_matchr(const char txt[], const char pat[]){
    if(txt[0] == '\0' || pat[0] == '\0') return -1; 
    
    int t_idx = str_len(txt) - 1; 
    int p_idx = str_len(pat) - 1;
    int pat_num = str_len(pat);
    
    while(p_idx >= 0 && t_idx >= 0){
        print_progress(txt, pat, t_idx, p_idx);
        
        if(txt[t_idx] == pat[p_idx]){
            t_idx--;
            p_idx--;
        }else{
            t_idx = t_idx + (pat_num - p_idx - 1 - 1); 
            p_idx = pat_num - 1; 
        }
    }
    if(p_idx < 0) return t_idx + 1; 
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
