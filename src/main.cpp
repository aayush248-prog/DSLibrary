#include<iostream>
// #include "Vector.h"
// #include "List.h"
#include "Hashmap.h"
#include "List.h"
using namespace std ;

class Student {
public:
    int id;

    Student() {}

    Student(int val) {
        id = val;
    }
    int formhash()const{
        return this->id;
    }
    bool operator==(const Student& other) const {
        return id == other.id;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }
};
int main(){
Student s1(2);
Student s2(3);
Student s3(4);
Linkedlist<Student>lst;
lst.push(s1);
lst.push(s2);
lst.push(s3);
cout<<lst[5].id;
return 0;
 
}