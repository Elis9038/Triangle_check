#include <QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

int exist;
string triangle;    // Will store triangle type here
float a, b, c;      // Triangle sides


void checkIfIt_exists() {

   if (a+b >= c && c+a >= b && b+c >= a) exist = 1;
   else exist = 0;

}

void checkIfIts_Isosceles() {

    if (a == b || b == c || a == c) {

        triangle = "isosceles (ravnobedrennij)";
    }
}


void checkIfIts_Equilateral() {

    if (a == b && b == c) {

        triangle = "equilateral (ravnostoronnij)";
    }
}


void checkIfIts_Rectangular() {

    if (a == b+c || b == c+a || c == b+a) {

        triangle = "rectangular (prjamougolnij)";
    }
}




int main(){

    while (true) {

        // Clear all the values to start over
        triangle = "";

        start:
        cout << "\nEnter three triangle sides to see its type.\n";

        while (!(cin >> a) || !(cin >> b) || !(cin >> c))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "\n No letters and characters allowed. Try again.";
            goto start;
        }

        checkIfIt_exists();

        if (exist == 1){
            checkIfIts_Isosceles();
            checkIfIts_Equilateral();
            checkIfIts_Rectangular();
        } else {
            cout << "Sorry, this triangle doesn't exist";
            goto start;
        }

        if (triangle == "") cout << "This triangle exists but doesn't match any type in this program";
        else cout << "This triangle is " << triangle;

    }

}

