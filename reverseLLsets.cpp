//reverse LL in sets of k

struct node *reverse (struct node *head, int k)
{
    struct node dummyGroupTail = {0};
    struct node* lastGroupTail = &dummyGroupTail;

    while (NULL != head) {
    struct node* nextGroupTail = head;
    struct node* rev = NULL;
    for (int cnt = k; (0 != cnt--) && (NULL != head); ) {
    struct node* next = head->next;
    head->next = rev;
    rev = head;
    head = next;
    }
    lastGroupTail->next = rev;
    lastGroupTail = nextGroupTail;
    }
    return dummyGroupTail.next;

}
