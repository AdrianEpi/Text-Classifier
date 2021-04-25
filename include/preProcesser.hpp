/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     preProcesser.hpp                                   =
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
 * @brief      This class describes a pre processer, it makes possible to
 *             preprocess data files before using them.
 */
class PreProcesser {

	private:
		// Attributes
		std::string inputFile_;						// Input file path
		std::string outputFile_;					// Output file path where the preprocessed text will store the data
		std::string data_;							// Stored data readed from input file

	public:
		// Builders & Destroyer
		PreProcesser (void);
		PreProcesser (std::string inputFile, std::string outpuFile);
		~PreProcesser (void);

		// Getters & Setters
		std::string get_InputFile (void) const;
		std::string get_OutputFile (void) const;
		std::string get_Data (void) const;

		void set_InputFile (std::string newInputFile);
		void set_OutputFile (std::string newOutputFile);
		void set_Data (std::string newData);

		// Operators Overload
		PreProcesser& operator= (const PreProcesser& newPreProcesser);

		// Functions
		void convertLowerCase (std::string& str);
		void convertLowerCase (void);
		void convertUpperCase (std::string& str);
		void convertUpperCase (void);
		void eraseReservedWords (std::vector<std::string>& reservedWords, std::string& fileName);
		void erasePunctuationSigns (std::string& str);
		void erasePunctuationSigns (void);
		void eraseURLs (std::string& str);
		void eraseURLs (void);
		void eraseHashtags (std::string& str);
		void eraseHashtags (void);
		void eraseNumbers (std::string& str);
		void eraseNumbers (void);
		void eraseAllNumbers (void);

		// Read & Write
		void loadData (std::string& inputFile);
		void printData (void);
		void storeData(std::string& outputFile);

};