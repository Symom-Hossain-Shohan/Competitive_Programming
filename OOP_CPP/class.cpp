#include<bits/stdc++.h>

using namespace std; 

class Employee{
public:
    string Name; 
    string University; 
    int age; 

    void introduceYourself()
    {
        cout << "Name: " << Name << endl; 
        cout << "University: " << University << endl; 
        cout << "Age: " << age << endl; 
    }
};

int main()
{
    Employee e1; 
    e1.Name = "Symom Hossain Shohan"; 
    e1.University = "Chittagong University of Engineering and Technology"; 
    e1.age = 24; 

    e1.introduceYourself(); 
}