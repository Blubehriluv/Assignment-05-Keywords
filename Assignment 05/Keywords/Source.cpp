#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int correctGuess;

int main() {
	// create word list to pull from
	const int NUM_WORDS = 10;
	enum fields { WORD, HINT, NUM_FIELDS };
	string wordBank[NUM_WORDS][NUM_FIELDS] = {
		{"mouse", "one kind of this clicks, while the other likes cheese"},//1
		{"music", "a sound containing rhythm, found on the radio"},//2
		{"refrigerator", "keeps our food cold"},//3
		{"university", "not a college, but holds advancing technology"},//4
		{"games", "the reason most people are studying here"},//5
		{"cookie", "baked in an oven when homemade"},//6
		{"headphones", "output device that lets you hear things digitally"},//7
		{"chicken", "a yummy animal that lays eggs"},//8
		{"computer", "the origin of Dora's name"},//9
		{"spaghetti", "there's vomit on his sweater already, mom's..."},//10
	};

	/*
	instructions
	*/
	cout << "CODE DECRYPTION PROGRAM INITIALIZING... " << endl;
	cout << "Unscramble [3] words to proceed." << endl;
	cout << "Type 'hint' if you need help.\n\n";


	/*
	select 3 of 10 words and scramble
	*/
	int totalAttempts = 0;
	int incorrectGuesses = 0;

	for (int i = 0; i < 3; i++) {
		// reset incorrect guess counter
		incorrectGuesses = 0;

		// seed random
		srand(static_cast<unsigned int>(time(0)));

		// choose a word
		int choice = rand() % NUM_WORDS;
		string theWord = wordBank[choice][WORD];
		string theHint = wordBank[choice][HINT];

		string jumbledWord = theWord;

		// jumble the word
		for (int j = 0; j < jumbledWord.length(); j++) {
			// select 2 random index
			int index1 = rand() % jumbledWord.length();
			int index2 = rand() % jumbledWord.length();

			// swap characters at both index
			char buffer = jumbledWord[index1];
			jumbledWord[index1] = jumbledWord[index2];
			jumbledWord[index2] = buffer;
		}

		cout << "Unscramble: " << jumbledWord << endl << endl;

		// player interaction loop
		string playerGuess = "";
		while (playerGuess != theWord) {
			// every 3 wrong guesses, offer help
			if ((incorrectGuesses % 3 == 0) && (incorrectGuesses > 0)) {
				cout << "---Stuck?? Enter 'hint'---\n";
			}

			totalAttempts++;

			// get players guess
			cout << "Your guess: ";
			cin >> playerGuess;

			// display hint
			if (playerGuess == "hint") {
				// reset incorrect guess counter
				incorrectGuesses = 0;
				cout << theHint << endl << endl;
			}
			// let player know if they're wrong
			else if (playerGuess != theWord) {
				incorrectGuesses++;
				cout << "Incorrect!\n\n";
			}
		}
		//Counter for the player's correct guesses
		correctGuess++;
		cout << "You got it! Nice!\n\n";
		cout << "You've guessed correctly " << correctGuess << " times!" << endl;

		//When the guesses equal 3, the player wins
		if (correctGuess == 3)
		{
			cout << "You win!" << endl;
			system("Pause");
		}
	}

	/*
	end stats
	*/
	cout << "-----COMPLETE-----\n\n";
	cout << "Total attempts: " << totalAttempts << endl << endl;

	cout << "------------------\n\n";

	return 0;
}