#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(LicensePlate plate) {
    Node* newNode = new Node;
    newNode->data = plate;
    newNode->next = head;
    head = newNode;
}

bool LinkedList::find(string plateStr) {
    Node* curr = head;
    while (curr) {
        if (curr->data.plateNumber == plateStr)
            return true;
        curr = curr->next;
    }
    return false;
}

void LinkedList::sort() {
    head = mergeSort(head);
}

Node* LinkedList::mergeSort(Node* h) {
    if (!h || !h->next)
        return h;

    Node* a;
    Node* b;
    split(h, &a, &b);

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a, b);
}

void LinkedList::split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

Node* LinkedList::merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;
    if (a->data.plateNumber <= b->data.plateNumber) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}



void LinkedList::displayByProvince(string province) {
    sort();
    Node* curr = head;
    while (curr) {
        string plate = curr->data.plateNumber;
        string plateProvince = plate.substr(0, 2);

        if (plateProvince == province)
            curr->data.display();

        curr = curr->next;
    }
}

void LinkedList::displayByDistrict(string district) {
    sort();
    Node* curr = head;
    while (curr) {
        string plate = curr->data.plateNumber;
        string plateDistrict = plate.substr(3, 2);

        if (plateDistrict == district)
            curr->data.display();

        curr = curr->next;
    }
}

void LinkedList::displayAll() {
    sort();
    Node* curr = head;
    while (curr) {
        curr->data.display();
        curr = curr->next;
    }
}

