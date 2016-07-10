
/*************************************************************************************************
 ** Program Filename:	main.cpp
 ** Authors:			Group 24 - Connor Pacala, Kelsey Bartlett, Stephanie Holcomb
 ** Date:				July 10, 2016
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
#include <climits>

//prototypes
int enumeration(std::vector<int> &);
int betterEnumeration(std::vector<int> &);
int divideAndConquerHelper(std::vector<int> &, int *, int *);
int divideAndConquer(std::vector<int> &);
int linear(std::vector<int> &);
void fileOut(std::string, std::vector<int> &, int, int, int);


/*************************************************************************************************
 ** Function:			main
 ** Description:		Contains main program flow and menus			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int main(int argc, char * argv[])
{

		
	std::string line;
	int currNum;
	std::vector<int> vNums;
	std::ifstream inFile;   
	std::ofstream outFile;
		
	inFile.open("MSS_Problems.txt");

	while(std::getline(inFile, line)) {
		std::stringstream inStream(line);
		inStream.ignore();
		while(inStream >> currNum) {
			vNums.push_back(currNum);
			//ignore brackets and commas
			//if (inStream.peek() == '['){ 
				//inStream.ignore();
			 //}
			 if(inStream.peek() == ',') {
				inStream.ignore();
			 }
			 else if(inStream.peek() == ']') {
				break;
			 }
		
		}
								
		// display the original array to console
			std::cout << std::endl << "***** Original Array ***** " << std::endl;
			std::cout << "[";
			for(int i = 0; i < vNums.size(); i++){
				if(i == vNums.size()-1)
					std::cout << vNums[i];
				else
					std::cout << vNums[i] << ", ";
			}
			std::cout << "]" << std::endl << std::endl;
			fileOut("\n*** Original Array ***", vNums, 0, vNums.size()-1,NULL);
			enumeration(vNums);
			betterEnumeration(vNums);
			divideAndConquer(vNums);
			linear(vNums);
				
		// clear the vector before next loop
		vNums.clear();
		
 }  // end getline
	
				
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

	std::cout << "Enumeration:" << std::endl;

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
			
		
		fileOut("Enumeration:", vNums,left, right, maxSum);
		
		std::cout << "[";
		for (int i = left; i <= right; i++) {
		
			std::cout << vNums[i];
			if(i<right) {
			 std::cout<<", ";
			}
			
		}
		std::cout << "]"<<std::endl;
		std::cout << maxSum << std::endl;
	   return 0;
  
	}

/*************************************************************************************************
 ** Function:			Maximum Sum Subarray - Better Enumeration Method
 ** Description:		
 ** Parameters:			None
 ** Pre-Conditions:		(assumes a .txt file exists and it is comma delimited)
 ** Post-Conditions:	None
 ***************************************************************************************************/

int betterEnumeration(std::vector<int>& vNums) {

	
	int left, right, sum, maxSum;
	sum = 0;
	maxSum = 0;
	std::cout << "Better Enumeration:" << std::endl;
	
	
	
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
				
			}
		
	}
		
       fileOut("Better Enumeration:", vNums,left, right, maxSum);
		
		std::cout << "[";
		for (int i = left; i <= right; i++) {
		
			std::cout << vNums[i];
			if(i<right) {
			 std::cout<<", ";
			}
			
		}
		std::cout << "]"<<std::endl;
		
		std::cout << maxSum << std::endl;
	   return 0;
  
	}

/*************************************************************************************************
 ** Function:			Maximum Sum Subarray - Divide and Conquer Method
 ** Description:		
 ** Parameters:			None
 ** Pre-Conditions:		(assumes a .txt file exists and it is comma delimited)
 ** Post-Conditions:	None
 ***************************************************************************************************/


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

	//calculate sum for subarray that crosses the midpoint
	int sum = 0;
	int lmid = INT_MIN;
	int rmid = INT_MIN;
	int lbound = mid;
	int rbound = mid + 1;

	//sum each value starting at midpoint
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

	//check if sum across midpoint greater than sum in each half
	if(midsum > lsum && midsum > rsum)
	{
		*left = lbound;
		*right = rbound;
		return midsum;
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
	
	 fileOut("Divide and Conquer:", vNum,left, right, sum);
	
	std::cout << "Divide And Conquer"<<std::endl;;
	std::cout << "[";
	for (int i = left; i <= right; ++i) {
		std::cout << vNum.at(i);
		if( i <right) {
			 std::cout<<", ";
			}
       }
	std::cout << "]" << std::endl;
		
	std::cout << sum << std::endl;
	
	return 0;
}

/*************************************************************************************************
 ** Function:			Maximum Sum Subarray - Linear Method
 ** Description:		
 ** Parameters:			None
 ** Pre-Conditions:		(assumes a .txt file exists and it is comma delimited)
 ** Post-Conditions:	None
 ***************************************************************************************************/

int linear(std::vector<int>& vNums) {
	
	
	int sum, maxSum, left, right, minIdx, maxIdx;
	sum = maxSum = 0; 
	minIdx = maxIdx = 0;
    left = right = 0;
	std::cout << "Linear" << std::endl;
	
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
	
    fileOut("Linear:", vNums, minIdx, maxIdx, maxSum);
		
	std::cout << "[";
	for (int i = minIdx; i <= maxIdx; i++) {
		
		std::cout << vNums[i];
		if(i<maxIdx) {
		 std::cout<<", ";
		}
			
	}
	std::cout << "]"<<std::endl;
	std::cout << maxSum << std::endl;
	return 0;



}


/*************************************************************************************************
 ** Function:			Maximum Sum Subarray - Export to .txt file
 ** Description:		exports original array and, the subarray and maxSum results for all 4 algorithms.
 ** Parameters:			None
 ** Pre-Conditions:		
 ** Post-Conditions:	None
 ***************************************************************************************************/

void fileOut(std::string alg, std::vector<int>& vNums, int left, int right, int maxSum) {
		
		std::ofstream outFile; 
		
		//appends results to this file if it already exists. Did not want to risk erasing or clearing anyone else's data.µ
		outFile.open("MSS_Results.txt", std::ofstream::app);
		
	
		//export subarray
        outFile << alg << std::endl;
		outFile << "[";
		for (int i = left; i <= right; i++) {
		
			outFile << vNums[i];
			if(i<right) {
			 outFile <<", ";
			}
		 }
		outFile << "]"<<std::endl;
		if(alg == "\n*** Original Array ***") {
		outFile << std::endl;
		}  // extra line after the original array prints

	
		//export maxSum
		if (maxSum != NULL) {
		outFile << maxSum << std::endl;
		}
		
		outFile.close();			

}

