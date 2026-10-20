// **************************************************************************************
// ******              STUDENT NAME: ERDOGAN BULUT									*****
// *****			 STUDENT NUMBER : B221202021									*****
// *****				ASSIGNMENT # :	ASSIGNMENT 1								*****
// *****					- HONOR CODE -											*****
// **************************************************************************************

// Program to approximate the definite integral of f(x) = x^3 + 4x using midpoint, left-hand, and right-hand rules.

#include <iostream> // Main C++ Library.
#include <iomanip> // C++ Library which is include setw(),setpresicion() etc.
#include <cmath> // C++ Library which is include math operation shortcuts.
using namespace std;

int main() { // Create the main function.

	double a, b; // Define variables called a, b. a value for start point of the interval and b value for final point of the interval.
	int n, i; // Define variables called n, i. n is the number of intervals we will examine in the interval we want to calculate. n must be integer because intervals can't be decimal number. i value for loops.
	cout << "Enter the values of a, b and n: "; // The values of a,b and n ask to user.
	cin >> a >> b >> n; // Get values from user.

	double deltaX = (b - a) / n; // Define deltaX as (b-a)/n. deltaX is the interval step value between [a,b].

	cout << "a : " << a << "\nb : " << b << "\nn : " << n << endl; // Print taken values from user.
	cout << "-------------------------------------------------------------------" << endl; // Print a line.
	cout << setw(6) << "i" << setw(12) << "x[i]" << setw(15) << "epsilon[i]" << setw(10) << "LHF" // Print the headlines of table.
		<< setw(10) << "RHF" << setw(9) << "MF" << endl;
	cout << "-------------------------------------------------------------------" << endl; // Print a line.

	double sumLHF = 0, sumRHF = 0, sumMF = 0; // Assign left Riemann Sum(sumLHF), Right Riemann Sum(sumRHF), and Midpoint Sum(sumMF) to zero.
	for (i = 1; i <= n; i++) { // A loop for creating a table with values of table's elements and calculating total of sums.
		double xi = a + (i - 1) * deltaX; // Calculating x(i) values. xi is the i'th term of the partition.
		double xi1 = a + i * deltaX; // Calculating x(i+1) values. xi1 is the i+1'th term of the partition.
		double epsiloni = xi + deltaX * 0.5; // Calculating epsilon(i) values. epsilon is the midpoints of two interval steps.
		double functionFxi = pow(xi, 3) + 4 * xi; // Calculating f(x(i)) values.
		double functionFxi1 = pow(xi1, 3) + 4 * xi1; // Calculating f(x(i+1) values.
		double functionFepsiloni = pow(epsiloni, 3) + 4 * epsiloni; // Calculating f(epsilon(i)) values.

		double LHF = functionFxi * deltaX; // Define LHF to f(x(i)) * deltaX => LHF (Left Hand Rule).
		double RHF = functionFxi1 * deltaX; // Define RHF to f(x(i+1)) * deltaX => RHF (Right Hand Rule).
		double MF = functionFepsiloni * deltaX; // Define MF to f(epsilon(i)) * deltaX => (MF Midpoint Rule).

		sumLHF += LHF; //Adding all LHF values to sumLHF. 
		sumRHF += RHF; //Adding all RHF values to sumRHF.
		sumMF += MF; //Adding all MF values to sumMF.

		cout << setw(6) << i << setw(10) << xi << setw(12) << epsiloni // Print the values of table's elements.
			<< setw(14) << LHF << setw(10) << RHF << setw(12) << MF << endl;
	}

	cout << "--------------------------------------" << endl; // Print a line.
	cout << "--------- INTEGRAL RESULTS -----------" << endl; // Print a header with lines.
	cout << "f(x)=x^3 + 4x from [" << a << "," << b << "] with " << n << " intervals" << endl; // Print function f(x) from [a,b] interval with n intervals.
	cout << "--------------------------------------" << endl; // Print a line.
	cout << "MIDPOINT RULE		: " << sumMF << endl; // Print total Midpoint sum.
	cout << "LEFT HAND RULE		: " << sumLHF << endl;// Print total Left Riemann Sum.
	cout << "RIGHT HAND RULE		: " << sumRHF << endl; // Print total Right Riemann Sum.
	cout << "--------------------------------------" << endl; // Print a line.

	return 0;
}
