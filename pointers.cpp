#include <bits/stdc++.h>

using namespace std;

class Entity{

public:
  Entity(){
    cout << "Object Created on Heap" << endl;
  }

  ~Entity(){
    cout << "Object Destroyed on Heap" << endl;
  }
};

shared_ptr<Entity> foo(){
  shared_ptr<Entity> ptr = make_shared<Entity>();
  return ptr;
}



#define TEST_CASE int* ref

TEST_CASE(int* A){
  return A;
}

class Node{

public:
  int val;
  Node* next;
  Node* prev;
  Node(int value): val(value), next(nullptr), prev(nullptr){};
};

void insert(Node*& head, int value){
  Node* newNode = new Node(value);
  if(head == nullptr){
    head = newNode;
    return;
  }

  Node* curr = head;
  while(curr->next != nullptr) curr = curr->next;
  curr->next = newNode;
  newNode->prev = curr;
}

void insertAtHead(Node*& head,int value){
  Node* newNode = new Node(value);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void insertAtIndex(Node*& head,int index, int value){
  Node* newNode = new Node(value);
  Node dummy(0);
  dummy.next = head;
  Node* curr = &dummy;

  while(index--) curr = curr->next;
  newNode->next = curr->next;
  curr->next->prev = newNode;
  curr->next = newNode;

  head = dummy.next;

}

void deleteAtHead(Node*& head){
  if(head == nullptr) return;

  Node* del = head;
  head = del->next;
  delete del;
}

void deleteAtTail(Node* head){
  Node* curr = head;
  while(curr->next != nullptr) curr = curr->next;
  delete curr;
}

void deleteAtIndex(Node*& head, int index){
  Node dummy(0);
  dummy.next = head;

  Node* curr = &dummy;
  while(index--) curr = curr->next;
  Node* del = curr->next;
  curr->next = del->next;
  del->next->prev = curr;
  delete del;
  head = dummy.next;
}

// void insert(Node*& head, int value){
//   Node* newNode = new Node(value);
//   if(head == nullptr){
//     head = newNode;
//     return;
//   }

//   Node* curr = head;
//   while(curr->next != nullptr) curr = curr->next;
//   curr->next = newNode;
// }

// void insertAtIndex(Node* head,int index,int value){
//   Node dummy(0);
//   dummy.next = head;

//   Node* curr = &dummy;
//   while(index--) curr = curr->next;
//   Node* newNode = new Node(value);
//   newNode->next = curr->next;
//   curr->next = newNode;
//   head = dummy.next;
// }

void display(Node* head){
  Node* temp = head;
  while(temp != nullptr) {
    cout << temp->val << " -> ";
    temp = temp->next;
  }
  
}


void print(const char* ptr){
  while(*ptr != '\0'){
    cout << *ptr;
    ptr++;
  }
}



int add(int a, int b){
  return a + b;
}

int main(){  


  int (*ptr)(int, int) = nullptr;
  ptr = &add;
  int res = (*ptr)(12, 43);

  cout << res << endl;


  

















  
  // Node* head = nullptr;
  // insert(head, 666);
  // insert(head, 453);
  // insert(head, 56);
  // insert(head, 909);

  // insertAtHead(head, 53535);
  // insertAtIndex(head, 0, 949253);
  // display(head);
  // cout << endl;

  // deleteAtIndex(head, 4);
  

  // display(head);


  // unique_ptr<int> ptr(new int[]{12, 334, 34});
  
  // unique_ptr<int> ptr = make_unique<int>(23);
  // int* x = ptr.get();

  // *x = 1432;
  // cout << *ptr << endl;
  // auto arr = std::make_unique<int[]>(5);



  



  





  return 0;
}