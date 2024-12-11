#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "CPlayer.h"

class CCard {
protected:
    std::string name;
    std::string secondName;
    int power;
    int resilience;

public:
    // Constructor
    CCard(const std::string& cardName, const std::string& cardSecondName, int cardPower, int cardResilience);

    // Virtual functions for card actions
    virtual void PlayCard(std::shared_ptr<CPlayer> player, std::shared_ptr<CPlayer> enemy);
    virtual void AttackEnemy(std::shared_ptr<CPlayer> player, std::shared_ptr<CPlayer> enemy);

    // Getters
    std::string GetCardName() const;
    int GetCardPower() const;
    int GetCardResilience() const;

    // Setters
    void SetCardPower(int newPower);
    void SetCardResilience(int newResilience);

    virtual ~CCard();
};
