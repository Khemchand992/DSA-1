
#include <stack>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int precedance(char c)
{
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='-' || c=='+')return 1;
    return 0;
}
string postfix(string s){
    stack<char> st;
    string ans="";
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }
        else if((s[i]>='A' && s[i]<='Z')|| (s[i]>='a' && s[i]<='z'))ans+=s[i];
        else {
            while(!st.empty() && precedance(s[i])<=precedance(st.top())){
                if(st.top()=='(')break;
                else {
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    int ch;
    do{
        
        cout<<"1: Want to find postfix "<<endl;
        cout<<"2: EXIT "<<endl;
        cout<<endl<<endl;
        cout<<"Enter choice "<<endl;
        cin>>ch;
        switch(ch){
            case 1: 
                    string s;
                    cout<<"Enter expression "<<endl;
                    cin>>s;
                    cout<<"Postfix expression of "<<s<<" is "<<postfix(s)<<endl;
                    break;
            
                    
        }
        
    }while(ch!=2);
    

    return 0;
}
