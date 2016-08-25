SRC  = main.cpp Output_Files.cpp Calendar.cpp Algorithm.cpp 
OBJS = ${SRC:.cpp=.o}
DEPS = Output_Files.h Calendar.h Random_Number_Generator.h Algorithm.h 
CXX  = c++
CXXFLAGS=-c -Wall -O3
BUILT = built by $$(id -un):

all: economics

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $<

economics: $(OBJS)
	$(CXX) -o $@ $(OBJS)

main.o: main.cpp Data_Parser.h PDF_and_CDF.h Statistics.h Random_Number_Generator.h
	$(CXX) $(CXXFLAGS) main.cpp