#include <iostream>
#include <string>
using namespace std;

// Encrypt text using Caesar Cipher
string caesarEncrypt(const string& text, int shift) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            result += c; // Keep non-alphabetic characters
        }
    }
    return result;
}
// Decrypt text using Caesar Cipher
string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, 26 - (shift % 26));
}

int main() {
    string plaintext, ciphertext;
    int key;

    // Prompt for encryption
    cout << "Enter the plaintext to encrypt: ";
    getline(cin, plaintext);
    cout << "Enter the key (shift value): ";
    cin >> key;
    cin.ignore(); // Clear newline character from input buffer

    ciphertext = caesarEncrypt(plaintext, key);
    cout << "Encrypted text: " << ciphertext << endl;

    // Prompt for decryption
    cout << "\nEnter the ciphertext to decrypt: ";
    string textToDecrypt;
    getline(cin, textToDecrypt);
    cout << "Enter the key used for encryption: ";
    int decryptKey;
    cin >> decryptKey;

    cout << "Decrypted text: " << caesarDecrypt(textToDecrypt, decryptKey) << endl;

    return 0;
}