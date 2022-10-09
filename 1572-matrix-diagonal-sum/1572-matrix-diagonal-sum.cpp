class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int sum =0;
        for(int i=0;i<m;i++){
            sum = sum + mat[i][i] + mat[i][m-1-i];
        }
        
        if(m%2==0){
            return sum;
        }
        else{ 
        return sum - mat[m/2][m/2]; 
        }
    }
};