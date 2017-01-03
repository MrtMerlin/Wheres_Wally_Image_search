/*
Author:			Martin Lewis
Student ID:		014096
Module:			CMP2090M Object Orientated Programming
Assignment no:	1

Description:	This is a program to use the nearest neighbour search to compare a small image, part of a larger image,
to the larger image itself. Reading in a .txt file into the program for both images, from this file reading
it into a matrix, for both images. Once the image is found it will then save the details of where the image
is to another file for inspection.
*/

#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Matrix.h"
#include "MatchImage.h"
#include "LargeImage.h"

using namespace std;

int main()
{
	HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(text, FOREGROUND_GREEN);
	
	int userInput = 0;

	cout << "***************************************************************************" << endl;
	cout << "***************************** WHERES WALLY ********************************" << endl;
	cout << "************************** Author: Martin Lewis ***************************" << endl;
	cout << "************************ Student Number: 014096 ***************************" << endl;
	cout << "***************************************************************************" << endl;

	while (userInput != 4)
	{
		cout << "What you like to do, please select one of the following options" << endl;
		cout << "1.\tFind Wally using Sum of Squared Differences (ssd)" << endl;
		cout << "2.\tFind Wally using Nearest Neighbour Search (NNS)" << endl;
		cout << "3.\tFind Wally using both SSD and NNS" << endl;
		cout << "4.\tExit Program" << endl;

		cin >> userInput;

		SetConsoleTextAttribute(text, FOREGROUND_RED);

		MatchImage<double>wally("..\\..\\tempest\\Wally_grey.txt", 49, 36);
		LargeImage<double>clutteredScene("..\\..\\tempest\\Cluttered_scene.txt", 768, 1024);

		if (userInput == 1)
		{
			wally.sumDiff(clutteredScene);
			clutteredScene.fillMatrix(wally.bMatchRow, wally.bMatchCol);
			clutteredScene.saveImage("Test.pgm", 255);
		}

		if (userInput == 2)
		{
			wally.calculate_normalised_correlation(clutteredScene);
		}
		
		if (userInput == 3)
		{
		
		}

		if (userInput == 4)
		{
			exit(0);
		}
	}
	

	/***************************************************************************/
	/*********************************TESTING AREA/*****************************/
	/***************************************************************************/	
	/*cout << wally.average(0, 0, 49, 36) << endl;
	cout << wally.sum(0, 0, 49, 36) - wally.average(0,0,49,36) << endl;*/
	///*cout << clutteredScene.average(0, 0, 49, 36) << endl;
	//clutteredScene.square(0, 0, 49, 36);*/
	//
	////cout << clutteredScene.average(0, 0, 49, 36)  << endl;
	//cout << wally.average(0, 0, 49, 36) << endl;
	//cout << wally.sum(0, 0, 49, 36) << endl;
	////wally.square(0, 0, 49, 36);
	//

	/*cout << "This is the sum:-" << endl;
	cout << wally.sum(0, 0, 20, 20) << endl;
	cout << "this is the average" << endl;
	cout << wally.average(0, 0, 20, 20) << endl;
	wally.printSubMatrix(0, 0, 49, 36);
*/
	/*cout << wally.square() << endl;*/

	//LargeImage<double>clutteredScene("C:\\tempest\\Cluttered_scene.txt", 768, 1024);
	
	//Matrix<double> m1(3, 3);

	//for (int row = 0; row < 3; ++row)   // Print the table
	//{
	//	for (int col = 0; col < 3; ++col)
	//		m1.setItem(row, col, (row + 1) * (col + 1));
	//}

	////// Print the entire matrix
	//cout << m1.average(0, 0, 3, 3) << endl;
	//cout << m1.sum(0, 0, 3, 3) << endl;

	// Output should look like this

	/*
	1       2       3       4       5       6       7       8       9
	2       4       6       8       10      12      14      16      18
	3       6       9       12      15      18      21      24      27
	4       8       12      16      20      24      28      32      36
	5       10      15      20      25      30      35      40      45
	6       12      18      24      30      36      42      48      54
	7       14      21      28      35      42      49      56      63
	8       16      24      32      40      48      56      64      72
	9       18      27      36      45      54      63      72      81
	*/


	// calling the print submatrix method with the parameters
	// printSubMatrix(int row, int col, int height, int width)
	// Uncomment this when you have creates the printSubMatrix method.

	  /*m1.printSubMatrix(0, 0, 2, 2);*/

	// Output should look like this

	/*
	16      20      24      28
	20      25      30      35
	24      30      36      42
	28      35      42      49
	32      40      48      56
	*/

	//cout << "Creating four matrices" << endl;
	////Matrix<int> m1(9, 9);
	//Matrix<int> m2(2, 2);
	//Matrix<int> m3(2, 2);
	//Matrix<int> m4(2, 2);

	//for (int row = 0; row < 9; ++row)
	//{
	//	for (int col = 0; col < 9; ++col)
	//		m1.setItem(row, col, (row + 1) * (col + 1));
	//}

	//cout << "m1 contents" << endl;
	//m1.printMatrix();

	//cout << "Average " << m1.average(0, 0, 9, 9) << endl;
	//cout << "Sum     " << m1.sum(0, 0, 9, 9) << endl << endl;

	//cout << "m1 contents (3, 3, 4, 5)" << endl;
	// m1.printSubMatrix(3, 3, 4, 5);

	 /*cout << "Sum     " << m1.sum(0, 0, 5, 5) << endl << endl;
     cout << "Average " << m1.average(0, 0, 4, 4) << endl;*/
	

	//cout << "m1 contents (2, 2, 3, 3)" << endl;
	//m1.printSubMatrix(2, 2, 3, 3);

	/*cout << "Average " << m1.average(0, 0, 2, 2) << endl;
	cout << "Sum     " << m1.sum(0, 0, 2, 2) << endl << endl;*/

	//cout << "m2 contents" << endl;
	//m2.fillMatrix(3);
	//m2.printMatrix();

	//cout << "m3 contents" << endl;
	//m3.fillMatrix(1);
	//m3.printMatrix();

	//cout << "m4 = m2 - m3" << endl;
	//m4 = m2 - m3;

	//m4.printMatrix();

	//cout << "m1.square()" << endl;
	/*m1 = m1.square();

	m1.printMatrix();*/

	//cout << "m4 = m3" << endl;
	//m4 = m3;

	//m4.printMatrix();

	system("pause");

	return 0;
}
