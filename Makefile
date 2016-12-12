CXX = g++
CXXFLAGS = -std=c++14 -fPIC -I./include
LDFLAGS = -shared -ldl -lSDL2

SOURCES=$(shell find src/$(TYPE) include/ -type f -iname '*.cpp')
OBJECTS=$(SOURCES:.cpp=.o)

TYPE = preload
OUT := libsdl-imgui.so

32bit_flags:
	$(eval CXXFLAGS += -m32)
	$(eval LDFLAGS += -m32)

64bit_flags:
	$(eval CXXFLAGS += -m64)
	$(eval LDFLAGS += -m64)

x86: clean 32bit_flags build
x64: clean 64bit_flags build

clean:
	rm -vf $(OBJECTS) $(OUT)

%.o: ../%.cc
	$(CXX) $(CXXFLAGS) -o "$@" "$<"

build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(OUT) $(LDFLAGS)