#include <iostream>

using namespace std;

int main() {

int Qscore1, Qscore2, Qscore3, total, ave = 0;

cout << "=================================================" << "\n" 
     << " || \t Input Quiz 1 Score: \t";
cin >> Qscore1;

cout << " || \t Input Quiz 2 Score: \t";
cin >> Qscore2;

cout << " || \t Input Quiz 3 Score: \t";
cin >> Qscore3;
cout << "=================================================" << "\n";

total = Qscore1 + Qscore2 + Qscore3;
ave = total/3;

cout << " || The average of the 3 quizzes scores: "<< ave << "\n"
     << " || The total of the 3 quizzes scores: "<< total << " pts"
     << "\n" << "=================================================" << "\n";

return 0;

}

