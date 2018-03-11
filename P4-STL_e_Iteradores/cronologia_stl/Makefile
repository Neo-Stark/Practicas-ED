SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -std=c++11


all: pruebacronologia union_cronologia estadisticaEventos filtradoIntervalo filtradoPalabraClave
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
pruebacronologia: $(BIN)/pruebacronologia

union_cronologia: $(BIN)/union_cronologia

estadisticaEventos: $(BIN)/estadisticaEventos

filtradoIntervalo: $(BIN)/filtradoIntervalo

filtradoPalabraClave: $(BIN)/filtradoPalabraClave

$(BIN)/% : $(OBJ)/cronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/%.o
	$(CXX) $(CPPFLAGS) -o $@ $^

$(OBJ)/%.o : $(SRC)/%.cpp $(INC)/%.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(OBJ)/%.o : $(SRC)/%.cpp 
	$(CXX) $(CPPFLAGS) -c $< -o $@

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
