#include "CPlayer.h"
#include <iostream>
#include <algorithm>

CPlayer::CPlayer(const std::string& playerName, int initialPrestige, const std::vector<std::shared_ptr<CCard>>& playerDeck)
    : name(playerName), prestige(initialPrestige), deck(playerDeck), table(std::make_shared<CTable>()) {}

void CPlayer::DrawCard() {
    if (!deck.empty()) {
        auto card = deck.back();
        deck.pop_back();
        hand.push_back(card);
        std::cout << name << " draws " << card->GetCardName() << "." << std::endl;
    } else {
        std::cout << name << " has no cards left to draw!" << std::endl;
    }
}

void CPlayer::PlayCard(std::shared_ptr<CPlayer> self, std::shared_ptr<CPlayer> enemy) {
    if (!hand.empty()) {
        auto card = hand.back();
        hand.pop_back();
        std::cout << name << " plays " << card->GetCardName() << "." << std::endl;
        card->PlayCard(self, enemy);
        table->PlaceCardOnTop(card);
    } else {
        std::cout << name << " has no cards to play!" << std::endl;
    }
}

void CPlayer::RemoveCard(const std::shared_ptr<CCard>& card) {
    auto it = std::find(hand.begin(), hand.end(), card);
    if (it != hand.end()) {
        hand.erase(it);
        std::cout << card->GetCardName() << " is removed from " << name << "'s hand." << std::endl;
    } else {
        std::cout << card->GetCardName() << " not found in " << name << "'s hand." << std::endl;
    }
}

std::string CPlayer::GetName() const {
    return name;
}

int CPlayer::GetPrestige() const {
    return prestige;
}

std::shared_ptr<CTable> CPlayer::GetTable() const {
    return table;
}

void CPlayer::SetPrestige(int newPrestige) {
    prestige = newPrestige;
}

CPlayer::~CPlayer() = default;
