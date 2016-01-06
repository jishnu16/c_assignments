#include <stdio.h>
#include <assert.h>
#include "array_utils.h"

void test_array_util_create(){
	ArrayUtil array = create(6,18);
	assert(array.length == 18);
	assert(array.typeSize == 6);
}

void test_array_utils_areEqual(){
	ArrayUtil array1 = create(6,18);
	ArrayUtil array2 = create(6,18);
	assert(areEqual(array1,array2) == 1);
}
void test_array_util_resize(){

  ArrayUtil util = create(4, 5);
  int * list_array = (int *)(util.base);
  list_array[0] = 2;
  list_array[1] = 4;
  list_array[2] = 8;
  list_array[3] = 16;
  list_array[4] = 32;

  assert(util.length == 5);
  ArrayUtil resized_util = resize(util, 7);
  assert(resized_util.length = 7);

  dispose(util);
}
void test_array_util_findIndex(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 2;
  list_array[1] = 4;
  list_array[2] = 8;
  list_array[3] = 16;

  int value1 = 8;
  int value2 = 16;
	int value3 = 1024;
  assert(findIndex(a, &value1) == 2);
  assert(findIndex(a, &value2) == 3);
  assert(findIndex(a, &value3) == -1);


  dispose(a);
}

int main(void)
{
	test_array_util_create();
	test_array_utils_areEqual();
	test_array_util_resize();
	test_array_util_findIndex();

	return 0;
}
