class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cell, int n) {
        vector<int> temp(8);
        vector<vector<int>> seen;
        while(n--){
            for(int i = 1; i < 7; i++){
                temp[i] = cell[i-1] == cell[i+1];
            }
            if(seen.size() && seen.front() == temp){
                return seen[n % seen.size()];
            }else{
                seen.push_back(temp);
            }
            cell = temp;
        }
        return cell;
    }
};