class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];

        }
     for(int i=1;i<n;i++){
         for(int j=0;j<n;j++){
             if(j==0){
                 dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+matrix[i][j];
             }else if(j==(n-1)){
                  dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+matrix[i][j];
             }else{
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+matrix[i][j];
             }
         }
     }
  sort(dp[n-1],dp[n-1]+n);
  return dp[n-1][0];      
    }
};
