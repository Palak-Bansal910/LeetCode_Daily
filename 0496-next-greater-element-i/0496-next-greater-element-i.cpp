class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
    //   *OPTIMAL APPROACH*
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = n- 1; i >= 0; i--){
            while(st.size() > 0 && arr[i]>= st.top()){
                    st.pop();
            }
            if(st.empty()){ 
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> Nge = nextLargerElement(nums2);
        vector<int> ans(nums1.size(),0);
        unordered_map<int,int> map;
        for(int i = 0; i < nums2.size();i++){
            map[nums2[i]] = Nge[i];
        }
        for(int i = 0; i <nums1.size(); i++){
            ans[i] = map[nums1[i]];
        }

        return ans;
    }
};