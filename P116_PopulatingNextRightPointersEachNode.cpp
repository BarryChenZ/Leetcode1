class Solution {
public:
    Node* connect(Node* root)
    {
        if (!root) return NULL;
        queue<Node*> que;
        que.push(root);
        int n=1;
        Node *tmp=NULL;

        while(!que.empty())
        {
            for (int i=0; i<n; i++)
            {
                tmp = que.front();
                que.pop();
                tmp->next = (que.empty()?NULL:que.front());
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
            n = que.size();
            tmp->next = NULL;
        }
        return root;
    }
};
