*****************************************
  Naive Approach
****************************************

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        vector<int> list;

        for(int i = 0; i < n; i++){
            ListNode* temp = lists[i];

            while(temp != nullptr){
                list.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        if(list.size() == 0) 
            return nullptr;

        sort(list.begin(), list.end());

        ListNode *head = new ListNode(list[0]);

        ListNode *temp = head;

        for(int i = 1; i < list.size(); i++){
            temp->next = new ListNode(list[i]);
            temp = temp->next;
        }

        return head;
    }
};
