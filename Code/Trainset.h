#pragma once
#include "Point.h"
#include<vector>
#include<math.h>

#define learning_rate 0.01

class Trainset {
private:
	std::vector<Point> examples;
public:
	Trainset(){}
	~Trainset(){}
	Trainset(std::vector<Point> examples) : examples(examples) {}

	void setExample(Point point) {
		examples.push_back(point);
	}
	Point getExample(int i) {
		return examples[i];
	}

	std::vector<Point> getExamples() {
		return examples;
	}

	double getMax_X() {
		double maxX = examples[0].getX();
		for (int i = 0;i <examples.size();i++) {
			if (examples[i].getX() > maxX) maxX = examples[i].getX();
		}
		return maxX;
	}
	double getMax_Y() {
		double maxY = examples[0].getY();
		for (int i = 0;i < examples.size();i++) {
			if (examples[i].getY() > maxY) maxY = examples[i].getY();
		}
		return maxY;
	}
	Point getMax_Point(){
		Point max;
		max.setX(this->getMax_X());
		max.setY(this->getMax_Y());
		return max;
	}

	int getNum_Examples() {
		return (int)examples.size();
	}

	Trainset normalized() {
		Trainset n;
		Point max = this->getMax_Point();
		for (int i = 0;i < examples.size();i++) {
			n.examples.push_back((this->examples[i])/max);
		}
		return n;
	}
};

double J (double theta0, double theta1, Trainset T) {
	double j=0;
	int m = T.getNum_Examples();
	for (int i = 0;i < m;i++) {
		j += pow(theta0 + theta1 * T.getExample(i).getX() - T.getExample(i).getY(), 2)/2/m;
	}
	return j;
}
double J_0(double theta0, double theta1, Trainset T) {
	double j = 0;
	int m = T.getNum_Examples();
	for (int i = 0;i < m;i++) {
		j += (theta0 + theta1 * T.getExample(i).getX() - T.getExample(i).getY()) / m;
	}
	return j;
}

double J_1(double theta0, double theta1, Trainset T) {
	double j = 0;
	int m = T.getNum_Examples();
	for (int i = 0;i < m;i++) {
		j += T.getExample(i).getX() * (theta0 + theta1 * T.getExample(i).getX() - T.getExample(i).getY()) / m;
	}
	return j;
}

void run_GD(double& theta0, double& theta1, Trainset T) {
	double temp0, temp1;
	for (int i = 0;i < 300000;i++) {
		 temp0 = theta0 - learning_rate * J_0(theta0, theta1, T);
		 temp1 = theta1 - learning_rate * J_1(theta0, theta1, T);
		 theta0 = temp0;
		 theta1 = temp1;
	}
}