#include <iostream>
#include <random>

int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    int min; int max;
    std::cin >> min >> max;
    int randomNum = getRandomNumber(min, max);
    std::cout << "Random number between " << min << " and " << max << ": " << randomNum << std::endl;
    return 0;
}