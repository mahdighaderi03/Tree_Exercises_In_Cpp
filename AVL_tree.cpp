#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    int height;

    node* create_node(int item) {
        node *n;
        n = new node;

        n->data = item;
        n->left = NULL;
        n->right = NULL;
        n->height = 1;
        return n;
    }

    void preorder(node *n) {
        if (n != NULL) {
            cout << n->data << " ";
            preorder(n->left);
            preorder(n->right);
        }
    }

    node* right_rotation(node *y) {
        node *x, *t2;
        x = y->left;
        t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    node* left_rotation(node* x) {
        node *y, *t2;

        y = x->right;
        t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    node* insert(node *root, int item) {
        if (root == NULL)
            return create_node(item);

        if (item < root->data)
            root->left = insert(root->left, item);
        else if (item > root->data)
            root->right = insert(root->right, item);
        else
            return root;

        root->height = max(height(root->left), height(root->right)) + 1;

        int b = balance(root);

        // left left rotation
        if (b >= 2 && item < root->left->data)
            return right_rotation(root);

        if (b <= -2 && item > root->right->data)
            return left_rotation(root);

        // left right rotation
        if (b >= 2 && item > root->left->data) {
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }

        // right left rotation
        if (b <= -2 && item < root->right->data) {
            root->right = right_rotation(root->right);
            return left_rotation(root);
        }

        return root;
    }

    node* remove(node *root, int item) {
        if (root == NULL)
            return root;

        if (item < root->data)
            root->left = remove(root->left, item);
        else if (item > root->data)
            root->right = remove(root->right, item);
        else {
            if (root->left == NULL || root->right == NULL) {
                node *temp = root->left ? root->left : root->right;

                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                node* temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;

                root->data = temp->data;
                root->right = remove(root->right, temp->data);
            }
        }

        if (root == NULL)
            return root;

        root->height = max(height(root->left), height(root->right)) + 1;

        int b = balance(root);

        // left left rotation
        if (b >= 2 && balance(root->left) >= 0)
            return right_rotation(root);

        // left right rotation
        if (b >= 2 && balance(root->left) < 0) {
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }

        // right right rotation
        if (b <= -2 && balance(root->right) <= 0)
            return left_rotation(root);

        // right left rotation
        if (b <= -2 && balance(root->right) > 0) {
            root->right = right_rotation(root->right);
            return left_rotation(root);
        }

        return root;
    }

    int height(node *n) {
        if (n == NULL)
            return 0;
        return n->height;
    }

    int max(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }

    int balance(node *n) {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }
};

int main() {
    node tree;
    node* root = NULL;
    int choice;
    int item;

    do {
        cout << "1. Insert item to tree " << endl;
        cout << "2. Show preorder tree " << endl;
        cout << "3. Remove node " << endl;
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
            cout << "Preorder Tree items: " << endl;
            tree.preorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Enter item to delete: ";
            cin >> item;
            root = tree.remove(root, item);
            break;
        }

    } while (choice != 0);

    return 0;
}
