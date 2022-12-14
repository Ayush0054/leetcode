class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i =0;i<s.length();i++){
            if(s[i]==']'){
                string temp;
                while(!st.empty()&& st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                string num;
                while(!st.empty()&& isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int number = stoi(num);
                string repeat;
                for(int j=0;j<number;j++){
                    repeat+=temp;
                }
                for(int k=0;k<repeat.size();k++){
                    st.push(repeat[k]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        return res;
    }
};