class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance =0;
       int defeciet = 0;
       int start =0;
       int i =0;
       while(i!=gas.size()){
           balance = balance + gas[i] - cost[i];
           
           if(balance<0){
               defeciet = defeciet + balance ;
               start = i+1;
               balance = 0;
           }
           i++;
       }
       if(balance+defeciet>=0){
           return start;
       }else{
           return -1;
       }
    }
};