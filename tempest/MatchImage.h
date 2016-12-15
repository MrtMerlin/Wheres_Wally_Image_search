#pragma once
#include "Matrix.h"
#include "LargeImage.h"
#include <iostream>
#include <iomanip>

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
		void sumDiff(Matrix<T>&search_matrix/*, int sRow, int sCol*/);
		void WritePGM(char *filename, double *bestmatch, int row, int col, int Q);

		//Deconstructors
		~MatchImage();

		void calculate_normalised_correlation(Matrix<T>&search_matrix); //, int sRow, int sCol);
		
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
MatchImage<T>::calculate_normalised_correlation(Matrix<T>&sMat)
{

}
template <class T>
void MatchImage<T>::sumDiff(Matrix<T>&sMat/*, int sRow, int sCol*/)
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

	
}

template<class T>
void MatchImage<T>::WritePGM(char *filename, double *bMatch, int row, int col, int Q)////////write file write file write file write file write file write file write file write file
{
	int i; //j;
	unsigned char *image;
	ofstream myfile;


	image = (unsigned char *) new unsigned char[bMatchRow * bMatchCol];


	// convert the integer values to unsigned char


	for (i = 0; i < bMatchRow * bMatchCol; i++)
		image[i] = (unsigned char)bMatch[i];


	myfile.open("C:\\WheresWally.pgm", ios::out | ios::binary | ios::trunc);


	if (!myfile) {
		cout << "Can't open file: " << filename << endl;
		exit(1);
	}


	myfile << "P5" << endl;
	myfile << bMatchCol << " " << bMatchRow << endl;
	myfile << Q << endl;


	myfile.write(reinterpret_cast<char *>(image), (bMatchRow*bMatchCol) * sizeof(unsigned char));


	if (myfile.fail()) {
		cout << "Can't write image " << filename << endl;
		exit(0);
	}


	myfile.close();


	delete[] image;


}
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