class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string w = "123456789";
        int r1 = to_string(low).size();
        int r2 = to_string(high).size();
        vector<int> ans;
        for(int i = 2; i <=9; i++){
            for(int j = 0; j <= w.size()-i; j++){
                int num = stoi(w.substr(j,i));
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};