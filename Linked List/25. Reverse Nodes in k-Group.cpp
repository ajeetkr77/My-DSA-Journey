*********************************************************

 Time Complexity : O(N)

Space Complexity : O(N)

******************************************************************

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> list;

        ListNode* temp = head;

        while(temp != nullptr){
            list.push_back(temp->val);
            temp = temp->next;
        }

        int n = list.size();

        int index = 0;

        while( index + k <= n ){
            reverse(list.begin() + index, list.begin() + index + k);
            index += k;
        }

        ListNode *head1 = new ListNode(list[0]);

        temp = head1;

        for(int i = 1; i < n; i++){  
            ListNode* node = new ListNode(list[i]);
            temp->next = node;
            temp = temp->next;
        }

        return head1;
    }
};
