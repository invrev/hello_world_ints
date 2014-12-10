#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

struct Student {
    string name;
    int age;
    int rollNo;
    Student (string aName,int aAge,int aRollNo) : 
        name(aName),age(aAge),rollNo(aRollNo)
    {

    };
};

struct NameComapartor {
    bool operator ()  (const Student &x,const Student &y) {
        return (x.name > y.name);
    }
};

int main () {
    priority_queue<Student,vector<Student>,NameComapartor> studentQ;
    studentQ.push(Student("C",12,34));
    studentQ.push(Student("B",11,34));
    studentQ.push(Student("A",10,34));
    while (!studentQ.empty()) {
        cout << "( " << studentQ.top().name <<  "," << studentQ.top().age << "," << studentQ.top().rollNo  << " )"<< endl;
        studentQ.pop();
    }

}
