#include <iostream>
#include <string>

using namespace std;

void playGame(string secretWord) {
    string guessedWord(secretWord.length(), '_');
    char guess;
    int attempts = 5;

    cout << "Guess the word: " << guessedWord << "\n";

    while (attempts > 0 && guessedWord != secretWord) {
        cout << "\nEnter a letter: ";
        cin >> guess;

        bool found = false;
        for (size_t i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }

        if (!found) {
            attempts--;
            cout << "Wrong guess! Attempts left: " << attempts << "\n";
        } else {
            cout << "Correct! Word progress: " << guessedWord << "\n";
        }
    }

    if (guessedWord == secretWord) {
        cout << "\nCongratulations! You guessed the word: " << secretWord << "\n";
    } else {
        cout << "\nGame Over! The correct word was: " << secretWord << "\n";
    }
}

int main() {
    string word = "apple"; // Set secret word
    playGame(word);
    return 0;
}
