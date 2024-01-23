#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node* create_node(int item){
        node *n;
        n = new node;
        n->data = item;
        n->left = NULL;
        n->right = NULL;

        return n;
    }

    int height(node *n){
        if (n == NULL){
            return -1;
        }
        else if (n->left == NULL && n->right == NULL){
            return 0;
        }
        else {
            int left_h = height(n->left);
            int right_h = height(n->right);

            if (left_h > right_h)
                return (left_h + 1);
            else
                return (right_h + 1);
        }
    }

    // Number of leaves
    int countleaf(node *n){
        if (n == NULL)
            return 0;
        else if(n->left == NULL && n->right == NULL)
            return 1;
        else
            return countleaf(n->left) + countleaf(n->right);
    }

    // Number of nodes
    int count(node *n){
        if (n ==  NULL)
            return 0;
        else
            return(1 + count(n->left) + count(n->right));
    }

    void delete_tree(node *n){
        if (n == NULL)
            return;

        delete_tree(n->left);
        delete_tree(n->right);

        delete n;
    }

    int max(node *n){
        int m, lmax, rmax;

        if (n == NULL)
            return -1;
        m = n->data;
        lmax = max(n->left);
        rmax = max(n->right);

        if(lmax > m)
            m = lmax;
        else if(rmax > m)
            m = rmax;

        return m;
    }

    void preorder(node *n){
        if(n != NULL){
            cout << n->data << " ";
            preorder(n->left);
            preorder(n->right);
        }
    }

    void inorder(node *n){
        if (n != NULL){
            inorder(n->left);
            cout << n->data << " ";
            inorder(n->right);
        }
    }

    void postorder(node *n){
        if (n != NULL){
            postorder(n->left);
            postorder(n->right);
            cout << n->data << " ";
        }
    }
};

int main(){
    node *root = nullptr;
    node obj;

    int item, choice;
    do{
        cout << "1. Create a new node\n";
        cout << "2. Calculate height\n";
        cout << "3. Count leaves\n";
        cout << "4. Count nodes\n";
        cout << "5. Delete tree\n";
        cout << "6. Find maximum value\n";
        cout << "7. Preorder traversal\n";
        cout << "8. Inorder traversal\n";
        cout << "9. Postorder traversal\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter data for the new node: ";
                cin >> item;
                root = obj.create_node(item);
                break;

            case 2:
                cout << "Height of the tree: " << obj.height(root) << endl;
                break;

            case 3:
                cout << "Number of leaves: " << obj.countleaf(root) << endl;
                break;

            case 4:
                cout << "Number of nodes: " << obj.count(root) << endl;
                break;

            case 5:
                obj.delete_tree(root);
                cout << "Tree deleted successfully.\n";
                break;

            case 6:
                cout << "Maximum value in the tree: " << obj.max(root) << endl;
                break;

            case 7:
                cout << "Preorder traversal: ";
                obj.preorder(root);
                cout << endl;
                break;

            case 8:
                cout << "Inorder traversal: ";
                obj.inorder(root);
                cout << endl;
                break;

            case 9:
                cout << "Postorder traversal: ";
                obj.postorder(root);
                cout << endl;
                break;

            case 0:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
