#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>

double calculate(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2, const int height, const int width){
	double num = 0;
	for(int i = 0; i < matrix2.size(); i++){
		num += matrix1[height][i] * matrix2[i][width];
	}
	return num;
}

void printMatrix(const std::vector<std::vector<double>>& answer){
	for(int i = 0; i < answer.size(); i++){
		for(int j = 0; j < answer[i].size(); j++){
			if(answer[i].size() - 1 == j){
				std::cout << answer[i][j] << std::endl;
			}else{
				std::cout << answer[i][j] << " ";
			}
		}
	}
}


int main(int argc, char* argv[]){
	if(argc != 2){ //Ensures that 1 argument is passed in
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
	input_file >> height1;
	input_file >> width1;
	double num;
	for(int i = 0; i < height1; i++){
		matrix1.push_back(std::vector<double>());
		for(int j = 0; j < width1; j++){
			input_file >> num;
			matrix1[i].push_back(num);
		}
	}
	std::vector<std::vector<double>> matrix2;
	int height2;
	int width2;
	input_file >> height2;
	input_file >> width2;
	for(int i = 0; i < height2; i++){
		matrix2.push_back(std::vector<double>());
		for(int j = 0; j < width2; j++){
			input_file >> num;
			matrix2[i].push_back(num);
		}
	}
	if(width1 != height2){
		std::cerr << "Incorrect dimensions between matrices, multiplication cannot be done"  << "\n";
		exit(1);
	}
	std::vector<std::vector<double>> answer;
	for(int i = 0; i < height1; i++){
		answer.push_back(std::vector<double>());
		for(int j = 0; j < width2; j++){
			answer[i].push_back(calculate(matrix1, matrix2, i, j));
		}
	}
	printMatrix(answer);
}