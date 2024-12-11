#pragma once
#include <vector>
#include <memory>
#include "CPlayer.h"
#include "CSettings.h"
#include "CLeaderboard.h"

class CGame {
private:
    std::vector<std::shared_ptr<CPlayer>> players;
    CSettings settings;
    CLeaderboard leaderboard;
    int maxRounds;
    int currentRound;

public:
    // Constructor
    CGame();

    // Add a player to the game
    void AddPlayer(const std::shared_ptr<CPlayer>& player);

    // Initialize game settings
    void Initialize(const CSettings& gameSettings);

    // Start the game loop
    void Play();

    // Save game results to leaderboard
    void SaveResults();

    // Display round status
    void DisplayRoundStatus() const;

    ~CGame();
};
