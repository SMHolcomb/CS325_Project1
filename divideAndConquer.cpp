#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctype.h>
#include <vector>
#include <stdlib.h>
#include <math.h>


int divideAndConquerHelper(std::vector<int> &vNum, int *left, int *right)
{
	int diff = *right - *left;

	if(diff == 0)	//single value
		return vNum.at(*left);
	
	int mid = *left + (diff) / 2;

	int startL = *left;
	int endL = mid;
	int startR = mid + 1;
	int endR = *right;	

	//find max subarray in each half of vector
	int lsum = divideAndConquerHelper(vNum, &startL, &endL);
	int rsum = divideAndConquerHelper(vNum, &startR, &endR);

	int total = lsum + rsum;

	//check right and left subarrays are next to one another in vNum
	if((total > lsum && lsum > rsum) || (total > rsum && rsum > lsum))
	{
		if(endL == startR - 1)
		{
			*left = startL;
			*right = endR;
			return total;
		}
	}

	//check if sum of left or right subarray is greater, return subarray with larger sum
	if(lsum > rsum)
	{
		*left = startL;
		*right = endL;
		return lsum;
	}
	else
	{
		*left = startR;
		*right = endR;
		return rsum;
	}
}

int divideAndConquer(std::vector<int> &vNum)
{
	int left = 0;
	int right = vNum.size() - 1;

	int sum = divideAndConquerHelper(vNum, &left, &right);
	
	std::cout << "Array: ";
	
	for (int i = left; i <= right; ++i)
		std::cout << vNum.at(i) << ' ';
		
	std::cout << std::endl << "Max sum: " << sum << std::endl;
	
	return 0;
}	

int main(int argc, char * argv[])
{
	static const int arr[] = {-100, 12, 8, 10, 34};
	std::vector <int> vNums(arr, arr + sizeof(arr) / sizeof(arr[0]));
	divideAndConquer(vNums);
}
