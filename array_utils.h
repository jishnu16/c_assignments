#include <stdio.h>
typedef struct array{
	void * base;
	int length;
	int typeSize;
} ArrayUtil;


ArrayUtil create(int,int);
int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil resize(ArrayUtil,int);
