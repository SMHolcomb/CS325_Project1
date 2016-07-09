
/*************************************************************************************************
 ** Program Filename:	main.cpp
 ** Author:				Group 24
 ** Date:				July 4, 2016
 ** Description:		main implementation file for CS324 Project 1 
 ** Input:				input .txt file
 ** Output:				output .txt file
 ***************************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctype.h>
#include <vector>
#include <stdlib.h>
#include <math.h>

//prototypes
int enumeration(std::vector<int> &);
int betterEnumeration(std::vector<int> &);
int divideAndConquer(std::vector<int> &, int, int);
int linear(std::vector<int> &);
void testRunTime();
void testManual();

/*************************************************************************************************
 ** Function:			main
 ** Description:		Contains main program flow and menus			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int main(int argc, char * argv[])
{

	
	
		
	
	testRunTime(); // generates 10 * n(10) * 4 random # arrays for logging run times
	//testManual(); // for manually entered vectors to test specific sizes or elements

      return 0;

}


/*************************************************************************************************
 ** Function:			Maximum Sum Subarray - Enumeration Method
 ** Description:		
/*************************************************************************************************/
 
int enumeration(std::vector<int>& vNums) {

	clock_t start, end;
	
	
	int left, right, sum, maxSum;
	sum = 0;
	maxSum = 0;
    
		 start = clock();
		
		 left = right = 0;
		 
		 for (int i = 0; i < vNums.size(); ++i) {
		 
				for(int j = i; j < vNums.size(); j++) {
					
					sum = 0;
					for (int k = i; k<=j; k++) {
			
					sum = sum + vNums[k];
			
					}
					if (sum > maxSum) {
					
						maxSum = sum;
						left = i;
						right = j;						
				  }
				}
			}
			
		end = clock();
		std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << ",";

	   return 0;
  
	}

/************************************************
		betterEnumeration
*************************************************/

int betterEnumeration(std::vector<int>& vNums) {

	clock_t start, end;
	int left, right, sum, maxSum;
	sum = 0;
	maxSum = 0;
	
	start = clock();
	
	 left = right = 0;
	  sum = vNums[0];
	 
	 for (int i = 0; i < vNums.size(); ++i) {
			sum=0;
			for(int j = i; j < vNums.size(); j++) {
				sum = sum + vNums[j];
			
	
					if (sum > maxSum) {
						maxSum = sum;
						left = i;
						right = j;

					}
				
			}
		
	}
		
       end = clock();
	   std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << ",";

	   return 0;
  
	}


/************************************************
		Divide and Conquer
*************************************************/

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

	
	int lsum = divideAndConquerHelper(vNum, &startL, &endL);
	int rsum = divideAndConquerHelper(vNum, &startR, &endR);

	
	int sum = 0;
	int lmid = INT_MIN;
	int rmid = INT_MIN;
	int lbound = mid;
	int rbound = mid + 1;

	
	for(int i = mid; i >= startL; --i)
	{
		sum += vNum.at(i);
		if(sum > lmid)
		{
			lbound = i;
			lmid = sum;
		}
	}
	sum = 0;
	for(int i = mid + 1; i <= endR; ++i)
	{
		sum += vNum.at(i);
		if(sum > rmid)
		{
			rbound = i;
			rmid = sum;
		}
	}
	
	int midsum = lmid + rmid;

	
	if(midsum > lsum && midsum > rsum)
	{
		*left = lbound;
		*right = rbound;
		return midsum;
	}

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
	clock_t start, end;
	
    start = clock();
	int sum = divideAndConquerHelper(vNum, &left, &right);
	
		end = clock();
		std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << ", ";

	return 0;
}


/************************************************
		Linear Time
*************************************************/

int linear(std::vector<int>& vNums) {
	
	clock_t start, end;
	int sum, maxSum, left, right, minIdx, maxIdx;
	sum = maxSum = 0; 
	minIdx = maxIdx = 0;
    left = right = 0;
	
	start = clock();
	for(int i = 0; i < vNums.size(); i++) {
		
		right = i;
		sum = sum + vNums[i];
	
		   if (sum < 0)    
			{				
				sum = 0;
				left = i+1;
			}

			if (sum > maxSum) {
				maxSum = sum;
				maxIdx = i;
				minIdx = left;
			}
	}
	
	end = clock();
	std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000);
	

	return 0;

}

/************************************************
		testRunTime
 Generates 10 random vectors of 10 different n values
  for each of 4 algorithms
  
*************************************************/


void testRunTime() {

	std::vector <int> vNums;
	int rNum;
	
	// Generate random numbers for testing
	
	std::vector <int> inputSize = {100,200,400, 600, 800, 1000, 2000, 5000, 7000, 10000};
	//std::vector <int> inputSize = {100,200,400, 600, 800, 1000, 2000, 3000, 4000, 5000};
	//std::vector <int> inputSize = {20,30,40, 50, 60, 70, 80, 100, 100, 300};
		
	srand((unsigned)time(NULL));
	
	for (int n = 0; n < inputSize.size(); n++) {  
	for (int x = 0; x < 10; x++) {
			vNums = {};
			for (int m = 0; m<inputSize[n]; m++) {
				rNum = rand()%199+ (-100);  //include negative numbers as well
				vNums.push_back(rNum);
			
				}
			
			std::cout << "\nn = " << inputSize[n]<< ",";
			
			enumeration(vNums);
			betterEnumeration(vNums);
			divideAndConquer(vNums); 
			linear(vNums);
		} // end x
			
	} // end n outer loop
}


/************************************************
		testManual
 for testing specific vector sizes/elements
  
*************************************************/

void testManual() {

//std::vector <int> vNums {1, 4, -9, 8, 1, 3, 3, 1, -1, -4, -6, 2, 8, 19, -10, -11};
	//std::vector <int> vNums {2, 9, 8, 6, 5, -11, 9, -11, 7, 5, -1, -8, -3, 7, -2};
	//std::vector <int> vNums {10, -11, -1, -9, 33, -45, 23, 24, -1, -7, -8, 19};
	//std::vector <int> vNums {31,-41, 59, 26, -53, 58, 97, -93, -23, 84};
	//std::vector <int> vNums {3, 2, 1, 1, -8, 1, 1, 2, 3};
	//std::vector <int> vNums {12, 99, 99, -99, -27, 0, 0, 0, -3, 10};
	//std::vector <int> vNums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	//std::vector <int> vNums {-97, 35, 21, -35, 18, -99, 56, 74, 21, 20};
	std::vector <int> vNums {29, -72, -6, -22, -7, -51, -21, -75, -38, -13};
	
	enumeration(vNums);
	betterEnumeration(vNums);
	divideAndConquer(vNums);µ
	linear(vNums);
	
}
