#include <iostream>
#include <cmath>
#include <string>

double kelvinToFahrenheit(double kelvin);

double calculateDistance(double x1, double y1, double x2, double y2);

int main() {

    double num1, num2, temp, kelvin, x1, y1, x2, y2, a, b, c;

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "\n--- Before Swapping ---" << std::endl;
    std::cout << "First number = " << num1 << std::endl;
    std::cout << "Second number = " << num2 << std::endl;

    // 3. Swapping using a temporary variable
    temp = num1;   // Store the value of num1 in temp
    num1 = num2;   // Copy the value of num2 into num1
    num2 = temp;   // Copy the value of temp (original num1) into num2

    // Display of values after swapping
    std::cout << "\n--- After Swapping ---" << std::endl;
    std::cout << "First number = " << num1 << std::endl;
    std::cout << "Second number = " << num2 << std::endl;


    
    std::cout << "\nEnter temperature in Kelvin: ";
    std::cin >> kelvin;

    double fahrenheit = kelvinToFahrenheit(kelvin);

    std::cout << kelvin << "k is equal to " << fahrenheit << " Fahrenheit." << std::endl;



    std::cout << "\nEnter coordinates of the first point (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter coordinates of the second point (x2 y2): ";
    std::cin >> x2 >> y2;

    double distance = calculateDistance(x1, y1, x2, y2);
    std::cout << "The distance between the two points is: " << distance << std::endl;

    return 0;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}


double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}