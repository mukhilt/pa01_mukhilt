// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include "card.h"
using namespace std;

class CardBST {
    private:
        struct Node {
            Card card;
            Node *left;
            Node *right;
            Node *parent;

            Node(Card card) {
                this->card = card;
                left = nullptr;
                right = nullptr;
                parent = nullptr;
            }
        };
    void clear(Node* current);
    Node *root;

    public:
        class Iterator {
        private:
            Node *current;
        public:
            Iterator(Node* n = nullptr){
                current = n;
            }
            const Card& operator*() const;
            bool operator==(const Iterator& other) const;
            bool operator!=(const Iterator& other) const;
            Iterator& operator++();
            Iterator& operator--();
        };
        CardBST();
        ~CardBST();
        bool insert(const Card& card);
        bool insert(Node* current, const Card& card);
        bool contains(const Card& card) const;
        bool remove(const Card& card);
        void printInOrder();
        Iterator begin() const;
        Iterator end() const;
        Iterator rbegin() const;
        Iterator rend() const;
};

void playGame(CardBST& Alice, CardBST& Bob);

#endif
