#include <concepts>
#include <format>
#include <ranges>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

class Person{

public:
    static int count;
    Person(){
        count++;
    }
};

int Person::count = 0;
int x = 10;

inline void count(){
    static int x = 0;
    x+=::x;
    cout << x << endl;
    return;
}

shared_ptr<int> factory(int x){
    return make_shared<int>(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    shared_ptr<int> res = factory(42);
  
    
    shared_ptr<list<pair<int, int>>> ptr = make_shared<list<pair<int, int>>>();

    if(ptr && ptr->empty()){
        ptr->emplace_back(12, 33);
        ptr->emplace_back(453, 52);
    }

    shared_ptr<list<pair<int, int>>> ptrr = ptr;

    for(auto& [k , v]: *ptr){
        cout << k << " : " << v << endl;
    }

    auto p = make_shared<vector<int>>();

    
    
    
    

    // Node* head = new Node();
    // Node* second = new Node();
    // Node* third = new Node();
    // Node* chris = new Node();
    // Node* fouth = new Node();
  
    // cout << sizeof(Node) << endl;

    // head->data = 54;
    // head->next = second;

    // second->data = 123;
    // second->next = third;

    // third->data = 674;
    // third->next = chris;
    // chris->data = 23;
    // chris->next = fouth;
    // fouth->data = 643;
    // fouth->next = NULL;

    // NodeElements(head);

    // delete head;
    // delete second;
    // delete third;
    // delete chris;
    // delete fouth;


    return 0;
}
