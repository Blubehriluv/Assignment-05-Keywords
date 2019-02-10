#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

string jumble;
string theWord;
string theHint;
int winCount = 0;
string decide;

void play()
{
	cout << "Unscramble: " << jumble << endl;
	string guess;
	cin >> guess;
	
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint << "\n";
		}
		else
		{
			cout << "That ain't it chief.";
		}

		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "\nCorrect!" << endl;
		if (winCount != 2)
		{
			winCount++;
			system("pause");
			play();
		}
		else
		{
			cout << "Would you like to play again? [y/n]" << endl;
			cin >> decide;
			if (decide == "y")
			{
				winCount = 0;
				play();
			}
			if (decide == "n")
			{
				cout << "Goodbye" << endl;
			}
		}
	}
}

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
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

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	theWord = WORDS[choice][WORD]; //word to guess
	theHint = WORDS[choice][HINT]; //hint for word

	jumble = theWord; //jumbled version of word
	int length = jumble.size();

	for (int i = 0; i < length; i++)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	if (winCount != 3)
	{
		play();
	}
}