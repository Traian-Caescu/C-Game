#include "CCard.h"

CCard::CCard(const std::string& cardName, const std::string& cardSecondName, int cardPower, int cardResilience)
    : name(cardName), secondName(cardSecondName), power(cardPower), resilience(cardResilience) {}

void CCard::PlayCard(std::shared_ptr<CPlayer> player, std::shared_ptr<CPlayer> enemy) {
    std::cout << player->GetName() << " plays " << GetCardName() << "." << std::endl;
}

void CCard::AttackEnemy(std::shared_ptr<CPlayer> player, std::shared_ptr<CPlayer> enemy) {
    std::cout << GetCardName() << " attacks " << enemy->GetName() << "." << std::endl;
    enemy->SetPrestige(enemy->GetPrestige() - power);
    std::cout << enemy->GetName() << "'s prestige is now " << enemy->GetPrestige() << "." << std::endl;
}

std::string CCard::GetCardName() const {
    return name + " " + secondName;
}

int CCard::GetCardPower() const {
    return power;
}

int CCard::GetCardResilience() const {
    return resilience;
}

void CCard::SetCardPower(int newPower) {
    power = newPower;
}

void CCard::SetCardResilience(int newResilience) {
    resilience = newResilience;
}

CCard::~CCard() = default;
