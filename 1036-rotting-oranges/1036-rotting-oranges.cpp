class Solution {
public:
bool is_inbound(int n, int m, int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        
        // Count the number of fresh oranges and enqueue the rotten ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        if (fresh == 0) return 0; // If there are no fresh oranges, return 0
        
        int ans = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS to spread the rot
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            for (int k = 0; k < size; k++) {
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();
                
                for (auto dir : dirs) {
                    int new_i = curr_i + dir.first;
                    int new_j = curr_j + dir.second;
                    if (is_inbound(n, m, new_i, new_j) && grid[new_i][new_j] == 1) {
                        grid[new_i][new_j] = 2;
                        fresh--;
                        q.push({new_i, new_j});
                        rotted = true;
                    }
                }
            }
            if (rotted) ans++;
        }
        
        if (fresh > 0) return -1; // If there are still fresh oranges left, return -1
        return ans;
    }
};