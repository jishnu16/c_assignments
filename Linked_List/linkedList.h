#include <stdio.h>

typedef struct linkedList{
    void *first;
    void *last;
    int length;
}LinkedList;

typedef struct element{
    void *element;
    void *previous;
    void *next;
}Node;

LinkedList createList(void);
