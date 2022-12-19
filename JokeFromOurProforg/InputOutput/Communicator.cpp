#include "InputOutput/Communicator.h"

void Communicator::Greeting() const {
	std::cout << "Which level do you want to choose? Enter 1 or 2\n";
}

void Communicator::SetFieldSize() const {
	std::cout << "The size of the map must be in range from 3 to 20\n";
	std::cout << "If you enter an incorrect output, the values will move to the rigth range\n";
	std::cout << "Enter the size of the map, separating it with a space." << std::endl;
	std::cout << "Format of the enter: Width Height" << std::endl;
}

void Communicator::WrongAnswer() const {
    std::cout << "Incorrect command! Please, check the correct format of the enter!\n";
}

void Communicator::SetStandartSize() const {
    std::cout << "Unfortunately, the specified field sizes do not meet the set criteria." << std::endl;
    std::cout << "The field sizes have been normalized." << std::endl;
}

void Communicator::Continue() const {
    std::cout << "Do you want to continue?" << std::endl;
    std::cout << "Enter any symbol to do it." << std::endl;
}

