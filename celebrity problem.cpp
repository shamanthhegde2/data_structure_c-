int getId(int M[MAX][MAX], int n)
{
    stack<int> st;
    for(int i=0;i<n;i++)
    st.push(i);
    while(st.size()>1)
    {
        int row=st.top();
        st.pop();
        int col=st.top();
        st.pop();
        if(M[row][col]==0)
        {
            st.push(row);
        }
        else
        {
            st.push(col);
        }
    }
    int cand=st.top();
    st.pop();
    for(int i=0;i<n;i++)
    {
        if(cand!=i)
        {
            if(M[cand][i]==1 || M[i][cand]==0)
            return -1;
        }
    }
    return cand;
}