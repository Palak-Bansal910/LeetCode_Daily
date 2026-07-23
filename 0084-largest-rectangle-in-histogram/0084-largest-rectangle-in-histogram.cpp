class Solution {
public:
    vector<int> nextSmallerLeft(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = 0; i <= n -1; i++){
            while(st.size() > 0 && arr[i]<= arr[st.top()]){
                    st.pop();
            }
            ans[i]=st.size() == 0? -1: st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerRight(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(st.size() > 0 && arr[i]<= arr[st.top()]){
                    st.pop();
            }
            ans[i]=st.size() == 0? n: st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        int n  = heights.size();
        vector<int> l = nextSmallerLeft(heights);
        vector<int> r = nextSmallerRight(heights);
        for(int i = 0; i< n; i++){
            int area = (r[i] - l[i] -1)* heights[i];
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};