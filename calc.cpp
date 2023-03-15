/*

	A calculator app written in C++ by Ajaykrishnan.R
	-------------------------------------------------
	compile using : "g++ -static-libstdc++ calc.cpp"

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <math.h>

using namespace std;

int main() {

	tuple<vector<string>, vector<string>> parser(string&);
	float calc(vector<string>&, vector<string>&);

	cout<<"WELCOME TO MY CALCULATOR, ENTER THE MATH EXPRESSION TO COMPUTE BELOW :"<<"\n";
	string expLine;
	getline(cin>>ws, expLine);

	auto [parsedNums, parsedOps] = parser(expLine);
		 
	cout<<"\nANS: "<<calc(parsedNums, parsedOps)<<"\n";

}

tuple<vector<string>, vector<string>> parser(string& line) {

	vector<string> parsedNums;
	vector<string> parsedOps;
	vector<string> mathOperations = {"+", "-", "*", "x", "/", "^", "%", "(", ")"};
	string numCollector = "";

	for(int i = 0; i < line.length(); i++) {

		if(isdigit(line[i]) && i != (line.length()-1)) numCollector+=line[i]; 

		/* length() is a member of string line, similar to size() of a vector*/

		else if(i == (line.length()-1)) {
			numCollector+=line[i];
			parsedNums.push_back(numCollector);
		}

		else if (find(mathOperations.begin(), mathOperations.end(), string(1, line[i])) != mathOperations.end()) { 

		/*
			Hitting a non digit character.
			string() is used to convert line[i] which is a char to a string so that it can be compared with another string.
		*/
			parsedNums.push_back(numCollector);
			parsedOps.push_back(string(1, line[i]));
			numCollector="";	
		}
		
	}

	return {parsedNums, parsedOps};
}

float calc(vector<string>& parsedNums, vector<string>& parsedOps) {

	vector<string> bodmas = {"/", "*", "+", "-"};
	tuple<int, int> NNN(vector<float>&, int&);
	vector<float> floatNums;
	for(string i:parsedNums) floatNums.push_back(stof(i));
	float f = nan("0");

	for(string i:bodmas) {
		for(int j = 0; j < parsedOps.size(); j++) {
			if(parsedOps[j] == i) {
				switch(i[0]) {
					case '+':
					{
						auto [leftNear, rightNear] = NNN(floatNums, j);
						floatNums[leftNear]+=floatNums[rightNear];
						floatNums[rightNear] = f;
						break;
					}
						
					case '-':
					{
						auto [leftNear, rightNear] = NNN(floatNums, j);
						floatNums[leftNear]-=floatNums[rightNear];
						floatNums[rightNear] = f;
						break;
					}
					case '*':
					{
						auto [leftNear, rightNear] = NNN(floatNums, j);
						floatNums[leftNear]*=floatNums[rightNear];
						floatNums[rightNear] = f;
						break;
					}
					case '/':
					{
						auto [leftNear, rightNear] = NNN(floatNums, j);
						floatNums[leftNear]/=floatNums[rightNear];
						floatNums[rightNear] = f;
						break;
					}
						
				}
			}
		}
	}

	return floatNums[0];

}	

tuple<int, int> NNN(vector<float>& floatNums, int& pos) { /* Not-NaN-Neighbour Finder */

	int leftNear = 0;

	int rightNear = floatNums.size() - 1;

	for(int i = 0; i <= pos; i++) {
		if(!isnan(floatNums[i]) && i > leftNear) leftNear = i;
	}

	for(int i = floatNums.size() - 1; i > pos; i--) {
		if(!isnan(floatNums[i]) && i < rightNear) rightNear = i;
	}

	return {leftNear, rightNear};

}
