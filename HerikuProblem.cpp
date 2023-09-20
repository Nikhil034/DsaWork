#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<string> getHaikuLine(int syllables) {
    vector<string> words;
    
    // Add your own words or phrases here
    if (syllables == 5) {
        words = {"Autumn leaves fall",
                 "Cherry blossoms bloom bright",
                 "Whispers of the wind"};
    } else if (syllables == 7) {
        words = {"Silent moonlight glows",
                 "Rivers winding through the hills",
                 "Nature's tranquil dance"};
    } else {
        words = {"Mist in morning light",
                 "Haiku lines should be just right",
                 "Capturing nature's sight"};
    }
    
    return words;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    
    // Generate a random Haiku
    for (int i = 0; i < 3; ++i) {
        int syllables = (i == 1) ? 7 : 5;
        vector<string> line = getHaikuLine(syllables);
        
        // Randomly select and print a word/phrase from the line
        int randomIndex = rand() % line.size();
        cout << line[randomIndex] << endl;
    }
    
    return 0;
}
