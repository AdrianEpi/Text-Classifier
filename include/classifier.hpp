/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     classifier.hpp                                     =
	=            Author:        Adrián Epifanio Rodríguez Hernández                =
	=            Date:          21/04/2021                                         =
	=            Subject:       Advanced Artificial Inteligence                    =
	=            Language:      C++                                                =
	=            Email:         alu0101158280@ull.edu.es                           =
	=            Place:         Universidad De La Laguna                           =
	=                           Escuela Superior de Ingeniería y Tecnología        =
	=                                                                              =
=========================================================================================
=======================================================================================*/
/*------------------  FUNCTIONS  -----------------*/

#pragma once
#include "vocabulary.hpp"
#include "Chrono.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <algorithm>

/*------------------------------------------------*/

class Classifier {

	private:
		// Attributes
		std::vector<std::string> inputFiles_;
		std::vector<Vocabulary> learnedData_;
		std::string data_;

	public:
		// Builders & Destroyer
		Classifier (void);
		Classifier (char* argv[], int& argc);
		~Classifier (void);

		// Getters & Setters
		std::vector<std::string> get_InputFiles (void) const;
		std::vector<Vocabulary> get_LearnedData (void) const;
		std::string get_Data (void) const;

		void set_InputFiles (std::vector<std::string> newInputFiles);
		void set_LearnedData (std::vector<Vocabulary> newLearnedData);
		void set_Data (std::string newData);

		// Functions
		void classifyFile (std::string& inputFile, std::string& stopWords);
		void classify (std::vector<std::string> sentence);
		void generateClassProbability (void);
		std::vector<std::string> preProcess (std::vector<std::string>& stopWords, std::string& sentence);

		// Read & Write
		void readInputFiles (char* argv[], int& argc);
		void storeFile (std::string& outputFile);
};