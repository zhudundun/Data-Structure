EXENAME = mp_intro
OBJS = main.o PNG.o HSLAPixel.o lodepng.o intro.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp intro.h cs225/PNG.h cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) main.cpp 

intro.o : intro.cpp intro.h
	$(CXX) $(CXXFLAGS) intro.cpp
	
PNG.o : cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

test: catchmain.o tests-part1.o tests-part2.o PNG.o HSLAPixel.o lodepng.o lab_intro.o
	$(LD) catchmain.o tests-part1.o tests-part2.o PNG.o HSLAPixel.o lodepng.o lab_intro.o $(LDFLAGS) -o test


catchmain.o : cs225/catch/catchmain.cpp cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

tests.o : tests/tests.cpp cs225/catch/catch.hpp intro.cpp intro.h
	$(CXX) $(CXXFLAGS) tests/tests.cpp




clean :
	-rm -f *.o $(EXENAME) test
