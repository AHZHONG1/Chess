# use CPPFLAGS to set proper configurations in different platforms
CPPFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -fsanitize=address,leak,undefined
SRCS = main.cpp MainMenu.cpp InGame.cpp PauseMenu.cpp Button.cpp State.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: Chess.exe

Chess.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ -o $@ $(CPPFLAGS) -MMD -MP -c $<

-include $(DEPS)

clean:
	rm -f *.o *.exe *.d
# (Windows) del *.o *.exe *.d
# (Linux or MacOS) rm -f *.o *.exe *.d