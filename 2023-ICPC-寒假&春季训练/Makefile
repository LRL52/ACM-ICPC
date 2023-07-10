# 获取当前目录下所有的 .cpp 文件
SOURCES = $(wildcard *.cpp)

# 将 .cpp 文件列表转换为对应的可执行文件列表
TARGETS = $(SOURCES:%.cpp=%)

# 编译器和编译参数
CXX = g++
CXXFLAGS = -g -DLRL52 -std=c++17 -Wall -Wextra -lm

# 默认规则，编译所有可执行文件
all: $(TARGETS)

# 通用规则，将 .cpp 文件编译为可执行文件
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 清理规则，删除所有可执行文件
clean:
	rm -f $(TARGETS)

.PHONY: all clean
