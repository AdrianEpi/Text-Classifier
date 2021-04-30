# Variables
TIME =$(LOGPATH)$(shell date)
# Object Vars
OBJECTS = main.o vocabulary.o preProcesser.o Chrono.o token.o corpus.o
# Compilation flags
CFLAGS = -c -std=c++17 -Wall

textClassifier: $(OBJECTS)
	g++ $(OBJECTS) -o textClassifier
	mv textClassifier ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

vocabulary.o: ../src/vocabulary.cpp ../include/vocabulary.hpp
	g++ $(CFLAGS) ../src/vocabulary.cpp

preProcesser.o: ../src/preProcesser.cpp ../include/preProcesser.hpp
	g++ $(CFLAGS) ../src/preProcesser.cpp

Chrono.o: ../src/Chrono.cpp ../include/Chrono.hpp
	g++ $(CFLAGS) ../src/Chrono.cpp

token.o: ../src/token.cpp ../include/token.hpp
	g++ $(CFLAGS) ../src/token.cpp

corpus.o: ../src/corpus.cpp ../include/corpus.hpp
	g++ $(CFLAGS) ../src/corpus.cpp



.PHONY: clean
clean:
	rm -rf ../build/*.o
	rm -rf ../bin/*

help:
	../bin/textClassifier --help
	
runCorpus:
	../bin/textClassifier --corpus ../inputs/ecom-train.csv ../inputs/stopWords.txt Electronics Household "Clothing & Accessories" Books

runVocabulary:
	../bin/textClassifier --vocabulary ../inputs/ecom-train.csv ../outputs/vocabulary2.txt ../inputs/stopWords.txt

runVocLog:
	echo "\n\n\nExecuted ${TIME}" >> ../outputs/runDetails.txt
	../bin/textClassifier ../inputs/ecom-train.csv ../outputs/vocabulary.txt ../inputs/stopWords.txt >> ../outputs/runDetails.txt
	echo "You can find full output at outputs/runDetails.txt"
