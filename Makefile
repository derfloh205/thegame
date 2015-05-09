SUBMISSION = a.out
EXECUTABLE = $(SUBMISSION)
SOURCES    = $(wildcard cppFiles/*.cpp)
OBJECTS    = $(patsubst %,%,${SOURCES:.cpp=.o})
CXX        = g++
CXXFLAGS   = -Wall -g -c -std=c++11 -o
LDFLAGS    =

all: $(EXECUTABLE)

%.o: %.cpp ; $(CXX) $(CXXFLAGS) $@ $< -MMD -MF ./$@.d

$(EXECUTABLE) : $(OBJECTS) ; $(CXX) -o $@ $^ $(LDFLAGS)

clean: ; rm -f ./cppFiles/*.o ; rm -f ./cppFiles/*.o.d ; rm -f $(EXECUTABLE)

valgrind: ; valgrind --tool=memcheck --leak-check=full ./$(EXECUTABLE)

run: ; ./$(SUBMISSION)
