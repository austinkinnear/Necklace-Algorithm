#include "Necklace.h"
#include <iostream>
using namespace std;

BeadNode::BeadNode(const std::string& mat) : material(mat), next(nullptr) {}

Necklace::Necklace() : head(nullptr) {}

Necklace::~Necklace() {
    while (head) {
        BeadNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int Necklace::append(const std::string& material) {
    if (material != "turquoise" && material != "coral" && material != "gold" && material != "copper") {
        return -1; // fails
    }

    BeadNode* newNode = new BeadNode(material);
    if (!head) {
        head = newNode;
    } else {
        BeadNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return 0; 
}

int Necklace::insert(int position, const std::string& material) {
    if (material != "turquoise" && material != "coral" && material != "gold" && material != "copper") {
        return -1; // fails
    }

    BeadNode* newNode = new BeadNode(material);
    if (!head) {
        head = newNode;
    } else if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        BeadNode* current = head;
        int count = 0;
        while (current && count < position - 1) {
            current = current->next;
            count++;
        }
        if (!current) {
            return -1; // Position does not exist
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    return 0; 
}

int Necklace::deleteNode(int position) {
    if (!head) {
        return -1; // empty list
    }

    if (position == 0) {
        BeadNode* temp = head;
        head = head->next;
        delete temp;
    } else {
        BeadNode* current = head;
        int count = 0;
        while (current && count < position - 1) {
            current = current->next;
            count++;
        }
        if (!current || !current->next) {
            return -1; // Position does not exist
        }
        BeadNode* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    return 0; 
}

int Necklace::search(const string& material) {
    BeadNode* current = head;
    int position = 0;
    while (current) {
        if (current->material == material) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Material not found
}

void Necklace::display() {
    BeadNode* current = head;
    int position = 0;
    while (current) {
        cout << "(" << position << ") " << current->material << endl;
        current = current->next;
        position++;
    }
}

int Necklace::size() {
    int count = 0;
    BeadNode* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}
