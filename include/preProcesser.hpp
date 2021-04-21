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

/*------------------------------------------------*/

/**
 * @brief      This class describes a pre processer, it makes possible to
 *             preprocess data files before using them.
 */
class PreProcesser {

	private:
		std::string inputFile_;						// Input file path
		std::string outpuFile_;						// Output file path where the preprocessed text will store the data
		std::string data_;							// Stored data readed from input file
		bool readyToProcess_;						// Dev flag to know if the data can be processed or not (must have an input and output file)

	public:
		// Builders & Destroyer
		PreProcesser (void);
		PreProcesser (std::string inputFile, std::string outpuFile);
		~PreProcesser (void);

		// Getters & Setters
		std::string get_InputFile (void) const;
		std::string get_OutputFile (void) const;
		std::string get_Data (void) const;
		bool get_ReadyToProcess (void) const;

		void set_InputFile (std::string newInputFile);
		void set_OutputFile (std::string newOutputFile);
		void set_Data (std::string newData);
		void set_ReadyToProcess (bool newReadyToProcess);

		// Operators Overload
		PreProcesser& operator= (const PreProcesser& newPreProcesser);

		// Functions
		void convertLowerCase (void);
		void convertUpperCase (void);
		void eraseReservedWords (std::vector<std::string> reservedWords);
		void eraseEmojis (void);
		void eraseURLs (void);
		void eraseHtml (void);
		void eraseHashtags (void);

};