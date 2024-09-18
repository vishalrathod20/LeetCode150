/*
// Definition for a Node.
class Node {
public:
    int val; // Value of the node
    vector<Node*> neighbors; // List of neighboring nodes (connected nodes)
    
    // Default constructor: initializes node value to 0 and an empty neighbors list.
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    // Constructor: initializes node with the given value and an empty neighbors list.
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    // Constructor: initializes node with the given value and provided neighbors list.
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    // A hash map to keep track of already visited nodes. Maps original nodes to their cloned counterparts.
    unordered_map<Node* , Node*> visited;

public:
    // Function to clone the graph
    Node* cloneGraph(Node* node) {
        // If the input node is null, return nullptr (base case for recursion).
        if(!node) return nullptr;
        
        // If the node is already cloned (found in the visited map), return the cloned node.
        if(visited.find(node) != visited.end()){
            return visited[node];
        }

        // Create a new node with the same value as the current node.
        Node* cloneNode = new Node(node->val);

        // Mark the current node as visited by storing the clone in the map.
        visited[node] = cloneNode;

        // Recursively clone all the neighboring nodes of the current node.
        for(Node* neighbor : node->neighbors){
            // Add the cloned neighbors to the cloneNode's neighbors list.
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        // Return the fully cloned node.
        return cloneNode;
    }
};
