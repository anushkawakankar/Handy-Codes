void connect(Node *p)
{
   if (p==NULL)
    return;

    queue<Node*>q;
    q.push(p);

    while(!q.empty())
    {
        int size=q.size();
        Node* prev=NULL;

        while(size--)
        {
            Node* temp=q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);

            if(prev!=NULL)
                prev->nextRight=temp;

            prev=temp;
        }

        prev->nextRight=NULL;
    }
}
