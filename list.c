#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List *listaLocal = (List *) malloc(sizeof(List));
  if(listaLocal == NULL) EXIT_FAILURE; 

  listaLocal->head = NULL;

  listaLocal->tail = NULL;

  listaLocal->current = NULL;

  return listaLocal;
}

void * firstList(List * list) 
{
  void * datoLocal = NULL;
  
  if(list == NULL)
  {
    return datoLocal;
  }
  else
  {
    if(list->head == NULL)
    {
      return datoLocal;
    }
    else
    {
      datoLocal = list->head->data;

      return datoLocal;
    }
  }
}

void * nextList(List * list) 
{
  void * datoLocal = NULL;
  
  if(list == NULL)
  {
    return datoLocal;
  }
  else
  {
    if(list->current == NULL)
    {
      return datoLocal;
    }
    else
    {
      if(list->current == list->tail)
      {
        return datoLocal;
      }
      else
      {
        datoLocal = list->current->next->data;
        list->current = list->current->next;

        return datoLocal;
      }
    }
  }
}

void * lastList(List * list) 
{
  void * datoLocal = NULL;

  if(list == NULL)
  {
    return datoLocal;
  }
  else
  {
    if(list->tail == NULL)
    {
      return datoLocal;
    }
    else
    {
      list->current = list->tail;
      datoLocal = list->tail->data;
  
      return datoLocal;
    }
  }
}

void * prevList(List * list) 
{
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}