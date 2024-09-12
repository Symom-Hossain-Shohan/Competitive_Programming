#include<bits/stdc++.h>

using namespace std; 

class AbstractEmployee{
    virtual void AbstractFunction() = 0; 
}; 

class Employee: AbstractEmployee{
private:
    string Name; 
    string University; 
    int age;
public:
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

    void setName(string name)
    {
        Name = name; 
    }
    string getName()
    {
        return Name; 
    }

    void setUni(string uni)
    {
        University = uni; 
    }
    string getUni()
    {
        return University; 
    }

    void setAge(int age)
    {
        this->age = age; 
    }
    int getAge()
    {
        return age; 
    }

    void AbstractFunction()
    {
        if(age>24)
        {
            cout << Name << " you are passed\n"; 
        }
        else 
        {
            cout << Name << " you are too young.\n"; 
        }
    }
};

int main()
{
    Employee e1 = Employee("Symom Hossain Shohan", "CUET", 24); 
    e1.introduceYourself(); 


    e1.setName("Shohan"); 
    e1.setAge(22); 

    cout << e1.getName() << endl; 

    e1.AbstractFunction(); 
}