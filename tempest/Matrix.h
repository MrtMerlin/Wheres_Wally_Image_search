#pragma once // prevents multiple inclusion of following code.
#include <sstream> // stringstream
#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <istream>

using namespace std;

template <class T>

class Matrix {
private:
	int numRows,
		numCols;
	T	mSum;

	T *ptrMatrix;

public: // public 

		// Contructors Destructors

	Matrix();
	Matrix(int row, int col);
	Matrix(const char *fileName, int row, int col);
	

	~Matrix();

	Matrix(const Matrix<T>&sMat);
	

	//overloading 
	Matrix<T>&operator=(const Matrix<T>&sMat);
	Matrix<T>operator-(const Matrix<T>&sMat);
	T average(int row, int col, int height, int width);
	T sum(int row, int col, int height, int width);
	T square (int row, int col, int height, int width);
	
	// Getters 

	int getNumRows();
	int getNumCols();

	T getItem(int row, int col);

	// Setters

	void setItem(int row, int col, T value);
	// signiture for fillMatrix
	void fillMatrix(int bestMatchRow, int bestMatchCol);


	// Display
	// // signiture for printMatrix
	void printMatrix();
	void printSubMatrix(int row, int col, int height, int width);
};


using namespace std;

template <class T>
Matrix<T>::Matrix()
{
	this->numRows = 5;
	this->numCols = 5;

	this->ptrMatrix = new (nothrow) T[this->numRows * this->numCols]{};

	if (this->ptrMatrix == nullptr)
		throw std::bad_alloc();  // Throw an exception at the point of failure
								 //cout << "Matrix()" << endl; // cout to display the constructor is being called.
}

template <class T>
Matrix<T>::Matrix(int rows, int cols)
{
	this->numRows = rows;
	this->numCols = cols;
	this->ptrMatrix = new (nothrow) T[this->numRows * this->numCols]{};

	if (this->ptrMatrix == nullptr)
		throw std::bad_alloc();  // Throw an exception at the point of failure
								 //cout << "Matrix(int)" << endl; // cout to display the constructor is being called.
}

/*
*	Copy constructor
*/
template <class T>
Matrix<T>::Matrix(const Matrix<T>& sMat)
{
	numRows = sMat.numRows;
	numCols = sMat.numCols;

	this->ptrMatrix = new (nothrow) T[this->numRows * this->numCols];

	if (this->ptrMatrix == nullptr)
		throw std::bad_alloc();  // Throw an exception at the point of failure
	else
	{
		// Copy source data to destination
		for (int i = 0; i < this->numRows * this->numCols; i++)
			this->ptrMatrix[i] = sMat.ptrMatrix[i];
	}
	cout << "Copy constructor finished" << endl;
}

/*
*	= assignment operator to deep copy the matrix data
*/
template <class T>
Matrix<T>&Matrix<T>::operator=(const Matrix<T>&sMat)
{
	// If we are assigning to ourself i.e. m1 = m1
	if (this == &sMat)
		return *this;  // Return a pointer to ourselves (why copy yourself to yourself)

	numRows = sMat.numRows;
	numCols = sMat.numCols;

	// Clear any already allocated memory
	if (this->ptrMatrix != nullptr) delete[] ptrMatrix;

	// Allocate the right amount of memory for the deep copy of the data
	this->ptrMatrix = new (nothrow) T[this->numRows * this->numCols];

	if (this->ptrMatrix == nullptr)
		throw std::bad_alloc();  // Throw an exception at the point of failure
	else
	{
		// Copy source data to destination
		for (int i = 0; i < this->numRows * this->numCols; i++)
			this->ptrMatrix[i] = sMat.ptrMatrix[i];
	}
	cout << "Assignment = finished" << endl;
	// Return a pointer to the copied matrix object
	return *this;
}

/*
*	 - subtraction operator
*/
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>&sMat)
{

	if (this->numRows != sMat.numRows || this->numCols != sMat.numCols)
		throw(std::runtime_error("Subtraction error matrix dimensions do not match!!"));

	// Allocate the right amount of memory for the new matrix of subtracted data
	Matrix<T> newMatrix(this->numRows, this->numCols);


	for (int row = 0; row < this->numRows; ++row)   // Print the table
	{
		for (int col = 0; col < this->numCols; ++col)
			newMatrix.ptrMatrix[row * this->numCols + col] = ptrMatrix[row * this->numCols + col] - sMat.ptrMatrix[row * this->numCols + col];
	}


	// Return a matrix object uses copy constructor to do this
	return newMatrix;
}

/*
*	Returns matrix sum
*/
template <class T>
T Matrix<T>::sum(int sRows, int sCols, int height, int width)
{
	T mSum = 0;

	// if statement this-> indicates variable ptrMatrix is part of this class. if ptrMatrix not = to nullptr step into if statement.
	if (this->ptrMatrix != nullptr)
	{
		// for statement, for each item within row 
		for (int row = sRows; row < sRows + height; ++row)
		{
			// for statement, for each item within column
			for (int col = sCols; col < sCols + width; ++col)		// for statement, for each item within row 
		
				//	adding contents of martrix together to get sum of all matrix
				mSum += this->getItem(row, col);
		}
	}
	else
		throw std::bad_alloc(); // error handling throw an exception at point of failure

	return mSum;
}

//(searchMatrix, startRow, startCol)
// {
// T Total = 0;
// T Diff = 0;
// for (int row = 0, row < this->numRow; row++)
	// for (int col = 0, col < this->numCol; col++)
			//{
				// diff line of code 
				// Diff = this->getItem(row, col) - source_matrix.getItem(startRow + row, startCol + row);
			//}
