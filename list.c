#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
  void *data;
  Node *next;
  Node *prev;
};

struct List {
  Node *head;
  Node *tail;
  Node *current;
};

typedef List List;

Node *createNode(void *data) {
  Node *new = (Node *)malloc(sizeof(Node));
  assert(new != NULL);
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

List *createList() {

  List *list = malloc(sizeof(List));

  list->head = NULL;
  list->current = NULL;
  list->tail = NULL;

  return list;
}

void *firstList(List *list) {

  if (list->head == NULL)
    return NULL;

  list->current = list->head;

  return list->current->data;
}

void *nextList(List *list) {

  if (list->current == NULL)
    return NULL;

  list->current = list->current->next;

  if (list->current == NULL)
    return NULL;

  return list->current->data;
}

void *lastList(List *list) {
  Node *current = list->head;
  Node *last = NULL;
  while (current != NULL) {
    last = current;
    current = current->next;
  }

  list->current = last;

  return last->data;
}

void *prevList(List *list) {
  if (list->current == NULL)
    return NULL;

  list->current = list->current->prev;

  if (list->current == NULL)
    return NULL;

  return list->current->data;
}

void pushFront(List *list, void *data) {
  Node *new = createNode(data);

  if (list->head == NULL) {
    list->head = new;
    list->tail = new;
    return;
  }

  list->head->prev = new;

  new->next = list->head;
  list->head = new;
}

void pushBack(List *list, void *data) {
  list->current = list->tail;
  pushCurrent(list, data);
}

void pushCurrent(List *list, void *data) {
  
  Node* new = createNode(data);

  Node* current = list->current;

  new->next = current->next;
  new->prev = current;

  if (current->next == NULL)
    printf("HELLO\n");

  current->next->prev = new;
  current->next = new;
  
}

void *popFront(List *list) {
  list->current = list->head;
  return popCurrent(list);
}

void *popBack(List *list) {
  list->current = list->tail;
  return popCurrent(list);
}

void *popCurrent(List *list) { return NULL; }

void cleanList(List *list) {
  while (list->head != NULL) {
    popFront(list);
  }
}