class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal = 0, res = 0;
        for(char ch : s){
            if(ch == '(')
                bal++;
            else{
                if(bal == 0) res++;
                else bal--;
            }
        }
        return bal+res;
    }
};
// stack<char> st;

        // for(char ch : s) {
        //     if(ch == '(') {
        //         st.push(ch);
        //     } else {
        //         if(!st.empty() && st.top() == '(')
        //             st.pop();
        //         else
        //             st.push(ch);
        //     }
        // }

        // return st.size();