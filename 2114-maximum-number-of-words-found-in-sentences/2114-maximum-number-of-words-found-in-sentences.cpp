class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res =0;
        for(int i =0;i<sentences.size();i++){
            int ans =0;
             for(int j=0;j<sentences[i].size();j++){
                  if(sentences[i][j]==' '){
                      ans++;
             }
             }
            res = max(res,ans+1);
        }
        return res;
    }
};