#include "NextWord.hpp"

Guessing::Guessing() {
    
    srand(static_cast<unsigned int>(time(0)));

}

void Guessing::startMessage() {
std::cout << "Welcome to the guessing word game! A word will be given to you\n"
"and your objective is to guess the word or phrase that is part\n"
"of the given word. For instance, if the given word is 'I'm', you\n"
"guess 'out'. Each player that guesses the correct guess word will\n"
"be given a point. The first player to accumulate the most points\n"
"wins the game! Good luck!\n\n\n";

}

void Guessing::_createList() {
    
    ifstream inputData;
    
    inputData.open("Guessing Words.txt");
    
    if (inputData.fail()) {
        std::cout << "Error\n";
    }
    
    else {
        
        map<string, string>::iterator itr;
        
        string temp1,
        temp2;
                
        inputData >> size;
        
        for (int i = 0; i < size; i++) {
            inputData >> temp1;
            inputData >> temp2;
            
            words.push_back(temp1);
            guessWords.push_back(temp2);
        }
        
    //        for (int i = 0; i < size; i++) {
    //            std::cout << words[i] << std::endl;
    //            std::cout << guessWords[i] << std::endl;
    //        }
        
        for (int i = 0; i < size; i++) {
            list.insert(pair<string, string>(words[i], guessWords[i]));
        }
        
    }
    
}

void Guessing::setScore(int points) {
    this->score = points;
}

int Guessing::getScore() {
    
    return score;
}

void Guessing::setName(string n) {
    this->name = n;
}

string Guessing::getName(){
    return name;
}

void Guessing::validateInt(int &input) {
    while ((input < 1) || (input > 10) || std::cin.fail() || std::cin.get() != '\n') {
        std::cout << "\nInvalid entry, please try again.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter: ";
        std::cin >> input;
        std::cout << std::endl;
    }
}

void Guessing::_userNames() {
    
    p1 = new Guessing();
    p2 = new Guessing();
    std::cout << "Player 1 please enter your name: ";
    std::getline(std::cin, name);
    p1->setName(name);

    std::cout << "Player 2 please enter your name: ";
    std::getline(std::cin, name);
    p2->setName(name);

    std::cout << p1->name << std::endl;
    std::cout << p2->name << std::endl;

}

void Guessing::_increaseScore(Guessing* &player) {
    player->setScore(player->getScore() + 1);
}

void Guessing::_generateWord(Guessing* &player) {
    
    int pos = rand() % (size - 1) + 1;
    
    std::cout << pos << std::endl;
    
    auto answer = list[words[pos]];
    if(list[words[pos]].find(guessWords[pos]) == false) {
        std::cout << "Key: " << words[pos] << std::endl;
        std::cout << "Value: " << guessWords[pos] << std::endl;
        std::cout << answer << std::endl;
    }
    
    _increaseScore(player);
    
}

void Guessing::start() {
    
    _createList();
    
    _userNames();

//    int rounds,
//    count;
//
//    std::cout << "\nEnter number of rounds (Max 10): ";
//    std::cin >> rounds;
//    validateInt(rounds);
    

    _generateWord(p1);

    
        
}


void Guessing::testPrint() {
    map<string, string>::iterator itr;

    for (itr = list.begin(); itr != list.end(); itr++) {
        std::cout << itr->first << " -> " << itr->second << std::endl;
    }
    
}


Guessing::~Guessing() {}
