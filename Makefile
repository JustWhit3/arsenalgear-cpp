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
	TARGET_EXEC := examples
	TEST_EXEC := tests
else
	TARGET_EXEC := examples.exe
	TEST_EXEC := tests.exe
endif
LIB := libarsenalgear.a
CC := g++

#====================================================
#     FOLDERS
#====================================================
BUILD_DIR := bin
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := test
LIB_DIR := lib
ifeq ($(O_SYSTEM),Windows)
	WIN_INCLUDE := C:\include
	WIN_BOOST := C:\boost\include\boost-1_79
	#WIN_BOOST_LIB := C:\boost\lib\libboost_iostreams-mgw8-mt-x32-1_79.a
endif

#====================================================
#     SOURCE FILES
#====================================================
ifeq ($(O_SYSTEM),$(filter $(O_SYSTEM),MacOS Linux))
	SRC := $(shell find $(SRC_DIR) -name '*.cpp')
	SRC_LIB := $(shell find $(SRC_DIR) -type f | grep -v 'examples.cpp')
	TEST := $(shell find $(SRC_DIR) -type f | grep -v 'examples.cpp') $(shell find $(TEST_DIR) -name '*.cpp')
else
	SRC := $(wildcard $(SRC_DIR)/*.cpp) 
	SRC_LIB := $(filter-out $(SRC_DIR)/examples.cpp, $(wildcard $(SRC_DIR)/*.cpp))
	TEST := $(filter-out $(SRC_DIR)/examples.cpp, $(wildcard $(SRC_DIR)/*.cpp)) $(wildcard $(TEST_DIR)/*.cpp) 
endif

#====================================================
#     SOURCE OBJECTS
#====================================================
OBJ := $(SRC:%=$(OBJ_DIR)/%.o)
OBJ_LIB := $(SRC_LIB:%=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST:%=$(OBJ_DIR)/%.o)

#====================================================
#     DEPENDENCIES AND FLAGS
#====================================================
DEPS := $(OBJ:.o=.d)
ifeq ($(O_SYSTEM),Linux)
	INC_DIR := $(shell find $(SRC_DIR) -type d)
	INC_FLAGS := $(addprefix -I,$(INC_DIR))
	CPPFLAGS := -std=c++17 -g $(INC_FLAGS) -MMD -MP
else ifeq ($(O_SYSTEM),MacOS)
	INC_DIR := $(shell find $(SRC_DIR) -type d)
	INC_FLAGS := $(addprefix -I,$(INC_DIR)) `pcre-config --cflags`
	CPPFLAGS := -std=c++17 -g $(INC_FLAGS) -MMD -MP
else
	INC_DIR := $(SRC_DIR)
	INC_FLAGS := $(addprefix -I,$(INC_DIR)) $(addprefix -I,$(WIN_INCLUDE)) $(addprefix -I,$(WIN_BOOST))
	CPPFLAGS := -std=c++17 -g $(INC_FLAGS) -MMD -MP -mbig-obj
	LDFLAGS := -mbig-obj
endif

#====================================================
#     ALIASES
#====================================================
.PHONY: clean all

#====================================================
#     BUILDING
#====================================================

#Building all:
all: $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/$(TEST_EXEC) $(LIB_DIR)/$(LIB)
examples: $(BUILD_DIR)/$(TARGET_EXEC) $(LIB_DIR)/$(LIB)
tests: $(BUILD_DIR)/$(TEST_EXEC) $(LIB_DIR)/$(LIB)

#Building main executable:
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

#Building test executable:
$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJ)
	@ mkdir -p $(dir $@)
	$(CC) $(TEST_OBJ) -o $@ $(LDFLAGS)

#Put object files into the object dir:
$(OBJ_DIR)/%.cpp.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#Create a static library from object files and put it in the library dir:
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