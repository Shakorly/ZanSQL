#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("test.txt");

	if (!file.is_open()){
		std::cout << "Error in open the file" << std::endl;

		return 1;

	}
	file<< "Hello, disk!" << std::endl;
	file.close();
    	std::cout << "Done writing" << std::endl;


	return 0;
}
