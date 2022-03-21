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
      if(list->current == list->head)
      {
        return datoLocal;
      }
      else
      {
        datoLocal = list->current->prev->data;
        
        list->current = list->current->prev;

        return datoLocal;
      }
    }
  }
}

void pushFront(List * list, void * data) 
{
  Node * nodeHead = createNode(data);

  if(list != NULL)
  {
    if(list->head == NULL)
    {
      list->head = nodeHead;
      
      list->tail = nodeHead;
    }
    else
    {
      list->head->prev = nodeHead;

      nodeHead->next = list->head;

      list->head = nodeHead;
    }
  }
}

void pushBack(List * list, void * data) 
{
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  Node * nodeAdd = createNode(data);

  if(list != NULL)
  {
    if(list->head == NULL)
    {
      list->head = nodeAdd;
      
      list->current = nodeAdd;
      
      list->tail = nodeAdd;
    }
    else
    {
      if(list->current->next == NULL)
      {
        list->current->next = nodeAdd;
        
        nodeAdd->prev = list->current;
        
        list->current = nodeAdd;
        
        list->tail = nodeAdd;
      }
      else
      {
        list->current->next->prev = nodeAdd;
        
        nodeAdd->next = list->current->next;
        
        nodeAdd->prev = list->current;
        
        list->current->next = nodeAdd;
        
        list->current = nodeAdd;
      }
    }
  }
}

void * popFront(List * list) 
{
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) 
{
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) 
{
  void * aux = NULL;

  if(list != NULL)
  {
    if(list->head != NULL)
    {
      if(list->head == list->current)
      {
        aux = list->current;

        list->head = list->head->next;

        list->current = list->head;
        
        free(list->head->prev);

        list->head->prev = NULL;

        return aux->data;
      }
      else
      {
        if(list->tail == list->current)
        {
          aux = list->current->data;

          list->tail = list->tail->prev;

          list->current = list->tail;

          free(list->tail->next);

          list->tail->next = NULL;
          
          return aux;
        }
        else
        {
          Node * nodeAux = (Node *)malloc(sizeof(Node));

          nodeAux = list->current;
          
          aux = list->current->data;

          list->current->prev->next = list->current->next;

          list->current = list->current->next;

          list->current->prev = nodeAux->prev;

          free(nodeAux);

          return aux;
        }
      }
    }
  }
  return aux;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}