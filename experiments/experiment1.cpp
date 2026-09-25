#include <iostream>
#include <fstream>
#include <string>

int main() {
    const int NUM_ROWS = 1000;

    // Version A: one file per row
    for (int i = 1; i <= NUM_ROWS; i++) {
        std::string filename = "many_files/row_" + std::to_string(i) + ".txt";
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "ERROR: could not open " << filename << std::endl;
            return 1;
        }
        file << "row number " << i << std::endl;
        file.close();
    }
    std::cout << "Version A done: " << NUM_ROWS << " files written" << std::endl;

    // Version B: one file, all rows packed together
    std::ofstream packed("packed.txt");
    if (!packed.is_open()) {
        std::cout << "ERROR: could not open packed.txt" << std::endl;
        return 1;
    }
    for (int i = 1; i <= NUM_ROWS; i++) {
        packed << "row number " << i << std::endl;
    }
    packed.close();
    std::cout << "Version B done: packed.txt written" << std::endl;

    return 0;
}
