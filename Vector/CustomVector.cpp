#include <bits/stdc++.h>


template<typename T>
class Vector{

private:
  T* data;
  size_t sz;
  size_t cap;

  void resize(){
    size_t newcap = cap == 0 ? 1 : cap * 2;
    T* newdata = new T[newcap];
    for(size_t i = 0; i < sz; ++i){
      newdata[i] = data[i];
    }
    delete[] data;
    data = newdata;
    cap = newcap;
  }
public:
  Vector(): data(nullptr), sz(0), cap(0){};
  ~Vector(){delete[] data;};

  void push_back(T value){
    if(sz == cap) resize();
    data[sz++] = value;
  }

  size_t capacity(){
    return cap;
  }

  void pop_back(){
    if(sz > 0) --sz;
  }

  //operator[] is a special member function that lets you use the square bracket syntax ([]) on objects of your class.
  T& operator[](size_t index){
    return data[index];
  }
  size_t size(){return sz;}
};

template<typename T>
class Person{

};

int main() {

 Vector<int> v;

  for (int i = 0; i < 10; i++) {
    v.push_back(i * 10);
    std::cout << "Size: " << v.size()
            << " Capacity: " << v.capacity() << "\n";
  }

    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
  
  
  
  return 0;
}