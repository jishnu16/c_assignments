#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "linkedList.h"

void test_createList(){
    LinkedList list;
    list = createList();

    assert(list.last == NULL);
    assert(list.first == NULL);
    assert(list.length == 0);
}


void test_get_first_element(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 400;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	assert(list.length ==4);
	int *first_element=(int *)get_first_element(list);
	assert(*first_element==100);
};

void test_add_to_list(){
  LinkedList list = createList();
  void *data =  malloc(sizeof(int));
  *(int *)data=8;

  int length = add_to_list(&list,data);
  assert(length==1);
  assert(list.length==1);
  assert(*(int *)list.first->element==8);
  assert(list.first->next==NULL);
  assert(list.last->next==NULL);

  void *value2 =  malloc(sizeof(int));
  *(int *)value2=10;
  length =  add_to_list(&list,value2);
  assert(length==2);
  assert(list.length==2);

  void *value3 =  malloc(sizeof(int));
  *(int *)value3 =12;
  length =  add_to_list(&list,value3);
  assert(length==3);
  assert(list.length==3);


};

void test_get_last_element(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 400;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	assert(list.length ==4);
	int *last_element=(int *)get_last_element(list);
	assert(*last_element==400);
};


void add_10(void *element){
	int *value = (int *)element;
	*value = (*value)+10;
}

void test_add_ten_forEach(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 400;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	assert(list.length ==4);
  forEach(list,&add_10);
  int *first_element=(int *)get_first_element(list);
  int *last_element=(int *)get_last_element(list);
  assert(*first_element == 110);
  assert(*last_element == 410);
};

void test_getElementAt(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 400;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	int result = *(int *)getElementAt(list,0);
	assert(result==100);
	result = *(int *)getElementAt(list,1);
	assert(result==200);
	result = *(int *)getElementAt(list,2);
	assert(result==300);
	result = *(int *)getElementAt(list,3);
	assert(result==400);
	int *resultNull;
	resultNull = (int *)getElementAt(list,-1);
	assert(resultNull==NULL);
	resultNull = (int *)getElementAt(list,9000);
	assert(resultNull==NULL);
};

void test_indexOf(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 400;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	assert(indexOf(list,value2)==1);
  assert(indexOf(list,value4)==3);
};

void test_deleteElementAt(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 400;
	void *value5 = malloc(sizeof(int));
	*(int *)value5 = 500;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	add_to_list(&list,value5);

	assert(*(int *)deleteElementAt(&list,4)==500);
	assert(*(int *)list.last->element==400);
	assert(list.length==4);
	assert(*(int *)deleteElementAt(&list,0)==100);
	assert(*(int *)list.last->element==400);
	assert(*(int *)list.first->element==200);
	assert(list.length==3);
	assert(*(int *)deleteElementAt(&list,1)==300);
	assert(*(int *)list.last->element==400);
	assert(*(int *)list.first->element==200);
	assert(list.length==2);
};

void test_asArray(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 400;
	void *value5 = malloc(sizeof(int));
	*(int *)value5 = 500;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	add_to_list(&list,value5);

	void *result[8],*result1[10];
	int arrayLength = asArray(list,result,3);
	assert(arrayLength==3);
	Node *start = list.first;
	for (int i = 0; i < arrayLength; i++){
		assert(*(int *)start->element == *(int *)result[i]);
		start = start->next;
	}
	assert(*(int *)start->element!=*(int *)result[3]);
	arrayLength = asArray(list,result1,10);
	assert(arrayLength==5);
	start = list.first;
	for (int i = 0; i < arrayLength; i++){
		assert(*(int *)start->element == *(int *)result1[i]);
		start = start->next;
	}
};

int isEven(void* hint, void* item){
  if(hint !=0)
	   return !(*(int *)item % 2);
  return 0;
};

int isOdd(void *hint,void *item){
	return !isEven(hint,item);
};

int isDivisibleBy(void* hint, void* item){
	return !(*(int *)item % *(int *)hint);
}

void test_filter(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 399;
	void *value5 = malloc(sizeof(int));
	*(int *)value5 = 405;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	add_to_list(&list,value5);

	void *hint = NULL;
	LinkedList list1 = filter(list,isEven,&hint);
	assert(list1.length==3);
	assert(*(int *)list1.first->element==100);
	assert(*(int *)list1.first->next->element==200);
  assert(*(int *)list1.last->element==300);


	list1 = filter(list,isOdd,&hint);
	assert(list1.length==2);
	assert(*(int *)list1.first->element==399);
	assert(*(int *)list1.last->element==405);

	int divisibleBy = 5;
	list1 = filter(list,isDivisibleBy,&divisibleBy);
	assert(list1.length==4);
	assert(*(int *)list1.first->element==100);
	assert(*(int *)list1.first->next->element==200);
  assert(*(int *)list1.first->next->next->element==300);
	assert(*(int *)list1.last->element==405);
};

void test_reverse(){
	LinkedList list = createList();
	void *value1 = malloc(sizeof(int));
	*(int *)value1 = 100;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 200;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 300;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 400;
	void *value5 = malloc(sizeof(int));
	*(int *)value5 = 500;
  add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	add_to_list(&list,value5);

	LinkedList list1 = reverse(list);
	assert(list1.length==5);
	assert(*(int *)list1.first->element==500);
	assert(*(int *)list1.first->next->element==400);
	assert(*(int *)list1.first->next->next->element==300);
	assert(*(int *)list1.first->next->next->next->element==200);
  assert(*(int*)list1.last->element == 100);
};
