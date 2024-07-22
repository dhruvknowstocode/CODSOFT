#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Function to generate a random combination of numbers for the lottery
vector<int> generateWinningCombination(int size, int range) {
    vector<int> combination;
    for (int i = 0; i < size; ++i) {
        combination.push_back(rand() % range + 1);
    }
    return combination;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    const int maxAttempts = 3;  // Maximum number of attempts
    const int lotterySize = 6;  // Size of the lottery combination
    int numberRange;
    cout << "Welcome to the Lottery Game!" << endl;
    cout << "Enter the range of numbers to choose from (e.g., 1 4): ";
    cin >> numberRange;
    vector<int> winningCombination = generateWinningCombination(lotterySize, numberRange);
    cout << "Choose " << lotterySize << " numbers between 1 and " << numberRange << "." << endl;
    vector<int> userCombination(lotterySize);
    int totalCorrectMatches = 0;
    for (int attempt = 0; attempt < maxAttempts; ++attempt) {
        cout << "\nAttempt " << attempt + 1 << endl;
        for (int i = 0; i < lotterySize; ++i) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> userCombination[i];
        }
        unordered_set<int> commonElements;
        for (int i = 0; i < lotterySize; ++i) {
            if (find(winningCombination.begin(), winningCombination.end(), userCombination[i]) !=
                winningCombination.end()) {
                commonElements.insert(userCombination[i]);
            }
        }
        int correctMatches = commonElements.size();
        totalCorrectMatches += correctMatches;
        cout << "\nWinning Combination: ";
        for (int number : winningCombination) {
            cout << number << " ";
        }

        cout << "\nYour Combination: ";
        for (int number : userCombination) {
            cout << number << " ";
        }

        cout << "\nCorrect Matches: " << correctMatches << endl;

        // Provide hints based on the number of correct matches
        if (correctMatches == 0) {
            cout << "Hint: None of your numbers match the winning combination. Try different numbers." << endl;
        } else if (correctMatches < lotterySize) {
            cout << "Hint: Some numbers are correct, but not in the right position. Keep trying!" << endl;
        }

        if (correctMatches == lotterySize) {
            cout << "\nCongratulations! You won the jackpot!" << endl;
            break;
        } else if (attempt == maxAttempts - 1) {
            cout << "\nSorry, you've reached the maximum number of attempts. Better luck next time!" << endl;
        }
    }

    // Calculate and display accuracy rate
    double accuracyRate = static_cast<double>(totalCorrectMatches) / (maxAttempts * lotterySize) * 100;
    cout << "\nAccuracy Rate: " << accuracyRate << "%" << endl;

    cout << "\nThanks for playing the Lottery Game!" << endl;

    return 0;
}

