#ifndef INT_SET_H
#define INT_SET_H

typedef struct{
    int max; 
    int num; 
    int *set; 
}IntSet; 


int init_IntSet(IntSet *s, int max);

int is_member(const IntSet *s, int n);

int is_full(const IntSet *s);

void clear_set(IntSet *s);

int add_ele(IntSet *s, int n);

void remove_ele(IntSet *s, int n);

int capacity(const IntSet *s);

int size(const IntSet *s);

void assign(IntSet *s1, const IntSet *s2);

int is_equal(const IntSet *s1, const IntSet *s2);

IntSet* union_set(IntSet *s1, const IntSet *s2, const IntSet *s3);

IntSet* to_union_set(IntSet *s1, const IntSet *s2);

IntSet* intersect_set(IntSet* s1, const IntSet *s2, const IntSet *s3);

IntSet* to_intersect_set(IntSet *s1, const IntSet *s2);

IntSet* difference_set(IntSet *s1, const IntSet *s2, const IntSet *s3);

IntSet* to_difference_set(IntSet *s1, IntSet *s2);

IntSet* symetric_difference_set(IntSet *s1, const IntSet *s2, const IntSet *s3);

int is_subset(const IntSet *s1, const IntSet *s2);

int is_subset_proper(const IntSet *s1, const IntSet *s2);

void print_set(const IntSet *s); 

void terminate_intSet(IntSet *s); 

#endif
