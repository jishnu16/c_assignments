#include <stdlib.h>
#include <string.h>
#include "array_utils.h"

ArrayUtil create(int typeSize , int length) {
	ArrayUtil array;
	array.base = calloc(length,typeSize);
	array.length = length;
	array.typeSize = typeSize;
	return array;
}

int areEqual(ArrayUtil array1, ArrayUtil array2){
  char *list_of_array1 = (char *)array1.base;
  char *list_of_array2 = (char *)array2.base;
  if(array1.typeSize != array2.typeSize || array1.length != array2.length)
    return 0;
	else{
	  for(int i = 0; i < array1.length; i++){
	    if(list_of_array1[i] != list_of_array2[i])
	      return 0;
			}
  }
  return 1;
}

ArrayUtil resize(ArrayUtil util,int length){
	util.base = realloc(util.base,util.typeSize*length);
	return util;
}

void dispose(ArrayUtil array){
  free(array.base);
}

int findIndex(ArrayUtil util, void *element){
  char *list = (char *)util.base;
  for(int i = 0; i < util.length; i++){
    if(memcmp(list, element, util.typeSize) == 0)
      return i;
    list += util.typeSize;
  }
  return -1;
}
