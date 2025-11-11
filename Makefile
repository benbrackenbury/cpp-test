CXX = g++
CXXFLAGS = -std=c++17 -Wall $(shell pkg-config --cflags glfw3)
LDFLAGS = $(shell pkg-config --libs glfw3) -framework Cocoa -framework OpenGL -framework IOKit
OUTDIR = out
TARGET = $(OUTDIR)/program
SOURCES = $(wildcard src/*.cpp)
$(TARGET): $(SOURCES)
	mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^
run: $(TARGET)
	./$(TARGET)
clean:
	rm -rf $(OUTDIR)
.PHONY: clean run
