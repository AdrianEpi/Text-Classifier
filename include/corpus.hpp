/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     corpus.hpp                                         =
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

/**
 * @brief      This class describes a corpus.
 */
class Corpus {

	private:
		// Attributes
		std::string name_;
		std::string outputFileName_;
		std::string inputFile_;
		PreProcesser preProcesser_;


	public:
		// Builders & Destroyer
		Corpus (void);
		Corpus (std::string name, std::string inputFile);
		~Corpus (void);

		// Getters & Setters
		std::string get_Name (void) const;
		std::string get_OutputFileName (void) const;
		std::string get_InputFile (void) const;
		PreProcesser get_PreProcesser (void) const;

		void set_Name (std::string newName);
		void set_OutputFileName (std::string newOutputFileName);
		void set_InputFile (std::string newInputFile);
		void set_PreProcesser (PreProcesser newPreProcesser);

		// Functions
		void generateCorpus (void);

};