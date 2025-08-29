#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseToEnd(ListNode* head) {
    ListNode*fast=head,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        //reverse half sau ,tu slow den fast
        ListNode*start=slow->next;
        while(start&&start->next){
            ListNode*next=start->next;
            start->next=next->next;
            next->next=slow->next;
            slow->next=next;
        }
        return head;
        //while(slow&&slow->next){
          //  head->next
        //}
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next= new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);

    std::cout << "Original List: ";
    printList(head);

     // Start reversing from node with value 2
    head = reverseToEnd(head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}
