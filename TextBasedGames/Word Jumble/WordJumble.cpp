#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string JumbleWord (const string originalWord);

enum {
    eword = 0,
    ehint
};

int main () {
    srand(static_cast<unsigned int>(time(0)));

    // possible words to jumble
    const int numOfWords = 5;
    const string words[numOfWords] = { "wall", "glasses", "labored", "persistent", "jumble" };
    const string hints[numOfWords] = { "in every room of the house", "you wear these on your face", "overworked", "stop asking!", "mixed up" };
    const string wordsAndHints[numOfWords][2] = {
        { "wall", "in every room of the house" },
        { "glasses" , "you wear these on your face" },
        { "labored", "overworked" },
        { "persistent", "stop asking!" },
        { "jumble", "mixed up" }
    };

    // random index number
    int choice = (rand() % numOfWords);

    // word player must guess
    string secretWord = words[choice];
    secretWord = wordsAndHints[choice][eword];

    string jumbledWord = JumbleWord(secretWord);

    cout << "\t\t\tWelcome to Word Jumble!" << endl << endl;
    cout << "Unscramble the letters to make a word." << endl;
    cout << "Enter 'hint' to see a hint." << endl;
    cout << "Enter 'quit' to quit the game." << endl;
    cout << "The jumbled word is: " << jumbledWord;

    string guess;
    do {
        cout << endl << endl << "Your guess: ";
        cin >> guess;

        if (guess == "hint")
            cout << wordsAndHints[choice][ehint]; //hints[choice];
        else if (guess != secretWord && guess != "quit")
            cout << "Sorry, that's not it.";

    } while ((guess != secretWord) && (guess != "quit"));

    if (guess == secretWord)
        cout << endl << "That's it!  You guessed it!" << endl;

    cout << endl << "Thanks for playing." << endl;

    system("pause");

    return 0;
}

string JumbleWord (const string originalWord) {
    originalWord;
    string jumbledWord = originalWord;

    size_t length = jumbledWord.size();

    for (size_t i = 0; i < length; i++) {
        size_t randomIndex = (rand() % length);
        char temp = jumbledWord[i];
        jumbledWord[i] = jumbledWord[randomIndex];
        jumbledWord[randomIndex] = temp;
    }

    return jumbledWord;
}