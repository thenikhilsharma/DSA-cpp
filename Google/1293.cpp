class Solution {
public:
    int solve(vector<vector<int>>& grid,int k){
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;

        q.push({0,0,0,k}); // x, y, curr path len, no. of obstacles we can remove
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            q.pop();

            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()) continue; // exit if current position is outside of the grid
            if(x==grid.size()-1 && y==grid[0].size()-1) return t[2]; // destination found
            if(grid[x][y]==1){
                if(t[3]>0) t[3]--; // if we encounter an obstacle and we can remove it
                else continue;
            }
			
			// the cell was previously visited by some path and we were able to remove more obstacles from the previous path.
			// then we don't need to continue on our current path
            if(vis[x][y]!=-1 && vis[x][y]>=t[3]) continue;
            vis[x][y]=t[3];
            
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
            
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) { return solve(grid,k); }
};