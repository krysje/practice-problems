#include <bits/stdc++.h>
using namespace std;

struct Node{   
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(int val){
    Node* root = new Node(val);
    return root;
}

Node* search(Node* node, int val){
    Node* out = NULL;

    if(node == NULL)
        return NULL;

    queue<Node*> q;
    q.push(node);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp->data == val) {out = temp; /*cout<<"FOUND "<<endl;*/}
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    return out;
}

Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    Node* nodeToInsert = createNode(val);

    queue<Node*> q;
    q.push(root);
    Node* temp = NULL;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->left == NULL){ temp->left = nodeToInsert; return temp->left;}      
        else  q.push(temp->left);

        if(temp->right == NULL){ temp->right = nodeToInsert; return temp->right;}      
        else  q.push(temp->right);
    }
    return root;
}

void setExtremeRightToNULL(Node* root, Node* deepestRight){
    queue<Node*> q;
    Node* temp = NULL;
    
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->left != NULL){
            if(temp->left == deepestRight){
                temp->left = NULL;
                return;
            }

             else q.push(temp->left);

        }

        if(temp->right != NULL){
            if(temp->right == deepestRight){ 
                temp->right = NULL;
                return;
            }

            else q.push(temp->right);
        
        }
    }
}

void deletenode(Node* root, int val){
    Node* nodeTodelete = search(root, val);

    if(nodeTodelete == NULL){
        cout<<"Node not found."<<endl;
        return;
    }

    queue<Node*> q;
    Node* temp = NULL;

    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->left != NULL)  q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }

    int deepestRight = temp->data;
    setExtremeRightToNULL(root, temp);
    nodeTodelete->data = deepestRight;

}

void DFSiterative(Node* root){
    queue<Node*> q;
    Node* temp = NULL;

    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<< temp->data <<", ";

        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);

        }
    }

void printPreorder(struct Node* node){
    if (node == NULL)
        return;
 
    cout << node->data << " ";
 
    printPreorder(node->left);
    printPreorder(node->right);
}

string DFSRecursive(Node* root, int level){
    if(root == NULL) return "-";

    if(level == 1)  return to_string(root->data);
    if(level > 1)   return DFSRecursive(root->left, level-1) + ", " + DFSRecursive(root->right, level-1); 

    return "";
}

void printTree(Node* root, int height){
    for(int i = 0; i <= height+1; i++)
        cout<< DFSRecursive(root, i)<<endl;

}

string preorder(Node* root,unordered_map<string,int> &m){
   
    string s="";
    
    if(root==NULL) return s;
    
        s += root->data;
        s += preorder(root->left,m);
        s += preorder(root->right,m);
        m[s]++;
       
        return s;
    }

bool dupSub(Node *root) {
    unordered_map<string,int> m;
    
    preorder(root,m);

        for(auto i:m){
            if(i.first.length()>1&&i.second>1){
                return 1;
            }
        }

    return 0;
}

int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(4);
    root->right = createNode(3);
    root->right->left = createNode(5);

    printPreorder(root);
    cout<<endl;

   // Node* node = search(root, 4);
   // cout<<node->data<<endl;


    Node* node1 = insert(root, 6);

    printPreorder(root);
    cout<<endl;

    deletenode(root, 2);

    printPreorder(root);
    cout<<endl;

    deletenode(root, 8);

    DFSiterative(root);

    cout<<endl;

    printTree(root, 2);




    return 0;
}