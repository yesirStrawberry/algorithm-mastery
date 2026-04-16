#ifndef ___IntStack
#define ___IntStack

typedef struct{
   int max; // stack 용량
   int ptr; // 현재 채워진 스텍의 개수 
   int* stk; // &st[0]
} IntStack; 

int Initialize(IntStack *s, int max); 

int Push(IntStack *s, int x); 

int Pop(IntStack *s, int *x); 

int Peek(const IntStack *s, int *x); 

void Clear(IntStack *s); 

int Capacity(const IntStack *s); 

int Size(const IntStack *s); 

int IsEmpty(const IntStack *s); 

int IsFull(const IntStack *s); 

int Search(const IntStack *s, int x); 

void print(const IntStack *s); 

void Terminate(IntStack *s); 

#endif 

