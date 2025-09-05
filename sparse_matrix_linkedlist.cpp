#include <iostream>
using namespace std;

struct Node {
    int row;
    int col;
    int val;
    Node* next;
};

Node* addOrUpdate(Node* head, int r, int c, int v) {
    if (v == 0) return head;

    Node* cur = head;
    while (cur != nullptr) {
        if (cur->row == r && cur->col == c) {
            cur->val = v;
            return head;
        }
        cur = cur->next;
    }

    Node* n = new Node;
    n->row = r;
    n->col = c;
    n->val = v;
    n->next = head;
    return n;
}

    // simple search through the list

int getValue(Node* head, int r, int c) {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->row == r && cur->col == c) {
            return cur->val;
        }
        cur = cur->next;
    }
    return 0;
}

void printDense(Node* head, int rows, int cols) {
    cout << "\nMatrix (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << getValue(head, i, j) << " ";
        }
        cout << "\n";
    }
}

void freeList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

// Main function

int main() {
    int rows, cols, nz;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter number of non-zero entries: ";
    cin >> nz;

    if (rows <= 0 || cols <= 0 || nz < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    Node* head = nullptr;

    cout << "Enter non-zero entries:\n";
    for (int i = 0; i < nz; i++) {
        int r, c, v;
        cout << "  Entry " << (i + 1) << ": ";
        cin >> r >> c >> v;

        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "  Skipped\n";
            continue;
        }

        head = addOrUpdate(head, r, c, v);
    }

    printDense(head, rows, cols);

    freeList(head);
    return 0;
}
