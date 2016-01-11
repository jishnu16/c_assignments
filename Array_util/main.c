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
  int * array = (int *)(util.base);
  array[0] = 2;
  array[1] = 4;
  array[2] = 8;
  array[3] = 16;
  array[4] = 32;

  assert(util.length == 5);
  ArrayUtil resized_util = resize(util, 7);
  assert(resized_util.length = 7);

  dispose(util);
}
void test_array_util_findIndex(){
  ArrayUtil util = create(4,5);
  int * array = (int *)(util.base);
  array[0] = 2;
  array[1] = 4;
  array[2] = 8;
  array[3] = 16;

  int value1 = 8;
  int value2 = 16;
	int value3 = 1024;
  assert(findIndex(util, &value1) == 2);
  assert(findIndex(util, &value2) == 3);
  assert(findIndex(util, &value3) == -1);

  dispose(util);
}

void test_array_util_findFirst(){
	ArrayUtil util = create(4,8);
	int *array = (int*)(util.base);
	array[0] = 2;
  array[1] = 4;
  array[2] = 8;
  array[3] = 16;
	array[4] = 18;
	array[5] = 13;
	array[6] = 17;
	array[7] = 37;

	assert(*(int*)findFirst(util,&isEven,NULL)==2);

	int number = 4;
	assert(*(int *)findFirst(util,&isDivisable,&number)==4);

	dispose(util);
}

void test_array_util_findLast(){
	ArrayUtil util =create(4,8);
	int *array = (int*)(util.base);
	array[0] = 2;
  array[1] = 4;
  array[2] = 8;
  array[3] = 16;
	array[4] = 18;
	array[5] = 13;
	array[6] = 17;
	array[7] = 37;


	assert(*(int*)findLast(util,&isEven,NULL)==18);

	int number = 4;

	assert(*(int *)findLast(util,&isDivisable,&number)==16);

	dispose(util);
}

void test_array_util_count(){
	ArrayUtil util = create(4,8);
	int *array = (int *)(util.base);
	array[0] = 2;
  array[1] = 4;
  array[2] = 8;
  array[3] = 16;
	array[4] = 18;
	array[5] = 13;
	array[6] = 17;
	array[7] = 37;

  assert(count(util,&isEven,NULL)==5);

	int number = 4;
	assert(count(util,&isDivisable,&number)==3);
	dispose(util);
}

void test_array_util_filter(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 50;

  ArrayUtil destination = create(4,5);

  assert(filter(a, &isEven, NULL, destination.base, 5 ) == 3 );

	int **new_destination = (int **)destination.base;

  assert(*new_destination[0]==12);
	assert(*new_destination[1]==34);
	assert(*new_destination[2]==50);
}

int main(void)
{
	test_array_util_create();
	test_array_utils_areEqual();
	test_array_util_resize();
	test_array_util_findIndex();
	test_array_util_findFirst();
	test_array_util_findLast();
	test_array_util_filter();

	return 0;
}
