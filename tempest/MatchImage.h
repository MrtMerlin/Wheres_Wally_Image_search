#pragma once
#include "Matrix.h"
#include "LargeImage.h"
#include <iostream>

using namespace std;

template<class T>
class MatchImage :public Matrix<T> {

	private:
		double normalised_correlation;
		int bMatchRow,
			bMatchCol,
			matrix_item_count;

		Matrix<T>tMat;

	protected:
		T sum	  = 0;
		T mean	  =	0;
		T sqr	  =	0;
		T tMatrix;
		T bMatch;
		T Total;
		T dif;
		T sDiff;

	public:
		//constructors
		MatchImage(const char *fileName, int rows, int cols);
		MatchImage();
		T sumDiff(Matrix<T>&search_matrix, int sRow, int sCol);
		//T WritePGM(char *filename, double *bestmatch, int row, int col, int Q);

			//Deconstructors
		~MatchImage();

	//void calculate_normalised_correlation(Matrix<T>&search_matrix, int sRow, int sCol);
		
};

template<class T>
MatchImage<T>::MatchImage(const char *fileName, int rows, int cols):Matrix<T>(fileName, rows, cols), tMat(rows,cols)
{
	this->bMatchRow = 0;
	this->bMatchCol = 0;
	this->matrix_item_count = rows * cols;


	
	sum = Matrix<T>::sum(0, 0, 49, 36);
	cout << "Total:  " << sum << endl;

	//find the mean of all the items in this image do it here as you only need to do it once.
	mean = Matrix<T>::average(0, 0, 49, 36);
	cout << "Average:  " << mean << endl;
	
	//subtract the mean from all the items in this image this will mean creating a new block of memory or altering your existing data
	

	//squaring the matrix given.
	sqr = Matrix<T>::square(0, 0, 49, 36);
	cout << "Squared:  " << sqr << endl;
	

	//create a block of memory to hold part of the larger picture or a matrix with the same size as wally*/
	//for (int row = 0; row < this->numRows; ++row)
	//{
	//	for (int col = 0; col < this->numCols; ++col)
	//	{
	//		tMat.setItem(row, col, double);
	//	}
	//}



	//for (int row = 0; row < this->getNumRows; ++row)
	//{
	//	for (int col = 0; col < this->getNumCols; ++col)
	//		std::cout << temp_Matrix[row][col] << "\t";
	//	std::cout << "\n";
	//}
}

template <class T>
MatchImage<T>::MatchImage()
{

}

template <class T>
MatchImage<T>:: ~MatchImage()
{

}

template <class T>
T MatchImage<T>::sumDiff(Matrix<T>&sMat, int sRow, int sCol)
{
	Total = 0;
	dif = 0;
	sDiff = 0;
	bMatch = 0;
	int outerRow = 0;
	int outerCol = 0;
	int row = 0;
	int col = 0;	


	for (outerRow = 0; outerRow < sMat.getNumRows() - this->getNumRows(); outerRow++)
	{
		for (outerCol = 0; outerCol < sMat.getNumCols() - this->getNumCols(); outerCol++)
		{
			for (row = 0; row < this->getNumRows(); row++)
			{
				for (col = 0; col < this->getNumCols(); col++)
				{
					dif = this->getItem(row, col) - sMat.getItem(sRow + row, sCol + col); // calculation for difference
					// this->getItem gets wally image minus searchMatrix which is the cluttered image.
					sDiff += dif * dif; // gets the squared value by multiplying diff by diff.
					Total = Total + sDiff;
					
					if (bMatch == 0)
						bMatch = Total;
					else if (bMatch > Total)
					{
						bMatch = Total;
					}
					
				}
			}
		}	
	}
	return sqr;
}

//template<class T>
//T MatchImage<T>::WritePGM(char *filename, double *bMatch, int row, int col, int Q)////////write file write file write file write file write file write file write file write file
//{
//
//
//	int i; //j;
//	unsigned char *image;
//	ofstream myfile;
//
//
//	image = (unsigned char *) new unsigned char[sizeR*sizeC];
//
//
//	// convert the integer values to unsigned char
//
//
//	for (i = 0; i<sizeR*sizeC; i++)
//		image[i] = (unsigned char)bestmatch[i];
//
//
//	myfile.open("..\\..\\WheresWally.pgm", ios::out | ios::binary | ios::trunc);
//
//
//	if (!myfile) {
//		cout << "Can't open file: " << filename << endl;
//		exit(1);
//	}
//
//
//	myfile << "P5" << endl;
//	myfile << sizeC << " " << sizeR << endl;
//	myfile << Q << endl;
//
//
//	myfile.write(reinterpret_cast<char *>(image), (sizeR*sizeC) * sizeof(unsigned char));
//
//
//	if (myfile.fail()) {
//		cout << "Can't write image " << filename << endl;
//		exit(0);
//	}
//
//
//	myfile.close();
//
//
//	delete[] image;
//
//
//}
//template <class T>
//T MatchImage<T>::calculate_normalised_correlation(Matrix<T>&search_matrix, int sRow, int sCol)
//{	
//		for (int row = 0; row < this->getNumRows(); row++)
//		{
//			for (int col = 0; col < this->getNumCols(); col++)
//			{
//				
//			}
//		}
//		cout << "Total     " << Total << endl;
//		return;
//}