class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string,int> freq;

        for(int i = 0; i < n; i++){
            string sub = "";

            for(int j = i; j < n; j++){
                sub += s[j];

                bool special = true;
                for(int k = 1; k < sub.size(); k++){
                    if(sub[k] != sub[0]){
                        special = false;
                        break;
                    }
                }

                if(special)
                    freq[sub]++;
            }
        }

        int ans = -1;

        for(auto &i : freq){
            if(i.second >= 3)
                ans = max(ans, (int)i.first.size());
        }

        return ans;
        
    }
};