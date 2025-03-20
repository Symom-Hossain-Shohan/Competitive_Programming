#include <bits/stdc++.h>
using namespace std;

vector<string> keywords, operators, dataTypes, functions, others;

map<string,int>check;

map<char,int>symbol_table;
int idx=-1;
map<char,int>vis;

//function, operator, data_type, key_word, others.
int is_dataType(string s)
{
    vector<string> keywords = {"int", "double","float", "bool"};
    return find(keywords.begin(), keywords.end(), s) != keywords.end();
}

int is_Function(string s)
{
    vector<string> keywords = {"main"};
    return find(keywords.begin(), keywords.end(), s) != keywords.end();
}

int is_keywords(string s)
{
    vector<string> keywords = {"return","for","if"};
    return find(keywords.begin(), keywords.end(), s) != keywords.end();
}

int is_operator(string s){
     vector<string> keywords = {">=","--","++","<="};
    return find(keywords.begin(), keywords.end(), s) != keywords.end();
}


void verify_token(string s)
{
    if (is_dataType(s))
    {
         dataTypes.push_back(s);//1
        cout<<"< "<<s<<",keyword>"<<endl;
    }
    else if (is_Function(s)){
         functions.push_back(s);//2
        cout<<"< "<<s<<",Function>"<<endl;
    }
    else if (is_keywords(s))
    {
         keywords.push_back(s);//3
        cout<<"< "<<s<<",keyword>"<<endl;
    }
    else if (is_operator(s))
    {
         cout<<"< "<<s<<",Operator>"<<endl;
    }
    else if (isdigit(s[0]))
    {
        others.push_back(s);
        cout<<"< "<<s<<",Constant>"<<endl;
    }
    
    else if (isalpha(s[0]) || s[0] == '_')
    {
        others.push_back(s);
        if(vis[s[0]]==0){
            idx++;
            vis[s[0]]=1;

        symbol_table[s[0]]=idx;
        }
        cout<<"< "<<s[0]<<","<<symbol_table[s[0]]<<" >"<<endl;
    }
    else if (strchr("=<>+*/", s[0]))
    {
        operators.push_back(s);//4
        // cout<<"< "<<s<<",Operator>"<<endl;
    }
    else if (strchr("(){};", s[0]))
    {
        others.push_back(s);
        cout<<"< "<<s<<",Operator>"<<endl;
    }
}





void process(string code)
{
    string s;

    for (int i = 0; i < code.length();)
    {
        //  cout<<code[i]<<" LL"<<endl;
        if (isspace(code[i]))
        {
            i++;
            continue;
        }
        // key, fun, dType
       
        else if(code[i]=='+' || code[i]=='-' || code[i]=='<'|| code[i]=='=' ||code[i]=='>')
        {
            s.clear();
            while (i < code.length() && (code[i]=='+' || code[i]=='-' || code[i]=='<'|| code[i]=='=' ||code[i]=='>'))
            {
                s.push_back(code[i++]);
            }
            verify_token(s);
            //  cout<<s<<endl;

        }
        if (isalpha(code[i]) || code[i] == '_')
        {
            s.clear();
            while (i < code.length() && (isalnum(code[i]) || code[i] == '_'))
            {
                s.push_back(code[i++]);
            }
            //  cout<<s<<" "<<"dd"<<endl;
            verify_token(s);
        }
        // numbers
        else if (isdigit(code[i]))
        {
            s.clear();
            while (i < code.length() && (isdigit(code[i]) || code[i] == '.'))
            {
                s.push_back(code[i++]);
            }
            verify_token(s);
            // cout<<s<<endl;
        }
       
        else
        {
            s.clear();
            s.push_back(code[i++]);
            verify_token(s);
            //  cout<<s<<endl;
        }
    }
}
int main()
{
    ifstream input_file("in.txt");
    if (!input_file.is_open())
    {
        cerr << "Error: Could not open the file 'in.txt'" << endl;
        return 1;
    }

    string code, line;
    while (getline(input_file, line))
    {
        code += line + '\n';
    }
    input_file.close();
    // cout<<code<<endl;
    process(code);
 
    cout << "Function: ";
    for (auto x : functions)
    {
        
            cout << x << " ";
          
        check[x]++;
    }
    cout << endl;
   
    cout << "Operators: ";
    for (auto x : operators)
    {
       
            cout << x << " ";
       
    }
    cout << endl;
    cout << "Data Type: ";
    for (auto x : dataTypes)
    {
        
            cout << x << " ";
         
            check[x]++;
    }
    cout << endl;
   
    cout << "Keywords: ";
    for (auto x :keywords)
    {
        
            cout << x << " ";
          
            check[x]++;
    }
    cout << endl;
   
    cout << "Others: ";
    for (auto x : others)
    {

        

            if(check[x]==0){
                cout << x << " ";
             
            
        }
    }
    cout << endl;
    
    
}
