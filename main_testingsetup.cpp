
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
	
			
		/*  // READ IN FROM FILE - INCOMPLETE */
	
			/*
			std::string vector;
			int currNum;  // current number being read in from .txt file
			//std::ifstream inFile(argv[1]);  // use this for running from flip/command i.e. ./main infile.txt
			
			std::ifstream inFile("MSS_TestProblems.txt");
			std::ofstream outFile("MSS_Results.txt");
			
			// check for error and exit
			
			while (!inFile.eof()) {
				
				getline(inFile, vector);
				
				std::stringstream inStream(vector);
				
				if (inStream.peek() == '[') {  // need single quotes here
				
					inStream.ignore();
					
					while(inStream >> currNum) {
					
					  vNums.push_back(currNum);
					 
					  if(inStream.peek() == ' ' || inStream.peek() == ',') {
					  
						inStream.ignore();
					  }
					}
				}
				
			}  //finish reading in
			
			//test print vector
			for(int i = 0; i < vNums.size(); i++) {
			
				std::cout << vNums[i] << " " << std::endl;
			}
		
		inFile.close();
		outFile.close();
         // END READ IN FROM FILE 
		 */
			
				
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

	clock_t start, end;
	
	
	int left, right, sum, maxSum;
	sum = 0;
	maxSum = 0;
    
	//std::cout << "\n***** Enumeration *****" << std::endl;
    
		 start = clock();
		 
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
			
		end = clock();
		//std::cout << "Time: " << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << " milliseconds" << std::endl;
		//std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << " ms" << std::endl;
		std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << ",";

		
		
		/*
		std::cout << "[";
		for (int i = left; i <= right; i++) {
		
			std::cout << vNums[i];
			if(i<right) {
			 std::cout<<", ";
			}
			
		}
		std::cout << "]"<<std::endl;
		std::cout << maxSum << std::endl;
		*/
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
	//std::cout << "\n***** Better Enumeration *****" << std::endl;
	
	start = clock();
	
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
		
       end = clock();
		//std::cout << "Time: " << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << " milliseconds" << std::endl;
		//std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << " ms" << std::endl;
		std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << ",";


		/*
		std::cout << "[";
		for (int i = left; i <= right; i++) {
		
			std::cout << vNums[i];
			if(i<right) {
			 std::cout<<", ";
			}
			
		}
		std::cout << "]"<<std::endl;
		
		std::cout << maxSum << std::endl;
		*/
	   return 0;
  
	}

/************************************************
		Divide and Conquer
*************************************************/


int divideAndConquer(std::vector<int>& vNums, int left, int right) {

	clock_t start, end;

    start = clock();
	return 0;


    end = clock();
	//std::cout << "Time: " << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << " milliseconds" << std::endl;
		//std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << " ms" << std::endl;
		std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << ",";

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
	//std::cout << "\n*****  Linear *****" << std::endl;
	
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
	//std::cout << "Time: " << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << " milliseconds" << std::endl;
	//std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000) << " ms" << std::endl;
	std::cout << (end - start) / (double)((CLOCKS_PER_SEC)/1000);
	
		
		
	/*
	std::cout << "[";
	for (int i = minIdx; i <= maxIdx; i++) {
		
		std::cout << vNums[i];
		if(i<maxIdx) {
		 std::cout<<", ";
		}
			
	}
	
	std::cout << "]"<<std::endl;
	std::cout << maxSum << std::endl;
	*/
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
	//std::vector <int> inputSize = {20,30,40, 50, 60, 70, 80, 100, 100, 300};  // smaller vector sizes for pre-test-testing
	
	srand((unsigned)time(NULL));
	
	for (int n = 0; n < inputSize.size(); n++) {  
	for (int x = 0; x < 10; x++) {
			vNums = {};
			for (int m = 0; m<inputSize[n]; m++) {
				rNum = rand()%199+ (-100);  //includes negative numbers as well
				vNums.push_back(rNum);
			
				}
					/*
				  std::cout << "\n\nNew Array: " << "[";
					for (int k = 0; k < vNums.size(); k++) {			
						std::cout << vNums[k];	
						if(k<vNums.size()-1) {
								std::cout<<", ";
							}
						}
					std::cout << "]" << std::endl;
					*/
			std::cout << "\nn = " << inputSize[n]<< ",";
			
			enumeration(vNums);
			betterEnumeration(vNums);
			//divideAndConquer(vNums,0,vNums.size()); // not working yet
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
	//divideAndConquer(vNums,0,vNums.size()); // not working yet
	linear(vNums);
	
}
