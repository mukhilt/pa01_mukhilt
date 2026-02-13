// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

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

  CardBST Alice;
  CardBST Bob;
  char suit;
  int value;
  string valueSt;

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)) {
    suit = line[0];
    valueSt = line.substr(2);
    if (valueSt == "a") value = 1;
    else if (valueSt == "j") value = 11;
    else if (valueSt == "q") value = 12;
    else if (valueSt == "k") value = 13;
    else value = stoi(valueSt);
    Card c(suit, value);
    Alice.insert(c);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)) {
    suit = line[0];
    valueSt = line.substr(2);
    if (valueSt == "a") value = 1;
    else if (valueSt == "j") value = 11;
    else if (valueSt == "q") value = 12;
    else if (valueSt == "k") value = 13;
    else value = stoi(valueSt);
    Card c(suit, value);
    Bob.insert(c);
  }
  cardFile2.close();

  playGame(Alice, Bob);

  cout << endl;
  
  cout << "Alice's cards: " << endl;
  for (auto it = Alice.begin(); it != Alice.end(); ++it) {
    cout << *it << endl;
  }
  cout << endl;
  cout << "Bob's cards: " << endl;
  for (auto it = Bob.begin(); it != Bob.end(); ++it) {
    cout << *it << endl;
  }
  
  return 0;
}
