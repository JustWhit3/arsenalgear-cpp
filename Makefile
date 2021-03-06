#====================================================
#     OS detection
#====================================================
ifeq ($(OS),Windows_NT)
	O_SYSTEM = Windows
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		O_SYSTEM = Linux
	else ifeq ($(UNAME_S),Darwin)
		O_SYSTEM = MacOS
	endif
endif

#====================================================
#     VARIABLES
#====================================================
ifeq ($(O_SYSTEM),$(filter $(O_SYSTEM),MacOS Linux))  
	MATH_EX := math 
	OPERATORS_EX := operators
	STREAM_EX := stream
	UTILS_EX := utils
	SYSTEM_EX := system
	CONTAINERS_EX := containers
	TEST_EX := tests
else
	MATH_EX := math.exe
	OPERATORS_EX := operators.exe
	STREAM_EX := stream.exe
	UTILS_EX := utils.exe
	SYSTEM_EX := system.exe
	CONTAINERS_EX := containers.exe
	TEST_EX := tests.exe
endif
LIB := libarsenalgear.a
CC := g++

#====================================================
#     DIRECTORIES
#====================================================

# Binary dirs
BUILD_DIR := bin
OBJ_DIR := obj
LIB_DIR := lib

# Source dirs
SRC_DIR := src
EX_DIR := examples
TEST_DIR := test

#====================================================
#     SOURCE FILES
#====================================================
ifeq ($(O_SYSTEM),$(filter $(O_SYSTEM),MacOS Linux))
	# Source files fo examples
	SRC_MATH := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'math.cpp')
	SRC_OPERATORS := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'operators.cpp')
	SRC_STREAM := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'stream.cpp')
	SRC_UTILS := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'utils.cpp')
	SRC_SYSTEM := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'system.cpp')
	SRC_CONTAINERS := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(EX_DIR) -name 'containers.cpp')

	# Other source files
	SRC_LIB := $(shell find $(SRC_DIR) -name '*.cpp')
	TEST := $(shell find $(SRC_DIR) -name '*.cpp') $(shell find $(TEST_DIR) -name '*.cpp')
else
	# Source files fo examples
	SRC := $(wildcard $(SRC_DIR)/*.cpp) 
	SRC_MATH := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(EX_DIR)/math.cpp)
	SRC_OPERATORS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(EX_DIR)/operators.cpp)
	SRC_STREAM := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(EX_DIR)/stream.cpp)
	SRC_UTILS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(EX_DIR)/utils.cpp)
	SRC_SYSTEM := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(EX_DIR)/system.cpp)
	SRC_CONTAINERS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(EX_DIR)/containers.cpp)

	# Source files fo examples
	SRC_LIB := $(wildcard $(SRC_DIR)/*.cpp)
	TEST := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(TEST_DIR)/*.cpp)
endif

#====================================================
#     SOURCE OBJECTS
#====================================================

# Source objects fo examples
OBJ_MATH := $(SRC_MATH:%=$(OBJ_DIR)/%.o)
OBJ_OPERATORS := $(SRC_OPERATORS:%=$(OBJ_DIR)/%.o)
OBJ_STREAM := $(SRC_STREAM:%=$(OBJ_DIR)/%.o)
OBJ_UTILS := $(SRC_UTILS:%=$(OBJ_DIR)/%.o)
OBJ_SYSTEM := $(SRC_SYSTEM:%=$(OBJ_DIR)/%.o)
OBJ_CONTAINERS := $(SRC_CONTAINERS:%=$(OBJ_DIR)/%.o)

# Other source objects
OBJ_LIB := $(SRC_LIB:%=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST:%=$(OBJ_DIR)/%.o)

#====================================================
#     DEPENDENCIES AND FLAGS
#====================================================
DEPS := $(OBJ_MATH:.o=.d) $(OBJ_OPERATORS:.o=.d) $(OBJ_STREAM:.o=.d) $(OBJ_UTILS:.o=.d) $(OBJ_SYSTEM:.o=.d) $(OBJ_CONTAINERS:.o=.d)
ifeq ($(O_SYSTEM),$(filter $(O_SYSTEM),MacOS Linux))
	INC_DIR := $(shell find $(SRC_DIR) -type d)
else
	INC_DIR := $(SRC_DIR)
endif
INC_FLAGS := $(addprefix -I,$(INC_DIR))
WFLAGS := -Wall -Wextra -Wno-reorder
CPPFLAGS := -std=c++17 -g $(INC_FLAGS) -MMD -MP $(WFLAGS) 

#====================================================
#     ALIASES
#====================================================
.PHONY: clean all

#====================================================
#     BUILDING
#====================================================

#Building all:
all: $(BUILD_DIR)/$(MATH_EX) $(BUILD_DIR)/$(OPERATORS_EX) $(BUILD_DIR)/$(STREAM_EX) $(BUILD_DIR)/$(UTILS_EX) $(BUILD_DIR)/$(SYSTEM_EX) $(BUILD_DIR)/$(CONTAINERS_EX) $(BUILD_DIR)/$(TEST_EX) $(LIB_DIR)/$(LIB)
examples: $(BUILD_DIR)/$(MATH_EX) $(BUILD_DIR)/$(OPERATORS_EX) $(BUILD_DIR)/$(STREAM_EX) $(BUILD_DIR)/$(UTILS_EX) $(BUILD_DIR)/$(SYSTEM_EX) $(LIB_DIR)/$(LIB)
tests: $(BUILD_DIR)/$(TEST_EX)

#====================================================
#     Building examples
#====================================================

# Math
$(BUILD_DIR)/$(MATH_EX): $(OBJ_MATH)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_MATH) -o $@ $(LDFLAGS)

# Operators
$(BUILD_DIR)/$(OPERATORS_EX): $(OBJ_OPERATORS)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_OPERATORS) -o $@ $(LDFLAGS)

# Stream
$(BUILD_DIR)/$(STREAM_EX): $(OBJ_STREAM)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_STREAM) -o $@ $(LDFLAGS)

# Utils
$(BUILD_DIR)/$(UTILS_EX): $(OBJ_UTILS)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_UTILS) -o $@ $(LDFLAGS)

# System
$(BUILD_DIR)/$(SYSTEM_EX): $(OBJ_SYSTEM)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_SYSTEM) -o $@ $(LDFLAGS)

# Containers
$(BUILD_DIR)/$(CONTAINERS_EX): $(OBJ_CONTAINERS)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ_CONTAINERS) -o $@ $(LDFLAGS)

#====================================================
#     Building tests
#====================================================
$(BUILD_DIR)/$(TEST_EX): $(TEST_OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(TEST_OBJ) -o $@ $(LDFLAGS)

#====================================================
#     Reordering objects
#====================================================
$(OBJ_DIR)/%.cpp.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#====================================================
#     Static library creation
#====================================================
$(LIB_DIR)/$(LIB): $(OBJ_LIB)
	@ mkdir -p $(dir $@)
	ar rcs $(LIB_DIR)/$(LIB) $(OBJ_LIB)

#====================================================
#     CLEAN
#====================================================
clean:
	rm -r $(OBJ_DIR) $(BUILD_DIR) $(LIB_DIR)

#====================================================
#     INCLUDE
#====================================================
-include $(DEPS)