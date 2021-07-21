Commands:

g++ -std=c++0x ert_main.c feedback_control.c -lgtest -lgtest_main -pthread --coverage -o Program

./Program  

gcov feedback_control.c

gcovr -r . --html example-html.html

gcovr -r . --html --html-details -o example-html-details.html

Note
*.html files show the results of statement/branch coverage.
