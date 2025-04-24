#include <iostream>
using namespace std;

class Person {
protected:
    int age;
    string name;

public:
    Person(string name, int age) : name(name), age(age) {}

    virtual void display() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Student : public Person {
protected:
    int rollN;
    string branch;
    float marks;

public:
    Student(string name, int age, int rollN, string branch, float marks)
        : Person(name, age), rollN(rollN), branch(branch), marks(marks) {}

    float calculateCGPA() {
        return marks / 10;
    }

    void display() override {
        cout << "Student Details:" << endl;
        Person::display();
        cout << "Roll Number: " << rollN << endl;
        cout << "Branch: " << branch << endl;
        cout << "Marks: " << marks << ", CGPA: " << calculateCGPA() << endl;
    }
};

class Faculty : public Person {
protected:
    int f_id;
    string dp;
    float salary;

public:
    Faculty(string name, int age, int f_id, string department, float salary)
        : Person(name, age), f_id(f_id), dp(department), salary(salary) {}

    void display() override {
        cout << "Faculty Details:" << endl;
        Person::display();
        cout << "Faculty ID: " << f_id << endl;
        cout << "Department: " << dp << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Student s1("Haris", 20, 26, "AIML", 100);
    s1.display();

    Faculty f1("Rupali mam", 50, 1111, "AIML", 15000.0);
    f1.display();

    return 0;
}

