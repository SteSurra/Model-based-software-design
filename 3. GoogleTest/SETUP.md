## Miniguide 

0. Install gcovr
```
brew install gcovr
```
In order to make it simpler to improve the quality of your tests, in terms of statements (lines) and branches coverage, it is possible to run these commands on your Linux terminal:
 
1. Compile source code:
```
g++ -std=c++0x ert_main.c feedback_control.c -lgtest -lgtest_main -pthread --coverage -o Program
```
2. Run the executable yet obtained:
```
./Program 
```
3. Obtain the coverage data by running the command:
```
gcov feedback_control.c
```
4. Generate HTML reports running the the command:
``` 
gcovr -r . --html example-html.html
gcovr -r . --html --html-details -o example-html-details.html
```
 
 
