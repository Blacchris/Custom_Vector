#include <iostream>

using namespace std;


class Node{

public:
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr){};
};

void insert(Node*& head, int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr) curr = curr->next;
    curr->next = newNode;
    return; 
}
void freeMemory(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        Node* del = curr;
        curr = curr->next;
        delete del;
    }
}
void display(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << " -> ";
        curr = curr->next;
    }
}

void insertAtTail(Node* head, int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* curr = head;
    while(curr->next != nullptr) curr = curr->next;
    curr->next = newNode;
}
 void insertAtIndex(Node* head, int val, int index){
    Node* newNode = new Node(val);
    if(index == 0 && head->next != nullptr){
        newNode->next = head->next;
        head->next = newNode;
    }
    
 }



template <typename T>
class Vector{

private:
    T* ptr;
    size_t sz;
    size_t capacity;

    void resize(){
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        T* newAlloc = new T[newCapacity];
        for(size_t i = 0; i < sz; ++i){
            newAlloc[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newAlloc;
        capacity = newCapacity;
    }

public:

    void push_back(T value){
        if(sz == capacity) resize();
        ptr[sz++] = value;
    }

    void pop_back(){
        if(sz > 0) --sz;
    }

    
};
int main(){


    int x = 12;
    int &y = x;

    cout << y << endl;
    y = 999;

    cout << x << endl;
    // Node* head = nullptr;
    // insert(head, 23);
    // insert(head, 63);
    // insert(head, 999);
    // insert(head, 756);
    // insert(head, 45);

    // display(head);
    // cout << endl;
    // insertAtIndex(head, 6666, 1);
    // display(head);
    // freeMemory(head);

    // size_t size = 3;
    // int* ptr = (int*) calloc(size, sizeof(int));

    // for(size_t i = 0; i < size; ++i) ptr[i] = i * 5;

    // for(size_t i = 0; i < size; ++i) cout << ptr[i] << " ";
    // cout << endl;

    // int* ptrr = (int*) realloc(ptr, size * 2 * sizeof(int));  // Fixed!

    // if (ptrr == NULL) {
    //     free(ptr);
    //     return -1;  // or handle error
    // }

    // ptr = ptrr;  // Update ptr (optional, depends on your needs)

    // for(size_t i = 0; i < size * 2; ++i) {
    //     cout << ptr[i] << " ";  // First 3 are copied, last 3 are uninitialized
    // }

    // free(ptr);  // Don't forget to free!



    return 0;
}