// }

/*
*	Returns the matrix average
*/
template <class T>
T Matrix<T>::average(int sRow, int sCol, int height, int width)
{
	//check if mSum == 0, if greater mSum == 0 do following
	if (mSum == 0) this->mSum = this->sum(sRow, sCol, width, height);
		T itemCount = width * height;

	return this->mSum / (T)itemCount;
}

/*
*	Square method squares each matrix element by its self returning a new matrix with the result.
*/
template <class T>
T Matrix<T>::square(int sRow, int sCol, int height, int width) {
	T sqr = 0;
	// if statement this-> indicates variable ptrMatrix is part of this class. if ptrMatrix not = to nullptr step into if statement.
	
	if (this->ptrMatrix != nullptr)
	{
		// for statement, for each item within row 
		for (int row = sRow; row < sRow + height; ++row)
		{
			// for statement, for each item within column
			for (int col = sCol; col < sCol + width; ++col)
				// prints out to screen, using the getItem method, using the ints row and col with a tabbed space between each item.
				sqr = this->getItem(row, col) * this->getItem(row, col);
			// create new line.
			
		}
	}
	else
		throw std::bad_alloc(); // error handling throw an exception at point of failure
	return sqr;
}

template <class T>
Matrix<T>::Matrix(const char *fileName, int row, int col)
{
	this->numRows = row;
	this->numCols = col;
	this->ptrMatrix = new (nothrow) T[this->numRows * this->numCols]{};

	if (this->ptrMatrix == nullptr)
	{
		throw std::bad_alloc();  // Throw an exception at the point of failure
	}
	else
	{
		int i = 0;

		ifstream readFile(fileName);

		if (readFile.is_open())
		{

			while (readFile.good())
			{
				if (i > row*col - 1) break;
				readFile >> ptrMatrix[i];
				i++;
			}
			readFile.close();
		}
		else {
			cout << "Unable to open file";
		}
	}
}

/*
*	Deallocate the memory for the matrix
*/
template <class T>
Matrix<T>::~Matrix()
{
	if (this->ptrMatrix != nullptr) delete[] ptrMatrix;
	//cout << "Matrix(deaalocation)" << endl; // cout to display the deconstructor is being called.
}


/*
*	Return the number of rows in the matrix
*/
template <class T>
int Matrix<T>::getNumRows()
{
	return this->numRows;
}

/*
*	Return the number of Cols in the matrix
*/
template <class T>
int Matrix<T>::getNumCols()
{
	return this->numCols;
}

/*
*	Get a single element from the matrix
*/
template <class T>
T Matrix<T>::getItem(int row, int col)
{
	if (this->ptrMatrix != nullptr)
		return ptrMatrix[row * this->numCols + col];
	else
		throw std::bad_alloc();
	//cout << "Matrix(double)" << endl; // cout to display the constructor is being called.
}

/*
*	Set a single element in the matrix
*/
template <class T>
void Matrix<T>::setItem(int row, int col, T value)
{
	if (this->ptrMatrix != nullptr)
		ptrMatrix[row * this->numCols + col] = value;
	else
		throw std::bad_alloc();
	//cout << "Matrix(void)" << endl; // cout to display the constructor is being called.
}


//	Fill the matrix with a single value
template <class T>
void Matrix<T>::fillMatrix(int bestMatchRow, int bestMatchCol) // matrix constructor with parameters being used within the method
{
	// if statement this-> indicates variable ptrMatrix is part of this class. if ptrMatrix not = to nullptr step into if statement.
	if (this->ptrMatrix != nullptr)
	{
		// for statement, for each item within row 
		for (int row = bestMatchRow; row < bestMatchRow + 49; ++row)
		{
			// for statement, for each item within column
			for (int col = bestMatchCol; col < bestMatchCol + 36; ++col)
			{
				// fill each space within ptrMatrix with value.
				this->setItem(row, col, 0);
			}
		}
	}
	else
		throw std::bad_alloc(); // error handling throw an exception at point of failure
}


/*
*	Prints the matrix to the screen
*/
template <class T>
void Matrix<T>::printMatrix()  // matrix constructor without any parameters. being called to printout matrix.
{
	// if statement this-> indicates variable ptrMatrix is part of this class. if ptrMatrix not = to nullptr step into if statement.
	if (this->ptrMatrix != nullptr)
	{
		// for statement, for each item within row 
		for (int row = 0; row < numRows; ++row)
		{
			// for statement, for each item within column
			for (int col = 0; col < numCols; ++col)
				// prints out to screen, using the getItem method, using the ints row and col with a tabbed space between each item.
				cout << this->getItem(row, col) << "\t";
			// create new line.
			cout << endl;
		}
	}
	else
		throw std::bad_alloc(); // error handling throw an exception at point of failure
}

template <class T>
void Matrix<T>::printSubMatrix(int sRow, int sCol, int height, int width)
{
	// if statement this-> indicates variable ptrMatrix is part of this class. if ptrMatrix not = to nullptr step into if statement.
	if (this->ptrMatrix != nullptr)
	{
		// for statement, for each item within row 
		for (int row = sRow; row < sRow + height; ++row)
		{
			// for statement, for each item within column
			for (int col = sCol; col < sCol + width; ++col)
				// prints out to screen, using the getItem method, using the ints row and col with a tabbed space between each item.
				cout << this->getItem(row, col)<< "\t";
			// create new line.
			cout << endl;
		}
	}
	else
		throw std::bad_alloc(); // error handling throw an exception at point of failure
}
