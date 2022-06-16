#====================================================
#     VARIABLES
#====================================================
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),$(filter $(UNAME_S),Darwin Linux))  
	TARGET_EXEC := examples
	TEST_EXEC := tests
else
	TARGET_EXEC += examples.exe
	TEST_EXEC += tests.exe
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

#====================================================
#     SOURCE FILES
#====================================================
ifeq ($(UNAME_S),$(filter $(UNAME_S),Darwin Linux))
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
ifeq ($(UNAME_S),$(filter $(UNAME_S),Darwin Linux))
	INC_DIR := $(shell find $(SRC_DIR) -type d)
else
    INC_DIR := $(SRC_DIR)
endif
ifeq ($(UNAME_S),Darwin)
	INC_FLAGS := $(addprefix -I,$(INC_DIR)) `pcre-config --cflags`
else ifeq ($(UNAME_S),Linux)
	INC_FLAGS := $(addprefix -I,$(INC_DIR))
else
    WIN_INCLUDE=C:\include
	WIN_BOOST=C:\boost\include\boost_1_79_0
	INC_FLAGS := $(addprefix -I,$(INC_DIR)) $(addprefix -I,$(WIN_INCLUDE)) $(addprefix -I,$(WIN_BOOST))
endif
ifeq ($(UNAME_S),$(filter $(UNAME_S),Darwin Linux))
	CPPFLAGS := -std=c++17 -g $(INC_FLAGS) -MMD -MP
else
	WIN_CPPFLAGS := -flto -Wl,-allow-multiple-definition
	CPPFLAGS := -std=c++17 -g $(INC_FLAGS) -MMD -MP $(WIN_CPPFLAGS)
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