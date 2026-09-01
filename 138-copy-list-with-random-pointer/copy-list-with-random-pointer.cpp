/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( !head ) return head ;

        unordered_map<Node*, vector<Node*>> rand ;
        Node *temp = head, *head2 = NULL, *prev2 = NULL ;

        while( temp ){
            Node* temp2 = new Node(temp->val) ;
            if ( !head2 ) head2 = temp2 ;
            if ( prev2 ) prev2 -> next  = temp2 ; 
            prev2 = temp2 ;
            rand[temp ->random].push_back( temp2 ) ; 
            temp = temp -> next ;   
        }
        temp = head ;
        Node* temp2 = head2 ;
        while ( temp2 ) {
            for ( int i = 0 ; i < rand[temp].size() ; i++ ) {
                rand[temp][i] -> random = temp2 ;
            }
            temp = temp -> next ;
            temp2 = temp2 -> next ;
        }
        return head2 ;
    }
};