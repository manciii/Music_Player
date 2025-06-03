#include <iostream>
#include <string>

using namespace std;

// Music node class
class Node {
public:
    string name;
    int length;
    string path;
    Node* prev;
    Node* next;

    Node(string name, int length, string path) {
        this->name = name;
        this->length = length;
        this->path = path;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    Node* tempPos;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        tempPos = nullptr;
        size = 0;
    }

    // Add node to the list
    void push(string name, int length, string path) {
        Node* newNode = new Node(name, length, path);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Set default pointer to head
    void setDefaultPointer() {
        tempPos = head;
    }

    // Traverse the list in given direction
    Node* traverse(int direction) {
        if (direction == 1 && tempPos && tempPos->next != nullptr) {
            tempPos = tempPos->next;
            return tempPos;
        } else if (direction == -1 && tempPos && tempPos->prev != nullptr) {
            tempPos = tempPos->prev;
            return tempPos;
        } else {
            return nullptr;
        }
    }

    // Check position of current node
    int nodePosition() {
        if (tempPos == nullptr) return -2; // uninitialized
        if (tempPos->next == nullptr) return -1; // last
        if (tempPos->prev == nullptr) return 1;  // first
        return 0; // middle
    }

    // Utility to print the current song info
    void printCurrent() {
        if (tempPos != nullptr) {
            cout << "Now playing: " << tempPos->name << endl;
            cout << "Length: " << tempPos->length << " min" << endl;
            cout << "Path: " << tempPos->path << endl;
        } else {
            cout << "No song is selected." << endl;
        }
    }
};

// Example usage
int main() {
    DoublyLinkedList dll;

    dll.push("Shipping Lanes", 1, "https://files.freemusicarchive.org/.../Night_Owl.mp3");
    dll.push("Enthusiast", 2, "https://files.freemusicarchive.org/.../Enthusiast.mp3");
    dll.push("Night Owl", 3, "https://files.freemusicarchive.org/.../Shipping_Lanes.mp3");

    dll.setDefaultPointer();
    dll.printCurrent();

    // Go forward
    Node* next = dll.traverse(1);
    if (next != nullptr) {
        dll.printCurrent();
    }

    // Go backward
    Node* prev = dll.traverse(-1);
    if (prev != nullptr) {
        dll.printCurrent();
    }

    return 0;
}
