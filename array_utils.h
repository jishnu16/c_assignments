#include <stdio.h>
typedef struct array{
	void * base;
	int length;
	int typeSize;
} ArrayUtil;

typedef int MatchFunc(void *, void *);

ArrayUtil create(int,int);
int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil resize(ArrayUtil,int);
void dispose(ArrayUtil);
int findIndex(ArrayUtil,void *);
void * findFirst(ArrayUtil,MatchFunc*,void *);
int isEven(void *,void *);
int isDivisable(void *,void *);
void *findLast(ArrayUtil,MatchFunc*,void *);
int count(ArrayUtil,MatchFunc*,void*);
