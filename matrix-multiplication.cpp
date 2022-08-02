#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>

int main(int argc, char* argv[]){
	if(argc != 1){ //Ensures that 1 argument is passed in
		cerr << "Need to pass in appropriate number of arguments\n";
		exit(1);
	}
	ifstream input_file (argv[1]);

	if(!input_file.good()){
		cerr << "Error unable to open file " << argv[1] << "\n";
		exit(1);
	}

	vector<vector<int>> matrix1;
	vector<vector<int>> matrix2;
}