/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     vocabulary.cpp                                     =
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
/*
* @Author: Adrian Epifanio
* @Date:   2021-04-21 13:37:30
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-04-21 13:59:40
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/vocabulary.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Vocabulary::Vocabulary (void) {
	set_InputFile("");
	set_OutpuFile("");
	set_Counter(0);	
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  inputFile  The input file
 * @param[in]  outpuFile  The outpu file
 */
Vocabulary::Vocabulary (std::string inputFile, std::string outpuFile) {
	set_InputFile(inputFile);
	set_OutpuFile(outpuFile);
	set_Counter(0);
}

/**
 * @brief      Destroys the object.
 */
Vocabulary::~Vocabulary (void) {
}

/**
 * @brief      Gets the input file.
 *
 * @return     The input file.
 */
std::string Vocabulary::get_InputFile (void) const {
	return inputFile_;
}

/**
 * @brief      Gets the outpu file.
 *
 * @return     The outpu file.
 */
std::string Vocabulary::get_OutpuFile (void) const {
	return outpuFile_;
}

/**
 * @brief      Gets the counter.
 *
 * @return     The counter.
 */
int Vocabulary::get_Counter (void) const {
	return counter_;
}

/**
 * @brief      Gets the vocabulary.
 *
 * @return     The vocabulary.
 */
std::set<std::string> Vocabulary::get_Vocabulary (void) const {
	return vocabulary_;
}

/**
 * @brief      Sets the input file.
 *
 * @param[in]  newInputFile  The new input file
 */
void Vocabulary::set_InputFile (std::string newInputFile) {
	inputFile_ = newInputFile;
}

/**
 * @brief      Sets the outpu file.
 *
 * @param[in]  newOutpuFile  The new outpu file
 */
void Vocabulary::set_OutpuFile (std::string newOutpuFile) {
	outpuFile_ = newOutpuFile;
}

/**
 * @brief      Sets the counter.
 *
 * @param[in]  newCounter  The new counter
 */
void Vocabulary::set_Counter (int newCounter) {
	counter_ = newCounter;
}

/**
 * @brief      Sets the vocabulary.
 *
 * @param[in]  newVocabulary  The new vocabulary
 */
void Vocabulary::set_Vocabulary (std::set<std::string> newVocabulary) {
	vocabulary_ = newVocabulary;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newVocabulary  The new vocabulary
 *
 * @return     The result of the assignment
 */
Vocabulary& Vocabulary::operator= (const Vocabulary& newVocabulary) {
	this -> set_Vocabulary(newVocabulary.get_Vocabulary());
	this -> set_Counter(newVocabulary.get_Counter());
	this -> set_OutpuFile(newVocabulary.get_OutpuFile());
	this -> set_InputFile(newVocabulary.get_InputFile());
	return *this;
}
