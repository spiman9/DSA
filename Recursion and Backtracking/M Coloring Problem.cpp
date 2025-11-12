// You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

// Note: The graph is indexed with 0-based indexing.

// Examples:
// Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
// Output: true
// Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj;
        
        prepareGraph(adj , edges , v); // prepare the grphj
        int colors[v] = {0};
        return solve(0 , adj , m , colors);
    }
    
    
    bool solve(int node , vector<vector<int>>&adj , int m , int colors[]){
        if(node == adj.size()){
            return true;
        }
        
        for(int i = 1 ; i <= m ; i++){
            //assign this color for checl
            if(CheckColor(node , i , m , colors , adj)){
                //we can assign color
                colors[node] = i;
                if(solve(node + 1 , adj , m , colors)){
                    return true;
                }
                colors[node] = 0;
            }
        }
        return false;
    }
    
    bool CheckColor(int node , int color , int m , int colors[] , vector<vector<int>>&adj){
        for(auto child : adj[node]){
            if(colors[child] == color){
                //adready taken color
                return false;
            }
        }
        return true;
    }
    
    void prepareGraph(vector<vector<int>>&adj , vector<vector<int>> &edges , int v){
        for(int i = 0 ; i < v ;++i){
            vector<int>temp;
            adj.push_back(temp);
        }
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }
};