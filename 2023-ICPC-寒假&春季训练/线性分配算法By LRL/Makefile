# By 2021090906016 刘芮利

target = LinearScanRegisterAllocation
CXX = g++
CXXFLAG = -O2 -std=c++23
RM = rm -f

all: $(target)

$(target): %: %.cpp
	$(CXX) $^ $(CXXFLAG) -o $@

run:
	./$(target) < data1.in
	./$(target) < data2.in

.PHONY: clean
clean:
	$(RM) $(target)