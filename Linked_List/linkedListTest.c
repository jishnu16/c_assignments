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
	*(int *)value1 = 80;
	void *value2 = malloc(sizeof(int));
	*(int *)value2 = 78;
	void *value3 = malloc(sizeof(int));
	*(int *)value3 = 889;
	void *value4 = malloc(sizeof(int));
	*(int *)value4 = 876;
	add_to_list(&list,value1);
	add_to_list(&list,value2);
	add_to_list(&list,value3);
	add_to_list(&list,value4);
	int result = *(int *)getElementAt(list,0);
	assert(result==80);
	result = *(int *)getElementAt(list,1);
	assert(result==78);
	result = *(int *)getElementAt(list,2);
	assert(result==889);
	result = *(int *)getElementAt(list,3);
	assert(result==876);
	int *resultNull;
	resultNull = (int *)getElementAt(list,-1);
	assert(resultNull==NULL);
	resultNull = (int *)getElementAt(list,4);
	assert(resultNull==NULL);
	resultNull = (int *)getElementAt(list,90);
	assert(resultNull==NULL);
};



int main(){
  test_createList();
  test_add_to_list();
  test_get_last_element();
  test_get_first_element();
  test_add_ten_forEach();
  test_getElementAt();

  return 0;
}
