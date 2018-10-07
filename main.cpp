#include <chrono>
#include <fstream>
#include "detours.hpp"
int main() {
	std::ofstream file;
	file.open("Avsyanochka.txt");
	int capacity = 4096;
	while (capacity !=35389440) {
		int * array = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			array[i] = rand() % 3;
		}
		sum_straight_detour(array, capacity);
	    auto startTime = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000; i++)
		sum_straight_detour(array, capacity);
		auto endTime = std::chrono::high_resolution_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
		file<<"count_elements="<<capacity<<" "<< "time:"<<diff<<" "<<"straight detour"<<std::endl;
		file<< std::endl;

		sum_reverse_detour(array, capacity);
		startTime = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000; i++)
		sum_reverse_detour(array, capacity);
		endTime = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
		file<<"count_elements="<<capacity<<" "<< "time:"<<diff<<" "<<"reverse detour"<<std::endl;
		file<<std::endl;

		sum_random_detour(array, capacity);
		startTime = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000; i++)
		sum_random_detour(array, capacity);
		endTime = std::chrono::high_resolution_clock::now();
		diff = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
		file<<"count_elements="<<capacity<<" "<< "time:"<<diff<<" "<<"random detour"<<std::endl;
		file<<std::endl;

		delete [] array;
		if (capacity == 16777216) capacity = 17694720;
		else capacity = capacity * 2;
	}
}
