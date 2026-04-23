#include <iostream>
using namespace std;

// Struktur node
struct node {
    int data;
    node* next;
};

class Queue {
public:
    node *front;
    node *back;

    // Constructor
    Queue() {
        front = back = NULL;
    }

    // Fungsi Enqueue: Menambah data ke belakang antrean
    void enqueue(node *n) {
        if (back == NULL) {
            front = back = n;
            return;
        } else {
            back->next = n;
            back = n;
        }
    }

    // Fungsi Dequeue: Menghapus data dari depan antrean
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! (Antrean kosong)" << endl;
            return;
        }

        node* n = front;
        front = front->next;

        // Jika setelah dihapus list menjadi kosong
        if (front == NULL) {
            back = NULL;
        }

        delete(n);
    }

    // Fungsi Print: Menampilkan isi antrean
    void print() {
        if (front == NULL) {
            cout << "Antrean kosong." << endl;
            return;
        }
        node* ptr = front;
        while (ptr != NULL) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
};

// Fungsi pembantu untuk membuat node baru
node* createNode(int val) {
    node* newNode = new node();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Queue q;

    cout << "--- Menambah ke Antrean (Enqueue) ---" << endl;
    q.enqueue(createNode(100));
    q.enqueue(createNode(200));
    q.enqueue(createNode(300));
    q.print(); // Output: 100 -> 200 -> 300 -> NULL

    cout << "\n--- Menghapus dari Depan (Dequeue) ---" << endl;
    q.dequeue();
    q.print(); // Output: 200 -> 300 -> NULL

    cout << "\n--- Tambah data lagi (400) ---" << endl;
    q.enqueue(createNode(400));
    q.print(); // Output: 200 -> 300 -> 400 -> NULL

    return 0;
}
