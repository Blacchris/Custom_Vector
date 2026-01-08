#include <bits/stdc++.h>


using namespace std;


class Node{

public:
  int val;
  Node* next;
  Node(int value): val(value), next(nullptr){};
};

void InsertAtIndex(Node*& head, int value, int index){
  Node dummy(0);
  dummy.next = head;
  Node* curr = &dummy;

  while(index--) curr = curr->next;
  Node* newNode = new Node(value);
  newNode->next = curr->next;
  curr->next = newNode;
}

void display(Node* head){
  Node* temp = head;
  while(temp != nullptr){
    cout << temp->val << " -> ";
    temp = temp->next;
  }
}

void removeOdd(Node*& head){
  
  while(head != nullptr && head->val % 2 != 0){
    Node* del = head;
    head = del->next;
    delete del;
  }

  Node* curr = head;
  while(curr != nullptr && curr->next != nullptr){
    if(curr->next->val % 2 != 0){
      Node* del = curr->next;
      curr->next = del->next;
      delete del;
    } else {
      curr = curr->next;
    }
  }
}
int main(){

  Node* head = new Node(1);
  Node* zero = new Node(2);
  Node* first = new Node(3);
  Node* second = new Node(4);
  Node* third = new Node(5);

  head->next = zero;
  zero->next = first;
  first->next = second;
  second->next = third;
  
  display(head);
  removeOdd(head);
  cout << endl;
  display(head);

  
  // string name;
  // int age;
  // unique_ptr<Person[]> ptr = make_unique<Person[]>(5);
  // for(int i = 0; i < 5; ++i){
  //   cin >> name >> age;
  //   ptr[i].name = name;
  //   ptr[i].age = age;
  // }

  // cout << endl;

  // for(int i = 0; i < 5; ++i) {
  //   cout << ptr[i].name << " is " << ptr[i].age << " years old.\n";
  // }


  





  return 0;
}