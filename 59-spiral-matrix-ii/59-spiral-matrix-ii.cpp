class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vv(n,vector<int>(n));
        int rowstart = 0;
        int rowend= n-1;
        int colstart =0;
        int colend= n-1;
        
        int cnt =1;
        
        while(colstart<=colend && rowstart<=rowend){
            for(int i = colstart ; i<=colend;i++){
                vv[rowstart][i] = cnt++;
            }
            rowstart++;
            
            for(int i = rowstart ; i<=rowend;i++){
                vv[i][colend] = cnt++;
            }
            colend--;
            for(int i = colend ; i>=colstart;i--){
                vv[rowend][i] = cnt++;
            }
            rowend--;
            for(int i = rowend ; i>=rowstart;i--){
                vv[i][colstart] = cnt++;
            }
            colstart++;
            
        }
        return vv;
    }
};