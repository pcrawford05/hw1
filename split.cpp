/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void push_front(Node*& list, Node*& item);
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if(in == nullptr)
    return;
  split(in->next, odds, evens);
  Node* temp = in;
  temp->next = nullptr;
  in = nullptr;
  if(temp->value % 2 == 0){
    push_front(evens, temp);
  } else {
    push_front(odds, temp);
  }
}

/* If you needed a helper function, write it here */
void push_front(Node*& list, Node*& item){
  if(list == nullptr)
    list = item;
  else {
    item->next = list;
    list = item;
  }
}