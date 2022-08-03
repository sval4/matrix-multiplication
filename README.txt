This project takes in two matrices and produces the multiplied answer in an easy to read format.
In order for this project to work it takes in an input text file that must first state the width and height
of the first matrix. Then it must state all the numbers in the matrix. Repeat this for the second matrix. To
run this program simply compile it in the command prompt and execute the file while passing in the input text file
as an argument. For examples of how to write the input text files see the text files that are part of this folder.
I tested my program with a few test cases a square matrix test case, matrices with different but valid dimensions,
matrices with negative numbers, and matrices with invalid dimensions. If a non number is used in the input file
the program will have undefined behavior as it may print out an error message or give a possible answer based on
its interpretation.

Example compilation and execution:
g++ matrix-multiplication.cpp
./a.out [testcase.txt]