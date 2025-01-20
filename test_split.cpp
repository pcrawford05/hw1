/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
using namespace std;
#include "split.h"
#include <iostream>

void printList(Node*& list);

int main(int argc, char* argv[])
{
  //Node* head = new Node(0, new Node(1, new Node(2,new Node(3, new Node(4, new Node(5,nullptr))))));
  Node* head = nullptr;
  head = new Node(0, nullptr);
  Node* temp = head;
  /*for(int i = 1; i < 10; i++){
    temp->next = new Node(i, nullptr);
    temp = temp->next;
  }*/
  cout << "Original List Before: " << endl;
  printList(head);
  Node* odds = nullptr, *evens = nullptr;
  split(head, odds, evens);
  cout << "Original List After: " << endl;
  printList(head);
  cout << "Odds List: " << endl;
  printList(odds);
  cout << "Evens List: " << endl;
  printList(evens);
}

void printList(Node*& list){
  Node* temp = list;
  while(temp != nullptr){
    cout << temp->value << endl;
    temp = temp->next;
  }
}