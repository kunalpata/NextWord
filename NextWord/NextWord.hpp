#ifndef NextWord_hpp
#define NextWord_hpp

#include <stdio.h>

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::ifstream;
using std::vector;
using std::map;
using std::pair;

class Guessing {
  
private:
    int score;
    string name;
    vector<string> words;
    vector<string> guessWords;
    map<string, string> list;
    /* need to declare as pointers since class declaration isn't
     complete yet, class declaration complete after ;
     pointer to class let's compiler know Guessing is the class so
     now it's defined, use dynamic memory allocation use objects*/
    Guessing *p1,
    *p2;
    
    void _createList();

    
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
    
    // input validation
    void validateInt(int &input);
    void validateString(string &input);
    
    ~Guessing();
    
};
#endif /* NextWord_hpp */
