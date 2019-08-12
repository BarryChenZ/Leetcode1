/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> OldToNew;
        map<Node*, bool> visited;
        Node* temp;
        if(head == NULL) return head;
        queue<Node*> q;
        q.push(head);
        visited[head] = true;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            OldToNew[temp] = new Node(temp->val, NULL, NULL);
            if(visited.find(temp->next) == visited.end() && temp->next != NULL){
                q.push(temp->next);
                visited[temp->next] = true;
            }
            if(visited.find(temp->random) == visited.end() && temp->random != NULL){
                q.push(temp->random);
                visited[temp->random] = true;
            }
        }
        for(auto oldtonew : OldToNew){
            oldtonew.second->next = OldToNew[oldtonew.first->next];
            oldtonew.second->random = OldToNew[oldtonew.first->random];
        }
        return OldToNew[head];
    }
};
