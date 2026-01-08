#include <bits/stdc++.h>

using namespace std;


vector<int> TopK(vector<int>& nums, size_t& k){
  unordered_map<int, int> mp;
  for(auto&i :nums) mp[i]++;
  vector<vector<int>>bucket(nums.size() + 1);
  for(auto& [k, v]:mp){
    bucket[v].push_back(k);
  }

  vector<int> res;
  for(int i = bucket.size() - 1; i >= 0; --i){
    for(auto&j : bucket[i]){
      res.push_back(j);
      if(res.size() == k) return res;
    }
  }
  return {};
}

// int FreqEven(vector<int>& nums){
//   unordered_map<int, int> mp;
//   for(auto&i:nums){
//     if(i % 2 == 0) mp[i]++;
//   }

//   int ans = -1;
//   int freq = 0;
//   for(auto& [k, v]: mp){
//     if()
//   }

// }

struct B;

struct A{
  shared_ptr<B> bptr;
};

struct B{
  shared_ptr<A> aptr;
};



 bool containsDuplicate(vector<int>& nums) {
  unordered_map<int, int> seen;
  for (int num : nums) {
      if (seen[num] >= 1)
          return true;
      seen[num]++;
  }
  return false;
}

bool XontainsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num) > 0)
                return true;
            seen.insert(num);
        }
        return false;
}

bool ContainsDuplicates(vector<int>& nums){
  unordered_set<int> seen;
  for(auto&i : nums){
    if(seen.contains(i)) return true;
    seen.insert(i);
  }
  return false;
}

bool ValidAnagram(string s, string t){
  if(s.size() != t.size()) return false;
  int freq[26] = {0};
  for(auto&c : s) freq[c - 'a']++;
  for(auto&c : t) freq[c - 'a']--;

  for(auto&i : freq){
    if(i != 0) return false;
  }
  return true;
}

vector<int> removeElement(vector<int>& nums, int val){
  int l = 0;
  for(size_t i = 0; i < nums.size(); ++i){
    if(nums[i] != val) nums[l++] = nums[i];
  }
  return nums;
}

vector<int> MoveZeroes(vector<int>& nums){
  int p = 0;
  for(size_t i = 0; i < nums.size(); ++i){
    if(nums[i] != 0){
      swap(nums[p++], nums[i]);
    }
  }
  return nums;
}

vector<int> removee(vector<int>&nums, int k){
  vector<int> res;
  for(auto&i:nums){
    if(i != k) res.push_back(i);
  }
  return res;
}

int BinarySearch(vector<int>& nums, int k){
  int l = 0;
  int h = nums.size() - 1;
  while(l <= h){
    int mid = midpoint(l, h);
    if(nums[mid] == k) return mid;
    else if(nums[mid] < k) l = mid + 1;
    else h = mid - 1;
  }
  return -1;
}

void SelectionSort(vector<int>&nums){
  for(size_t i = 0; i < nums.size(); ++i){
    int min_index = i;
    for(size_t j = i + 1; j < nums.size(); ++j){
      if(nums[j] < nums[min_index]) min_index = j;
    }
    swap(nums[i], nums[min_index]);
  }
}

string* reverseString(string *ptr, int size){
  int l = 0;
  int h = size - 1;
  while(l < h){
    swap(*(ptr + l), *(ptr + h));
    l++;
    h--;
  }
  return ptr;
}

bool ValidPalindrome(string &s){
  int l = 0;
  int h = s.size() - 1;
  while(l < h){
    if(!isalnum(s[l])) {
      l++;
      continue;
    }
    if(!isalnum(s[h])) {
      h--;
      continue;
    }
    if(tolower(s[l]) != tolower(s[h])) return false;
    l++;
    h--;
  }
  return true;
}

