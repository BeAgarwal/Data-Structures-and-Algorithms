
Node *reverse(Node *node){
    if(node == NULL)
        return NULL;
    Node *current = node;
    Node *previous = NULL, *following = NULL;
    while(current != NULL){
        following = current->next;
        current->next = previous;
        previous = current;
        current = following;
    }
    return previous;
}

struct Node * mergeResult(Node *node1,Node *node2)
{
    if(node1 == NULL and node1 == NULL)
        return NULL;
    if(node1 == NULL)
        return reverse(node2);
    if(node2 == NULL)
        return reverse(node1);
        
    Node *head1 = node1;
    Node *head2 = node2;
    Node *temp = new Node;
    Node *res = temp;
 
    while(head1 && head2){
        if(head1->data < head2->data){
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    if(head1) temp->next = head1;
    if(head2) temp->next = head2;
 
    return reverse(res->next);
}
