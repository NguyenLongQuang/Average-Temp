#include "Trainset.h"
#include "Point.h"

int main() {
	std::string address;
	std::cout << "Input data address (Ex: data.txt): ";
	std::getline(std::cin, address);

	std::ifstream input (address);

	if (!input.is_open()) std::cout << "Could not open the file\n";
	else {
		std::string line;
		Point p;
		Trainset trainning_examples;

		input >> line;
		while (input >> line) {
			p = Point(line);
			trainning_examples.setExample(p);
		}

		std::cout << "\nLearning...";
		double theta0 = 0, theta1 = 0;
		run_GD(theta0, theta1, trainning_examples.normalized());
		std::cout << "\nInput number of test: ";
		int n_test;
		std::cin >> n_test;
		double x, y;
		for (int i = 0;i < n_test;i++) {
			std::cin >> x;
			x = x / trainning_examples.getMax_X();
			y = trainning_examples.getMax_Y() * (theta0 + theta1 * x);
			std::cout << "\nOutput: " << y << std::endl;
		}
	}
	return 0;
}
