/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case 1: empty list
        if (head == nullptr)
        {
            return nullptr;
        }
        
        // Base case 2: one item in list
        if (head && head->next == nullptr)
        {
            return head;
        }

        auto currNode = head->next;
        auto prevNode = head;
        head->next = nullptr;

        while (currNode != nullptr)
        {
            auto nextNode = currNode->next;
            currNode->next = prevNode;
            
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }
};
