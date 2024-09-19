class Solution {
    unordered_map<int,vector<int>> graph;
    unordered_map<int,int> visited;
    
    bool dfs(int course){
        if(visited[course] ==1) return false;
        if(visited[course] == 2) return true;

        visited[course] = 1;//mark as visiting

        for(int neighbor : graph[course]){
            if(!dfs(neighbor)) return false;
        }

        visited[course] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //fill the adj 
        for(const auto& pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }

        //check all nodes

        for(int i = 0; i<numCourses; ++i){
            if(visited.find(i) == visited.end()){
                if(!dfs(i)) return false;
            }
        }
        return true;
    }
};
