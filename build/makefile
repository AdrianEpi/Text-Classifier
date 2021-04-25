#Variable objetos
OBJECTS = main.o vocabulary.o preProcesser.o Chrono.o
#Flags de compilacion
CFLAGS = -c -std=c++17 -Wall

textClassifier: $(OBJECTS)
	g++  $(OBJECTS) -o textClassifier
	mv *.o ../objects
	mv textClassifier ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

vocabulary.o: ../src/vocabulary.cpp ../include/vocabulary.hpp
	g++ $(CFLAGS) ../src/vocabulary.cpp

preProcesser.o: ../src/preProcesser.cpp ../include/preProcesser.hpp
	g++ $(CFLAGS) ../src/preProcesser.cpp

Chrono.o: ../src/Chrono.cpp ../include/Chrono.hpp
	g++ $(CFLAGS) ../src/Chrono.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/textClassifier ../inputs/ecom-train.csv
