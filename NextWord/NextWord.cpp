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
        
        int numWords;
        
        string temp,
        temp2,
        tempWord,
        answer;
        
        // input number key words
        inputData >> size;
        
        // import key words to words container
        for (int i = 0; i < size; i++) {
            inputData >> temp;
            words.push_back(temp);
        }
        
        //TODO: Enter answers in 2d array
        
        // import number of word elements for each key
        inputData >> numWords;
        
        // import into map and assign key value pairs
        for (int i = 0; i < size; i++) {
            tempWord = words[i];
            for (int i = 0; i < numWords; i++) {
                inputData >> answer;
                list[tempWord].insert(answer);
            }
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

bool Guessing::validateString(string &input) {
    

    for (int i = 0; i < input.length(); i++) {
        putchar(tolower(input[i]));
    }
    
    std::cout << input << std::endl;
    
//    for (const char c : input) {
//        if (!isalpha(c) && !isspace(c)) {
//            std::cout << "\nInvalid entry, please try again.\n";
//            std::cin.clear();
//            std::cin.ignore('\n');
//            std::cout << "Enter: ";
//            std::cin >> input;
//            validateString(input);
//        }
//    }

    return true;
    
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

}

void Guessing::_increaseScore(Guessing* &player) {
    player->setScore(player->getScore() + 1);
}

bool Guessing::_wordChecker(Guessing* &player, string keyWord, string guessWord) {
    
    // iterator to find the key word in map
    map<string,set<string>>::iterator itr = list.begin();
    itr = list.find(keyWord);
    
    // second iterator to find its guess word within map
    set<string> listOfWords = itr->second;
    set<string>::iterator it = listOfWords.find(guessWord);

    
    if(itr != list.end()) {
        if (it != listOfWords.end()) {
            return true;
        }
    }
    
    return false;
}

string Guessing::_generateWord() {
    
    int pos = 0;
    bool check = false;

    /* only allows each word to appear once in game, uses a set
     to store the words in to prevent duplicate appearances */
    while (check == false) {
        pos = rand() % size;
                
        // check in set to see if word exists
        set<string>::iterator it = usedWords.begin();
        it = usedWords.find(words[pos]);
        
        // if it reached end of set the word isn't in the set
        if (it == usedWords.end()) {
            usedWords.insert(words[pos]);
            check = true;
        }
    }

    return words[pos];
        
}

bool Guessing::_playerInput(Guessing* &player) {
    
    string key,
    guess,
    line;
    
    bool rightWord;

    
    std::cout << player->getName() << "'s turn\n";
    std::cout << line.assign(12, '-') << std::endl;
    
    key = _generateWord();
    
    std::cout << "Word: " << key << std::endl;
    std::cout << "Enter word to guess: ";
    std::cin >> guess;
    //TODO: use tolower() to lowercase input
    
    rightWord = _wordChecker(player, key, guess);
    
    if (rightWord == true) {
        std::cout << "Correct!\n\n";
        return true;
    }
    
    return false;
    
}

void Guessing::_playerTurn(Guessing* &player1, Guessing* &player2) {
    
    bool correctWord,
    correctWord2;
    
    correctWord = _playerInput(player1);
    
    /* if the player going first guesses correctly no double points for
     next player */
    if (correctWord == true) {
        _increaseScore(player1);
        correctWord2 = _playerInput(player2);
        if (correctWord2 == true) {
            _increaseScore(player2);
        }
        else {
            std::cout << "Incorrect\n\n";
        }
    }
    // if player going first guesses incorrectly, double points for next player
    else if (correctWord == false) {
        std::cout << "Incorrect, " << player2->getName() << " can retrieve double points\n"
        "if the word is guessed correctly\n\n";
        correctWord2 = _playerInput(player2);
        if (correctWord2 == true) {
            std::cout << player2->getName() << " retrieves double points.\n\n";
            _increaseScore(player2);
            _increaseScore(player2);
        }
        else {
            std::cout << "Incorrect\n\n";
        }
    }
}

void Guessing::_playerStats(Guessing* &player1, Guessing* &player2) {
    
    std::cout << player1->name << " score: " << player1->score << std::endl;
    std::cout << player2->name << " score: " << player2->score << std::endl;
    
}

void Guessing::start() {
    
    _createList();
    
    _userNames();
    
    int rounds = 0,
    count = 0,
    roundNum = 1;
    
    string line;

    //TODO: Maybe even rounds only?
    std::cout << "\nEnter number of rounds (Max 10): ";
    std::cin >> rounds;
    validateInt(rounds);
    std::cout << std::endl;
    
    while (count < rounds) {
        std::cout << "\t\t\t\t" << line.assign(9, '-') << std::endl;
        std::cout << "\t\t\t\t|Round " << roundNum << "|" << std::endl;
        std::cout << "\t\t\t\t" << line.assign(9, '-') << std::endl;
        if (count % 2 == 0) {
            _playerTurn(p1, p2);
            _playerStats(p1, p2);
            std::cout << std::endl;
            count++;
        }
        else {
            _playerTurn(p2, p1);
            _playerStats(p1, p2);
            std::cout << std::endl;
            count++;
        }
        roundNum++;
    }
    
    if (p1->score > p2->score) {
        std::cout << p1->name << " wins!\n";
        std::cout << "Final Score: " << p1->score << std::endl;
        std::cout << p2->name << std::endl;
        std::cout << "Final Score: " << p2->score << std::endl;
    }
    else if (p2->score > p1->score) {
        std::cout << p2->name << " wins!\n";
        std::cout << "Final Score: " << p2->score << std::endl;
        std::cout << p1->name << std::endl;
        std::cout << "Final Score: " << p1->score << std::endl;
    }
    else {
        std::cout << "It's a draw!\n";
        std::cout << p1->name << std::endl;
        std::cout << "Final Score: " << p1->score << std::endl;
        std::cout << p2->name << std::endl;
        std::cout << "Final Score: " << p2->score << std::endl;
    }
    
    
        
}


void Guessing::testPrint() {
    map<string,set<string>>::iterator itr;
    
    for (itr = list.begin(); itr != list.end(); itr++) {
        std::cout << itr->first << " -> ";
        set<string> listOfWords = itr->second;
        set<string>::iterator it;
        for (it = listOfWords.begin(); it != listOfWords.end(); it++) {
            std::cout << *it << " -> ";
        }
        std::cout << std::endl;
    }
    
}


Guessing::~Guessing() {}
