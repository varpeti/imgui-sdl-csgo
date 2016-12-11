CXX = g++
CXXFLAGS = -std=c++14 -m64 -fPIC -I./include
LDFLAGS = -shared -ldl -lSDL2 -m64

SOURCES=$(shell find src/$(TYPE) include/ -type f -iname '*.cpp')
OBJECTS=$(SOURCES:.cpp=.o)

TYPE = preload
OUT := libsdl-imgui.so

all: build

clean:
	rm -vf $(OBJECTS) $(OUT)

%.o: ../%.cc
	$(CXX) $(CXXFLAGS) -o "$@" "$<"

build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(OUT) $(LDFLAGS)