
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
int divideAndConquerHelper(std::vector<int> &, int *, int *);
int divideAndConquer(std::vector<int> &);
int linear(std::vector<int> &);
void fileOut(std::string, std::vector<int> &, int, int, int);
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

		
	
	//testRunTime(); // generates 10 * n(10) * 4 random # arrays for logging run times
	//testManual(); // for manually entered vectors to test specific sizes or elements
	std::string line;
	int currNum;
	std::vector<int> vNums;
	std::ifstream inFile;   
	std::ofstream outFile; //("MSS_Results.txt");
	
	inFile.open("MSS_TestProblems.txt");
	//inFile.open("MSS_Problems.txt");


	while(std::getline(inFile, line)) {
		std::stringstream inStream(line);
		inStream.ignore();
		while(inStream >> currNum) {
			vNums.push_back(currNum);
			//ignore brackets and commas
			//if (inStream.peek() == '['){  // shouldn't ignore this
				//inStream.ignore();
			 //}
			 if(inStream.peek() == ',') {
				inStream.ignore();
			 }
			 else if(inStream.peek() == ']') {
				break;
			 }
		
		} //end while inStream>currNum
								
		// display the starting array.
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
				
		// clear the vector before next loop..
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
		 //sum = vNums[0];
		 
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

/************************************************
		betterEnumeration
*************************************************/

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
		
	//std::cout << std::endl << "Max sum: " << sum << std::endl;
	std::cout << sum << std::endl;
	
	return 0;
}

/************************************************
		Linear Time
*************************************************/

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

/************************************************
		export to .txt file
 Generates 10 random vectors of 10 different n values
  for each of 4 algorithms
  
*************************************************/

void fileOut(std::string alg, std::vector<int>& vNums, int left, int right, int maxSum) {
		
		std::ofstream outFile; //("MSS_Results.txt");
		
		outFile.open("MSS_ResultsTESTING.txt", std::ofstream::app);
		//outFile.open("MSS_Results.txt", std::ofstream::app);

		/* //  moved this as a call from main function so it will only print once for each array
		// export original array
		outFile << "Original Array: ";
		outFile << "[";
		//int size = vNums.size();
		for (int i = 0; i < vNums.size() - 1; i++) {
			outFile << vNums[i] << ", ";
		}
		int end = vNums.size()-1;
		outFile << vNums[end] << "]" << std::endl;
		*/
		
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
		}  // this is a hacky way of getting an extra line after the original array prints

	
		//export maxSum
		if (maxSum != NULL) {
		outFile << maxSum << std::endl;
		}
		outFile.close();			


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
	
	//std::vector <int> inputSize = {100,200,400, 600, 800, 1000, 2000, 5000, 7000, 10000};
	std::vector <int> inputSize = {100,200,400, 600, 800, 1000, 2000, 3000, 4000, 5000};
	//std::vector <int> inputSize = {2,3,4, 6, 8, 10, 20, 50};  // smaller vector sizes for pre-test-testing
	
	srand((unsigned)time(NULL));
	
	for (int n = 0; n < inputSize.size(); n++) {  
	for (int x = 0; x < 10; x++) {
			vNums = {};
			for (int m = 0; m<inputSize[n]; m++) {
				rNum = rand()%199+ (-100);  //includes negative numbers as well
				vNums.push_back(rNum);
			
				}
		
		  std::cout << "\nOriginal Array: " << "[";
			for (int k = 0; k < vNums.size(); k++) {
				
				std::cout << vNums[k];
				
				if(k<vNums.size()-1) {
				
						std::cout<<", ";
					}
				}
			
			std::cout << "]" << std::endl;
			
			enumeration(vNums);
			betterEnumeration(vNums);
			divideAndConquer(vNums); 
			linear(vNums);
			
		} // end x
			
	} // end n outer loop
}



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
	divideAndConquer(vNums); 
	linear(vNums);
	
}
