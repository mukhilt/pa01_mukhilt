// card_list.cpp
// Author: Mukhil Thavathiru Murugan
// Implementation of the classes defined in card_list.h

#include <iostream>
#include "card_list.h"
using namespace std;

CardBST::CardBST() {
    root = nullptr;
}
CardBST::~CardBST() {
    clear(root);
}
void CardBST::clear(Node* current) {
    if (current == nullptr) {
        return;
    }
    clear(current->left);
    clear(current->right);
    delete current;
}
bool CardBST::insert(const Card& card) {
    if (root == nullptr) {
        root = new Node(card);
        return true;
    }
    return insert(root, card);
}
bool CardBST::insert(Node* current, const Card& card) {
    if (card == current->card) {
        return false;
    }
    if (card > current->card) {
        if (current -> right == nullptr) {
            Node* newNode = new Node(card);
            newNode->parent = current;
            current->right = newNode;
            return true;
        }
        return insert(current -> right, card);
    }
    if (card < current -> card) {
        if (current -> left == nullptr) {
            Node* newNode = new Node(card);
            newNode->parent = current;
            current -> left = newNode;
            return true;
        }
        return insert(current -> left, card);
    }
    return false;
}
bool CardBST::contains(const Card& card) const{
    Node* current = root;
    while (current != nullptr) {
        if (current -> card == card) {
            return true;
        }
        else if (current -> card < card) {
            current = current->right;
        }
        else {
            current = current->left;
        }
    }
    return false;
}
bool CardBST::remove(const Card& card) {
    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr && !(current->card == card)) {
        parent = current;
        if (card < current->card) current = current->left;
        else current = current->right;
    }

    if (current == nullptr) return false;

    Node* target = current;

    if (target->left != nullptr && target->right != nullptr) {
        Node* successorParent = target;
        Node* successor = target->right;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        target->card = successor->card;
        parent = successorParent;
        target = successor;
    }

    Node* child = (target->left != nullptr) ? target->left : target->right;

    if (parent == nullptr) {
        root = child;
        if (child) child->parent = nullptr;
    } else if (parent->left == target) {
        parent->left = child;
        if (child) child->parent = parent;
    } else {
        parent->right = child;
        if (child) child->parent = parent;
    }

    delete target;
    return true;
}

const Card& CardBST::Iterator::operator*() const {
    return current->card;
}

bool CardBST::Iterator::operator==(const Iterator& it) const {
    return current == it.current;
}

bool CardBST::Iterator::operator!=(const Iterator& it) const {
    return current != it.current;
}

CardBST::Iterator& CardBST::Iterator::operator++() {
    if (current == nullptr) {
        return *this;
    }
    if (current -> right != nullptr) {
        current = current -> right;
        while (current -> left != nullptr) {
            current = current -> left;
        }
        return *this;
    }
    Node* par = current->parent;
    while (par != nullptr && current == par->right) {
        current = par;
        par = par->parent;
    }
    current = par;
    return *this;
}

CardBST::Iterator& CardBST::Iterator::operator--() {
    if (current == nullptr) return *this;

    if (current->left != nullptr) {
        current = current->left;
        while (current->right != nullptr) {
            current = current->right;
        }
        return *this;
    }
    Node* p = current->parent;
    while (p != nullptr && current == p->left) {
        current = p;
        p = p->parent;
    }
    current = p;
    return *this;
}

CardBST::Iterator CardBST::begin() const {
    Node* cur = root;
    if (cur == nullptr) return Iterator(nullptr);
    while (cur->left != nullptr) cur = cur->left;
    return Iterator(cur);
}
CardBST::Iterator CardBST::end() const {
    return Iterator(nullptr);
}

CardBST::Iterator CardBST::rbegin() const {
    Node* cur = root;
    if (cur == nullptr) return Iterator(nullptr);
    while (cur->right != nullptr) cur = cur->right;
    return Iterator(cur);
}
CardBST::Iterator CardBST::rend() const {
    return Iterator(nullptr);
}

void playGame(CardBST& Alice, CardBST& Bob) {
    bool matchFound = true;

    while (matchFound) {
        matchFound = false;
        for (auto it = Alice.begin(); it != Alice.end(); ++it) {
            Card c = *it;
            if (Bob.contains(c)) {
                cout<<"Alice picked matching card " << c << endl;
                Alice.remove(c);
                Bob.remove(c);
                matchFound = true;
                break;
            }
        }

        for (auto it = Bob.rbegin(); it != Bob.rend(); --it) {
            Card c = *it;
            if (Alice.contains(c)) {
                cout<<"Bob picked matching card " << c << endl;
                Bob.remove(c);
                Alice.remove(c);
                matchFound = true;
                break;
            }
        }
    }
}



