#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
  Node *prev;
};

Node* reverse(Node *head){
  Node *current = head;
  while(current != NULL){
    head = current;
    Node *temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  return head;
}

int main(int argc, char const *argv[]) {
  struct Node head;
  head.data = 2;
  struct Node n2, n3;
  n2.data = 4;
  n3.data = 6;
  head.next = &n2;
  n2.next = &n3;
  n3.next = NULL;
  n2.prev = &head;
  n3.prev = &n2;
  head.prev = NULL;
  Node *r_head = reverse(&head);
  while(r_head){
    cout << r_head->data;
    r_head = r_head->next;
  }
  return 0;
}
