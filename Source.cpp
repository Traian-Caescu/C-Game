#include <memory>
#include <cstdlib>
#include <ctime>
#include <crtdbg.h>
#include "CCardDeckLoader.h"
#include "CGame.h"
#include "CPlayer.h"
#include <iostream>

// Define memory allocation mapping
#define CRTDBG_MAP_ALLOC

using namespace std;

int main() {
    {
        try {
            // Load card decks from files
            const auto profPlagiaristFile = make_shared<CCardDeckLoader>("plagiarist.txt");
            const auto profPifflePaperFile = make_shared<CCardDeckLoader>("piffle-paper.txt");
            const auto profPointlessFile = make_shared<CCardDeckLoader>("pointless.txt");
            const auto profPerditionFile = make_shared<CCardDeckLoader>("perdition.txt");

            // Verify decks are loaded
            if (profPlagiaristFile->GetCards().empty() || profPifflePaperFile->GetCards().empty() ||
                profPointlessFile->GetCards().empty() || profPerditionFile->GetCards().empty()) {
                throw runtime_error("One or more decks failed to load.");
            }

            // Create professor players
            int prestige = 30;
            const auto profPlagiarist = make_shared<CPlayer>("Plagiarist", prestige, profPlagiaristFile->GetCards());
            const auto profPifflePaper = make_shared<CPlayer>("Piffle-paper", prestige, profPifflePaperFile->GetCards());
            const auto profPointless = make_shared<CPlayer>("Pointless", prestige, profPointlessFile->GetCards());
            const auto profPerdition = make_shared<CPlayer>("Perdition", prestige, profPerditionFile->GetCards());

            // Initialize random seed using current time
            srand(static_cast<unsigned>(time(nullptr)));

            // Set up game
            CGame game;
            game.AddPlayer(profPlagiarist);
            game.AddPlayer(profPifflePaper);
            game.AddPlayer(profPointless);
            game.AddPlayer(profPerdition);

            // Display initial player statuses
            cout << "Initial player statuses:\n";
            for (const auto& player : {profPlagiarist, profPifflePaper, profPointless, profPerdition}) {
                cout << player->GetName() << " - Prestige: " << player->GetPrestige() << endl;
            }

            // Play the game
            game.Play();
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    // Check for memory leaks
    _CrtDumpMemoryLeaks();
    return 0;
}
