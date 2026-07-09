#include<iostream>
#include "Vector.h"
#include "List.h"
using namespace std ;
class Student {
public:
    int id;

    Student() {}

    Student(int val) {
        id = val;
    }
};
int main(){
Vector<int>v;
// v.push_back(1);
// v.push_back(2);
for(int i=0;i<v.Size();i++){
    cout<<v[i];
}
 Student s1(2);
    Student s2(3);
    Student s3(4);
    Student s4(5);

    Linkedlist<Student> ll;

    ll.push(s1);
    ll.push(s2);
    ll.push(s3);
    ll.push(s4);

    for (int i = 0; i < ll.count; i++) {
        cout << ll[i].id << " ";
    }

    cout << endl;
    return 0;
}