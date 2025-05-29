CC = g++
CFLAGS = -Iinclude -fopenmp `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`
SOURCES = src/main.cpp src/ImageProcessor.cpp src/ImageEnhancer.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = image-processor

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)