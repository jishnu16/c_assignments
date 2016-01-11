#include <stdio.h>
#include <stdLib.h>
#include "linkedList.h"

void initialize(LinkedList *list){
    list -> first = NULL;
    list -> last = NULL;
    list -> length = 0;
}
LinkedList createList(void){
    LinkedList list;
    initialize(&list);
    return list;
}

// void initializeNode(Node *node){
//     node -> previous = NULL;
//     node -> next = NULL;
// }
