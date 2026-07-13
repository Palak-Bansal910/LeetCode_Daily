class Solution {
public:
    int& minVal(int &a, int &b, int &c) {
            if (a <= b && a <= c)
                return a;
            else if (b <= a && b <= c)
                return b;
            else
                return c;
    }
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> map(26,vector<int>(3,-1));
        int maxlen = -1;
        char prev = '*';
        int curr_len = 1;
        for(char ch : s){
            int ind = ch -'a';
            curr_len = (prev == ch)? curr_len+1:1;
            prev = ch;
            int& mini = minVal(map[ind][0],map[ind][1],map[ind][2]);
            if(curr_len > mini){
                mini = curr_len;
            }        
        }
        for(int i = 0; i < 26; i++){
            int temp = min({map[i][0],map[i][1],map[i][2]});
            maxlen = max(maxlen, temp);
        }
        return maxlen;

        
    }
    /*unordered_map<string,int> freq;

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
        */
        
};