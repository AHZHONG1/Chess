# use CPPFLAGS to set proper configurations in different platforms
CPPFLAGS = $(INCLUDE) -MMD -MP -fsanitize=address,leak,undefined
SRCS = main.cpp Stockfish.cpp MainMenu.cpp InGame.cpp PauseMenu.cpp Button.cpp General.cpp ChessBoard.cpp GamePieces.cpp GamePieces/Rook.cpp GamePieces/Pawn.cpp GamePieces/Knight.cpp GamePieces/Bishop.cpp GamePieces/Queen.cpp GamePieces/King.cpp Timer.cpp GameSetting.cpp PromotionBox.cpp PopUpMessageBox.cpp EndGameScreen.cpp DropdownBox.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
INCLUDE =
# (Windows) INCLUDE = -I"C:\Program Files\SFML\SFML-2.6.0\include"
# (Linux) INCLUDE =
LIB =
# (Windows) LIB = -L"C:\Program Files\SFML\SFML-2.6.0\lib"
# (Linux) LIB =

LINKER = $(LIB) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -fsanitize=address,leak,undefined

all: Chess.exe

Chess.exe: $(OBJS)
	g++ $^ -o $@ $(LINKER) 

%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

-include $(DEPS) 

clean:
	rm -f *.o *.exe *.d && cd GamePieces && rm -f *.o *.exe *.d;
	
# (Windows) del *.o *.exe *.d && cd GamePieces && del *.o *.exe *.d;
# (Linux or MacOS) rm -f *.o *.exe *.d && cd GamePieces && rm -f *.o *.exe *.d;