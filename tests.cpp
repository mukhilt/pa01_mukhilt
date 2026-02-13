#include <iostream>
#include <cassert>
#include "card.h"
#include "card_list.h"

using namespace std;

int main() {

    // INSERT / CONTAINS
    {
        CardBST t;
        Card a('h', 5);
        Card b('s', 10);

        assert(!t.contains(a));
        assert(t.insert(a));
        assert(t.contains(a));
        assert(t.insert(b));
        assert(!t.insert(a)); // duplicate
    }

    // REMOVE
    {
        CardBST t;
        Card a('h', 5);
        Card b('s', 10);

        assert(!t.remove(a)); // empty
        t.insert(a);
        t.insert(b);

        assert(t.remove(a));
        assert(!t.contains(a));
        assert(!t.remove(a)); // remove twice
    }

    // ITERATOR EMPTY
    {
        CardBST t;
        assert(t.begin() == t.end());
        assert(t.rbegin() == t.rend());
    }

    // ITERATOR SINGLE
    {
        CardBST t;
        Card a('h', 5);
        t.insert(a);

        auto it = t.begin();
        assert(*it == a);
        ++it;
        assert(it == t.end());

        auto rit = t.rbegin();
        assert(*rit == a);
        --rit;
        assert(rit == t.rend());
    }

    // PLAYGAME BASIC
    {
        CardBST A;
        CardBST B;

        A.insert(Card('h', 5));
        A.insert(Card('s', 9));

        B.insert(Card('h', 5));
        B.insert(Card('d', 3));

        playGame(A, B);

        assert(!A.contains(Card('h', 5)));
        assert(!B.contains(Card('h', 5)));
    }

    cout << "OK\n";
    return 0;
}
