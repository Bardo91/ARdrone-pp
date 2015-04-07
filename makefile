################################################################################
# VISUAL TRACKIN UI MAKEFILE
#	Author: Pablo Ramón Soria
#	Date: 2013/11/22
################################################################################

########## Variables ##########
CXX = g++
CPP_FILES := $(shell find ./src/ -name '*.cpp')
OBJ_FILES = $(patsubst %.cpp, %.o, $(CPP_FILES))

CXX_FLAGS = -fPIC -std=c++11 -g -Wall

########## EXTERNAL INCLUDES ##########
INCLUDES := -I./src
LIBRARIES := 
DEPENDENCIES := 

########## RULES ##########

all: 

build_example:
	$(CXX)  ./src/main.cpp -o ardronepp_example  $(INCLUDES) -L./ -lardronepp $(CXX_FLAGS)

run_example:
	./ardronepp_example

# Remove preious files
clean:
	@echo "--------------------------------------"
	@echo "Cleaning project----------------------"
	rm -f $(OBJ_FILES)
	@echo "Project Cleaned-----------------------"


# Compile static library
static_lib: $(OBJ_FILES)
	@echo "--------------------------------------"
	@echo "Current cpps--------------------------"
	@echo $(CPP_FILES)
	@echo "Searching for objects-----------------"
	@echo $(OBJ_FILES)
	@echo "Prepare compilation-------------------"
	ar rcs libardronepp.a $^
	@echo "Generated static library -------------"

# Compile shared library
shared_lib: $(OBJ_FILES)
	@echo "--------------------------------------"
	@echo "Current cpps--------------------------"
	@echo $(CPP_FILES)
	@echo "Searching for objects-----------------"
	@echo $(OBJ_FILES)
	@echo "Prepare compilation-------------------"
	$(CXX) -shared -o libardronepp.so $(OBJ_FILES) $(CXX_FLAGS)
	@echo "Generated shared library -------------"



# Compile to .o
%.o: %.cpp
	@echo "--------------------------------------"
	@echo "compiling " $^ " to " $@
	$(CXX) -c $^ -o $@ $(INCLUDES) $(LIBRARIES) $(DEPENDENCIES) $(CXX_FLAGS)


########## PHONY ##########
.PHONY: all clean run static_lib shared_lib




