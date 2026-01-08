#include <bits/stdc++.h>

using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int value): data(value), next(nullptr){};
};

 

class Linkedlist{

private:
  Node* head;
public:
  Linkedlist(): head(nullptr){};
  void insert(int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
      head = newNode;
      return;
    }else {
      Node* temp = head;
      while(temp->next != nullptr){
        temp = temp->next;
      }
      temp->next = newNode;
    }
    return;
  }

  void addAtHead(int val){
    head->data = val;
    return;
  }

  void addAtTail(int val){
    if(head == nullptr) return;
    Node* curr = head;
    while(curr->next != nullptr){
      curr = curr->next;
    }
    curr->data = val;
  }

  void addAtIndex(int index, int val){
    if(head == nullptr) return;
    int count = 0;
    if(count == index){
      head->data = val;
      return;
    }

    Node* curr = head->next;
    while(count != index){
      curr = curr->next;
      count++;
    }

    curr->data = val;
  }

  void deleteAtIndex(int index){
    int count = 0;
    if(count == index){
      Node* removeNode = head;
      head = head->next;
      delete removeNode;
      return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while(count != index){
      prev = curr;
      curr = curr->next;
      count++;
    }
    
  }



  void display(){
    Node* temp = head;
    while(temp != nullptr){
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    freeMemory();
    return;
  }

  void deleteByValue(int value){
    if(head == nullptr){
      cout << "Not found!" << endl;
      return;
    }
    while(head != nullptr && head->data == value){
      Node* removeNode = head;
      head = head->next;
      delete removeNode;
    }

    Node* prev = head;
    Node* curr = head->next;
    while(curr != nullptr && curr->data != value){
      prev = curr;
      curr = curr->next;
    }

    if(curr == nullptr) {
      cout << "Not found!" << endl;
      return;
    }else {
      Node* removeNode = curr;
      prev->next = curr->next;
      delete removeNode;
    }
    return;
  }

  void freeMemory(){
    Node* temp = head;
    while(temp != nullptr){
      Node* removeNode = temp;
      temp = temp->next;
      delete removeNode;
    }
    return;
  }

  void deleteTail(){
    Node* prev = head;
    Node* temp = head->next;
    while(temp->next != nullptr){
      prev = temp;
      temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
    return;
  }
};

void deleteNode(Node*& head, int value){

  while(head != nullptr && head->data == value){
    Node* removeNode = head;
    head = head->next;
    delete removeNode;
  }

  Node* curr = head;
  while(curr != nullptr && curr->next != nullptr){
    if(curr->next->data == value){
      Node* removeNode = curr->next;
      curr->next = curr->next->next;
      delete removeNode;
    } else {
      curr = curr->next;
    }
  }
}


class MyLinkedList{

private:
  Node* head;
  int size;

public:
  MyLinkedList(){
    head = new Node(0);
    size = 0;
  }

  int get(int index){
    Node* curr = head->next;
    while(index--) curr = curr->next;
    return curr->data;
  }

  void addAtHead(int val){
    Node* newNode = new Node(val);
    newNode->next = head->next;
    head->next = newNode;
    size++;
  }

  void addAtTail(int val){
    Node* curr = head->next;
    while(curr->next != nullptr){
      curr = curr->next;
    }
    Node* newNode = new Node(val);
    curr->next = newNode;
    size++;
  }

  void addAtIndex(int index, int val){
    Node* curr = head;
    while(index--)curr = curr->next;
    Node* newNode = new Node(val);
    newNode->next = head->next;
    head->next = newNode;
    size++;
  }

  void deleteAtIndex(int index){
    if(index < 0 || index >= size) return;
    Node* curr = head;
    while(index--)curr = curr->next;
    Node* removeNode = curr->next;
    curr->next = removeNode->next;
    delete removeNode;
    size--;
  }

};






int main() {


  Node* head = new Node(434);
  Node* first = new Node(43);
  Node* second = new Node(3);
  Node* third = new Node(22);
  Node* fouth = new Node(11);

  head->next = first;
  first->next = second;
  second->next = third;
  third->next = fouth;
  fouth->next = nullptr;
  
  // insertAtIndex(head, 0, 666);

  Node* temp = head;
  while(temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
 


 

  

  

  
  























  

  // cout << **(B + 1)<< endl;
  // char c[] = "Hello Michael";
  // print(c);
  //cout treats a char* as a C-style string, 
  //so it prints characters until it sees a null 
  //terminator ('\0'). This is special behavior just for char*.

  /* c++; is illegal — because:
  c is not a variable — it's an array name, which behaves like a constant pointer.
  You can't change the address of an array.
  So c++ causes a compile-time error like:*/
  return 0;
}