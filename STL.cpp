#include <bits/stdc++.h>
#include <memory>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int value): data(value), next(nullptr){};
};

void insert(Node*& head, int value){
  Node* newNode = new Node(value);
  if(head == nullptr){
    head = newNode;
    return;
  }
  else {
    Node* temp = head;
    while(temp->next != nullptr){
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void removeOdd(Node*& head){
  while(head != nullptr && head->data % 2 != 0){
    Node* removeNode = head;
    head = head->next;
    delete removeNode;
  }
  Node* curr = head;
  while(curr != nullptr && curr->next != nullptr){
    if(curr->next->data % 2 != 0){
      Node* removeNode = curr->next;
      curr->next = curr->next->next;
      delete removeNode;
    } else {
      curr = curr->next;
    }
  }
}

void display(Node*& head){
  Node* temp = head;
  while(temp != nullptr){
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr" << endl;
  return;
}

void freeMemory(Node*& head){
  while(head != nullptr){
    Node* freeNode = head;
    head = head->next;
    delete freeNode;
  }
  return;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // int* ptr = new int[5]{12, 3, 44, 34, 5};
  // string* str = new string[3]{"mike", "albert", "randy"};
 
  // Node* head = nullptr;
  // insert(head, 12);
  // insert(head, 7);
  // insert(head, 18);
  // insert(head, 35);
  // insert(head, 40);
  // insert(head, 53);
  // insert(head, 22);
  // insert(head, 91);
  // insert(head, 65);
  // insert(head, 79);

  // removeOdd(head);
  // display(head);
  // freeMemory(head);
  
  


  
  
  
  

  

  // for (auto &i : nums)
  //   cout << i << " ";

  // string s = "egg";
  // string t = "add";
  // if(Isomorphic(s, t))cout << "true" << endl;
  // else cout << "false" << endl;

  // unsigned char c = 200;
  // cout << (int)c << endl;

  // int freq[26] = {0};
  // freq[5] = 12;
  // if(freq[5]) cout << "true" << endl;
  // else cout << "false" << endl;

  // int freq[5];

  // fill(begin(freq), end(freq), 5);
  // cout << endl;
  // cout << Accumulate(begin(freq), end(freq), 2) << endl;

  // unsigned char freq1[256] = {0};

  // string ss = "mikel";
  // string t = "chris";
  // for(size_t i = 0; i < ss.size(); ++i){
  //   freq1[ss[i]] = t[i];
  // }

  // for(auto&c:freq1) cout << c << " ";

  // vector<int> nums = {1, 1, 2, 3, 3, 3};
  // unordered_map<int, int> mp;
  // for (const auto& i:nums) mp[i]++;

  // for (const auto& [n, f]:mp) {
  //   cout << n << ", " << f << endl;
  // }

  // vector<vector<int>> res(nums.size() + 1);
  // for (auto& [n, f]:mp) {
  //   res[f].push_back(n);
  // }

  // for (const auto& pair:res) {
  //   for (const auto i:pair) {
  //     cout << i << ", ";
  //   }
  // }
  // for (int i = 0; i < 4; i++) {
  //   cout << (ptr + i) << endl;
  // }
  // cout << increment(A) << endl;
  // ptr = A;
  // *(ptr + 1) = 54;
  // cout << *(ptr + 1) << endl;
  // for (auto i:A) cout << i << ", ";

  // cout << *(A+1) << endl;

  // string s = ")";
  // if(isValid(s)) cout << "True" << '\n';
  // else cout << "False" << '\n';
  // string s = "hello";
  // for (int i = 0; i < s.size()/2; i++) {
  //   swap(s[i], s[s.size() - i - 1]);
  // }
  // cout << __cplusplus << endl;

  // string s = "acb";
  // string t = "ahbgdc";
  // int x = stoi("123");

  // Convert 23 to binary
  //  int num = 23;
  //  string binary = "";
  //  if (num == 0) binary = "0";
  //  while (num > 0) {
  //    binary = char('0' + (num % 2)) + binary;
  //    num /= 2;
  //  }
  //  cout << "Binary of 23: " << binary << endl;

  // string s = "ab";
  // string t = "aa";

  // if (isIsomorphic(s,t)) {
  //   cout << "True" << endl;
  // } else {
  //   cout << "False" << endl;
  // }
  // string s = "aabbccpo";
  // cout << firstUnique(s);
  // vector<string> ss = {"man", "mat", "nam", "ant", "nat", "mom", "aet", "eat", "tea"};

  // cout << "[  ";
  // for (const auto&res: anagram(ss)) {
  //   cout << "[";
  //   for (const auto&s: res) {
  //     cout << s << " ";
  //   }
  //   cout << "],";
  // }
  // cout << "  ]";

  // int mx = 0;

  // vector<uint64_t> nums = {2, 4, 1, 5, 6, 3,2, 4, 6, 3, 1, 1, 3};
  // SORT(nums, 0, nums.size() - 1);
  // for (const auto&i: nums) {cout << i << "  ";};
  // int n = nums.size();
  // if (isSorted(nums, n)) {cout << "True" << endl;}
  // else {cout << "False" << endl;}
  return 0;
}