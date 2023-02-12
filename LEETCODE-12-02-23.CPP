// https://leetcode.com/problems/shortest-path-with-alternating-colors/solutions/3177259/c-o-n-e-o-n-e/

class Solution {
public:

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
    //  here we are using bfs because bfs always increases the steps to get to a node by one in each iteration
    // creating graph: here we need to make the graph and store the colors of its edge as 0 if red and 1 if blue
    vector<vector<pair<int,int>>> graph(n); // graph[u,v, color]
    for(auto &i: redEdges)
        graph[i[0]].push_back({i[1], 1});

     for(auto &i: blueEdges)
        graph[i[0]].push_back({i[1], 0});
    
    vector<int> ans(n, -1); // to store the distances
    vector<vector<bool>> vis(n,vector<bool>(2)); // to visit the graph nodes
    queue<vector<int>> q; // to store the nodes
  
    // the node 0 is 0 steps from itself
    vis[0][1]=false;
    vis[0][0]=false;
    ans[0]=0;
    q.push({0,0,-1}); // we dont visit the 0 node from any other node as it is senseless
    while(!q.empty())
    {
        auto qfront=q.front();
        q.pop();
        int currnode=qfront[0]; // this is the current node
        int steps=qfront[1]; // this is the number of steps from 0 to current node so far
        int prevcolor=qfront[2]; // the color of the first visit

        for(auto [next, color]: graph[currnode])
        {
            if(!vis[next][color] && color!=prevcolor)
            {
                vis[next][color]=true;
                q.push({next, steps+1, color});
                if(ans[next]==-1)
                  ans[next]=steps+1;
            }
        }
    }
    return ans;
    }
};


