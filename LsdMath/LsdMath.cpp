// LsdMath.cpp

#include "LsdMath.h"


namespace LsdMath {

	// Constructors
	Vector2::Vector2() {
		x = 0;
		y = 0;
	}

	Vector2::Vector2(float _x, float _y) {
		x = _x;
		y = _y;
	}

	// Returns the string version of a vector
	std::string Vector2::toString() {
		return "x: " + std::to_string(x) + " y: " + std::to_string(y);
	}

	// Sets x,y,z to that of the rhs vector
	void Vector2::operator =(Vector2 vector) {
		x = vector.x;
		y = vector.y;
	}

	// Adds two vectors together and returns the result
	Vector2 Vector2::operator +(Vector2 vector) {
		return Vector2(x+vector.x, y+vector.y);
	}

	// Adds two vectors together and sets the lhs vector to the result
	void Vector2::operator +=(Vector2 vector) {
		*this = *this + vector;
	}

	// Subtracts the rhs vector from the lhs vector and returns the result
	Vector2 Vector2::operator -(Vector2 vector) {
		return Vector2(x - vector.x, y - vector.y);
	}

	// Subtracts the rhs vector from the lhs vector and sets the lhs vector to the result
	void Vector2::operator -=(Vector2 vector) {
		*this = *this - vector;
	}

	// Calculates magnitude of the vector, returns a float
	float Vector2::mag() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	// Calculates the squared magnitude of a vector, returns a float
	float Vector2::magSq() {
		return pow(x, 2) + pow(y, 2);
	}

	// Calculates the dot product, returns a float
	float Vector2::dot(Vector2 vector) {
		return x * vector.x + y * vector.y;
	}

	// Calculates the distance between two vectors, returns a float
	float Vector2::dist(Vector2 vector) {
		return (*this - vector).mag();
	}

	// Normalizes, returns a vector
	Vector2 Vector2::normalize() {
		return sq() / magSq();
	}

	Vector2 operator * (Vector2 vector, float num) {
		return Vector2(vector.x * num, vector.y * num);
	}

	Vector2 operator * (float num, Vector2 vector) {
		return vector * num;
	}

	Vector2 operator / (Vector2 vector, float num) {
		return Vector2(vector.x / num, vector.y / num);
	}

	Vector2 operator / (float num, Vector2 vector) {
		return vector / num;
	}

	Vector2 Vector2::sq() {
		return Vector2(x*x, y*y);
	}

	Vector2 Vector2::floor() {
		return Vector2(std::floor(x), std::floor(y));
	}

	Vector2 Vector2::ceil() {
		return Vector2(std::ceil(x), std::ceil(y));
	}

	Vector2 Vector2::round() {
		return Vector2(std::round(x), std::round(y));
	}


	// Constructors
	Vector3::Vector3() {
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3::Vector3(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	// Returns the string version of a vector
	std::string Vector3::toString() {
		return "x: " + std::to_string(x) + " y: " + std::to_string(y) + " z: " + std::to_string(z);
	}

	// Sets x,y,z to that of the rhs vector
	void Vector3::operator =(Vector3 vector) {
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}

	// Adds two vectors together and returns the result
	Vector3 Vector3::operator +(Vector3 vector) {
		return Vector3(x + vector.x, y + vector.y, z + vector.z);
	}

	// Adds two vectors together and sets the lhs vector to the result
	void Vector3::operator +=(Vector3 vector) {
		*this = *this + vector;
	}

	// Subtracts the rhs vector from the lhs vector and returns the result
	Vector3 Vector3::operator -(Vector3 vector) {
		return Vector3(x - vector.x, y - vector.y, z - vector.z);
	}

	// Subtracts the rhs vector from the lhs vector and sets the lhs vector to the result
	void Vector3::operator -=(Vector3 vector) {
		*this = *this - vector;
	}

	// Calculates magnitude of the vector, returns a float
	float Vector3::mag() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	// Calculates the squared magnitude of a vector, returns a float
	float Vector3::magSq() {
		return pow(x, 2) + pow(y, 2) + pow(z, 2);
	}

	// Calculates the dot product, returns a float
	float Vector3::dot(Vector3 vector) {
		return x*vector.x + y*vector.y + z*vector.z;
	}

	// Calculates the distance between two vectors, returns a float
	float Vector3::dist(Vector3 vector) {
		return (*this - vector).mag();
	}

	// Normalizes, returns a vector
	Vector3 Vector3::normalize() {
		return this->sq() / this->magSq();
	}


	Vector3 operator * (Vector3 vector, float num) {
		return Vector3(vector.x * num, vector.y * num, vector.z * num);
	}

	Vector3 operator * (float num, Vector3 vector) {
		return vector * num;
	}

	Vector3 operator / (Vector3 vector, float num) {
		return Vector3(vector.x / num, vector.y / num, vector.z / num);
	}

	Vector3 operator / (float num, Vector3 vector) {
		return vector / num;
	}

	Vector3 Vector3::cross(Vector3 vector) {
		return Vector3(y * vector.z - vector.y * z, x * vector.z - vector.x * z, x * vector.y - vector.x * y);
	}

	Vector3 Vector3::sq() {
		return Vector3(x * x, y * y, z * z);
	}

	Vector3 Vector3::floor() {
		return Vector3(std::floor(x), std::floor(y), std::floor(z));
	}

	Vector3 Vector3::ceil() {
		return Vector3(std::ceil(x), std::ceil(y), std::ceil(z));
	}

	Vector3 Vector3::round() {
		return Vector3(std::round(x), std::round(y), std::round(z));
	}
}