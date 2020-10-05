#include <iostream>
#include<vector>
using namespace std;
class stack
{
    vector<int> v;
    public:
    void push(int data)
    {
        v.push_back(data);
    }
    bool empty()
    {
        return v.empty();
    }
    void pop()
    {
        if(!v.empty())
        {
            v.pop_back();
        }
    }
    int top()
    {
        return v.back();
    }
};

int main()
{
    stack s;
    for(int i=1;i<=10;i++)
    {
        s.push(i);
    }
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
