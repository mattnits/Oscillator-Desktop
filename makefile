cppsrc = $(wildcard *.cpp) \
		$(wildcard src/processing/*.cpp) \
		$(wildcard src/gui/*.cpp)

obj = $(cppsrc:.c=.o)

LDFLAGS = -Wall -Wextra -Werror 
LDFLAGS2 = `wx-config --cxxflags --libs`

Oscillator: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS2)