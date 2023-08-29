#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
        chairs.resize(5, vector<Chair>(7, Chair(0, 0))); // 5 rows, 7 columns
    }
    void displayChairs() const {
        cout << "  ";
        for (int col = 0; col < 7; ++col) {
            cout << col + 1 << " ";
        }
        cout << "\n";
        for (int row = 0; row < 5; ++row) {
            cout << char('A' + row) << " ";
            for (int col = 0; col < 7; ++col) {
                cout << (chairs[row][col].isReservedChair() ? "X " : "O ");
            }
            cout << "\n";
        }
    }
    bool reserveChair(int row, int col) {
        if (row < 0 || row >= 5 || col < 0 || col >= 7) {
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
    double processonlinepayment(double totalCost) const {
        int cardnumber;
        cout<<"Enter your cardnumber :";
        cin>>cardnumber;
        cout << "Processing credit card payment...\n";
        return totalCost;
    }
    double processCashPayment(double totalCost) const {
        int totalcash;
        cout<<"Enter your cash deposited: ";
        cin>>totalcash;
        cout<<"Here's your change: ";
        cout << "Processing cash payment...\n";
        return totalCost;
    }
};
int main() {
    Film film("Gadar 2", "21:30");
    Theater theater(film);
    cout << "Welcome to top trending movie:" << film.getTitle() << "!\n";
    cout << "Your Show is at :" << film.getShowTime() << "\n\n";
    while (true) {
        theater.displayChairs();
        char rowChar;
        int col;
        cout << "Enter the seat that you want to book (e.g., A1): ";
        cin >> rowChar >> col;
        int row = rowChar - 'A';
        if (theater.reserveChair(row, col - 1)) {
            int numTickets;
            cout << "Enter the total number of tickets that you want to book: ";
            cin >> numTickets;

            double totalCost = theater.calculateTotalCost(numTickets);
            cout << "Total cost of your movie ticket is: Rs" << totalCost << "\n";

            char paymentMethod;
            cout << "Select payment method (P : Online payment , C : Cash): ";
            cin >> paymentMethod;

            double finalCost=0;
            if (paymentMethod == 'P' || paymentMethod == 'p') {
                finalCost = theater.processonlinepayment(totalCost);
            } else if (paymentMethod == 'C' || paymentMethod == 'c') {
                finalCost = theater.processCashPayment(totalCost);
            } else {
                cout << "Invalid payment method selected.\n";
                continue;
            }

            cout << "Payment successful. Enjoy the movie and heres the reciept!\n";
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
