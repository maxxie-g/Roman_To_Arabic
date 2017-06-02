#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// string input: The input (either path or actual value)
// bool option:  The option for how the algorithm should behave
//				 true:  It will read from the file given
//				 false: It will just convert from what the user types

void convertRoman(string input, bool option) {
	// ifstream roman_numerals:	   The input file stream
	// string current_line:        Quasi-buffer for pushing lines into line
	// vector<string> line:		   Vector for all of the lines in the file
	// vector<int> converted_nums: Vector for storing all of the converted numbers
	//							   (not yet ready to be output)
	// vector<int> _outputVector:  Vector for outputting converted numbers
	// int _output:				   Total value of _outputVector
	// int counter:				   A counter for iterating through converted_nums

	ifstream roman_numerals;
	string current_line;
	vector<string> line;
	vector<int> converted_nums, _outputVector;
	int _output, counter;

	roman_numerals.open(input);

	if (option) {
		if (roman_numerals.is_open()) {
			// Checks to see if the file is open/found.
			// If it is not, the error message "Unable to open file" is displayed
			while (getline(roman_numerals, current_line)) {
				// Inputs all of the lines into a vector of strings
				line.push_back(current_line);
			}
		}
		else cout << "Unable to open file";
		roman_numerals.close();
	}
	else line.push_back(input);

	for (string readLine : line) {
		// for every string in the file
		// These next three line clear all counters and vectors.
		_output = 0;
		converted_nums.clear();

		for (char c : readLine) {
			// for every character in the length of line			
			switch (c) {
			case 'I':
				converted_nums.push_back(1);
				break;
			case 'V':
				converted_nums.push_back(5);
				break;
			case 'X':
				converted_nums.push_back(10);
				break;
			case 'L':
				converted_nums.push_back(50);
				break;
			case 'C':
				converted_nums.push_back(100);
				break;
			case 'D':
				converted_nums.push_back(500);
				break;
			case 'M':
				converted_nums.push_back(1000);
				break;
			}
		}

		for (counter = 0; counter < (int)converted_nums.size() - 1; counter++) {
			// Tests to see if an element is less than the next element
			// If element b is less than element b+1, it multiplies element b by -1
			if (converted_nums[counter] < converted_nums[counter + 1]) {
				converted_nums[counter] = -1 * converted_nums[counter];
			}
		}

		for (counter = 0; counter < (int)converted_nums.size(); counter++) {
			// This sums the converted_nums vector into a variable and then pushes
			// that _output variable to an _outputVector
			_output = _output + converted_nums[counter];
		}
		_outputVector.push_back(_output);
	}

	for (counter = 0; counter < (int)_outputVector.size(); counter++) {
		// This outputs the converted roman numerals to into a readable format
		cout << counter + 1 << ". " << _outputVector[counter] << '\n';
	}
	cin.get();
}