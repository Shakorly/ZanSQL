#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

int main() {
    const int NUM_ROWS = 1000;

    // Time reading 1000 separate files
    auto start_a = std::chrono::steady_clock::now();
    for (int i = 1; i <= NUM_ROWS; i++) {
        std::string filename = "many_files/row_" + std::to_string(i) + ".txt";
        std::ifstream file(filename);
        std::string line;
        std::getline(file, line);
        file.close();
    }
    auto end_a = std::chrono::steady_clock::now();
    auto duration_a = std::chrono::duration_cast<std::chrono::microseconds>(end_a - start_a);
    std::cout << "Reading 1000 separate files: " << duration_a.count() << " microseconds" << std::endl;

    // Time reading 1 packed file
    auto start_b = std::chrono::steady_clock::now();
    std::ifstream packed("packed.txt");
    std::string line;
    while (std::getline(packed, line)) {
        // just reading through
    }
    packed.close();
    auto end_b = std::chrono::steady_clock::now();
    auto duration_b = std::chrono::duration_cast<std::chrono::microseconds>(end_b - start_b);
    std::cout << "Reading 1 packed file: " << duration_b.count() << " microseconds" << std::endl;

    return 0;
}
