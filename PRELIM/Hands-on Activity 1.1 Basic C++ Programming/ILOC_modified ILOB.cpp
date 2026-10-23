#include <iostream>
#include <cmath>
#include <string>

double computeArea(double a, double b, double c);
double computePerimeter(double a, double b, double c);
std::string determineTriangle(double a, double b, double c);

int main () {

    double a, b, c;

    std::cout << "------------------------------" << std::endl;
    std::cout << "Enter side A: ";
    std::cin >> a;
    std::cout << "Enter side B: ";
    std::cin >> b;
    std::cout << "Enter side C: ";
    std::cin >> c;
    std::cout << "------------------------------" << std::endl;

    double area = computeArea(a, b, c);
    double perimeter = computePerimeter(a, b, c);
    std::string triangleType = determineTriangle(a, b, c);

    std::cout << "\nTriangle Information:" << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Type: " << triangleType << "\n" << std::endl;

    return 0;
}

double computeArea(double a, double b, double c) {
    double s = (a + b + c) / 2; // semi-perimeter
    return std::sqrt(s * (s - a) * (s - b) * (s - c)); // Area's formula
}
double computePerimeter(double a, double b, double c) {
    return a + b + c;
}
std::string determineTriangle(double a, double b, double c) {
    double longestSide, side1, side2;

    if (a >= b && a >= c) {
        longestSide = a;
        side1 = b;
        side2 = c;
    } else if (b >= a && b >= c) {
        longestSide = b;
        side1 = a;
        side2 = c;
    } else if (c >= a && c >= b) {
        longestSide = c;
        side1 = a;
        side2 = b;
    } else {
        return "Invalid triangle sides";
    }

    double longestSquare = pow(longestSide, 2);
    double sumOfSquares = pow(side1, 2) + pow(side2, 2);

    if (longestSquare == sumOfSquares) {
        return "Right-angled triangle";
    } else if (longestSquare < sumOfSquares) {
        return "Acute-angled triangle";
    } else {
        return "Obtuse-angled triangle";
    }
}