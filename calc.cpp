/*

	A calculator app written in C++ by Ajaykrishnan.R
	-------------------------------------------------
	compile using : "g++ -static-libstdc++ ./calc.cpp"

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	vector<string> parser(string&);
	int calc(vector<string>&, vector<string>&);
	cout<<"WELCOME TO MY CALCULATOR, ENTER THE MATH EXPRESSION TO COMPUTE BELOW :"<<"\n";
	string expLine;
	cin>>expLine;
	vector<string> parsedNums, parsedOps = parser(expLine);

	for(string i:parsedNums) cout<<i<<"\n";
	for(string i:parsedOps) cout<<i<<"\n";
		
	calc(parsedNums, parsedOps);
	
}

vector<string> parser(string& line) {

	vector<string> parsedNums;
	vector<string> parsedOps;
	vector<string> mathOperations = {"+","-", "*", "x", "/", "^", "%", "(", ")"};
	string numCollector = "";

	// int j = 0, k = 0;

	for(int i = 0; i < line.length(); i++) {

		if(isdigit(line[i]) && i != (line.length()-1)) numCollector+=line[i]; 

		/* length() is a member of string line, similar to size() of a vector*/

		else if(i == (line.length()-1)) {
			numCollector+=line[i];
			//parsedNums[j]=numCollector;
			parsedNums.push_back(numCollector);
		}

		else if (find(mathOperations.begin(), mathOperations.end(), string(1, line[i])) != mathOperations.end()) { 

		/*
			Hitting a non digit character.
			string() is used to convert line[i] which is a char to a string so that it can be compared with another string.
		*/
			//parsedNums[j++]=numCollector;
			//parsedOps[k++]=line[i];
			parsedNums.push_back(numCollector);
			parsedOps.push_back(string(1, line[i]));
			numCollector="";	
		}
		
	}

	//for(string i:parsedNums) cout<<i<<"\n";
	//for(string i:parsedOps) cout<<i<<"\n";
	
	return parsedNums, parsedOps;
}

int calc(vector<string>& parsedNums, vector<string>& parsedOps) {

	int result = stoi(parsedNums[0]);

	for(int i = 0; i < parsedOps.size(); i++) {
		switch(parsedOps[i][0]) { /* parsedOps[i] is a string but switch needs char */
			case '+':
				result+=stoi(parsedNums[i+1]);
				cout<<'+';

		}
	}
	for(string i:parsedOps) cout<<i<<"\n";

	return result;
}
