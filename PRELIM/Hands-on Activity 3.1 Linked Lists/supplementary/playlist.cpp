#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "playlist_ll.h"

// function to print the interactive options menu
void printMenu() {
    std::cout << "\n================ MUSIC PLAYER MENU ================" << std::endl;
    std::cout << " 1. Next Song" << std::endl;
    std::cout << " 2. Previous Song" << std::endl;
    std::cout << " 3. Add Song to Beginning" << std::endl;
    std::cout << " 4. Remove Current Song" << std::endl;
    std::cout << " 5. Play/Display All Songs Once" << std::endl;
    std::cout << " 6. Exit Player" << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << "Enter your choice (1-6): ";
}

int main()
{
    // Initialize an empty playlist
    DoublyList<std::string> *head = nullptr;
    
    // Track the currently playing song node pointer
    DoublyList<std::string> *currentPlaying = nullptr;

    int choice = 0;
    std::string songName;

    std::cout << "Welcome to the Circular Playlist Creator!" << std::endl;

    while (choice != 6) {
        // Display current playing status
        std::cout << "\n---------------------------------------------------" << std::endl;
        if (currentPlaying != nullptr) {
            std::cout << "NOW PLAYING: [ " << currentPlaying->data << " ]" << std::endl;
        } else {
            std::cout << "NOW PLAYING: [ No songs in playlist ]" << std::endl;
        }

        printMenu();
        std::cin >> choice;

        // Error checking
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a valid number (1-6)." << std::endl;
            continue;
        }

        // Clear input buffer before reading dynamic string names
        std::cin.ignore(); 

        switch (choice) {
            case 1: // Next Song
                if (currentPlaying != nullptr) {
                    currentPlaying = currentPlaying->next;
                } else {
                    std::cout << "The playlist is empty." << std::endl;
                }
                break;

            case 2: // Previous Song
                if (currentPlaying != nullptr) {
                    currentPlaying = currentPlaying->prev;
                } else {
                    std::cout << "The playlist is empty." << std::endl;
                }
                break;

            case 3: // Add Song to Head
                std::cout << "Enter song name to add: ";
                std::getline(std::cin, songName);
                dllInsertHead<std::string>(songName, &head);
                
                if (currentPlaying == nullptr) {
                    currentPlaying = head;
                }
                std::cout << "Added '" << songName << "' to the beginning." << std::endl;
                break;

            case 4: // Remove Current Song
                if (currentPlaying == nullptr) {
                    std::cout << "Playlist is already empty." << std::endl;
                } else {
                    DoublyList<std::string> *nodeToDelete = currentPlaying;
                    
                    // Move currentPlaying pointer to the next track before deleting the target node
                    if (currentPlaying->next == currentPlaying) {
                        currentPlaying = nullptr;
                    } else {
                        currentPlaying = currentPlaying->next;
                    }
                    
                    std::cout << "Removing song: '" << nodeToDelete->data << "'" << std::endl;
                    dllDelNode<std::string>(&head, nodeToDelete);
                }
                break;

            case 5: // Play/Display All Songs Once
                std::cout << "\n--- Full Playlist Status ---" << std::endl;
                dllTraverse(head);
                break;

            case 6: // Exit Player
                std::cout << "Thank you for using the Music Player. Goodbye!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice selection. Try numbers 1 through 8." << std::endl;
                break;
        }
    }

    return 0;
}
