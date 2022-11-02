class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*" ){
                long long op1 = s.top();
                s.pop();
                 long long op2 = s.top();
                s.pop();
                if(tokens[i]=="+") op1=op2+op1;
                if(tokens[i]=="-") op1=op2-op1;
                if(tokens[i]=="/") op1=op2/op1;
                if(tokens[i]=="*") op1=op2*op1;
                s.push(op1);
            }
            else{
                s.push(stoll(tokens[i]));
            }
            
        }
        return s.top();
    }
};