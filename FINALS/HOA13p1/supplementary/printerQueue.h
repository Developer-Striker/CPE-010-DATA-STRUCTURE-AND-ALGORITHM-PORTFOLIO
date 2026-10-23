#ifndef PRINTERQUEUE_H
#define PRINTERQUEUE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>

// Create the Job class
class Job {
public:
    int id;
    std::string username;
    int pages;
    Job* next; // Pointer for the linked list node representation

    Job(int jobId, std::string name, int numPages) {
        id = jobId;
        username = name;
        pages = numPages;
        next = nullptr;
    }
};

// Create the Printer class using a Queue (First-Come, First-Served)
class Printer {
private:
    Job* front; // Points to the first job to be processed
    Job* rear;  // Points to the last job added

public:
    Printer() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a new job to the pending print queue (Enqueue)
    void addJob(int id, std::string username, int pages) {
        Job* newJob = new Job(id, username, pages);
        
        if (rear == nullptr) { // If queue is empty
            front = rear = newJob;
        } else {
            rear->next = newJob;
            rear = newJob;
        }
        std::cout << "[ADDED] Job #" << id << " by " << username << " (" << pages << " pages) added to the queue.\n";
    }

    // Process all jobs currently in the queue one by one (Dequeue)
    void processJobs() {
        if (front == nullptr) {
            std::cout << "[STATUS] No pending print jobs.\n\n";
            return;
        }
        std::cout << "\n======================================================";
        std::cout << "\n >>> [STATUS] Processing Multiple Print Request... <<<\n";
        std::cout << "======================================================\n\n";
        while (front != nullptr) {
            Job* temp = front;
            
            // Print status
            std::cout << "[PRINTING] Processing Job #" << temp->id 
                      << " for User: " << temp->username 
                      << " [" << temp->pages << " pages]...\n";
            queueDelay();
            // Move front pointer forward
            front = front->next;
            
            // If the queue became empty, update rear pointer too
            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp; // Free memory allocated for the completed job
        }
        std::cout << "\n[--- All pending print jobs completed successfully. ---]\n\n";
    }

    // Destructor to clean up memory if program exits
    ~Printer() {
        while (front != nullptr) {
            Job* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void timeDelay() {
        return std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    void queueDelay() {
        return std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};




#endif