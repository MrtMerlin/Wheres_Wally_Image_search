#pragma once
#include "Matrix.h"
#include <iostream>

using namespace std;

template<class T>
class LargeImage :public Matrix<T>
{
	private:
		T normalised_correlation;
		T bestMatchRow,
			bestMatchCol,
			matrix_item_count;

	protected:

		T mean = 0;

	public:
		LargeImage(const char *fileName, int rows, int cols);
		LargeImage();
		~LargeImage();
};

template<class T>
LargeImage<T>::LargeImage(const char *fileName, int rows, int cols):Matrix<T>(fileName, rows, cols)
{
	this->bestMatchRow = 0;
	this->bestMatchCol = 0;
	this->matrix_item_count = rows * cols;
}

template<class T>
LargeImage<T>::LargeImage()
{
}

template<class T>
LargeImage<T>::~LargeImage()
{
}
