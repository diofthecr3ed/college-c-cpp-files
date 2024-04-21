#include <iostream>

using namespace std;

class node {
    friend class tree;
   private:
        int data;
        node *lchild, *rchild;
};

class tree {
  private:
        node *root;
        node* insert_node(node*, int);
        bool findNode(node*, int);
        node* createNode(int);
        void print(node *);
        void removeNodes(node *);
  public:
        tree() { root = NULL; }
        tree(int val)   { root = createNode(val); }
        ~tree() { // destructor code goes here
            removeNodes(root);
        }
        void printTree() {    print(this->root); return; }
        void treeFind(int data) {    
                if (findNode(root, data)){
                        cout<<"Node found"<<endl;
                } 
                else{
                        cout<<"Node not found"<<endl;
                }
        }
        void treeInsert(int data)       { insert_node(this->root, data); }
};

void tree::removeNodes(node *root)      // Which order is this?
{
   if (root != NULL)
   {
        removeNodes(root->lchild);
        removeNodes(root->rchild);
        cout << "Deleting... " << root->data << endl;
        delete root;
   }
}

node* tree::createNode(int data)
{
   node *tmp = new node;
   tmp->data = data;
   tmp->lchild = tmp->rchild = NULL;
   return tmp;
}

bool tree::findNode(node * root, int data){
        if (root==nullptr){
                return false;
        }
        if (root->data == data){
                return true;
        }
        if (root->data > data) {
                return findNode(root->lchild, data);
        }
        else {
                return findNode(root->rchild, data);
        }
}

void tree::print(node *root_node) // displaying the nodes (in order)
{
        if (root_node!=nullptr){
        print(root_node ->lchild);
        cout<<root_node->data<<endl; // base condition
        print(root_node -> rchild);
        }
}



node* tree::insert_node(node* root, int data) // inserting nodes!
{
        node* newnode = new node;
        newnode->data=data;
        newnode->lchild = newnode->rchild = NULL;
        if (root==NULL)
                return newnode;
        if (root->data > newnode->data) {
                root->lchild=insert_node(root->lchild, data);
        }
        else {
                root->rchild=insert_node(root->rchild, data);
        }
        return root;
}



int main()
{
   tree t1(66);
   int val;
   cout << "Enter data (-9999 to stop): ";
   cin >> val;
   if (val == -9999) return 0;
   while (val != -9999)
   {
        t1.treeInsert(val);
        cout << "Enter data (-9999 to stop): ";
        cin >> val;
   }

   t1.printTree();
   t1.treeFind(5);
   return 0;
}
