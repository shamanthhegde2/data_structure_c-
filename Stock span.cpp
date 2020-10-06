#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
	stack<int> st;
    int n;
    cin>>n;
    int a[n];
    vector<int> ans(n,1);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(st.empty() || a[st.top()]>a[i])
        {
            st.push(i);
        }
        else
        {
            while(!st.empty() && a[st.top()]<=a[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans.at(i)=i-st.top();
            }
            else
            {
                ans.at(i)+=i;
            }
            st.push(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
	}
	return 0;
}