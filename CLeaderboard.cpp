#include "CLeaderboard.h"

// Add a win for a player
void CLeaderboard::AddWin(const std::string& playerName) {
    leaderboard[playerName]++;
}

// Display the leaderboard
void CLeaderboard::DisplayLeaderboard() const {
    std::cout << "\n--- Leaderboard ---" << std::endl;
    for (const auto& entry : leaderboard) {
        std::cout << entry.first << ": " << entry.second << " wins" << std::endl;
    }
}

// Save the leaderboard to a file
void CLeaderboard::SaveToFile(const std::string& fileName) const {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open leaderboard file for writing." << std::endl;
        return;
    }

    for (const auto& entry : leaderboard) {
        file << entry.first << " " << entry.second << std::endl;
    }

    file.close();
}

// Load the leaderboard from a file
void CLeaderboard::LoadFromFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open leaderboard file for reading." << std::endl;
        return;
    }

    leaderboard.clear();
    std::string name;
    int wins;
    while (file >> name >> wins) {
        leaderboard[name] = wins;
    }

    file.close();
}
