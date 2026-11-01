#include <iostream>
#include "votesSort.h"
#include <cstdlib>
#include <ctime>
#include <string>

const int max_size = 100;

// Array containing the list of candidates to iterate for the winner
const std::string candidateNames[5] = {
    "Bo Dalton Capistrano",
    "Cornelius Raymon Agustín",
    "Deja Jayla Bañaga",
    "Lalla Brielle Yabut",
    "Franklin Relano Castro"
};

void displayAll(int arr[]);
int majorityVote(int voteArray[], const int& arrSize);

int main(){

    int votes[max_size];
    srand(time(0));

    for (int i = 0; i < max_size; i++){
        votes[i] = rand()%5 + 1;
    }

    // Displays the unsorted votes first
    std::cout << "Unsorted Votes:\n";
    displayAll(votes);
    std::cout << "\n\n";

    // Calls function to sort, count, and find the winner
    int winningIndex = majorityVote(votes, max_size);

    // Print the winner's name using the returned index
    std::cout << "\n🏆 Winning Candidate: " << candidateNames[winningIndex] 
    << " (ID: " << winningIndex + 1 << ")\n";

    return 0;
}

void displayAll(int arr[]){
    for (int i = 0; i < max_size; i++){
        std::cout << arr[i] << " ";
    }
}

int majorityVote(int voteArray[], const int& arrSize){
    int voteCount[5] = {0};
    insertionSort(voteArray, arrSize);
    
    // Count occurrences
    for (int i = 0; i < arrSize; i++){
        voteCount[voteArray[i] - 1]++;
    }

    // Find max
    int max = voteCount[0];
    int winner = 0; 

    std::cout << "Sorted Votes:\n";
    displayAll(voteArray);
    std::cout << "\n\n";

    std::cout << "--- | Vote Tallying Breakdown | ---\n\n";
    for (int i = 0; i < 5; i++){
        if (voteCount[i] > max){
            max = voteCount[i];
            winner = i;
        }
        // Print the counts with the names alongside them
        std::cout << candidateNames[i] << " (" << i+1 << "): " << voteCount[i] << " votes\n";
        
    }
    return winner;
}
