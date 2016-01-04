#include <stdlib.h>
#include "array_utils.h"
ArrayUtil create(int typeSize , int length) {
	ArrayUtil array;
	array.base = calloc(length,typeSize);
	array.length = length;
	array.typeSize = typeSize;
	return array;
}

int areEqual(ArrayUtil firstArray,ArrayUtil secondArry) {
	if(firstArray.length == secondArry.length && firstArray.typeSize == secondArry.typeSize)
		  return 1;
	return 0;
}

ArrayUtil resize(ArrayUtil util, int length) {
  ArrayUtil *array = realloc(util.base,length);
   array->length = length;
   return *array;
}
