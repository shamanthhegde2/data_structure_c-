class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> st;
        int n=heights.size();
        int max_area=0;
        int area_top=0;
        int i=0;
        int current;
        while(i<n)
        {
            if(st.empty() || heights[st.top()]<=heights[i])
            {
                st.push(i);
                i++;
            }
            else
            {
                current=st.top();
                st.pop();
                area_top=heights[current]*(st.empty()?i:i-st.top()-1);
                if(area_top > max_area)
                    max_area=area_top;
            }
        }
        while(!st.empty())
        {
            current=st.top();
            st.pop();
            area_top=heights[current]*(st.empty()?i:i-st.top()-1);
            if(area_top > max_area)
                max_area=area_top;
            
        }
        return max_area;
    }
};