// https://leetcode.com/problems/max-area-of-island/description/

class Solution {
public:
    
    vector<pair<int, int>> steps = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
    
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        int m = grid.size(), n = grid[0].size(), ans = 0;
        stack<pair<int, int>> stk;
        
        if (grid[i][j] && !visited[i][j]) {
            stk.push({i, j});
            visited[i][j] = true;
        }
        
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            ans++;
            for(auto step : steps){
                int r = top.first + step.first;
                int c = top.second + step.second;
                if (r > -1 && r < m && c > -1 && c < n && grid[r][c] && !visited[r][c]){
                    stk.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        
        return ans;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.size() ? grid[0].size() : 0, ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                ans = max(ans, dfs(grid, i, j, visited));
        }
        
        return ans;
    }
};
