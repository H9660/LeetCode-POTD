// https://leetcode.com/problems/edit-distance/description/
// Solution: https://leetcode.com/problems/edit-distance/solutions/3233037/c-o-n-m-o-n-m/

class Solution {
public:
    
    int solve(string a, string b, int m, int n, vector<vector<int>> dp)
    {
      if(m==0 || n==0)
      return max(m,n);
      
      if(dp[m][n]!=-1)
      return dp[m][n];

      if(a[m-1]==b[n-1])
      return dp[m][n]=solve(a,b,m-1,n-1,dp);
      else return dp[m][n]=min(solve(a,b,m-1, n-1, dp), min(solve(a,b,m-1,n,dp),solve(a,b,m,n-1,dp)))+1;
    }

    int solvetab(string a, string b, int n, int m, vector<vector<int>> dp)
    {
        for(int i=0;i<=n;i++)
        dp[i][0]=i;   // here the total number of deletions
        for(int i=0;i<=m;i++)
        dp[0][i]=i;   //  number of insertions
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];

                else dp[i][j]=min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
            }
        }

        return dp[n][m];

    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1,-1));
        return solvetab(word1, word2, word1.length(), word2.length(), dp);
    }
}; 
