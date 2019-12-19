#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "NextWord.hpp"

using std::string;
using std::ifstream;
using std::vector;
using std::map;
using std::pair;


int main() {
        
    Guessing startGame;

    startGame.startMessage();
    
    startGame.start();
            
    
    return 0;
}
