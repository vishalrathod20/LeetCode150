/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
     // Pass head and tail by reference to modify them in the function
    void insertAtTail(Node*& head, Node*& tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL; // Handle the edge case of an empty list

        // Step 1: Create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;

        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Step 2: Create a map to link original nodes to clone nodes
        unordered_map<Node*, Node*> oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode != NULL) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // Step 3: Adjust the random pointers of the cloned nodes
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL) {
            if (originalNode->random != NULL) {
                cloneNode->random = oldToNewNode[originalNode->random];
            } else {
                cloneNode->random = NULL;
            }
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

**********************************************************************************************************************************************************************************
**********************************************************************************************************************************************************************

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Agar list khali hai toh seedha null return kar do
        if (head == NULL) return NULL; // Handle edge case of empty list
        
        // Step 1: Har node ka clone banao aur usse original node ke saath interweave karo
        Node* temp = head;
        while (temp != NULL) {
            Node* newNode = new Node(temp->val); // Current node ka ek clone banao
            newNode->next = temp->next; // Clone ko original node ke baad insert karo
            temp->next = newNode; // Original node ko clone se link karo
            temp = newNode->next; // Agli original node par move karo
        }

        // Step 2: Cloned nodes ke random pointers adjust karo
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next; // Clone ke random pointer ko set karo
            }
            temp = temp->next->next; // Agli original node par move karo
        }

        // Step 3: Original list aur cloned list ko alag karo
        Node* cloneHead = head->next; // Cloned list ka head set karo
        Node* original = head; // Original list ke liye pointer
        Node* clone = cloneHead; // Cloned list ke liye pointer

        while (original != NULL) {
            original->next = original->next->next; // Original list ko restore karo
            if (clone->next != NULL) {
                clone->next = clone->next->next; // Cloned list ko restore karo
            }
            original = original->next; // Agli original node par move karo
            clone = clone->next; // Agli cloned node par move karo
        }

        return cloneHead; // Cloned list ka head return karo
    }
};
