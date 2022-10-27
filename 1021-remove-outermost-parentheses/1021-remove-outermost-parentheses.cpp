class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans ="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(st.size()>0){
                    ans = ans + '(';
                }
                st.push('(');
            }
            else{
                if(st.size()>1){
                    ans = ans + ')';
                }
                st.pop();
            }
        }
        return ans;
        
        /***********************
       // second approach 
        string ans="";
        int opened = 0;
        for (char c : s) {
            if (c == '(' && opened++ > 0){               
                ans += c;
            }
            if (c == ')' && opened-- > 1){           
                ans += c;
            }
        }
        return ans;
        
        *****************/
        
        
        
        
    }
};