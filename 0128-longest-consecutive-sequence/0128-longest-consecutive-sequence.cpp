class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longest = 0;
        for(auto i:nums){
            s.insert(i);
        }
        for(auto i : s){
            if(s.find(i-1) == s.end()){
                int current = i;
                int length = 1;
                while(s.find(current + 1) != s.end()){
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }   
        }
        
        return longest;
    }
};