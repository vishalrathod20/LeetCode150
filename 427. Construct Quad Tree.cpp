/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid,0,0,grid.size());
    }

    Node* build(const vector<vector<int>>& grid, int x, int y, int length){
        if(allSame(grid,x,y,length)){
            return new Node(grid[x][y],true);
        }

        int halfLength = length/2;
        Node* topLeft = build(grid,x,y,halfLength);
        Node* topRight = build(grid,x,y+halfLength,halfLength);
        Node* bottomLeft = build(grid,x+halfLength, y, halfLength);
        Node* bottomRight = build(grid,x+halfLength,y+halfLength,halfLength);

        return new Node(true,false,topLeft,topRight,bottomLeft,bottomRight);
    }

    bool allSame(const vector<vector<int>>& grid, int x, int y ,int length){
        int val = grid[x][y];
        for(int i = x; i< x+length; ++i){
            for(int j = y; j<y+length; ++j){
                if(grid[i][j] != val){
                    return false;
                }
            }
        }
        return true;
    }

};
