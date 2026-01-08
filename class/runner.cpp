#include <iostream>
#include <memory>
#include <chrono>


using namespace std;


class Person{

private:
   string name;
   int age;
   Person* ptr;

public:
   Person(string name_param, int age_param): name(name_param), age(age_param){
      std::cout << "Object is created" << endl;
   }

   void setName(string name_param){
      name = name_param;
   }

   string getName(){
      return name;
   }

   void setPointer(Person* ptr_param){
      ptr = ptr_param;
   }

   void* getAddress(){
      return ptr;
   }

   ~Person(){
      delete ptr;
      cout << "Object is destroyed" << endl;
   }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = chrono::high_resolution_clock::now();

    Person p("chris", 23);
    p.setPointer(new Person("mike", 233));


    Person* ptr = (Person*) p.getAddress();
    cout << ptr->getName() << endl;


    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration<double, milli>(end - start).count() << " ms\n";

    return 0;
}
