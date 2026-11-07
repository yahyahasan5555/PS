// https://leetcode.com/problems/partition-list/description/

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
       // ListNode* head {};
       // Solution(int val): head(new ListNode(val)) {}
       
       ListNode* partition(ListNode* head, int x) {
              ListNode *less_list_head {nullptr}, *less_list_tail {nullptr};
              ListNode *greater_list_head {nullptr}, *greater_list_tail {nullptr}; 

              while(head) {
                     ListNode* next {head->next};

                     if(head->val < x) {
                            if(!less_list_head) less_list_head = less_list_tail = head;
                            else less_list_tail->next = head, less_list_tail = head;
                            less_list_tail->next = nullptr;
                     } else {
                            if(!greater_list_head) greater_list_head = greater_list_tail = head;
                            else greater_list_tail->next = head, greater_list_tail = head;
                            greater_list_tail->next = nullptr;
                     }

                     head = next;
              }

              if(less_list_tail) {
                     less_list_tail->next = greater_list_head;
                     return less_list_head;
              }

              return greater_list_head;
       }

       // void insert(int x) {
       //        if(!head) head = new ListNode(x);
       //        else {
       //               ListNode* cur {head};
       //               while(cur && cur->next) cur = cur->next;
       //               cur->next = new ListNode(x);
       //        }
       // }

       // void print() {
       //        for(ListNode* cur {head}; cur; cur = cur->next) cout << cur->val << ' '; cout << endl;
       // }


};

// void testCase(void) {
//        Solution sol(1);
//        sol.insert(4);
//        sol.insert(3);
//        sol.insert(2);
//        sol.insert(5);
//        sol.insert(2);
       
//        sol.print(); // 1 4 3 2 5 2
//        sol.partition(sol.head, 3);
//        sol.print(); // 1 2 2 4 3 5
// }


// signed main() {
//        testCase();
//        return 0;
// }