vector<int> apply(vector<int>& nums){
  size_t i = 0;
  while(i < nums.size() - 1){
    int l = i + 1;
    if(nums[i] == nums[l]){
      nums[i++] *= 2;
      nums[l] = 0;
    } else {
      i++;
    }
    int k = 0;
    for(size_t i = 0; i < nums.size(); ++i){
      if(nums[i] != 0) swap(nums[k++], nums[i]);
    }
  }
  return nums;
}

vector<vector<string>> groupAnagram(vector<string>&strs){
  unordered_map<string, vector<string>> mp;
  for(auto&str:strs){
    int freq[26] = {0};
    for(auto&c:str) freq[c - 'a']++;
    string key = to_string(freq[0]);
    for(int i = 1; i < 26; ++i){
      key +=", " + to_string(freq[i]);
    }
    mp[key].push_back(str);
  }
  vector<vector<string>> res;
  for(auto& [k, v]:mp)res.push_back(move(v));
  return res;
}

int CountFreq(vector<int>&nums){
 int freq[101] = {0};
  for(auto&i:nums)freq[i]++;

  int mx = INT_MIN;
  for(int i = 0; i < 101; ++i) mx = max(mx, freq[i]);
  int ans = 0;
  for(int i = 0; i < 101; ++i) {
    if(freq[i] == mx) ans += mx;
  }
  return ans;
}

int firstUnique(string s){
  int freq[26] = {0};
  for(auto&c:s)freq[c - 'a']++;
  for(size_t i = 0; i < s.size(); ++i){
    if(freq[s[i] - 'a'] == 1) return i;
  }
  return -1;
}
char findDiff(string s, string t){
  int freq[26] = {0};
  for(auto&c:s)freq[c - 'a']++;
  for(auto&c:t){
    if(--freq[c - 'a'] < 0) return c;
  }
  return -1;
}
bool ransomNote(string s, string t){
  int freq[26] = {0};
  for(auto&c:t)freq[c - 'a']++;
  for(auto&c:s){
    if(--freq[c - 'a'] < 0) return false;
  }
  return true;
}

bool IsomorphicStrings(string s, string t){
  if(s.size() != t.size()) return false;
  unordered_map<char, char> mp1;
  unordered_map<char, char> mp2;
  for(size_t i = 0; i < s.size(); ++i){
    if((mp1.contains(s[i]) && mp1[s[i]] != t[i]) || (mp2.contains(t[i]) && mp2[t[i]] != s[i])) return false;
    mp1[s[i]] = t[i];
    mp2[t[i]] = s[i];
  }
  return true;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

 vector<int> nums = {1,2,2,3,1,4,0,0};


 string s = "paper";
 string t = "title";
 if(IsomorphicStrings(s, t))cout << "true" << endl;
 else cout << "false" << endl;

  // int freq[10] = {0};
  // for(auto&i:nums) freq[i]++;

  // for(auto&i:freq) cout << i << " ";

  
  // int num = 255;
  // string binary = "";
  // while(num > 0){
  //   binary = char('0' + (num % 2)) + binary;
  //   num /= 2;
  // }

  // cout << binary << endl;

  



 
  // int i = 0;
  // unsigned int res;

  // while(i < 32){
  //   res = pow(2, i++);
  // }
  
  // cout << res << endl;












  // int n;
  // cin >> n;
  // while(n--){
  //   string word;
  //   cin >> word;

  //   size_t len = word.size();
  //   if(len <= 10){
  //     cout << word << endl;
  //   }else {
  //     cout << word[0] << (len - 2) << word[len - 1] << endl;
  //   }
  // }

  // int n;
  // cin >> n;
  // while(n--){
  //   int x;
  //   cin >> x;

  //   if(x % 2 != 0) cout << "False" << endl;
  //   else cout << "True" << endl;
  // }
 
 
  // shared_ptr<int> ptr;

  // {
  //   shared_ptr<int> ptrr = make_unique<int>(445);
  //   cout << ptrr << endl;
  //   ptr = ptrr;
  // }
  // cout << ptr << endl;
  // cout << *ptr << endl;

  return 0;
}