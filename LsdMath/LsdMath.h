//LsdMath.h
#pragma once
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>

namespace LsdMath {
	class Vector2 {
	public:
		float x;
		float y;

		// Constructors
		Vector2();
		Vector2(float _x, float _y);

		// Returns the string version of a vector
		std::string toString();

		// Sets x,y,z to that of the rhs vector
		void operator =(Vector2 vector1);

		// Adds two vectors together and returns the result
		Vector2 operator +(Vector2 vector);

		// Adds two vectors together and sets the lhs vector to the result
		void operator +=(Vector2 vector);

		// Subtracts the rhs vector from the lhs vector and returns the result
		Vector2 operator -(Vector2 vector);

		// Subtracts the rhs vector from the lhs vector and sets the lhs vector to the result
		void operator -=(Vector2 vector);

		// Friend function for the * operator, takes in a float and a vector
		friend Vector2 operator * (Vector2 vector, float num);
		friend Vector2 operator * (float num, Vector2 vector);

		// Friend function for the / operator, takes in a float and a vector
		friend Vector2 operator / (Vector2 vector, float num);
		friend Vector2 operator / (float num, Vector2 vector);

		// Calculates magnitude of the vector, returns a float
		float mag();

		// Calculates the squared magnitude of a vector, returns a float
		float magSq();

		// Calculates the dot product, returns a float
		float dot(Vector2 vector);

		// Calculates the distance between two vectors, returns a float
		float dist(Vector2 vector);

		// Normalizes, returns a vector
		Vector2 normalize();

		// Squares each element of the vector
		Vector2 sq();

		// Calculates the floor of each element of the vector
		Vector2 floor();

		// Calculates the ceiling of each element of the vector
		Vector2 ceil();

		// Rounds each element of the vector
		Vector2 round();
	};

	Vector2 operator * (Vector2 vector, float num);
	Vector2 operator * (float num, Vector2 vector);

	Vector2 operator / (Vector2 vector, float num);
	Vector2 operator / (float num, Vector2 vector);


	class Vector {
	public:
		std::vector<float> elements;
		size_t dim;

		Vector(size_t Dim);
		Vector(std::initializer_list<float> l);

		// Returns the vector as a string
		std::string toString();

		// Sets x,y,z to that of the rhs vector
		void operator =(Vector vector);

		// Adds two vectors together and returns the result
		Vector operator +(Vector vector);
		// Adds two vectors together and sets the lhs vector to the result
		void operator +=(Vector vector);
		// Subtracts the rhs vector from the lhs vector and returns the result
		Vector operator -(Vector vector);
		// Subtracts the rhs vector from the lhs vector and sets the lhs vector to the result
		void operator -=(Vector vector);

		Vector operator *(float num);
		Vector operator /(float num);

		void operator *= (float num);
		void operator /= (float num);



		// Friend function for the * operator, takes in a float and a vector
		friend Vector operator * (float num, Vector vector);

		// Calculates magnitude of the vector, returns a float
		float mag();

		// Calculates the squared magnitude of a vector, returns a float
		float magSq();

		// Calculates the dot product, returns a float
		float dot(Vector vector);

		// Calculates the distance between two vectors, returns a float
		float dist(Vector vector);

		// Normalizes, returns a vector
		Vector normalize();

		// Squares each element of the vector
		Vector sq();

		// Calculates the floor of each element of the vector
		Vector floor();

		// Calculates the ceiling of each element of the vector
		Vector ceil();

		// Rounds each element of the vector
		Vector round();
	};


	Vector operator * (float num, Vector vector);



	class Matrix {
	public:
		std::vector<std::vector<float>> elements;
		size_t rows;
		size_t cols;

		Matrix(size_t Rows, size_t Cols);
		Matrix(std::initializer_list<std::initializer_list<float>> l);

		void operator=(Matrix m);

		void operator+=(Matrix m);
		void operator-=(Matrix m);
		void operator*=(Matrix m);

		Matrix operator+(Matrix m);
		Matrix operator-(Matrix m);
		Matrix operator*(Matrix m);

		void operator *=(float f);
		void operator /=(float f);

		Matrix operator*(float f);
		Matrix operator/(float f);

		friend Matrix operator*(float f, Matrix m);
	};


	Matrix operator*(float f, Matrix m);
}