CXX = g++
CXXFLAGS = -Wall -std=c++11
LIBNAME = librail_fence.a
TARGET_EN = encryption
TARGET_DE = decryption
SRC_LIB = rail_fence_algorithm.cpp
SRC_MAIN_EN = encryption.cpp
SRC_MAIN_DE = decryption.cpp
SRC_TEST = test.cpp
TEST_TARGET = test_rail_fence

all: $(TARGET_EN) $(TARGET_DE) $(TEST_TARGET)

$(LIBNAME): rail_fence_algorithm.o
	$(AR) rcs $(LIBNAME) rail_fence_algorithm.o

rail_fence_algorithm.o: rail_fence_algorithm.cpp rail_fence_algorithm.h
	$(CXX) $(CXXFLAGS) -c rail_fence_algorithm.cpp

$(TARGET_EN): $(SRC_MAIN_EN) $(LIBNAME)
	$(CXX) $(CXXFLAGS) -o $(TARGET_EN) $(SRC_MAIN_EN) -L. -l rail_fence

$(TARGET_DE): $(SRC_MAIN_DE) $(LIBNAME)
	$(CXX) $(CXXFLAGS) -o $(TARGET_DE) $(SRC_MAIN_DE) -L. -l rail_fence

$(TEST_TARGET): $(SRC_TEST) $(LIBNAME)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(SRC_TEST) $(LIBNAME) -l gtest -l gtest_main -pthread

clean:
	rm -f *.o $(LIBNAME) $(TARGET_EN) $(TARGET_DE) $(TEST_TARGET)

