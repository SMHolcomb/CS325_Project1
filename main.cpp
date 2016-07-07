
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


/*************************************************************************************************
 ** Function:			main
 ** Description:		Contains main program flow and menus			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int main(int argc, const char * argv[])
{

	int rNum, result, result2, result3, result4;
	//std::vector <int> vNums {1, 4, -9, 8, 1, 3, 3, 1, -1, -4, -6, 2, 8, 19, -10, -11};
	//std::vector <int> vNums {2, 9, 8, 6, 5, -11, 9, -11, 7, 5, -1, -8, -3, 7, -2};
	//std::vector <int> vNums {10, -11, -1, -9, 33, -45, 23, 24, -1, -7, -8, 19};
	//std::vector <int> vNums {31,-41, 59, 26, -53, 58, 97, -93, -23, 84};
	//std::vector <int> vNums {3, 2, 1, 1, -8, 1, 1, 2, 3};
	//std::vector <int> vNums {12, 99, 99, -99, -27, 0, 0, 0, -3, 10};
	//std::vector <int> vNums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	//std::vector <int> vNums {-97, 35, 21, -35, 18, -99, 56, 74, 21, 20};
	std::vector <int> vNums {29, -72, -6, -22, -7, -51, -21, -75, -38, -13};
	
	/*
	// Generate random numbers for testing
	std::vector <int> vNums;
	srand((unsigned)time(NULL));
	
	for (int i = 0; i < 10; i++) {
		rNum = rand()%199+ (-100);
		vNums.push_back(rNum);
	
	}
	*/
	
		std::cout << "Original numbers: " << "[";
	for (int i = 0; i < vNums.size(); i++) {
				
				std::cout << vNums[i];
				
				if(i<vNums.size()-1) {
				
						std::cout<<", ";
					}
					
			}
			
	std::cout << "]" << std::endl;
	
	
	result = enumeration(vNums);
	result2 = betterEnumeration(vNums);
	//result3 = divideAndConquer(vNums, 0, vNums.size());  // not working yet
	result4 = linear(vNums);  // failing on certain arrays. Sum appears correct, but subarray not displaying correctly.
	
		
		
		
		/*  // READ IN FROM FILE - INCOMPLETE
	
		*/  // END READ IN FROM FILE
		
	
       	 
      return 0;

}


/*************************************************************************************************
 ** Function:			Maximum Sum Subarray - Enumeration Method
 ** Description:		
 ** Parameters:			None
 ** Pre-Conditions:		(assumes a .txt file exists and it is comma delimited)
 ** Post-Conditions:	None
 ***************************************************************************************************/

int enumeration(std::vector<int>& vNums) {

	
	int left, right, sum, maxSum;
	sum = 0;
	maxSum = 0;


		 left = right = 0;
		 sum = vNums[0];
		 
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
			
		std::cout << "\n***** Enumeration *****\n" << std::endl;
        std::cout << "SubArray with max sum: " << std::endl;
		
		std::cout << "[";
		for (int i = left; i <= right; i++) {
		
			std::cout << vNums[i];
			if(i<right-1) {
			 std::cout<<", ";
			}
			
		}
		std::cout << "]"<<std::endl;
		std::cout<< "MAX SUM: " << maxSum << std::endl;
	   return 0;
  
	}

/************************************************
		betterEnumeration
*************************************************/

int betterEnumeration(std::vector<int>& vNums) {

	
	int left, right, sum, maxSum;
	sum = 0;
	maxSum = 0;
	std::cout << "\n***** Better Enumeration *****\n" << std::endl;
	
	
	
		// enumerate through, saving sum for future use
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
				//std::cout << "current i: " << vNums[i] << "  current j: " << vNums[j] << "  sum: " << sum << "  maxSum: " << maxSum << std::endl;
			}
		
	}
		
        std::cout << "SubArray with max sum: " << std::endl;
		
		std::cout << "[";
		for (int i = left; i <= right; i++) {
		
			std::cout << vNums[i];
			if(i<right-1) {
			 std::cout<<", ";
			}
			
		}
		std::cout << "]"<<std::endl;
		std::cout<< "MAX SUM: " << maxSum << std::endl;
	   return 0;
  
	}

/************************************************
		Divide and Conquer
*************************************************/

//std::vector<int> divideAndConquer(std::vector<int>& vNums, int left, int right) {
int divideAndConquer(std::vector<int>& vNums, int left, int right) {



	return 0;


}



/************************************************
		Linear Time
*************************************************/

int linear(std::vector<int>& vNums) {
	
	std::cout << "\n*****  Linear *****\n" << std::endl;
	int sum, maxSum, left, right, minIdx, maxIdx;
	sum = maxSum = 0; 
	minIdx = maxIdx = 0;
    left = right = 0;
	
	for(int i = 0; i < vNums.size(); i++) {
		//left = i;
		right = i;
		// left and right are both 0 coming in
		sum = sum + vNums[i];  // add current value to running sum
		
		
		
		   if (sum < 0)    
			{
				//sum = vNums[i];
				sum = 0;
				left = i+1;
				//right = i+1;   
				
				
			}

			if (sum > maxSum) {
				maxSum = sum;
				maxIdx = i;
				minIdx = left;
			}
			
		  
		 //std::cout << "i= " << i << " current " << vNums[i] << "   Sum: " << sum << "  maxSum: " << maxSum << " minIdx: " << minIdx << "  maxIdx: " << maxIdx << std::endl;
	    
		  
	}
		//std::cout << "Min index: " << minIdx << "    Max index: " << maxIdx << std::endl;
		

    /* PRINTING RESULTS FOR TESTING */

	
	std::cout << "SubArray with max sum: " << std::endl;
		
	std::cout << "[";
	for (int i = minIdx; i <= maxIdx; i++) {
		
		std::cout << vNums[i];
		if(i<maxIdx) {
		 std::cout<<", ";
		}
			
	}
	std::cout << "]"<<std::endl;
	std::cout<< "MAX SUM: " << maxSum << std::endl;
	return 0;



}


