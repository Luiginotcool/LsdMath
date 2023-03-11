//LsdMath.h
#pragma once
#include <string>
#include <cmath>

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

	class Vector3 {
	public:

		float x;
		float y;
		float z;

		// Constructors
		Vector3();
		Vector3(float _x, float _y, float _z);

		// Returns the string version of a vector
		std::string toString();

		// Sets x,y,z to that of the rhs vector
		void operator =(Vector3 vector);

		// Adds two vectors together and returns the result
		Vector3 operator +(Vector3 vector);

		// Adds two vectors together and sets the lhs vector to the result
		void operator +=(Vector3 vector);

		// Subtracts the rhs vector from the lhs vector and returns the result
		Vector3 operator -(Vector3 vector);

		// Subtracts the rhs vector from the lhs vector and sets the lhs vector to the result
		void operator -=(Vector3 vector);

		// Friend function for the * operator, takes in a float and a vector
		friend Vector3 operator * (Vector3 vector, float num);
		friend Vector3 operator * (float num, Vector3 vector);

		// Friend function for the / operator, takes in a float and a vector
		friend Vector3 operator / (Vector3 vector, float num);
		friend Vector3 operator / (float num, Vector3 vector);

		// Calculates magnitude of the vector, returns a float
		float mag();

		// Calculates the squared magnitude of a vector, returns a float
		float magSq();

		// Calculates the dot product, returns a float
		float dot(Vector3 vector);

		// Calculates the distance between two vectors, returns a float
		float dist(Vector3 vector);

		// Normalizes, returns a vector
		Vector3 normalize();

		// Returns the cross product of two vectors
		Vector3 cross(Vector3 vector);

		// Squares each element of the vector
		Vector3 sq();

		// Calculates the floor of each element of the vector
		Vector3 floor();

		// Calcualtes the ceiling of each element of the vector
		Vector3 ceil();

		// Rounds each element of the vector
		Vector3 round();
	};

	Vector3 operator * (Vector3 vector, float num);
	Vector3 operator * (float num, Vector3 vector);

	Vector3 operator / (Vector3 vector, float num);
	Vector3 operator / (float num, Vector3 vector);
}