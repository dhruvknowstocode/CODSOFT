#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int hiddennumber = rand() % 100 + 1;
    int userguess;
    int numberoftries = 0;
    bool correctguess = false;
    cout << "Welcome to the Number Guessing Game made by me \\-_-//" << endl;
    while (!correctguess) {
        cout << "Enter your guess :";
        cin >> userguess;
        numberoftries++;
        if (userguess < hiddennumber) {
            cout << "Your guess is too low. Try again." << endl;
        } else if (userguess > hiddennumber) {
            cout << "Your guess is too high. Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << numberoftries << " attempts." << endl;
            correctguess = true;
        }
    }
    return 0;
}

