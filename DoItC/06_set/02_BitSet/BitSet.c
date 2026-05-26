#include <stdio.h>
#include "BitSet.h"

int is_member(BitSet s, int n) {
	return s & SetOf(n); 
}

void add_bset(BitSet *s, int n) {
	*s |= SetOf(n); 
}

void remove_bset(BitSet* s, int n) {
	*s &= ~SetOf(n); 
}

int size_bset(const BitSet s) {
	int n = 0; 
	int bs = s; 
	for (; bs != BitSetNull; bs &= bs - 1) {
		n++; 
	}
	return n; 
}

void print_bset(const BitSet s) {
	printf("{"); 
	for (int i = 0; i < BitSetBits; i++) {
		if (is_member(s, i)) printf(" %d", i); 
	}
	printf("}\n"); 
}
