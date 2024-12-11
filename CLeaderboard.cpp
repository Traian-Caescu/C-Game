// CLeaderboard.h
#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

class CLeaderboard {
private:
    std::map<std::string, int> mScores; // Stores player names and their scores

public:
    CLeaderboard() = default;

    // Adds or updates the player's score
    void AddScore(const std::string& playerName, int score);

    // Saves the leaderboard to a file
    void SaveToFile(const std::string& filename) const;

    // Loads the leaderboard from a file
    void LoadFromFile(const std::string& filename);

    // Displays the leaderboard
    void Display() const;
};

// CLeaderboard.cpp
#include "CLeaderboard.h"

void CLeaderboard::AddScore(const std::string& playerName, int score) {
    if (mScores.find(playerName) != mScores.end()) {
        mScores[playerName] += score;
    } else {
        mScores[playerName] = score;
    }
}

void CLeaderboard::SaveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open leaderboard file for writing." << std::endl;
        return;
    }

    for (const auto& entry : mScores) {
        file << entry.first << " " << entry.second << std::endl;
    }

    file.close();
}

void CLeaderboard::LoadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open leaderboard file for reading." << std::endl;
        return;
    }

    mScores.clear();
    std::string playerName;
    int score;
    while (file >> playerName >> score) {
        mScores[playerName] = score;
    }

    file.close();
}

void CLeaderboard::Display() const {
    std::cout << "\n--- Leaderboard ---" << std::endl;
    for (const auto& entry : mScores) {
        std::cout << entry.first << ": " << entry.second << " points" << std::endl;
    }
}
