class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int bal = 0;
        string ans = "";
        stack<char> st;
        for(char ch : s){
            if(ch == '(') bal++;
            else if(ch == ')'){
                if(bal == 0) continue;
                bal--;
            }
            st.push(ch);
        }
        string temp = "";
        for(stack<char> i = st;!i.empty();i.pop()){
            temp += i.top();
        }
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] == '(' && bal-- > 0) continue;
            ans += temp[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
        //  stack<int> st;

        // for(int i = 0; i < s.size(); i++) {
        //     if(s[i] == '(') {
        //         st.push(i);
        //     }
        //     else if(s[i] == ')') {
        //         if(!st.empty()) {
        //             st.pop();
        //         }
        //         else {
        //             s[i] = '*';  
        //         }
        //     }
        // }

        // while(!st.empty()) {
        //     s[st.top()] = '*';  
        //     st.pop();
        // }

        // string ans;
        // for(char ch : s) {
        //     if(ch != '*')
        //         ans += ch;
        // }

        // return ans;