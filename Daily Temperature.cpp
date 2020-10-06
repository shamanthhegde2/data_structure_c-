 vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size());
        stack<int> st;
        for(int i=0;i<T.size();i++)
        {
            if(st.empty() || T.at(st.top())>=T.at(i))
            {
                st.push(i);//0
            }
            else
            {
                while(!st.empty() && T.at(st.top())<T.at(i))
                {
                    ans.at(st.top())=i-st.top();//1
                    st.pop();//0
                }
                st.push(i);//1
            }
        }
        return ans;
        
    }