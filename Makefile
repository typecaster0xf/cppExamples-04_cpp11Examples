big5.exe: big5.cpp
	g++ $< -std=c++11 -o $@

rangedForAndLambda.exe: rangedForAndLambda.cpp
	g++ $< -std=c++11 -o $@

ackermann.exe: ackermannTester.cpp ackermann.h
	g++ $< -std=c++11 -o $@

.PHONY: clean
clean:
	rm -f *.exe
