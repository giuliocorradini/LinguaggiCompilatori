OBJ = main.o lexer.o
EXEC = kaleidoscope_lexer
CXX = clang++
CXXFLAGS = -std=c++20
LEX = flex

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

lexer.cc: lexer.l
	$(LEX) -o lexer.cc lexer.l

.PHONY: clean cleanall

clean:
	rm *.o lexer.cc

cleanall: clean
	rm $(EXEC)
