// LsdMathTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LsdMath.h"

using namespace std;
using namespace LsdMath;

int main()
{
    Vector2 v1 = Vector2(1, 3);
    Vector2 v2 = Vector2(2, 6);
    Vector3 v3 = Vector3(1, 3, 4);
    Vector3 v4 = Vector3(2, 5, 3);

    cout << "LsdMathTester\n";
    cout << "v1: " + v1.toString() << endl;
    cout << "v2: " + v2.toString() << endl;
    cout << "v1 + v2: " << (v1 + v2).toString() << endl;
    cout << "v1 - v2: " << (v1 - v2).toString() << endl;
    cout << "v1 * 3: " << (v1 * 3).toString() << endl;
    cout << "v1 / 2: " << (v1 / 2).toString() << endl;
    cout << "Dist v1 and v2: " << (v1.dist(v2)) << endl;
    cout << "v1 . v2: " << (v1.dot(v2)) << endl;
    cout << "mag of v1: " << (v1.mag()) << endl;
    cout << "magSq of v1: " << (v1.magSq()) << endl;
    cout << "v1^2: " << (v1.sq()).toString() << endl;

    cout << "v3: " + v3.toString() << endl;
    cout << "v4: " + v4.toString() << endl;
    cout << "v3 + v4: " << (v3 + v4).toString() << endl;
    cout << "v3 - v4: " << (v3 - v4).toString() << endl;
    cout << "v3 * 3: " << (v3 * 3).toString() << endl;
    cout << "v3 / 2: " << (v3 / 2).toString() << endl;
    cout << "Dist v3 and v4: " << (v3.dist(v4)) << endl;
    cout << "v3 . v4: " << (v3.dot(v4)) << endl;
    cout << "v3 x v4: " << (v3.cross(v4)).toString() << endl;
    cout << "mag of v3: " << (v3.mag()) << endl;
    cout << "magSq of v3: " << (v3.magSq()) << endl;
    cout << "v3^2: " << (v3.sq()).toString() << endl;
    int a[3] = { 1,2,3 };
    size_t a = 11;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
