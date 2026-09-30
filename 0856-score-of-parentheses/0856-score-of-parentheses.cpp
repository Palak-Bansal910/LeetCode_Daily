class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;
        for(char& c : s){
            if(c == '('){
                st.push(score);
                score = 0;
            }else{
                score += st.top() + max(score, 1);
                st.pop();
            }
        }
        return score;
    }
};