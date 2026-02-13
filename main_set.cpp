// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  set<Card> Alice;
  set<Card> Bob;

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    char suit = line[0];
    string valueString = line.substr(2);
    int value;
    if (valueString == "a") {
      value = 1;
    }
    else if (valueString == "j") {
      value = 11;
    }
    else if (valueString == "q") {
      value = 12;
    }
    else if (valueString == "k") {
      value = 13;
    }
    else {
      value = stoi(valueString);
    }
    Card card(suit, value);
    Alice.insert(card);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit = line[0];
    string valueString = line.substr(2);
    int value;
    if (valueString == "a") {
      value = 1;
    }
    else if (valueString == "j") {
      value = 11;
    }
    else if (valueString == "q") {
      value = 12;
    }
    else if (valueString == "k") {
      value = 13;
    }
    else {
      value = stoi(valueString);
    }
    Card card(suit, value);
    Bob.insert(card);
  }
  cardFile2.close();

  while (true) {
    bool found = false;
    for (auto it = Alice.begin(); it != Alice.end(); ++it) {
      auto itBob = Bob.find(*it);
      if (itBob != Bob.end()) {
        cout << "Alice picked matching card " << *it << endl;
        Bob.erase(itBob);
        Alice.erase(it);
        found = true;
        break;
      }
    }

    for (auto it = Bob.rbegin(); it != Bob.rend(); ++it) {
      auto itAlice = Alice.find(*it);
      if (itAlice != Alice.end()) {
        cout << "Bob picked matching card " << *it << endl;
        Alice.erase(itAlice);
        auto itBob = Bob.find(*it);
        Bob.erase(itBob);
        found = true;
        break;
      }
    }
    if (found == false) {
      break;
    }
  }


  cout << "Alice's cards:" << endl;
  for (auto it = Alice.begin(); it != Alice.end(); ++it) {
    cout << *it << endl;
  }
  cout << endl;
  cout << "Bob's cards:" << endl;
  for (auto it = Bob.begin(); it != Bob.end(); ++it) {
    cout << *it << endl;
  }

  return 0;

}


