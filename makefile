CXX = g++

TARGET = graphicus

TARGET_DEL = graphicus

SRCS = canevas.cpp couche.cpp forme.cpp graphicus-01.cpp tests.cpp rectangle.cpp carre.cpp cercle.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)
	
%.o: %.cpp
	$(CXX) -c $< -o $@
	
run:
	./$(TARGET)
	
clean:
	rm $(TARGET_DEL) $(OBJS)
