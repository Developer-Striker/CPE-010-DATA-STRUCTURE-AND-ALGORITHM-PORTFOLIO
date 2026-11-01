#include <iostream>
#include <chrono>
#include <iomanip>

int rpower(int x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

int brpower(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) {
        int y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        int y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    int x = 2;
    int exponents[] = {10000, 20000, 30000};

    std::cout << std::left << std::setw(12) << "Exponent (N) "
              << std::setw(22) << " rpower time (ns)"
              << std::setw(22) << "brpower time (ns)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    for (int n : exponents) {
        // rpower measurement
        auto start1 = std::chrono::high_resolution_clock::now();
        rpower(x, n);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();

        // brpower measurement
        auto start2 = std::chrono::high_resolution_clock::now();
        brpower(x, n);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto dur2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
        std::cout << std::left << std::setw(12) << n
        << std::setw(22) << dur1
        << std::setw(22) << dur2 << std::endl;
    }

    return 0;
}