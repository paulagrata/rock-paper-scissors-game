#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype>

int main() {
    std::cout << "rock, paper, scissors, lizard, SPOCK! \n\n"; 
    std::cout << "choose one: \n";
    std::cout << "1: rock \n";
    std::cout << "2: paper \n";
    std::cout << "3: scissors \n";
    std::cout << "4: lizard \n";
    std::cout << "5: spock \n\n";

    int rock = 1;
    int paper = 2;
    int scissors = 3;
    int lizard = 4;
    int spock = 5;

    srand(time(NULL));

    do {
        int userchoice;
        std::cout << "rock, paper, scissors, lizard, spock? ";
        if (!(std::cin >> userchoice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "enter a number listed silly:\n";
            continue;
        }
      
        // choices
        std::string choices[] = { "rock", "paper", "scissors", "lizard", "spock" };
        std::cout << "you choose: " <<  choices[userchoice - 1] << "\n"; 

        int compchoicename = std::rand() % 5;
        std::string computername = choices[compchoicename];
        compchoicename += 1;

        std::cout << "I choose: " << computername << "\n";
      
       // determine winner
        if (userchoice == compchoicename) {
            std::cout << "tied. D:\n";
        } else if ((userchoice == rock && compchoicename == scissors) ||
                   (userchoice == rock && compchoicename == lizard) ||
                   (userchoice == paper && compchoicename == rock) ||
                   (userchoice == paper && compchoicename == spock) ||
                   (userchoice == scissors && compchoicename == paper) ||
                   (userchoice == scissors && compchoicename == lizard) ||
                   (userchoice == lizard && compchoicename == spock) ||
                   (userchoice == lizard && compchoicename == paper) ||
                   (userchoice == spock && compchoicename == scissors) ||
                   (userchoice == spock && compchoicename == rock)) {
            std::cout << "you win. :D\n";
        } else {
            std::cout << "you lose, I win. \n";
        }

        // play again
        std::string playAgain;
        std::cout << "\ndo you want to play again? ";
        std::cin >> playAgain;
      
        // convert answer to lowercase
        for (char& c : playAgain) {
            c = std::tolower(c);
        }

        if (playAgain != "yes") {
            std::cout << "okay, bye.\n";
            break;
        }

        std::cout << "\n";
    } while (true);

    return 0;
}

      /* 
    key:
    lizard > spock
    spock > scissors
    scissors > lizard
    lizard > paper
    paper > spock
    spock > rock
    rock > lizard
    */
