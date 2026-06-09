# Compiler configuration
CXX := c++
CXXFLAGS := $(shell pkg-config --cflags Qt6Widgets Qt6Multimedia)
LDFLAGS := $(shell pkg-config --libs Qt6Widgets Qt6Multimedia)
MOC := /usr/lib/qt6/libexec/moc

# Main
TARGET := wandahoi
SRCS := main.cpp audioplayer.cpp imagelabel.cpp moc_imagelabel.cpp
OBJS := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
moc_%.cpp: %.hpp
	$(MOC) $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
