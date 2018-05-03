#makefile


CC=g++					
CXXFLAGS=-g

demostracion = main.cpp DNI.cpp
estadistico = main_estadisticas.cpp DNI.cpp

demostracion: ${demostracion}						
	@$(CC) $(CXXFLAGS) -o arbol ${demostracion} 
	
estadistico: ${estadistico}
	@$(CC) $(CXXFLAGS) -o arbol ${estadistico}

clean: 
	@rm -f arbol