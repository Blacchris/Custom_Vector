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

  void push_back (T value){
    if(sz == cap) resize();
    data[sz++] = value;
  }

  size_t capacity() const{
    return cap;
  }

  void pop_back(){
    if(sz > 0) --sz;
  }

  bool empty() const{
    return sz == 0;
  }

  //operator[] is a special member function that lets you use the square bracket syntax ([]) on objects of your class.
  T& operator[](size_t index){
    if(index >= sz) throw std::out_of_range("Out of bounds");
    return data[index];
  }

  const T& at(size_t index) const {
    if(index >= sz) throw std::out_of_range("Out of bounds");
    return data[index];
  }

  const T& front() const {
    if(sz == 0) throw std::out_of_range("Vector is empty");
    return data[0];
  }

  const T& back() const {
    if(sz == 0) throw std::out_of_range("Vector is empty");
    return data[sz - 1];
  }

  size_t size() const {return sz;}
};



using namespace std;

int main() {

 Vector<int> v;

 for(int i = 0; i < 5; ++i){
  v.push_back(i * 5);
 }

 cout << "Value at index: " << v.at(2) << endl;
 cout << "Value at front: " << v.front() << endl;
 cout << "Value at back: " << v.back() << endl;



  
  
  
  return 0;
}