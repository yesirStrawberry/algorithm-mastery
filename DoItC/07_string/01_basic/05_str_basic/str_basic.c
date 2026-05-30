#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "str_basic.h"

int str_len(const char *s){
    int idx = 0;
    while(s[idx] != '\0') idx++;
    return idx;
}

char *str_chr(const char *s, int c){
    int idx = 0;
    c = (char)c;
    while(s[idx] != c){
        if(s[idx] == '\0') return NULL;
        idx++;
    }
    return (char *)(s + idx);
}

char *str_rchr(const char *s, int c){
    int idx = str_len(s);
    c = (char)c;
    while(idx >= 0){
        if(s[idx] == c) return (char *)(s + idx);
        idx--;
    }
    return NULL;
}

int str_cmp(const char *s1, const char *s2){
    while(*s1 == *s2){
        if(*s1 == '\0') return 0;
        s1++; s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int str_ncmp(const char *s1, const char *s2, size_t n){
    while(n-- > 0){
        if(*s1 == '\0' || *s1 != *s2) 
            return (unsigned char)*s1 - (unsigned char)*s2;
        s1++; s2++;
    }
    return 0;
}

int str_cmpic(const char *s1, const char *s2){
    unsigned char c1, c2;
    do {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;
        if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
        if(c2 >= 'A' && c2 <= 'Z') c2 += 32;
        if(c1 == '\0' || c1 != c2) break;
    } while(1);
    return (int)c1 - (int)c2;
}

int str_ncmpic(const char *s1, const char *s2, size_t n){
    unsigned char c1, c2;
    while(n > 0){
        c1 = (unsigned char)*s1;
        c2 = (unsigned char)*s2;
        if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
        if(c2 >= 'A' && c2 <= 'Z') c2 += 32;
        if(c1 == '\0' || c1 != c2) break;
        s1++; s2++; n--;
    }
    return (int)c1 - (int)c2;
}

void swap_ptr(char **x, char **y){
    char *tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_str(char *x, char *y){
    char tmp[6];
    int len_x = str_len(x);
    int len_y = str_len(y);
    memcpy(tmp, x, len_x + 1);
    memcpy(x, y, len_y + 1);
    memcpy(y, tmp, len_x + 1);
}

void str_dump(const char *s){
    do {
        printf("%c: ", *s);
        for(int i = CHAR_BIT - 1; i >= 0; i--)
            putchar(((*s >> i) & 1U) ? '1' : '0');
        printf(" [%02X]\n", (unsigned char)*s);
    } while(*s++ != '\0');
}
