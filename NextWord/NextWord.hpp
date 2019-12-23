#ifndef NextWord_hpp
#define NextWord_hpp

#include <stdio.h>

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using std::string;
using std::ifstream;
using std::vector;
using std::map;
using std::pair;
using std::set;


class Guessing {
  
private:
    int score = 0,
    size = 0,
    tempPos = 0;
    string name;
    vector<string> words;
    vector<string> guessWords;
    map<string,set<string>> list;
    set<string> usedWords;

    /* need to declare as pointers since class declaration isn't
     complete yet, class declaration complete after ;
     pointer to class let's compiler know Guessing is the class so
     now it's defined, use dynamic memory allocation use objects*/
    Guessing *p1,
    *p2;
    
    void _createList();
    void _userNames();
    string _generateWord();
    void _increaseScore(Guessing* &player);
    bool _wordChecker(Guessing* &player, string keyWord, string guessWord);
    void _playerTurn(Guessing* &player1, Guessing* &player2);
    bool _playerInput(Guessing* &player);
    void _playerStats(Guessing* &player1, Guessing* &player2);
    
public:
    Guessing();
    void start();
    void startMessage();
    
    // setters and getters
    void setScore(int);
    int getScore();
    void setName(string);
    string getName();
    
    // test to print
    void testPrint();
    void wordImporter();
    
    // input validation
    void validateInt(int &input);
    bool validateString(string &input);
    
    ~Guessing();
    
};
#endif /* NextWord_hpp */
