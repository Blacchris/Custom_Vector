#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class HashMap{
private:
   vector<list<pair<int, string>>> table;
   const static int SIZE = 10;

   int hashfunction(int key){
      return key % SIZE;
   }
public:
   HashMap(){
      table.resize(SIZE);
   }
   void insert(int key, string value){
      int index = hashfunction(key);
      auto& chain = table[index];
      for(auto& [k, v]: chain){
         if(key == k){
            v = value;
            return;
         }
      }
      chain.emplace_back(key, value);
      return;
   }

   void display(){
      for(size_t i = 0; i < SIZE; ++i){
         cout << "[";
         for(auto&[k, v]: table[i]){
            cout << "[Key: " << k << " : " << "value: " << v << "] -> ";
         }
         cout << "]" << endl;
      }
      return;
   }

   string get(int key){
      int index = hashfunction(key);
      auto& chain = table[index];
      for(auto& [k, v]: chain){
         if(k == key) return v;
      }
      return "Not Found!";
   }

   void remove(int key){
      int index = hashfunction(key);
      auto& chain = table[index];
      for(auto it = chain.begin(); it != chain.end(); ++it){
         if(it->first == key){
            chain.erase(it);
            cout << "Key: " << key << " is removed" << endl;
            return;
         }
      }
      cout << "Key not found: " << key << endl;
      return;
   }

   bool contains(int key){
      int index = hashfunction(key);
      auto& chain = table[index];
      for(auto& [k, v]: chain){
         if(key == k) return true;
      }
      return false;
   }

   void clear(){
      for(auto& chain: table){
         chain.clear();
      }
      return;
   }

   size_t size(){
      size_t c = 0;
      for(auto& chain: table){
         c += chain.size();
      }
      return c;
   }
};




class Node{

public:
   int val;
   Node* next;
   Node(int value): val(value), next(nullptr){};
};

Node* mergedLinkedlist(Node* list1, Node* list2){
   Node dummy(0);
   Node* node = &dummy;
   
   while(list1 != nullptr && list2 != nullptr){
      if(list1->val < list2->val){
         node->next = list1;
         list1 = list1->next;
      } else {
         node->next = list2;
         list2 = list2->next;
      }
      node = node->next;
   }

   node->next = list1 ? list1 : list2;
   return dummy.next;
}

Node* removeLinkedlist(Node* head, int value){
   Node dummy(0);
   Node* node = &dummy;
   node->next = head;
   while(node->next != nullptr){
      if(node->next->val == value){
         Node* del = node->next;
         node->next = del->next;
         delete del;
      } else {
         node = node->next;
      }
   }
   return dummy.next;
}

void insert(Node*& head, int val){
   Node* newNode = new Node(val);
   if(head == nullptr){
      head = newNode;
      return;
   }

   Node* temp = head;
   while(temp->next != nullptr) temp = temp->next;
   temp->next = newNode;
}

Node* RemoveDuplicates(Node* head){
   Node* temp = head;
   while(temp != nullptr && temp->next != nullptr){
      if(temp->val == temp->next->val){
         Node* del = temp->next;
         temp->next = del->next;
         delete del;
      } else {
         temp = temp->next;
      }
   }
   return head;
}

Node* removeOdd(Node* head){
   Node dummy(0);
   Node* node = &dummy;
   node->next = head;
   while(node->next != nullptr){
      if(node->next->val % 2 != 0){
         Node* del = node->next;
         node->next = del->next;
         delete del;
      } else {
         node = node->next;
      }
   }
   return dummy.next;
}

Node* removeNthnode(Node* head, int n){
   Node dummy(0);
   dummy.next = head;
   Node* fast = &dummy;
   Node* slow = &dummy;
   while(n--) fast = fast->next;
   while(fast->next != nullptr){
      fast = fast->next;
      slow = slow->next;
   }
   Node* del = slow->next;
   slow->next = del->next;
   delete del;
   return dummy.next;
}

#include <chrono>
#define PI 3.14



bool wordPattern(string pattern, string s){
   unordered_map<string, char> mp1;
   unordered_map<char, string> mp2;

   stringstream ss(s);
   string  ws;
   size_t i = 0;
   while(ss >> ws){
      if(i >= pattern.size()) return false;
      char c = pattern[i++];
      if((mp1.contains(ws) && mp1[ws] != c) || (mp2.contains(c) && mp2[c] != ws)) return false;

      mp1[ws] = c;
      mp2[c] = ws;
   }
   return i == pattern.size();
}


