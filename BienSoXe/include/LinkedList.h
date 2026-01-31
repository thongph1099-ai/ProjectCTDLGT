#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LicensePlate.h"

struct Node {
    LicensePlate data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

    
    Node* mergeSort(Node* h);
    Node* merge(Node* a, Node* b);
    void split(Node* source, Node** front, Node** back);

public:
    LinkedList();
    ~LinkedList();

    void insert(LicensePlate plate);
    bool find(string plateStr);
    void sort(); 
    void displayByProvince(string province);
    void displayByDistrict(string district);
    void displayAll();
    LicensePlate* search(string plate);
};

#endif
