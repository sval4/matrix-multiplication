#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

//calculates the value of each number in the answer matrix
const std::string calculate(const std::vector<std::vector<double>>& matrix1, 
	const std::vector<std::vector<double>>& matrix2, const int height, const int width, 
	std::vector<int>& spaces){
	
	double num = 0;
	std::ostringstream ss1;

	//loops through all the numbers of the given row in matrix 1
	//with all the numbers of the given column in matrix 2
	//multiplying the the corresponding numbers and adding the rest
	for(int i = 0; i < matrix2.size(); i++){
		num += matrix1[height][i] * matrix2[i][width];
	}

	ss1 << num;
	//finds which number is the longest for a given column
	spaces[width] = std::max(spaces[width], int(ss1.str().size()));
	return ss1.str();
}

void printMatrix(const std::vector<std::vector<std::string>>& answer, 
	const std::vector<int>& spaces){
	
	for(int i = 0; i < answer.size(); i++){
		for(int j = 0; j < answer[i].size(); j++){
			if(answer[i].size() - 1 == j){
				std::cout << answer[i][j] << std::endl;
			}else{
				//gives at least two spaces between adjacent numbers and keeps each column aligned
				std::cout << answer[i][j] << std::string(spaces[j] + 2 - answer[i][j].size(), ' ');
			}
		}
	}
}

void createMatrix(std::vector<std::vector<double>>& matrix, std::ifstream& input_file, int& height, 
	int& width){

	input_file >> height;
	input_file >> width;
	double num;
	for(int i = 0; i < height; i++){
		matrix.push_back(std::vector<double>());
		for(int j = 0; j < width; j++){
			input_file >> num;
			matrix[i].push_back(num);
		}
	}
}

int main(int argc, char* argv[]){
	if(argc != 2){ //Ensures that 2 arguments are passed in
		std::cerr << "Need to pass in appropriate number of arguments\n";
		exit(1);
	}

	std::ifstream input_file (argv[1]);

	if(!input_file.good()){
		std::cerr << "Error unable to open file " << argv[1] << "\n";
		exit(1);
	}

	std::vector<std::vector<double>> matrix1;
	int height1;
	int width1;
	createMatrix(matrix1, input_file, height1, width1);
	
	std::vector<std::vector<double>> matrix2;
	int height2;
	int width2;
	createMatrix(matrix2, input_file, height2, width2);

	//matrix multiplication can only be done if the width of the first matrix is equal to the 
	//height of the second
	if(width1 != height2){
		std::cerr << "Incorrect dimensions between matrices, multiplication cannot be done" << "\n";
		exit(1);
	}

	std::vector<std::vector<std::string>> answer;
	//used to get the maximum length of each number in each column of the answer matrix
	std::vector<int> spaces(width2, 0); 

	//loops through height1 then width2 because the answer matrix will have the height of the first 
	//matrix and the width of the second matrix
	for(int i = 0; i < height1; i++){
		answer.push_back(std::vector<std::string>());
		for(int j = 0; j < width2; j++){
			answer[i].push_back(calculate(matrix1, matrix2, i, j, spaces));
		}
	}

	printMatrix(answer, spaces);
	
	return 0;
}