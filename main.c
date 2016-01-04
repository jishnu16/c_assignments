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

void test_array_utils_resize(){
  ArrayUtil array1 = create(6,18);
  ArrayUtil array2 = resize(array1,8);
  assert(array2.length == 8);
}


int main(void)
{
	test_array_util_create();
	test_array_utils_areEqual();
  test_array_utils_resize();

	return 0;
}
