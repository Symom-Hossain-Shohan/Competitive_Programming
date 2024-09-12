#include<bits/stdc++.h>

using namespace std; 

class Employee{
public:
    string Name; 
    string University; 
    int age; 

    Employee(string Name, string University, int age)
    {
        this->Name = Name; 
        this->University = University; 
        this->age = age; 
    }

    void introduceYourself()
    {
        cout << "Name: " << Name << endl; 
        cout << "University: " << University << endl; 
        cout << "Age: " << age << endl; 
    }
};

int main()
{
    Employee e1 = Employee("Symom Hossain Shohan", "CUET", 24); 
    e1.introduceYourself(); 
}