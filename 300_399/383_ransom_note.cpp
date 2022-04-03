#include <iostream>

using namespace std;


#define BUFFER_LEN ('z'-'a'+1)

bool canConstruct(string ransomNote, string magazine) {
    // First, count all chars in 'magazine' from 'a' to 'z'
    int charCount[BUFFER_LEN] = {};

    for (char c: magazine) {
        charCount[tolower(c)-'a']++;
    }

    // Then, substract the charcters used in 'ransomNote'
    for (char c: ransomNote) {
        charCount[tolower(c)-'a']--;
    }

    // If there are any negative count in the list, it cannot be constructed,
    // otherwise it can be.
    for (int i=0; i<BUFFER_LEN; ++i) {
        if (charCount[i] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string note1 = "asdf";
    string mag1  = "asde";

    string note2 = "qwer";
    string mag2  = "qwerty";

    cout << "Can construct '" << note1 << "' with '" << mag1 << "'?: " <<
            (canConstruct(note1, mag1)? "yes": "no") << endl;

    cout << "Can construct '" << note2 << "' with '" << mag2 << "'?: " <<
            (canConstruct(note2, mag2)? "yes": "no") << endl;


    string note3 = "az";
    string mag3  = "ab";

    cout << "Can construct '" << note3 << "' with '" << mag3 << "'?: " <<
            (canConstruct(note3, mag3)? "yes": "no") << endl;

    return 0;
}