#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node* createNode(int item);
    node* insert(node* root, int item);
    node* search(node* root, int item);
    node* remove(node* root, int item);
    void inorder(node* root);
    void postorder(node* root);
    void preorder(node* root);
    
};

node* node::createNode(int item) {
    node* n;
    n = new node;
    n->data = item;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* node::insert(node* root, int item) {
    if (root == NULL)
        return createNode(item);

    if (item < root->data)
        root->left = insert(root->left, item);
    else if (item > root->data)
        root->right = insert(root->right, item);

    return root;
}

node* node::remove(node* root, int item) {
    if (root == NULL)
        return root;

    if (item < root->data)
        root->left = remove(root->left, item);
    else if (item > root->data)
        root->right = remove(root->right, item);
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

node* node::search(node* root, int item) {
    if (root == NULL || root->data == item)
        return root;

    if (item < root->data)
        return search(root->left, item);
    else if (item > root->data)
        return search(root->right, item);

    return NULL;
}

void node::inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << "-";
        inorder(root->right);
    }
    cout << endl;
}

void node::postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "-";
    }
    cout << endl;
}

void node::preorder(node* root) {
    if (root != NULL) {
        cout << root->data << "-";
        preorder(root->left);
        preorder(root->right);
    }
    cout << endl;
}

int main() {
    node tree;
    node* root = NULL;
    int choice;
    int item;

    do {
        cout << "1. Insert item to tree " << endl;
        cout << "2. Search item in tree " << endl;
        cout << "3. Show inorder tree " << endl;
        cout << "4. Show postorder tree " << endl;
        cout << "5. Show preorder tree " << endl;
        cout << "6. Delete node " << endl;
        cout << "0. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item to insert: ";
            cin >> item;
            root = tree.insert(root, item);
            break;
        case 2:
            cout << "Enter item for search on Tree: ";
            cin >> item;
            if (tree.search(root, item)) {
                cout << "Item found in the tree." << endl;
            }
            else {
                cout << "Item not found in the tree." << endl;
            }
            break;
        case 3:
            cout << "Inorder Tree items: " << endl;
            tree.inorder(root);
            break;
        case 4:
            cout << "Postorder Tree items: " << endl;
            tree.postorder(root);
            break;
        case 5:
            cout << "Preorder Tree items: " << endl;
            tree.preorder(root);
            break;
        case 6:
            cout << "Enter item to delete " << endl;
            cin >> item;
            root = tree.remove(root, item);
            break;
        }

    } while (choice != 0);

    return 0;
}
