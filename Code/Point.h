#pragma once
#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <string>

class Point {
private:
	double x = 0;
	double y = 0;
public:
	Point() {}
	~Point() {}
	Point(double x, double y) : x(x), y(y) {}

	Point(std::string input) : x(std::stod(input)){
		std::string y="";
		int i = 0;
		while (input[i++] != ',');
			for (;i < input.size();i++) y += input[i];
		this->y = std::stod(y);
	}

	void setX(double x) {
		this->x = x;
	}

	void setY(double y) {
		this->y = y;
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	friend std::istream& operator>>(std::istream& input, Point& point) {
		input >> point.x >> point.y;
		return input;
	}
	friend std::ostream& operator<<(std::ostream& output, Point& point) {
		output << "(" << point.getX() << "," << point.getY() << ")";
		return output;
	}

	

	Point operator+(Point& point) {
		Point plus;
		plus.x = this->x + point.x;
		plus.y = this->y + point.y;
		return plus;
	}
	Point operator-(Point& point) {
		Point minus;
		minus.x = this->x + point.x;
		minus.y = this->y + point.y;
		return minus;
	}
	Point operator/(Point& point) {
		Point divide;
		divide.x = this->x / point.x;
		divide.y = this->y / point.y;
		return divide;
	}
	Point operator*(Point& point) {
		Point multiply;
		multiply.x = this->x * point.x;
		multiply.y = this->y * point.y;
		return multiply;
	}
	double Dot(Point A, Point B) {
		return A.x * B.x + A.y * B.y;
	}
};


