#include <stdio.h>
typedef struct array{
	void * base;
	int length;
	int typeSize;
} ArrayUtil;

typedef int MatchFunc(void *, void *);
typedef void(ConvertFunc)(void*,void*,void*);
typedef void(OperationFunc)(void*,void*);
typedef void* (ReducerFunc)(void*,void*,void*);

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
int filter(ArrayUtil,MatchFunc*,void*,void** ,int);
void convert_plus(void*, void*, void*);
void map(ArrayUtil source,ArrayUtil,ConvertFunc*,void*);
void operation_minus(void*,void*);
void forEach(ArrayUtil, OperationFunc*, void*);
void* reduce_sum(void*, void*, void*);
void* reduce(ArrayUtil, ReducerFunc*, void*, void*);
