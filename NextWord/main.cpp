#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include "NextWord.hpp"

using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::map;
using std::pair;
using std::set;


int main() {
        
    Guessing startGame;

    startGame.startMessage();

    startGame.start();
    
    return 0;
}

