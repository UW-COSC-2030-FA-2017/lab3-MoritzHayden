//Hayden Moritz
//COSC 2030 - Lab03
//September 25, 2017

#include<iostream>
using namespace std;

//Factorial function definition using 'long' for the integers and 'float' for the product.
float factorialLong(long n)
{
	if (n > 1) {
		return n * factorialLong(n - 1);
	}
	else {
		return 1;
	}
}

//Factorial function definition using 'double' for the integers and the product.
double factorialDouble(double n)
{
	if (n > 1) {
		return n * factorialDouble(n - 1);
	}
	else {
		return 1;
	}
}

//Write a function f(n) that computes the sum by computing and storing the ratio 1/n and then adding up 'n' copies of the ratio
//I expect that for every value of 'n', the sum will be 1.
double fDouble(double n)
{
	double ratio = 1 / n;
	double sum = 0;
	for (double r = 0; r < n; r++) {
		sum = sum + ratio;
	}
	return sum;
}

float fFloat(float n)
{
	float ratio = 1 / n;
	float sum = 0;
	for (float r = 0; r < n; r++) {
		sum = sum + ratio;
	}
	return sum;
}

int main()
{
	//Using the 'short' data type, write some code that reads 'n' and computes the
	//sum of the consecutive integers 1 through 'n'
	cout << "Summation functions:" << endl << endl;
	short nShort = 0, sumShort = 0;
	cout << "Enter the value of 'n': ";
	cin >> nShort;
	for (short s = 0; s <= nShort; s++) {
		sumShort = sumShort + s;
	}
	cout << "The value of 'n' (short) is: " << nShort << endl;
	cout << "The sum (short) is: " << sumShort << endl << endl;
	//One can detect an overflow by checking or calculating what the maximum value a certain data type can hold.
	//In the case of short, the maximum value it can hold is 32767. When 'n' equals 256, the sum of consecutive integers between 1 and 256 is 32896.
	//Because 32896 > 32767, the calculation results in an overflow.

	//Write the same code, but use the 'long' data type
	long nLong = 0, sumLong = 0;
	cout << "Enter the value of 'n': ";
	cin >> nLong;
	for (long l = 0; l <= nLong; l++) {
		sumLong = sumLong + l;
	}
	cout << "The value of 'n' (long) is: " << nLong << endl;
	cout << "The sum (long) is: " << sumLong << endl << endl;
	//The value of n that results in an overflow is 65536.
	//A derived formula to calculate this is: nMax=sqrt(2*dataTypeMax)

	//Using the 'long' data type, write some code that reads 'n' and computes the
	//product (of type 'float') of the consecutive integers 1 through 'n'
	cout << "Factorial functions:" << endl << endl;
	long nLongProd = 0;
	float productFloat = 0;
	cout << "Enter the value of 'n': ";
	cin >> nLongProd;
	productFloat = factorialLong(nLongProd);
	//Call the function declared before the main class
	cout << "The value of 'n' (long) is: " << nLongProd << endl;
	cout << "The product (float) is: " << factorialLong(nLongProd) << endl << endl;
	//The value of n that results in an overflow is 35.
	//The maximum value of a float is: 3.402823 × 10^38
	//The value of 35! is 1.033314796 * 10^40
	//Because (1.033314796 * 10^40) > (3.402823 × 10^38), we get an overflow.

	//Using the 'double' data type, write some code that reads 'n' and computes the
	//product of the consecutive integers 1 through 'n'
	long nDoubleProd = 0;
	double productDouble = 0;
	cout << "Enter the value of 'n': ";
	cin >> nDoubleProd;
	productDouble = factorialDouble(nDoubleProd);
	//Call the function declared before the main class
	cout << "The value of 'n' (double) is: " << nDoubleProd << endl;
	cout << "The product (double) is: " << factorialDouble(nDoubleProd) << endl << endl;
	//The value of 'n' that results in an overflow is 171.
	//The maximum value of a double is 1.8E+308
	//The value of 171! is 1.24101807 E+309
	//Because (1.24101807 E+309) > (1.8E+308), we get an overflow.


	//Call the fDouble function defined before the main class
	//I expect that for every value of 'n', the sum will be 1.
	cout << "Ratio summation functions:" << endl << endl;
	double nDoubleRatio = 0;
	cout << "Enter the value of 'n': ";
	cin >> nDoubleRatio;
	cout << "Ratio (1/n): 1/" << nDoubleRatio << endl;
	cout << "The sum of 1/n, n times is: " << fDouble(nDoubleRatio) << endl << endl;

	//Call the fFloat function defined before the main class
	//I expect that for every value of 'n', the sum will be 1.
	float nFloatRatio = 0;
	cout << "Enter the value of 'n': ";
	cin >> nFloatRatio;
	cout << "Ratio (1/n): 1/" << nFloatRatio << endl;
	cout << "The sum of 1/n, n times is: " << fFloat(nFloatRatio) << endl << endl;

	//These past two tests confirmed my hypothesis that the sum of this function, for any value on 'n', will be 1.
	//However, when the value of 75 is inserted as 'n', the float value reads 0.999999 instead of 1.
	//This is simply due to the way float addition works.

	//Now for the "puzzles"
	//Float puzzle
	cout << "Puzzles:" << endl << endl;
	cout << "Puzzle using float:" << endl;
	for (float i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}
	//The error here occurs when the for loop checks if i is less than 4.4.
	//This happens because of the way floating point addition works. In this case,
	//the computer sees i as 4.3999, which is less than 4.4, so it prints it out.

	//Double puzzle
	cout << endl << "Puzzle using double:" << endl << endl;
	for (double i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}
	//This example is much better, because now the value of i is calculated as a double, so no floating point
	//calculations are made, thus making i a round 4.4 on its last run through.

	system("pause");
	return 0;
}