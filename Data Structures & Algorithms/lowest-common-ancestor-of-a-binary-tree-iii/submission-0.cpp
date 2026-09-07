/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<int> seen;
       
        while (p != nullptr)
        {
            seen.insert(p->val);
            p = p->parent;
        }
        
        while (q != nullptr)
        {
            if (seen.contains(q->val))
            {
                return q;
            }

            q = q->parent;
        }

        return nullptr;
    }
};