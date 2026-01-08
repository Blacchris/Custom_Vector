#include <bits/stdc++.h>

using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int value): data(value), next(nullptr){};
};
Node* removeDuplicates(Node* head){
  unordered_set<int> seen;
  Node* prev = nullptr;
  Node* temp = head;
  while(temp != nullptr){
    if(seen.contains(temp->data)){
      Node* removeNode = temp;
      prev->next = temp->next;
      temp = temp->next;
      delete removeNode;
    } else {
      seen.insert(temp->data);
      prev = temp;
      temp = temp->next;
    }
  }
  return head;
}

Node* removeOdds(Node* head){
  while(head != nullptr && head->data % 2 == 0){
    Node* removeNode = head;
    head = head->next;
    delete removeNode;
  }

  Node* curr = head;
  while(curr != nullptr && curr->next != nullptr){
    if(curr->next->data % 2 != 0){
      Node* removeNode = curr->next;
      curr->next = curr->next->next;
      delete(removeNode);
    } else {
      curr = curr->next;
    }
  }

  return head;
}

int main(){
 
  Node* head = new Node(42);
  Node* second = new Node(435);
  Node* third = new Node(42);
  Node* fouth = new Node(34);
  Node* fifth = new Node(435);
  Node* sixth = new Node(32);
  Node* seventh = new Node(64);
  Node* eight = new Node(64);

  head->next = second;
  second->next = third;
  third->next = fouth;
  fouth->next = fifth;
  fifth->next = sixth;
  sixth->next = seventh;
  seventh->next = eight;
  eight->next = nullptr;

  Node* p = head;
  while(p != nullptr){
    cout << p->data << " -> ";
    p = p->next;
  }
  cout << endl;

  Node* k = removeOdds(head);
  Node* j = k;
  while(j != nullptr){
    cout << j->data << " -> ";
    j = j->next;
  }

  cout << endl;

  Node* res = removeDuplicates(head);

  Node* temp = res;
  while(temp != nullptr){
    cout << temp->data << " -> ";
    temp = temp->next;
  }

 

  Node* rmv = head;
  while(rmv != nullptr){
    Node* removeNode = rmv;
    rmv = rmv->next;
    delete removeNode;
  }

  
  

  return 0;
}