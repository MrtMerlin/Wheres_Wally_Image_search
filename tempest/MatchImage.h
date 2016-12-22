#pragma once
#include "Matrix.h"
#include "LargeImage.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath> // look up cmath for square root.

using namespace std;

template<class T>
class MatchImage :public Matrix<T> {

	private:
		double normalised_correlation;
		int bMatchRow,
			bMatchCol,
			matrix_item_count;

		Matrix<T>wally_Mean_Mat;
		Matrix<T>clutteredScene_Temp_Mat;


	protected:
		T sum	  = 0;
		T mean	  =	0;
		T sqr	  =	0;
		T tMatrix;
		T bMatch;
		T Total;
		T dif;
		T sDiff;
		T wally_Image_Mean;
		

	public:
		//constructors
		MatchImage(const char *fileName, int rows, int cols);
		MatchImage();

		//Deconstructors
		~MatchImage();

		void sumDiff(Matrix<T>&sMat);
		void MatchImage<T>::calculate_normalised_correlation(Matrix<T>&sMat);

};

template<class T>
MatchImage<T>::MatchImage(const char *fileName, int rows, int cols):Matrix<T>(fileName, rows, cols), wally_Mean_Mat(rows, cols), clutteredScene_Temp_Mat(rows, cols)
{
	this->bMatchRow = 0;
	this->bMatchCol = 0;
	this->matrix_item_count = rows * cols;

	//find the mean of all the items in this image do it here as you only need to do it once.


	wally_Image_Mean = average(0, 0, this->getNumRows(), this->getNumCols());
	//subtract the mean from all the items in this image this will mean creating a new block of memory or altering your existing data
	for (int row = 0; row < this->getNumRows(); row++)
	{
		for (int col = 0; col < this->getNumCols(); col++)
		{
			this->wally_Mean_Mat.setItem(row, col, (this->getItem(row, col) - wally_Image_Mean));
		}
	}
	//create a block of memory to hold part of the larger picture or a matrix with the same size as wally*/
	for (int row = 0; row < this->getNumRows(); ++row)
	{
		for (int col = 0; col < this->getNumCols(); ++col)
		{
			this->clutteredScene_Temp_Mat.setItem(row, col, this->getItem(row,col));
		}
	}
}

template <class T>
MatchImage<T>::MatchImage()
{

}

template <class T>
MatchImage<T>:: ~MatchImage()
{

}

//template <class T>
//void MatchImage<T>::calculate_normalised_correlation(Matrix<T>&sMat)
//{
//	for (int outerRow = 0; outerRow < sMat.getNumRows() - this->getNumRows(); outerRow++)
//	{
//		cout << ";)";
//		for (int outerCol = 0; outerCol < sMat.getNumCols() - this->getNumCols(); outerCol++)
//		{
//			Total = 0;
//			for (int row = 0; row < this->getNumRows(); row++)
//			{
//				
//			}
//		}
//	}
//}
template <class T>
void MatchImage<T>::sumDiff(Matrix<T>&sMat)
{
	bMatch = 1000000000;

	cout << "********************************************************************************" << endl;
	cout << "********************************************************************************" << endl;
	cout << "***************************The Sum of Square Differences************************" << endl;
	cout << "************************************Wheres Wally********************************" << endl;
	cout << "********************************************************************************" << endl;
	cout << "********************************************************************************" << endl;

	for (int outerRow = 0; outerRow < sMat.getNumRows() - this->getNumRows(); outerRow++)
	{
		cout << ";)";
		for (int outerCol = 0; outerCol < sMat.getNumCols() - this->getNumCols(); outerCol++)
		{
			Total = 0;
			for (int row = 0; row < this->getNumRows(); row++)
			{
				for (int col = 0; col < this->getNumCols(); col++)
				{
					dif = this->getItem(row, col) - sMat.getItem(outerRow + row, outerCol + col); // calculation for difference
					// this->getItem gets wally image minus searchMatrix which is the cluttered image.
					sDiff = dif * dif; // gets the squared value by multiplying diff by diff.
					Total = Total + sDiff;
				}
			}
			if (Total < bMatch)
			{
				bMatchRow = outerRow;
				bMatchCol = outerCol;
				bMatch = Total;
			}
		}	
	}
	cout << endl;
	cout << fixed << setprecision(0) << "Best Match: " << bMatch << endl;
	cout << "Best Row: " << bMatchRow << endl;
	cout << "Best Col: " << bMatchCol << endl;

	for (bMatchRow; bMatchRow < this->getNumRows(); bMatchRow++)
	{
		for (bMatchCol; bMatchCol < this->getNumCols(); bMatchCol++)
		{
			MatchImage::fillMatrix(255);
		}
	}
}

template <class T>
void MatchImage<T>::calculate_normalised_correlation(Matrix<T>&sMat)
{
	T clutteredScene_sum = 0;
	T test = 0;


	for (int outerRow = 0; outerRow < sMat.getNumRows() - this->getNumRows(); outerRow++)
	{
		cout << ";)";
		for (int outerCol = 0; outerCol < sMat.getNumCols() - this->getNumCols(); outerCol++)
		{
			for (int row = 0; row < this->getNumRows(); row++)
			{
				for (int col = 0; col < this->getNumCols(); col++)
				{
					clutteredScene_sum += this->getItem(row, col), sMat.getItem(outerRow + row, outerCol + col);
					T itemCount = row * col;
					test = clutteredScene_sum / (T)itemCount;
				}
			}
		}
	}
	cout << clutteredScene_sum << endl;
	cout << test << endl;

}


