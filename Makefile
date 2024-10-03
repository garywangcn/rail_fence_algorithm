CXX = g++
CXXFLAGS = -Wall -std=c++11
LIBNAME = librail_fence.a
TARGET = encryption
SRC_LIB = rail_fence_algorithm.cpp
SRC_MAIN = encryption.cpp
TEST_TARGET = test_rail_fence
SRC_TEST = test.cpp

all: $(TARGET) $(TEST_TARGET)

$(LIBNAME): rail_fence_algorithm.o
	$(AR) rcs $(LIBNAME) rail_fence_algorithm.o

rail_fence_algorithm.o: rail_fence_algorithm.cpp rail_fence_algorithm.h
	$(CXX) $(CXXFLAGS) -c rail_fence_algorithm.cpp

$(TARGET): $(SRC_MAIN) $(LIBNAME)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC_MAIN) -L. -l rail_fence

$(TEST_TARGET): $(SRC_TEST) $(LIBNAME)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(SRC_TEST) $(LIBNAME) -l gtest -l gtest_main -pthread

clean:
	rm -f *.o $(LIBNAME) $(TARGET) $(TEST_TARGET)

