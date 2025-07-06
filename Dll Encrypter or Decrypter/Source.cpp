#include <iostream>
#include <fstream>

void XorEncryptFile(const char* input, const char* output, uint8_t key = 0x5A) {
    std::ifstream in(input, std::ios::binary);
    std::ofstream out(output, std::ios::binary);
    if (!in || !out) {
        std::cerr << "Error opening input/output file.\n";
        return;
    }
    char c;
    while (in.get(c)) {
        out.put(c ^ key);
    }
    std::cout << "Processing complete: " << output << "\n";
}

int main() {
    const char* inputDLL = "Dummy.dll";                // Original DLL
    const char* encryptedDLL = "Dummy_encrypted.dll";  // Encrypted output
    const char* decryptedDLL = "Dummy_decrypted.dll";  // Decrypted output

    // Encrypt the DLL
    XorEncryptFile(inputDLL, encryptedDLL);

    // Decrypt the DLL (just XOR again with the same key)
    XorEncryptFile(encryptedDLL, decryptedDLL);

    return 0;
}
