#Variable objetos
OBJECTS = main.o 
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


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run1:
	../bin/textClassifier ../inputs/ecom-train.csv
