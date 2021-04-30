/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     vocabulary.hpp                                     =
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
#include "preProcesser.hpp"
#include "Chrono.hpp"
#include "token.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cstring>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>

/*------------------------------------------------*/

/**
 * @brief      This class describes a vocabulary and 
 */
class Vocabulary {

	private:
		// Attributes
		std::string inputFile_;			// Input file path
		std::string outpuFile_;			// Output file where the vocabulary will be stored
		int vocabularyCounter_;			// Number of different words in the vocabulary
		int nTokens_;					// Number of words in the text
		std::set<Token> vocabulary_;	// Set with all the vocabulary

	public:
		// Builders & Destroyer
		Vocabulary (void);
		Vocabulary (std::string inputFile, std::string outpuFile);
		~Vocabulary (void);

		// Getters & Setters
		std::string get_InputFile (void) const;
		std::string get_OutpuFile (void) const;
		int get_VocabularyCounter (void) const;
		int get_NTokens (void) const;
		std::set<Token> get_Vocabulary (void) const;

		void set_InputFile (std::string newInputFile);
		void set_OutpuFile (std::string newOutpuFile);
		void set_VocabularyCounter (int newVocabularyCounter);
		void set_NTokens (int newNTokens);
		void set_Vocabulary (std::set<Token> newVocabulary);

		// Operators Overload
		Vocabulary& operator= (const Vocabulary& newVocabulary);

		// Functions
		void preProcessData (std::string& stopWordFile);
		std::vector<std::string> loadStopWord (std::string& inputFile);
		void generateVocabulary (std::string& inputFile, bool tokenized);

		// Write
		void readVocabulary (std::string& inputFile);
		void storeVocabulary (std::string& outputFile);
};