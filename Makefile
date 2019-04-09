a.out:main-func.o GameCore.o validation.o MetaFunc.o SDL-Func.o
	g++ main-func.o GameCore.o validation.o MetaFunc.o SDL-Func.o -lSDL_ttf
main-func.o:main-func.cpp
	g++ main-func.cpp -lSDL_ttf -c
SDL-Func.o:SDL-Func.cpp
	g++ SDL-Func.cpp -lSDL_ttf -c
GameCore.o:GameCore.cpp
	g++ GameCore.cpp validation.cpp -c
validation.o:validation.cpp
	g++ validation.cpp GameCore.cpp -c
MetaFunc.o:MetaFunc.cpp
	g++ MetaFunc.cpp -c
