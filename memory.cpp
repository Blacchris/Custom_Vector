#include <bits/stdc++.h>

using namespace std;

class Person{

public:
  string name;
  int age;

  Person(){};

  Person(string name, int age): name(name), age(age){
    cout << "Object is created" << endl;
  };

  ~Person(){
    cout << "Object is deleted" << endl;
  }

};

template<typename T>
unique_ptr<T> make_ptr(T x){
  throw std::runtime_error("Error");
  return make_unique<T>(x);
}



int main(){
  
  // Person g("chris", 23);
  // auto res = make_ptr(g);
  // cout << res << '\n' << res->name << endl;
  

  shared_ptr<Person> ptr = nullptr;

  {
    shared_ptr<Person> ptrr = make_shared<Person>("chris", 23);
    ptr = ptrr;
    cout << ptr.use_count() << endl;
  }

  cout << ptr.use_count() << endl;


 
  
  // new Person("mike", 43);

  // unique_ptr<Person> ptr = make_unique<Person>("mike", 23);
  // cout << ptr->name << endl;
  // cout << ptr->age << endl;

  // shared_ptr<Person> ptr = make_shared<Person>("mike", 23);
  // auto ptrr = ptr;
  
  // cout << ptr.use_count() << endl;


 

  return 0;
}