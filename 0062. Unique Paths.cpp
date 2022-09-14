62. Unique Paths
class Solution {
public:
    //Method 1: BFS
    int uniquePaths(int m, int n) {
        vector<vector<int>> graph(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> que;
        
        graph[0][0] = 1;
        visited[0][0] = true;
        que.push(make_pair(0,0));
        
        while(!que.empty()){
            pair<int,int> p = que.front();
            que.pop();
            if((p.first + 1) < m) {
                graph[p.first + 1][p.second] += graph[p.first][p.second];
                if(!visited[p.first+1][p.second]) que.push(make_pair(p.first + 1, p.second));
                visited[p.first + 1][p.second] = true;
            }
            if((p.second + 1) < n) {
                graph[p.first][p.second + 1] += graph[p.first][p.second];
                if(!visited[p.first][p.second+1]) que.push(make_pair(p.first, p.second + 1));
                visited[p.first][p.second + 1] = true;
            }
        }
        
        return graph[m-1][n-1];
    }
    
    //Method 2: DP
    int uniquePaths(int m, int n) {  
        if(m == 0 || n == 0)  return 0;  
        int **dp = new int*[m];  
        for(int i = 0; i < m; i++)  dp[i] = new int[n];  
 
        dp[0][0] = 1;  
        for(int i = 1; i < m; i++)   dp[i][0] = 1;  
        for(int j = 1; j < n; j++)   dp[0][j] = 1;  
        
        for(int i = 1; i < m; i++) 
            for(int j = 1; j < n; j++)  
                dp[i][j] = dp[i][j-1] + dp[i-1][j];  
 
        int res = dp[m-1][n-1];  
        for(int i = 0; i < m; i++)  delete [] dp[i];  
          
        delete [] dp;  
        return res;  
    }

};
