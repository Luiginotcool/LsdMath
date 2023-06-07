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
		return Vector2(x + vector.x, y + vector.y);
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
		return Vector2(x * x, y * y);
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

	Vector::Vector(size_t Dim) {
		for (int i = 0; i < Dim; i++) { elements.push_back(0); }
		dim = Dim;
	}

	Vector::Vector(std::initializer_list<float> l) {
		elements.insert(elements.end(), l.begin(), l.end());
		dim = l.size();
	}

	// Returns the vector as a string
	std::string Vector::toString() {
		std::string out = "";
		for (int i = 0; i < elements.size(); i++) {
			out += std::to_string(i) + ": " + std::to_string(elements[i]) + "\n";
		}
		return out;
	}

	// Sets elements to that of the rhs vector
	void Vector::operator =(Vector vector) {
		if (dim == vector.dim) {
			elements.clear();
			elements.insert(elements.end(), vector.elements.begin(), vector.elements.end());
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
		}
	}

	// Adds two vectors together and returns the result
	Vector Vector::operator +(Vector vector) {
		if (dim == vector.dim) {
			Vector out(dim);
			out = *this;
			out += vector;
			return out;
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
			return Vector(0);
		}
	}

	// Adds two vectors together and sets the lhs vector to the result
	void Vector::operator +=(Vector vector) {
		if (dim == vector.dim) {
			for (int i = 0; i < dim; i++) {
				elements[i] += vector.elements[i];
			}
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
		}
	}

	// Subtracts the rhs vector from the lhs vector and returns the result
	Vector Vector::operator -(Vector vector) {
		if (dim == vector.dim) {
			Vector out(dim);
			out = *this;
			out -= vector;
			return out;
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
			return Vector(0);
		}
	}

	// Subtracts the rhs vector from the lhs vector and sets the lhs vector to the result
	void Vector::operator -=(Vector vector) {
		if (dim == vector.dim) {
			for (int i = 0; i < dim; i++) {
				elements[i] += vector.elements[i];
			}
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
		}
	}

	Vector Vector::operator*(float num) {
		Vector out(dim);
		out = *this;
		out *= num;
		return out;
	}

	Vector Vector::operator/(float num) {
		if (num != 0) {
			Vector out(dim);
			out = *this;
			out /= num;
			return out;
		}
	}

	void Vector::operator*=(float num) {
		for (int i = 0; i < dim; i++) {
			elements[i] *= num;
		}
	}

	void Vector::operator/=(float num) {
		if (num != 0) {
			for (int i = 0; i < dim; i++) {
				elements[i] /= num;
			}
		}
		else {
			throw std::invalid_argument("Divide by zero");
		}
	}

	// Friend function for the * operator, takes in a float and a vector
	Vector operator * (float num, Vector vector) {
		return vector * num;
	}



	// Calculates magnitude of the vector, returns a float
	float Vector::mag() {
		return sqrt(this->magSq());
	}

	// Calculates the squared magnitude of a vector, returns a float
	float Vector::magSq() {
		float sum = 0;
		for (int i = 0; i < dim; i++) {
			sum += pow(elements[i], 2);
		}
		return sum;
	}

	// Calculates the dot product, returns a float
	float Vector::dot(Vector vector) {
		if (dim == vector.dim) {
			float sum = 0;
			for (int i = 0; i < dim; i++) {
				sum += elements[i] * vector.elements[i];
			}
			return sum;
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
			return 0;
		}
	}

	// Calculates the distance between two vectors, returns a float
	float Vector::dist(Vector vector) {
		if (dim == vector.dim) {
			return (*this - vector).mag();
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
			return 0;
		}
	}

	// Normalizes, returns a vector
	Vector Vector::normalize() {
		return (*this / this->mag());
	}

	// Squares each element of the vector
	Vector Vector::sq() {
		Vector out(dim);
		for (int i = 0; i < dim; i++) {
			out.elements[i] = pow(elements[i], 2);
		}
		return out;
	}

	// Calculates the floor of each element of the vector
	Vector Vector::floor() {
		Vector out(dim);
		for (int i = 0; i < dim; i++) {
			out.elements[i] = std::floor(elements[i]);
		}
		return out;
	}

	// Calculates the ceiling of each element of the vector
	Vector Vector::ceil() {
		Vector out(dim);
		for (int i = 0; i < dim; i++) {
			out.elements[i] = std::ceil(elements[i]);
		}
		return out;
	}

	// Rounds each element of the vector
	Vector Vector::round() {
		Vector out(dim);
		for (int i = 0; i < dim; i++) {
			out.elements[i] = std::round(elements[i]);
		}
		return out;
	}

	Matrix::Matrix(size_t Rows, size_t Cols) {
		rows = Rows;
		cols = Cols;
		for (int y = 0; y < rows; y++) {
			elements.push_back(std::vector<float>());
			for (int x = 0; x < cols; x++) {
				elements[y].push_back(0);
			}
		}
	}

	Matrix::Matrix(std::initializer_list<std::initializer_list<float>> l) {
		rows = (*l.begin()).size();
		cols = l.size();
		for (int y = 0; y < rows; y++) {
			elements.insert(elements.end(), (*(l.begin()+y)).begin(), (*(l.begin() + y)).end());
		}
	}

	void Matrix::operator=(Matrix m) {
		if ((rows == m.rows) && (cols = m.cols)) {
			for (int y = 0; y < rows; y++) {
				for (int x = 0; x < cols; x++) {
					elements[y][x] = m.elements[y][x];
				}
			}
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
		}
	}

	void Matrix::operator+=(Matrix m) {
		if ((rows == m.rows) && (cols = m.cols)) {
			for (int y = 0; y < rows; y++) {
				for (int x = 0; x < cols; x++) {
					elements[y][x] += m.elements[y][x];
				}
			}
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
		}
	}
	void Matrix::operator-=(Matrix m) {
		if ((rows == m.rows) && (cols = m.cols)) {
			for (int y = 0; y < rows; y++) {
				for (int x = 0; x < cols; x++) {
					elements[y][x] -= m.elements[y][x];
				}
			}
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
		}
	}
	void Matrix::operator*=(Matrix m) {
		if (cols == m.rows) {
			for (int y = 0; y < rows; y++) {
				for (int x = 0; x < cols; x++) {
					float sum = 0;
					for (int i = 0; i < 3; i++) {
						sum += elements[y][i] * m.elements[i][x];
					}
					elements[y][x] = sum;
				}
			}
		}
		else {
			throw std::invalid_argument("Vector dimension mismatch");
		}
	}

	Matrix Matrix::operator+(Matrix m) {
		Matrix out(rows, cols);
		out = *this;
		out += m;
		return out;
	}
	Matrix Matrix::operator-(Matrix m) {
		Matrix out(rows, cols);
		out = *this;
		out -= m;
		return out;
	}
	Matrix Matrix::operator*(Matrix m) {
		Matrix out(rows, cols);
		out = *this;
		out *= m;
		return out;
	}

	void Matrix::operator *=(float f) {
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < cols; x++) {
				elements[y][x] *= f;
			}
		}
	}
	void Matrix::operator /=(float f) {
		if (f != 0) {
			for (int y = 0; y < rows; y++) {
				for (int x = 0; x < cols; x++) {
					elements[y][x] /= f;
				}
			}
		}
		else {
			throw std::invalid_argument("Divide by zero");
		}
	}

	Matrix Matrix::operator*(float f) {
		Matrix out(rows, cols);
		out = *this;
		out *= f;
		return out;
	}
	Matrix Matrix::operator/(float f) {
		Matrix out(rows, cols);
		out = *this;
		out /= f;
		return out;
	}

	Matrix operator*(float f, Matrix m) {
		return m * f;
	}

}