#include <iostream>
#include <fstream>
#include "myTemps.h"
#include <string>
#include <sstream>

using namespace std;

int main()
{
	myTemperatures myTemps; //creating an object from myTemperatures class
	ifstream TempFile; //input file stream

	string degree; //string to store the stars
	int temperature; //temp variable declared
	int maxVal = 120; //max temp allowed
	int minVal = -30; //min temp allowed



	TempFile.open("TempFile.dat"); // Open the file


	if (!TempFile.is_open())
		{
		cout << "File did not open!" << endl; //if my file failed to open, outputs...
		}

	cout << endl;
	cout << endl;
	cout << "This is a bar chart that shows the hourly temperatures!" << endl; //Heading
	cout << endl; 
	string line; //created a string to store lines from the file



	while (getline(TempFile, line)) //read each line from the file
		{
		stringstream tempStream(line); //stringstream created 

		while (tempStream >> temperature) //reading the temperatures from the input file
			{

			degree = ""; // Clear the degree string for each temperature

				if (temperature >= minVal && temperature < 0) //checks if temp is between -30 and -1
					{
					int stars = 10 - ((temperature + 30) / 3); //number of stars = 10 for -30 and decreases by 3 for each temperature

						for (int i = 0; i < stars; i++) //loop for accumulating stars
							{
							degree += "*"; //adding a star to the degree string
							}
					}

				else if (temperature >= 0 && temperature <= maxVal) //checks if temp is between 0 and 120
					{
					int stars = temperature / 3; // 1 star for every 3 degrees

						for (int i = 0; i < stars; i++) //loop for accumulating stars
							{
							degree += "*"; //adding a star to the degree string
							}

					}
				cout << "Temperature: " << temperature << " degrees " << degree << endl << endl; //outputs the temperature and the degrees to the right, puts a line of space after each bar
			}
		}

	cout << endl; //putting a space between the bar chart and the scale

	cout << "--> temperature ranges from -30 degrees to 120 degrees <--" << endl;
	cout << "--> each star represents 3 degrees <--" << endl;

	TempFile.close(); // Close the file

	return 0;
}