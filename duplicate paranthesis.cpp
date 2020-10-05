#include<iostream>
#include<stack>
using namespace std;
bool duplicate_paranthesis(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=')')
        st.push(s[i]);
        else
        {
            if(st.empty() || st.top()=='(')
            {
                return true;
            }
            while(!st.empty() && st.top()!='(')
            {
                st.pop();
            }
            if(st.empty())
            return true;
            else
            st.pop();
        }
    }
    return false;
}
int main()
{
    string str;
    cin>>str;
    if(duplicate_paranthesis(str))
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}