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
		return x * vector.x + y * vector.y + z * vector.z;
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

	class Matrix3x3 {
	public:

		float M[9]{0};

		Matrix3x3() {

		}
		Matrix3x3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz) {
			M[0] = xx;
			M[1] = xy;
			M[2] = xz;
			M[3] = yx;
			M[4] = yy;
			M[5] = yz;
			M[6] = zx;
			M[7] = zy;
			M[8] = zz;
		}

		void operator=(Matrix3x3 m) {
			M[0] = m.M[0];
			M[1] = m.M[1];
			M[2] = m.M[2];
			M[3] = m.M[3];
			M[4] = m.M[4];
			M[5] = m.M[5];
			M[6] = m.M[6];
			M[7] = m.M[7];
			M[8] = m.M[8];
		}

		void operator+=(Matrix3x3 m) {
			for (int i = 0; i < 9; i++) {
				M[i] += m.M[i];
			}
		}
		void operator-=(Matrix3x3 m) {
			for (int i = 0; i < 9; i++) {
				M[i] -= m.M[i];
			}
		}
		void operator*=(Matrix3x3 m) {
			float n[9]{ 0 };
			n[0] = M[0] * m.M[0] + M[1] * m.M[3] + M[2] * m.M[6];
			n[1] = M[0] * m.M[1] + M[1] * m.M[4] + M[2] * m.M[7];
			n[2] = M[0] * m.M[2] + M[1] * m.M[5] + M[2] * m.M[8];
			n[3] = M[3] * m.M[0] + M[4] * m.M[3] + M[5] * m.M[6];
			n[4] = M[3] * m.M[1] + M[4] * m.M[4] + M[5] * m.M[7];
			n[5] = M[3] * m.M[2] + M[4] * m.M[5] + M[5] * m.M[8];
			n[6] = M[6] * m.M[0] + M[7] * m.M[3] + M[8] * m.M[6];
			n[7] = M[6] * m.M[1] + M[7] * m.M[4] + M[8] * m.M[7];
			n[8] = M[6] * m.M[2] + M[7] * m.M[5] + M[8] * m.M[8];
			std::copy(std::begin(n), std::end(n), std::begin(M));
		}

		Matrix3x3 operator+(Matrix3x3 m) {
			Matrix3x3 out = *this;
			out += m;
			return out;
		}
		Matrix3x3 operator-(Matrix3x3 m) {
			Matrix3x3 out = *this;
			out -= m;
			return out;
		}
		Matrix3x3 operator*(Matrix3x3 m) {
		}

		void operator *=(float f) {
			for (int i = 0; i < 9; i++) {
				M[i] *= f;
			}
		}
		void operator /=(float f) {
			for (int i = 0; i < 9; i++) {
				M[i] /= f;
			}
		}

		Matrix3x3 operator*(float f) {
			Matrix3x3 out = *this;
			out *= f;
			return out;
		}
		Matrix3x3 operator/(float f) {
			Matrix3x3 out = *this;
			out /= f;
			return out;
		}
	};

	Vector3 operator*(Matrix3x3 m, Vector3 v) {
		Vector3 v = Vector3(m.M[0] * v.x + m.M[1] * v.y + m.M[2] * v.z, m.M[3] * v.x + m.M[4] * v.y + m.M[5] * v.z, m.M[6] * v.x + m.M[7] * v.y + m.M[8] * v.z);
		return v;
	}

	Matrix3x3 operator*(float f, Matrix3x3 m) {
		Matrix3x3 newM = Matrix3x3();
		for (int i = 0; i < 9; i++) {
			newM.M[i] = m.M[i] * f;
		}
	}
}