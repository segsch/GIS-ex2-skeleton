COMP = g++-10

GOOGLETEST_LIB = /usr/src/googletest/googletest/gcc-10-build/lib/
GOOGLETEST_INCLUDE = /usr/src/googletest/googletest/include/

#put all your object files here
OBJS = GIS.o tests.o internalTests.o main.o #other objects should be placed here!
#The executabel filename DON'T CHANGE
EXEC = ex2
CPP_COMP_FLAG = -std=c++20 -Werror -Wall -Wextra -pedantic-errors -DNDEBUG -I$(GOOGLETEST_INCLUDE) 
CPP_LINK_FLAG = -L$(GOOGLETEST_LIB) -lgtest -lgtest_main -pthread

$(EXEC): $(OBJS)
	$(COMP) $(OBJS) $(CPP_LINK_FLAG) -o $@

#a rule for building a simple c++ source file
#use g++ -MM main.cpp to see dependencies
internalTests.o: internalTests.cpp
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

GIS.o: GIS.cpp
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

tests.o: tests.cpp #put dependencies here!
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

main.o: main.cpp #put dependencies here!
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

clean:
	rm -f $(OBJS) $(EXEC)
