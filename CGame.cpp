#include "CGame.h"
#include <iostream>
#include <algorithm>

CGame::CGame() : maxRounds(30), currentRound(0) {}

CGame::~CGame() = default;

void CGame::AddPlayer(const std::shared_ptr<CPlayer>& player) {
    players.push_back(player);
}

void CGame::Initialize(const CSettings& gameSettings) {
    settings = gameSettings;
    maxRounds = (settings.GetDifficulty() == 1) ? 20 : (settings.GetDifficulty() == 3) ? 40 : 30;
    std::cout << "Game initialized with difficulty level: "
              << (settings.GetDifficulty() == 1 ? "Easy" : settings.GetDifficulty() == 2 ? "Medium" : "Hard")
              << " and max rounds: " << maxRounds << std::endl;
}

void CGame::Play() {
    std::cout << "Starting the game...\n" << std::endl;
    while (currentRound < maxRounds && players.size() > 1) {
        DisplayRoundStatus();
        for (size_t i = 0; i < players.size(); ++i) {
            auto& player = players[i];
            auto& opponent = players[(i + 1) % players.size()];

            player->DrawCard();
            player->PlayCard(player, opponent);

            if (opponent->GetPrestige() <= 0) {
                std::cout << opponent->GetName() << " has been defeated and is removed from the game." << std::endl;
                leaderboard.AddWin(player->GetName());
                players.erase(players.begin() + ((i + 1) % players.size()));
                --i; // Adjust index after removal
            }

            if (players.size() == 1) {
                break;
            }
        }
        ++currentRound;
    }

    if (players.size() == 1) {
        std::cout << players[0]->GetName() << " is the winner!" << std::endl;
        leaderboard.AddWin(players[0]->GetName());
    } else {
        std::cout << "Game ended in a draw." << std::endl;
    }

    SaveResults();
}

void CGame::SaveResults() {
    leaderboard.SaveToFile("leaderboard.txt");
    std::cout << "Leaderboard updated and saved to file." << std::endl;
}

void CGame::DisplayRoundStatus() const {
    std::cout << "\n--- Round " << currentRound + 1 << " ---" << std::endl;
    for (const auto& player : players) {
        std::cout << player->GetName() << " - Prestige: " << player->GetPrestige() << std::endl;
    }
    std::cout << std::endl;
}
