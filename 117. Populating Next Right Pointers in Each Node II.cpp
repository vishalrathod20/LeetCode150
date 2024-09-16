/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
 if (!root) return nullptr;  // NULL return karna padega kyunki function ka return type Node*

        Node* leftMost = root;

        while (leftMost) {
            Node* head = leftMost;  // Current level ka head node
            Node* prev = NULL;  // Pichle node ko track karne ke liye
            leftMost = NULL;  // Naya level ka leftmost node

            while (head) {
                // Left child ko process karo
                if (head->left) {
                    if (prev) prev->next = head->left;  // Pichle node ka next point kare is node ko
                    else leftMost = head->left;  // Agar level ka pehla node hai, toh leftmost set karo
                    prev = head->left;  // Pichla update karo
                }

                // Right child ko process karo
                if (head->right) {
                    if (prev) prev->next = head->right;
                    else leftMost = head->right;
                    prev = head->right;
                }

                head = head->next;  // Next node pe move karo
            }
        }

        return root;  // Return the root node
    }
};
