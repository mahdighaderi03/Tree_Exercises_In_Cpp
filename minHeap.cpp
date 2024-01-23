#include <iostream>
using namespace std;

int *x;
int c;
int size;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int parent(int i) {
    return (i - 1) / 2;
}

void add(int item) {
    if (size == c)
        return;

    size++;
    int i = size - 1;
    x[i] = item;

    while (i != 0 && x[i] < x[parent(i)]) {
        swap(&x[i], &x[parent(i)]);
        i = parent(i);
    }
}

void minheapfy(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < size && x[l] < x[i])
        smallest = l;
    if (r < size && x[r] < x[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&x[i], &x[smallest]);
        minheapfy(smallest);
    }
}

int remove() {
    int root;
    if (size <= 0)
        return -1;
    if (size == 1) {
        size--;
        return x[0];
    }

    root = x[0];
    x[0] = x[size - 1];
    size--;
    minheapfy(0);

    return root;
}

int main() {
    cout << "Enter the capacity of the heap: ";
    cin >> c;
    x = new int[c];
    size = 0;

    int choice, item;
    do {
        cout << "Menu: " << endl;
        cout << "1. Add element " << endl;
        cout << "2. Remove element " << endl;
        cout << "3. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to add: ";
                cin >> item;
                add(item);
                break;

            case 2:
                item = remove();
                if (item != -1)
                    cout << "Removed element: " << item << endl;
                else
                    cout << "Heap is empty! " << endl;
                break;

            case 3:
                cout << "Exiting the program. " << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option. " << endl;
        }

    }while (choice != 3);

    delete[] x;
    return 0;
}
