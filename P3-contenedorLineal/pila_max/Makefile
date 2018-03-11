SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11

cola: $(OBJ)/usopilas_max.o $(OBJ)/pila_max_cola.o
	$(CXX) -o $(BIN)/usopilas_max $^

vector: $(OBJ)/usopilas_max.o $(OBJ)/pila_max_vd.o 
	$(CXX) -o $(BIN)/usopilas_max $^

$(OBJ)/pila_max_cola.o: $(SRC)/pila_max_cola.cpp $(INC)/pila_max_cola.h
	$(CXX) $(CPPFLAGS) $< -o $@
$(OBJ)/pila_max_vd.o: $(SRC)/pila_max_vd.cpp $(INC)/pila_max_vd.h
	$(CXX) $(CPPFLAGS) $< -o $@
$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp $(INC)/pila_max.h
	$(CXX) $(CPPFLAGS) $< -o $@


$(OBJ)/pila_max_vd.o: 
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
