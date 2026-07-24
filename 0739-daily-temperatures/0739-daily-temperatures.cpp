class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> days(n,0);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(st.size() > 0 && temp[i] >= temp[st.top()]){
                    st.pop();
            }
            if (!st.empty())
                days[i] = st.top() - i;
            st.push(i);
        }
        return days;
    }
};