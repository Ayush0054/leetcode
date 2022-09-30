class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxi =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                int x = st.size();
                maxi=max(maxi,x);
                st.pop();
            }
        }
        return maxi;
    }
};