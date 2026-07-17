// The Tokenizer
// Write a C code snippet using strtok() that takes the string "C,C++,Java,Python,Rust" and prints each language on a new line. Please submit your solution by providing a GitHub file link.

// Enter your answer:

// Custom Implementation (No <string.h>)
// Write a custom C function int my_strlen(const char *str) that calculates and returns the length of a string without using the built-in strlen() function.

// Please submit your solution by providing a GitHub file link.

// Enter your answer:

// String Reversal (In-Place)
// Write a C function void reverse_string(char *str) that reverses a string in-place (without allocating a second array or using external memory).

// Input: "Data Structures"
// Output: "serutcurtS ataD"
// Please submit your solution by providing a GitHub file link.

// Enter your answer:

// Substring Search (Custom strstr)
// Implement your own version of the standard C strstr() function: int find_substring(const char *haystack, const char *needle). The function should return the starting index of the first occurrence of the needle string within the haystack string. If the needle is not found, return -1.

// Input: haystack = "Embedded Systems", needle = "bed"
// Output: 2 (since "bed" starts at index 2)
// Constraint: Do not use any functions from <string.h>.
// Please submit your solution by providing a GitHub file link.

// Enter your answer:

URL Encoder (Space Replacement)
Write a C function void url_encode(char *str, int true_length) that replaces all spaces in a string with "%20". Assume the string has sufficient buffer space at the end to hold the additional characters, and you are given the "true" length of the initial string.

Input: "Hello World  ", true_length = 11
Output: "Hello%20World"
Please submit your solution by providing a GitHub file link.

Enter your answer:

// Practice with awk
// You are given a data file named employees.txt which contains information about a small company's engineering team. The fields are separated by a comma (,) and represent: Name, Department, HourlyWage, HoursWorked

// Create the data file using the text below:

// Alice,Engineering,50,40
// Bob,Marketing,35,38
// Charlie,Engineering,60,45
// David,HR,30,40
// Eva,Engineering,55,35
// Task1: Basic Field Extraction
// Print only the names and departments of all employees. The output should look like this:

// Alice Engineering
// Bob Marketing
// ...
// Task2: Filtering by Row (Pattern Matching)
// Filter the dataset to only display employees who work in the Engineering department. Print their entire record. The output should look like this:

// Alice,Engineering,50,40
// Charlie,Engineering,60,45
// Eva,Engineering,55,35
// Task3: Basic Arithmetic (Calculating Total Pay)
// Write an awk script to calculate the gross pay for each employee (HourlyWage * HoursWorked). Print the employee's name followed by their calculated pay. Output should look like this

// Alice gross pay: $2000
// Bob gross pay: $1330
// Charlie gross pay: $2700
// David gross pay: $1200
// Eva gross pay: $1925
// Task4: Using Built-in Variables (NR and NF)
// Print every line of the file, prefixed by its line number (Record Number) and the total number of fields in that line. Output should look like this

// 1 (4 fields): Alice,Engineering,50,40
// 2 (4 fields): Bob,Marketing,35,38
// 3 (4 fields): Charlie,Engineering,60,45
// 4 (4 fields): David,HR,30,40
// 5 (4 fields): Eva,Engineering,55,35
// Task 5: The Grand Finale (BEGIN, END, and Conditionals)
// Write a complete awk command that:

// Calculates the total payroll cost for the Engineering department only.
// Prints the final total at the end of the execution.
// Output should look like this

// Total Engineering Payroll: $6625
// Please create a shell script and submit your solution by providing a GitHub file link.

// Enter your answer: