#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};
Node *head;

void insertAtStart(int data) {
  Node *temp = new Node();
  temp->data = data;
  temp->next = head;
  head = temp;
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

void insertAtEnd(int data) {
  Node *lastNode = new Node();
  lastNode->data = data;
  lastNode->next = NULL;
  if (head == NULL) {
    head = lastNode;
    return;
  }
  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = lastNode;
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

bool insertAtPosition(int data, int position) {
  int length = getLength();
  if (length == 0 || position > length) {
    return false;
  }
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  Node *temp = head;
  if (position == 0) {
    newNode->next = head;
    head = newNode;
    return true;
  }
  for (int i = 1; i < position; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  return true;
}

void deleteFromStart() {
  if (head == NULL) {
    return;
  }
  if (head->next == NULL) {
    head = NULL;
    return;
  }
  Node *temp = head;
  head = head->next;
  delete temp;
}

void deleteFromEnd() {
  if (head == NULL) {
    return;
  }
  if (head->next == NULL) {
    delete head;
    head = NULL;
    return;
  }
  Node *temp = head;
  while (temp->next && temp->next->next) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = NULL;
}

void printForwardRecursion(Node *temp) {
  if (!temp)
    return;
  cout << temp->data << " ";
  printForwardRecursion(temp->next);
}

void printBackwardRecursion(Node *temp) {
  if (!temp)
    return;
  printBackwardRecursion(temp->next);
  cout << temp->data << " ";
}

int searchElement(int data) {
  if (!head)
    cout << "List is empty" << endl;
  int length = getLength();
  Node *temp = head;
  for (int i = 0; i < length; i++) {
    if (temp->data == data)
      return i;
    temp = temp->next;
  }
  return -1;
}

void reverse() {
  if (!head || !head->next) {
    return;
  }
  Node *current = head;
  Node *prev = NULL;
  Node *next = current->next;
  while (current->next) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  current->next = prev;
  head = current;
}

void reverseUsingRecursion(Node *current) {
  if (current == NULL)
    return;
  if (current->next == NULL) {
    head = current;
    return;
  }
  reverseUsingRecursion(current->next);
  Node *nextNode = current->next;
  nextNode->next = current;
  current->next = NULL;
}

int main() {
  head = NULL;
  cout << "Starting" << endl;
  insertAtStart(1);
  insertAtStart(2);
  insertAtEnd(4);
  insertAtEnd(5);
  insertAtStart(3);
  insertAtPosition(6, 5);
  printList();
  deleteFromStart();
  printList();
  deleteFromEnd();
  printForwardRecursion(head);
  cout << endl;
  printBackwardRecursion(head);
  cout << endl;
  reverse();
  printForwardRecursion(head);
  cout << endl;
  reverseUsingRecursion(head);
  printForwardRecursion(head);
  cout << endl;
  insertAtStart(2);
  printList();
  int position = searchElement(4);
  if (position < 0) {
    cout << "404! Element not found" << endl;
  } else {
    cout << "Element found at " << position << endl;
  }
  return 0;
}