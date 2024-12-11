#include "CSettings.h"
#include <fstream>

// Set difficulty level
void CSettings::SetDifficulty(int level) {
    if (level >= 1 && level <= 3) {
        difficultyLevel = level;
        std::cout << "Difficulty set to " << (level == 1 ? "Easy" : level == 2 ? "Medium" : "Hard") << "." << std::endl;
    } else {
        std::cerr << "Invalid difficulty level. Please choose between 1 (Easy), 2 (Medium), or 3 (Hard)." << std::endl;
    }
}

// Toggle sound effects
void CSettings::ToggleSoundEffects() {
    soundEffectsEnabled = !soundEffectsEnabled;
    std::cout << "Sound Effects " << (soundEffectsEnabled ? "Enabled." : "Disabled.") << std::endl;
}

// Get difficulty level
int CSettings::GetDifficulty() const {
    return difficultyLevel;
}

// Check if sound effects are enabled
bool CSettings::IsSoundEffectsEnabled() const {
    return soundEffectsEnabled;
}

// Save settings to a file
void CSettings::SaveSettings(const std::string& fileName) const {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open settings file for writing." << std::endl;
        return;
    }

    file << difficultyLevel << "\n" << soundEffectsEnabled << std::endl;
    file.close();
}

// Load settings from a file
void CSettings::LoadSettings(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open settings file for reading." << std::endl;
        return;
    }

    file >> difficultyLevel >> soundEffectsEnabled;
    file.close();
}
