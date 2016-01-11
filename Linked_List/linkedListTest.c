#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "linkedList.h"

void test_createList(){
    LinkedList list;
    list = createList();

    assert(NULL == list.last);
    assert(list.first == NULL);
    assert(list.length == 0);

}

int main(){
  test_createList();

  return 0;
}
