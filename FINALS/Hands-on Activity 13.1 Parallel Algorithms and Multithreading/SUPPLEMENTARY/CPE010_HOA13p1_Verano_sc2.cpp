#include <iostream>
#include "printerQueue.h"
#include <thread>
#include <chrono>

// Thread function for Batch 1: 
// Handles all original Batch 1 jobs
void runBatchOne(Printer* printer1) {
    
    printer1->queueDelay();
    printer1->addJob(101, "Striker", 5);  // <--- This runs in parallel with #104
    printer1->queueDelay();
    printer1->addJob(102, "James", 12);
    printer1->queueDelay();
    printer1->addJob(103, "Jobert", 3);
    printer1->queueDelay();

    printer1->processJobs();
    printer1->timeDelay();
}

// Thread function for Batch 2: 
// Handles all original Batch 2 jobs
void runBatchTwo(Printer* printer2) {
    // Initial offset delay so that it won't process at the same time
    // which might break the printer if it process at the same time.
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    
    printer2->queueDelay();
    printer2->addJob(104, "James", 25);   // <--- This runs in parallel with #101
    printer2->queueDelay();
    printer2->addJob(105, "Ely", 7);
    printer2->queueDelay();

    printer2->processJobs();
    printer2->timeDelay();
}

int main() {
    // Create two separate instances so that they don't fight over the same pointers
    Printer printerBatch1;
    Printer printerBatch2;

    std::cout << "\n====================================================\n";
    std::cout << "       >>> Full Parallel Batch Processing <<<\n";
    std::cout << "====================================================\n\n";

    // Start both batches at the exact same time
    std::thread T1(runBatchOne, &printerBatch1);
    std::thread T2(runBatchTwo, &printerBatch2);

    // Wait for both concurrent streams to completely finish
    T1.join();
    T2.join();

    // Final check loop matching your original code structure
    printerBatch1.processJobs();
    printerBatch2.processJobs();

    std::cout << "\n[--- All original assignment jobs completed successfully. ---]\n\n";
    return 0;
}
