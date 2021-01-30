// P1 
// Time complexity : 
// Push O(1) + O(1)
// Pop O(1) + O(1)
// delete O(1)

// head - 5,
// mid - 5,
// countNode 1,



Node* push(Node* head, int val)
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    countNode++;
    if(countNode == 1) mid = newNode;
    else
    {
        if(countNode%2) mid = mid->prev;
    }
    return newNode;
}

int pop(Node* head)
{
    if(!countNode) return -1;
    int val = head->data;
    head = head->next;
    head->prev = NULL;
    countNode--;
    if(countNode == 0) mid = NULL;
    if(!countNode%2) mid = mid->next;
    return val;
}

void deleteMiddle()
{
    if(countNode == 1) free(mid);
    Node* mid2 = mid;
    if(mid2->next != NULL)
        mid2->next->prev = mid2->prev;
    if(mid2->prev != NULL)
        mid2->prev->next = mid->next;
    //free(mid2);
    countNode--;
    if(!countNode%2) mid = mid->prev;
    if(countNode%2) mid = mid->next;
    free(mid2);
    
}


