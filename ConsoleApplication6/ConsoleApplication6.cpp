#include<iostream>
#include<Windows.h>
using namespace std;

class Student
{
    char* name;
    char* surname;
    int age;
public:
    Student();
    Student(const char* Name, const char* Surname, int Age);
    void Output();
    ~Student();
    void Input() {
        char buff[10];
        char buff2[15];
        cout << "Enter name -> ";
        cin >> buff;
        cout << "Enter surname -> ";
        cin >> buff2;

        if (name != nullptr) {
            delete[]name;
        }
        if (surname != nullptr) {
            delete[]surname;
        }
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);
        surname = new char[strlen(buff2) + 1];
        strcpy_s(surname, strlen(buff2) + 1, buff2);

        cout << "Enter age -> ";
        cin >> age;
    }

};

Student::Student()
{
    name = nullptr;
    surname = nullptr;
    age = 0;
}

Student::Student(const char* Name, const char* Surname, int Age)
{
    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);
    surname = new char[strlen(Surname) + 1];
    strcpy_s(surname, strlen(Surname) + 1, Surname);
    age = Age;
}

void Student::Output()
{
    cout << "Name: " << name << endl
        << "Surname: " << surname << endl
        << "Age: " << age << endl << endl;
}

Student::~Student()
{
    delete[] name;
    delete[] surname;
}

int main()
{
    Student obj1("Oleg", "Popov", 21);
    obj1.Output();
    obj1.Input();
    obj1.Output();
}