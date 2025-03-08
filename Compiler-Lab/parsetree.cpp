#include<bits/stdc++.h>
using namespace std;

void show(stack<char> st)
{
    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    map<pair<char, char>, string> rules; 
    rules[{'E', 'i'}] = "Te"; 
    rules[{'E', '('}] = "Te";
    rules[{'e', '+'}] = "+Te";
    rules[{'e', ')'}] = "0";
    rules[{'e', '$'}] = "0";
    rules[{'T', 'i'}] = "Ft";
    rules[{'T', '('}] = "Ft";
    rules[{'t', '+'}] = "0";
    rules[{'t', '*'}] = "*Ft";
    rules[{'t', ')'}] = "0";
    rules[{'t', '$'}] = "0";
    rules[{'F', 'i'}] = "i";
    rules[{'F', '('}] = "(E)";


    string in = "i+i*i$";
    stack<char> st;
    string mathced = "";
    st.push('$');
    st.push('E');

    stack<char> input;
    for(int i = in.size()-1; i >= 0; i--)
    {
        input.push(in[i]);
    }



    while(!st.empty() and !input.empty())
    {
        char st_top = st.top(), in_top = input.top();
        if(st_top == in_top)
        {
            mathced += in_top;
            st.pop();
            input.pop();
        }
        else if(st_top == '0')
        {
            st.pop();
        }
        else 
        {
            string temp = rules[{st_top, in_top}];
            st.pop();
            for(int i = temp.size()-1; i >= 0; i--)
            {
                if(temp[i]!='0')
                st.push(temp[i]);
            }
        }
        cout << "Matched: " << mathced << endl;
        cout << "Stack: "; 
        show(st);
        cout << "Input: ";
        show(input);
    }

    if(st.empty() && input.empty())
    {
        cout << "Accepted" << endl;
    }
    else 
    {
        cout << "Rejected" << endl;
    }

}