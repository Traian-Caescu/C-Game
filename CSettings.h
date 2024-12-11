#pragma once
#include <string>
#include <iostream>

class CSettings {
private:
    int difficultyLevel; // 1: Easy, 2: Medium, 3: Hard
    bool soundEffectsEnabled;

public:
    // Constructor to initialize default settings
    CSettings() : difficultyLevel(2), soundEffectsEnabled(true) {}

    // Setters
    void SetDifficulty(int level) {
        if (level >= 1 && level <= 3) {
            difficultyLevel = level;
            std::cout << "Difficulty set to " << (level == 1 ? "Easy" : level == 2 ? "Medium" : "Hard") << "." << std::endl;
        } else {
            std::cerr << "Invalid difficulty level. Please choose between 1 (Easy), 2 (Medium), or 3 (Hard)." << std::endl;
        }
    }

    void ToggleSoundEffects() {
        soundEffectsEnabled = !soundEffectsEnabled;
        std::cout << "Sound Effects " << (soundEffectsEnabled ? "Enabled." : "Disabled.") << std::endl;
    }

    // Getters
    int GetDifficulty() const {
        return difficultyLevel;
    }

    bool IsSoundEffectsEnabled() const {
        return soundEffectsEnabled;
    }

    // Save settings to a file
    void SaveSettings(const std::string& fileName) const {
        std::ofstream file(fileName);
        if (!file.is_open()) {
            std::cerr << "Failed to open settings file for writing." << std::endl;
            return;
        }

        file << difficultyLevel << "\n" << soundEffectsEnabled << std::endl;
        file.close();
    }

    // Load settings from a file
    void LoadSettings(const std::string& fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            std::cerr << "Failed to open settings file for reading." << std::endl;
            return;
        }

        file >> difficultyLevel >> soundEffectsEnabled;
        file.close();
    }
};
