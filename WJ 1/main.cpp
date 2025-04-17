//
//  main.cpp
//  WJ 1
//
//  Created by Alex on 2025-04-17.
//

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    
    
    // Создается массив
    
    enum elements {WORD, HINT, NUM_COLUMS};
    const int NUM_ROWS = 5;
    
    string TEXTS [NUM_ROWS][NUM_COLUMS]= {
        
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };
    
    
    // Выберается слово

    srand(static_cast<unsigned int>(time(0)));
    int choice = rand() % NUM_ROWS;
    
    string theWord = TEXTS [choice][WORD];
    string theHint = TEXTS [choice][HINT];
    
    
    // Перемешиваем буквы
    
    string jumble = theWord;
    
    int length = jumble.size();
    
    for (int i = 0; i < length; ++i) {
        
        int index1 = rand () % length;
        int index2 = rand () % length;
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    };
    
    // Ввод от пользователя
    
    string input;
    
    // Вывод на консоль
    
    cout << "\t\tWelcome to Game nr. 1\n\n"
    
    << "Unscramble the letters to make a word.\n"
    << "Enter 'hint' for a hint.\n"
    << "Enter 'quit' to quit the game\n\n"
    << "The jumble is: " << jumble << endl << endl;
    
    while (true) {
            cout << "Your guess: ";
            cin >> input;

            if (input == theWord) {
                cout << "🎉 Congratulations! You guessed it!\n";
                break;
            }
            else if (input == "hint") {
                cout << "💡 Hint: " << theHint << "\n";
            }
            else if (input == "quit") {
                cout << "👋 Goodbye!\n";
                break;
            }
            else {
                cout << "❌ Try again.\n";
            }
        }
    
    
    cout << endl << endl;
    
    return 0;
}
