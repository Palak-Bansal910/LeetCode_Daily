class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int curr_alt = 0;
        int largest_alt = 0;
        for(int i = 0; i < n; i++){
            curr_alt += gain[i];
            largest_alt = max(curr_alt, largest_alt);
        }

        return largest_alt;
    }
};