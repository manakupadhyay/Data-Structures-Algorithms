#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
};
Node *head;

Node *initialize(int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void printList() {
  if (head == NULL) {
    cout << "List is empty" << endl;
    return;
  }
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void insertAtStart(int data) {
  Node *newNode = initialize(data);
  if (head == NULL) {
    head = newNode;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void insertAtEnd(int data) {
  Node *newNode = initialize(data);
  if (head == NULL) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

int getLength() {
  if (head == NULL) {
    return 0;
  }
  Node *temp = head;
  int length = 0;
  while (temp) {
    length++;
    temp = temp->next;
  }
  return length;
}

void insertAtIndex(int data, int index) {
  int length = getLength();
  if (index > length || index < 0) {
    return;
  }
  if (head == NULL) {
    insertAtStart(data);
    return;
  }
  if (length == index) {
    insertAtEnd(data);
    return;
  }
  Node *temp = head;
  for (int i = 1; i < index; i++) {
    temp = temp->next;
  }
  Node *newNode = initialize(data);
  Node *nextNode = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
  newNode->next = nextNode;
  nextNode->prev = newNode;
}

void reverseUsingRecursion(Node *current) {
  if (current->next == NULL) {
    head = current;
    return;
  }
  reverseUsingRecursion(current->next);
  Node *next = current->next;
  next->prev = next->next;
  next->next = current;
  current->next = current->prev;
}

int main() {
  head = NULL;
  insertAtStart(2);
  insertAtStart(1);
  insertAtStart(4);
  insertAtIndex(8, 1);
  insertAtEnd(7);
  insertAtEnd(16);
  insertAtStart(10);
  printList();
  Node *temp = head;
  reverseUsingRecursion(temp);
  printList();
  return 0;
}