void print(int x){
   if(x == 0) return;
   cout << x << endl;
   print(x - 1);
}

int fact(int n){
   if(n == 1) return 1;
   return n * fact(n - 1);
}

int sumNumbers(int n){
   if(n <= 1) return n;
   return n + sumNumbers(n - 1);
}

void reversePrint(const string& s, int index){
   if (index < 0) return;
   cout << s[index];
   reversePrint(s, index - 1);
}

bool palindrome(string s, int l, int h){
   if(l >= h) return true;
   if(s[l] != s[h]) return false;

   return palindrome(s, ++l, --h);
}

int sum(int n){
   int res = 0;
   for(int i = 1; i <= n; ++i){
      res += i;
   }
   return res;
}

int factorial(int n){
   int res = 1;
   for(int i = n; i > 0; --i) res *= i;
   return res;
}


template<typename T>
class Vector{

private:
   T* data;
   size_t sz;
   size_t capacity;

   void resize(){
      size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
      T* newdata = new T[newCapacity];
      for(size_t i = 0; i < sz; ++i){
         newdata[i] = data[i];
      }
      delete[] data;
      data = newdata;
      capacity = newCapacity;
   }
public:

   Vector(): data(nullptr), sz(0), capacity(0){
      cout << "Object[] created" << endl;
   };
   ~Vector(){
      delete[] data;
      cout << "Object[] deleted" << endl;
   }

   void push_back(T value){
      if(sz == capacity){
         resize();
      }
      data[sz++] = value;
   }

   T operator[](int index){
      return data[index];
   }

   size_t size(){
      return sz;
   }
};
bool ValidParentheses(string s){
   stack<char> st;
   for(const auto&c:s){
      if(c == '(' || c == '{' || c == '['){
         st.push(c);
      }else {
         if(st.empty()) return false;
         char k = st.top();
         if((c == ')' && k != '(') || (c == '}' && k != '{') || (c == ']' && k != '[')) return false;
         st.pop(); 
      }
   }
   return st.empty();
}

int partition(vector<int>&nums, int l, int h){
   int pivot = nums[h];
   int i = l - 1;
   for(int j = l; j < h; ++j){
      if(nums[j] < pivot){
         i++;
         swap(nums[i], nums[j]);
      }
   }
   i++;
   swap(nums[i], nums[h]);
   return i;
   
}

void QuickSort(vector<int>& nums, int l, int h){
   if(l < h){
      int pivot = partition(nums, l, h);
      QuickSort(nums, l, pivot - 1);
      QuickSort(nums, pivot + 1, h);
   }
}
#include <thread>

int RomanTONumber(string s){
   unordered_map<char, int> mp{
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
   };

   int res = 0;

   for(const auto &c:s){
      res += mp[c];
   }

   return res;
}

typedef int s32;
typedef uint32_t u32;
typedef uint64_t u64;


uint32_t Max(u32 arr[], int size){
   u32 mx = INT_MIN;
   for(u32 i = 0; i < size; ++i){
      mx = (u32) max(mx, arr[i]);
   }
   return mx;
}
int main(){

   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   auto start = chrono::high_resolution_clock::now();


  
   u32 arr[]{12, 2, 34, 23, 3};
   cout << "result: " << Max(arr, 5) << endl;



   

   auto end = chrono::high_resolution_clock::now();
   cout << chrono::duration<double, milli>(end - start).count() << " ms\n";




   // Node* list1 = new Node(1);
   // Node* second = new Node(2);
   // Node* fouth = new Node(4);

   // list1->next = second;
   // second->next = fouth;

   // Node* list2 = new Node(1);
   // Node* third = new Node(3);
   // Node* fourth = new Node(4);

   // list2->next = third;
   // third->next = fourth;

   // Node* res = mergedLinkedlist(list1, list2);

   // while(res != nullptr){
   //    cout << res->val << " -> ";
   //    res = res->next;
   // }

   // vector<int> nums = {1, 2, 3, 4, 5};
   // size_t n = nums.size();
   // vector<int> res(n, 1);

   // int prefix = 1;
   // for(size_t i = 0; i < n; ++i){
   //    res[i] = prefix;
   //    prefix *= nums[i];
   // }

   // int suffix = 1;
   // for (size_t i = n; i-- > 0; ) {
   //    res[i] *= suffix;
   //    suffix *= nums[i];
   // }

   // for(auto&i : res) cout << i << " ";
   

   
   return 0;
}
