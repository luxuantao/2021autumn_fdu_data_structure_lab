struct ListNode* mergeSort(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *work = head;
    while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
            work -> next = l1;
            l1 = l1 -> next;
        } else {
            work -> next = l2;
            l2 = l2 -> next;
        }
        work = work -> next;
    }
    work -> next = l1 ? l1 : l2;
    return head -> next;
}

struct ListNode* sortList(struct ListNode* head){
    if (!head || !head -> next) {
        return head;
    }
    struct ListNode *slow = head, *fast = head, *pre = fast;
    while (fast && fast -> next) {
        pre = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    pre -> next = NULL;
    return mergeSort(sortList(head), sortList(slow));
}
