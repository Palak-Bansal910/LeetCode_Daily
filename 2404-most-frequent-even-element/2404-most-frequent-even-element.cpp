class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> freq;
        for (auto num : nums) {
            if (num % 2 == 0)
                freq[num]++;
        }
        int ans = -1;
        int maxFreq = 0;

        for (auto i : freq) {
            if (i.second > maxFreq) {
                maxFreq = i.second;
                ans = i.first;
            }
        }

        return ans;
    }
};