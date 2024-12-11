#pragma once
#include <string>
#include <vector>
#include <memory>
#include "CCard.h"
#include "CTable.h"

class CPlayer : public std::enable_shared_from_this<CPlayer> {
private:
    std::string name;
    int prestige;
    std::vector<std::shared_ptr<CCard>> deck;
    std::shared_ptr<CTable> table;
    std::vector<std::shared_ptr<CCard>> hand;

public:
    // Constructor
    CPlayer(const std::string& playerName, int initialPrestige, const std::vector<std::shared_ptr<CCard>>& playerDeck);

    // Draw a card from the deck to the hand
    void DrawCard();

    // Play a card from the hand
    void PlayCard(std::shared_ptr<CPlayer> self, std::shared_ptr<CPlayer> enemy);

    // Remove a card from the hand
    void RemoveCard(const std::shared_ptr<CCard>& card);

    // Getters
    std::string GetName() const;
    int GetPrestige() const;
    std::shared_ptr<CTable> GetTable() const;

    // Setters
    void SetPrestige(int newPrestige);

    ~CPlayer();
};
