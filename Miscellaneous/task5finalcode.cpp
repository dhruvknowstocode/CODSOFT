#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime> // Added for srand
using namespace std;

// Constants for the number of rows and columns
const int NUM_ROWS = 5;
const int NUM_COLS = 7;

class Chair {
private:
    int rownumber;
    int colnumber;
    bool isReserved;

public:
    Chair(int r, int c) : rownumber(r), colnumber(c), isReserved(false) {}

    bool reserve() {
        if (isReserved) {
            cout << "Chair " << char('A' + rownumber) << colnumber + 1 << " is already reserved.\n";
            return false;
        }
        isReserved = true;
        return true;
    }

    bool isReservedChair() const {
        return isReserved;
    }

    double getPrice() const {
        return 250.0; // Fixed price for all chairs
    }

    string getChairInfo() const {
        return char('A' + rownumber) + to_string(colnumber + 1);
    }
};

class Film {
private:
    string title;
    string showTime;

public:
    Film(const string& t, const string& time) : title(t), showTime(time) {}

    string getTitle() const {
        return title;
    }

    string getShowTime() const {
        return showTime;
    }
};

class Theater {
private:
    vector<vector<Chair>> chairs;
    Film film;

public:
    Theater(const Film& f) : film(f) {
        chairs.resize(NUM_ROWS, vector<Chair>(NUM_COLS, Chair(0, 0))); // Using constants
    }

    void displayChairs() const {
        cout << "  ";
        for (int col = 0; col < NUM_COLS; ++col) {
            cout << col + 1 << " ";
        }
        cout << "\n";
        for (int row = 0; row < NUM_ROWS; ++row) {
            cout << char('A' + row) << " ";
            for (int col = 0; col < NUM_COLS; ++col) {
                cout << (chairs[row][col].isReservedChair() ? "X " : "0 ");
            }
            cout << "\n";
        }
    }

    bool reserveChair(int row, int col) {
        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
            cout << "Invalid chair selection.\n";
            return false;
        }
        return chairs[row][col].reserve();
    }

    double calculateTotalCost(int numTickets) const {
        return numTickets * chairs[0][0].getPrice();
    }

    string getFilmInfo() const {
        return "Film: " + film.getTitle() + " | Show Time: " + film.getShowTime();
    }

    double processOnlinePayment(double totalCost) const {
        int cardnumber;
        cout << "Enter your card number: ";
        cin >> cardnumber;
        int var = rand() % 10 + 1;
        if (var > 5) {
            cout << "Servers down!! Please try again later\n";
            return -1;
        } else {
            cout << "Processing credit card payment...\n";
            return totalCost;
        }
    }

    double processCashPayment(double totalCost) const {
        int totalcash;
        cout << "Enter your cash deposited: ";
        cin >> totalcash;
        cout << "Processing cash payment...\n";
        return totalCost;
    }
};

// Function to validate and get a valid seat input
bool getValidSeatInput(int& row, int& col) {
    char rowChar;
    cout << "Enter the seat that you want to book (e.g., A1): ";
    cin >> rowChar >> col;
    row = rowChar - 'A';

    if (row < 0 || row >= NUM_ROWS || col < 1 || col > NUM_COLS) {
        cout << "Invalid seat selection.\n";
        return false;
    }

    return true;
}

// Function to validate and get a valid payment method
char getValidPaymentMethod() {
    char paymentMethod;
    cout << "Select payment method (P: Online payment, C: Cash): ";
    cin >> paymentMethod;

    if (paymentMethod != 'P' && paymentMethod != 'p' && paymentMethod != 'C' && paymentMethod != 'c') {
        cout << "Invalid payment method selected.\n";
        return ' ';
    }

    return paymentMethod;
}

int main() {
    srand(time(0)); // Seed for rand()

    string movieName;
    cout << "Enter the movie name: ";
    getline(cin, movieName);

    string showTime = "9:30";
    Film film(movieName, showTime);
    Theater theater(film);

    cout << "Welcome to the movie: " << film.getTitle() << "!\n";
    cout << "Your Show is at: " << film.getShowTime() << "\n\n";

    while (true) {
        theater.displayChairs();

        int row, col;
        if (!getValidSeatInput(row, col)) {
            continue;
        }

        if (theater.reserveChair(row, col - 1)) {
            int numTickets;
            cout << "Enter the total number of tickets that you want to book: ";
            cin >> numTickets;

            double totalCost = theater.calculateTotalCost(numTickets);
            cout << "Total cost of your movie ticket is: Rs" << totalCost << "\n";

            char paymentMethod;
            do {
                paymentMethod = getValidPaymentMethod();
            } while (paymentMethod == ' ');

            double finalCost = 0;
            if (paymentMethod == 'P' || paymentMethod == 'p') {
                finalCost = theater.processOnlinePayment(totalCost);
            } else if (paymentMethod == 'C' || paymentMethod == 'c') {
                finalCost = theater.processCashPayment(totalCost);
            }

            if (finalCost < 0) {
                cout << "Payment failed. Please try again later.\n";
            } else {
                cout << "Payment successful. Enjoy the movie and here's the receipt!\n";
            }
        }

        char continueChoice;
        cout << "Do you want to continue reserving? (y/n): ";
        cin >> continueChoice;
        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
    }

    cout << "Thank you for using the Chair Reservation System!\n";
    return 0;
}