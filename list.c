// list/list.c
//
// Implementation for linked list.
//Worked with Khalil Scott-Shepherd and Jamarri White
//Coded in repl.it for easy testing
// <Keerthana Pullela>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc(){
  list_t* list_new = (list_t*) malloc(sizeof(list_t));
  list_new->head = NULL;
  return list_new;
}

node_t *node_alloc(elem val) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = val;
  new_node->next = NULL;
  return new_node;
}

void list_free(list_t *l){
  node_t *cur = l->head;
  while (cur != NULL){
    node_t *temp_cur = cur->next;
    free(cur);
    cur = temp_cur;
  }
  if(cur == NULL){
    printf("Empty list");
  }
}

char* toString(list_t *l) {
  char temp[250];
}

void node_free(node_t *n) {
  free(n);
}

void list_print(list_t *l){
  node_t *cur = l->head;
  while(cur != NULL) {
    printf("%d ", cur->value);
    cur = cur->next;
  }
  if (cur == NULL){
    printf("Empty list");
  }
}

int list_length(list_t *l){
  int length = 0;
  node_t *cur = l->head;
  while(cur != NULL){
    length++;
    cur = cur->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value){
  node_t *app_val;
  node_t *cur = l->head;
  app_val = node_alloc(value);
  while(cur->next != NULL){
    cur = cur -> next;
  }
  cur -> next = app_val;
  app_val -> next = NULL;
  if (cur == NULL){
    printf("Empty list");
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t *head = malloc(sizeof(node_t));
  head->value = value;
  head->next = l->head;
  l->head = head;
}

void list_add_at_index(list_t *l, elem value, int index){
  int add = 0;
  node_t *cur = l->head;
  node_t *temp = NULL;
  node_t *app_val;
  app_val = node_alloc(value);
  if (index == 0){
    return list_add_to_front(1,value);
  }
  while(add < index){
    temp = cur;
    cur = cur->next;
    add++;
  }
  temp->next = app_val;
  app_val->next = cur;
}

elem list_remove_from_back(list_t *l) { 
  node_t *cur = l->head;
  if (cur == NULL){
    return; 
  }
  while(cur->next != NULL){
    cur = cur->next;
  }
  elem previous = cur->value;
  free(cur);
  return previous;
}

elem list_remove_from_front(list_t *l) { 
  node_t *cur = l->head;
  if(cur == NULL){
    printf("Empty list");
    return ;
  }
  node_t *list_start = l->head;
  elem nextval = l->head->value;
  list_start = l->head;
  l->head = l->head->next;
  free(list_start);
  return nextval;
}

elem list_remove_at_index(list_t *l, int index) { 
  node_t *cur = l->head;
  if (cur == NULL){
    printf("Empty list");
    return ;
  }
  int remove = 0;
  node_t *temp = l->head;
  while(temp->next != NULL && remove < index){
    temp = temp->next;
    remove++;
  }
  node_t *remove_elem = temp->next;
  elem val = temp->next->value;
  temp -> next = temp->next->next;
  free(remove_elem);
  return val;
}

bool list_is_in(list_t *l, elem value) {
  node_t *cur = l->head;
  while(cur != NULL){
    if (cur->value == value){
      return true;
    }
    cur = cur->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) { 
  int get_elem = 0;
  node_t *cur = l->head;
  while(cur != NULL){
    if (get_elem == index){
      return cur->value;
    }
    cur = cur->next;
    get_elem++;
  }
  return -1;
}
 
int list_get_index_of(list_t *l, elem value) { 
  node_t* current = l->head;
  
  while (l->head != NULL){
    if (l->head->value != value){
      l->head = l->head->next;
    }
    else{
      l->head = current;
      return true;
    }
  }
  l->head = current;
  return -1; 
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

node_t *node_alloc(elem value) {
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

list_t *list_alloc() { 
    list_t* list = (list_t*) malloc(sizeof(list_t));
    list->head = NULL;
  return list; 
  }

// want to  free up the nodes to free up space on the heap - free memory and point to the next one. 
void list_free(list_t *l){
  node_t *ptr = l->head;
  if (ptr == NULL)
    printf("Linked list is empty");
  while(ptr != NULL) {
    node_t *temp = ptr -> next;
    free(ptr);
    ptr = temp;
  }
}


void list_print(list_t *l) {
  node_t *current_node;
  current_node = l->head; 
  if(current_node == NULL){
    printf("The list is empty");
  }
  else {
      while (current_node!= NULL) {
        printf("The currentnode is %d \n", current_node->value);
        current_node= current_node->next; 
        }
    }
}

int list_length(list_t *l) { 
  int node_count = 0;
  node_t *current = l->head;
  while(current != NULL)
  {
    node_count ++;
    current = current->next; 
  }
  return node_count; 
}


void list_add_to_back(list_t *l, elem value) {
  node_t *current = l->head;
  node_t *new_node = node_alloc(value);
  if (current == NULL) {
    l->head = new_node;
    return;
  }

  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

// create new node; 
// set new node value 
// point newnode next to the head; 
// point head to new node. 
void list_add_to_front(list_t *l, elem value) {
  node_t *new = node_alloc(value); 
  new ->next = l->head;
  l->head = new; 
}


void list_add_at_index(list_t *l, elem value, int index) {
 if ((index >= list_length(l)) || (index < 0)) {
    return;
  }
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  node_t *current = l->head;
  int curr_index = 0;
  for (curr_index = 0; curr_index < index-1; curr_index++) {
    current = current->next;
  }
  if (current == NULL) {
    l->head = new_node;
  } else {
    new_node->next = current->next;
    current->next = new_node;
  }
}

void node_free(node_t *node){ 
  
  if (node->next != NULL) {
     node_free(node->next);
   } else {
     free(node);
   }
}


elem list_remove_from_back(list_t *l) { 
  node_t *current = l->head;
  node_t *to_ret = current;
  while ((current != NULL) && (current->next != NULL)) {
    if (current->next->next == NULL) {
      to_ret = current->next;
      current->next = NULL;
    } else {
      current = current->next;
    }
  }
  return to_ret->value;
}


elem list_remove_from_front(list_t *l) { 
  if(!l){
    printf("Linked list is empty");
    return;  
  } else {
    int to_rem = l->head->value;
    l->head = l->head->next;
    return to_rem;
  }
}


elem list_remove_at_index(list_t *l, int index) { 
  if ((index >= list_length(l)) || (index < 0)) {
    return 0;
  }
  node_t *current = l->head;
  int curr_index = 0;
  for (curr_index = 0; curr_index < index-1; curr_index++) {
    current = current->next;
  }
  int to_ret = current->next->value;
  current->next = current->next->next;
  return to_ret; 
}

bool list_is_in(list_t *l, elem value) { 
  node_t *curr = l->head;
  while (curr != NULL) {
    if (curr->value == value) {
      return true;
    }
    curr = curr->next;
  }
  return false;; 
}

elem list_get_elem_at(list_t *l, int index) { 
 if ((index >= list_length(l)) || (index < 0)) {
    return 0;
  }
  node_t *current = l->head;
  int curr_index = 0;
  
  for (curr_index; curr_index < index; curr_index++) {
    current = current->next;
  }
  return current->value; 
}


int list_get_index_of(list_t *l, elem value) { 
  node_t *current = l->head;
  int index = 0;
  
  while (current != NULL) {
    if (current->value == value) {
      return index;
    }
    current = current->next;
    index += 1;
  }
  return -1;; 
}