#include <cstdlib>
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int val) {
        this->data = val;
        this->next = nullptr;
    }
};

class LinkedList {
  private:
    Node *head;

  public:
    void traverse() {
        Node *temp = this->head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        newNode->next = this->head;
        this->head = newNode;
    }

    void insertAtGivenPosition(int val, int position) {
        Node *temp = this->head;

        for (int i = 2; i < position; i++) {
            if (temp->next != nullptr) {

                temp = temp->next;
            }
        }

        Node *newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);

        // Please don't forget this important condition
        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }

        Node *temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deleteAtBeginning() {
        Node *temp = this->head;
        this->head = this->head->next;
        free(temp);
    }

    void deleteAtGivenPostion(int position) {
        Node *temp = this->head;
        for (int i = 2; i < position; i++) {
            if (temp->next != nullptr) {
                temp = temp->next;
            }
        }
        Node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }

    void deleteAtEnd() {
        Node *temp = this->head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = nullptr;
        free(temp2);
    }

    int search(int val) {
        Node *temp = this->head;
        int inc = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                return inc++;
            }
            temp = temp->next;
            inc++;
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    LinkedList l = LinkedList();

    // Insert At the End
    cout << "Testing insert at the End : ";
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);

    l.traverse();

    // Insert At the Beginning
    cout << "Testing insert at the Beginning : ";
    l.insertAtBeginning(-1);
    l.insertAtBeginning(-2);
    l.insertAtBeginning(-3);
    l.insertAtBeginning(-4);
    l.insertAtBeginning(-5);

    l.traverse();

    // Insert at the given position
    cout << "Testing insert at the given position : ";
    l.insertAtGivenPosition(10, 2);
    l.insertAtGivenPosition(10, 5);

    l.traverse();

    cout << endl;
    cout << endl;

    // Delete At the Beginning
    cout << "Delete At the Beginning : ";

    l.deleteAtBeginning();
    l.deleteAtBeginning();
    l.deleteAtBeginning();

    l.traverse();

    // Delete At the Given Position
    cout << "Delete At the Given Position : ";
    l.deleteAtGivenPostion(2);
    l.traverse();

    // Delete At the End
    cout << "Delete At the End : ";
    l.deleteAtEnd();
    l.traverse();

    // Search the value
    cout << "Search for the Given Value : ";
    cout << l.search(-3) << endl;
    cout << l.search(-2) << endl;
    cout << l.search(4) << endl;
    cout << l.search(10) << endl;
    return 0;
}
