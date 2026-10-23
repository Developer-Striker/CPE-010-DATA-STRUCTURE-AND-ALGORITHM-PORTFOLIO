#include <iostream>
#include <queue>
#include "printerQueue.h"
#include <iomanip>
#include <chrono>
#include <thread>

int main() {
    Printer officePrinter;


    std::cout << "\n\t    >>> Shared Office Printer <<<\n\n";

    // Multiple users sending print requests
    std::cout << "======================================================\n";
    std::cout << "      >>> Queuing Multiple Print Requests... <<<\n";
    std::cout << "======================================================\n\n";
    officePrinter.queueDelay();
    officePrinter.addJob(101, "Striker", 5);
    officePrinter.queueDelay();
    officePrinter.addJob(102, "James", 12);
    officePrinter.queueDelay();
    officePrinter.addJob(103, "Jobert", 3);
    officePrinter.queueDelay();

    // Printer handles and processes all the incoming requests in FIFO order
    officePrinter.processJobs();
    officePrinter.timeDelay();

    // Second wave of incoming print requests
    std::cout << "======================================================\n";
    std::cout << "      >>> Queuing Multiple Print Requests... <<<\n";
    std::cout << "======================================================\n\n";
    officePrinter.queueDelay();
    officePrinter.addJob(104, "James", 25);
    officePrinter.queueDelay();
    officePrinter.addJob(105, "Ely", 7);
    officePrinter.queueDelay();

    officePrinter.processJobs();
    officePrinter.timeDelay();

    officePrinter.processJobs();

    return 0;
}
