/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     preProcesser.cpp                                   =
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
* @Date:   2021-04-21 13:04:42
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-04-21 13:58:34
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/preProcesser.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
PreProcesser::PreProcesser (void) {
	set_InputFile("");
	set_OutputFile("");
	set_Data("");
	set_ReadyToProcess(true);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  inputFile  The input file
 * @param[in]  outpuFile  The outpu file
 */
PreProcesser::PreProcesser (std::string inputFile, std::string outpuFile) {
	set_InputFile(inputFile);
	set_OutputFile(outpuFile);
	set_Data("");
	set_ReadyToProcess(true);
}

/**
 * @brief      Destroys the object.
 */
PreProcesser::~PreProcesser (void) {

}

/**
 * @brief      Gets the input file.
 *
 * @return     The input file.
 */
std::string PreProcesser::get_InputFile (void) const {
	return inputFile_;
}

/**
 * @brief      Gets the output file.
 *
 * @return     The output file.
 */
std::string PreProcesser::get_OutputFile (void) const {
	return outputFile_;
}

/**
 * @brief      Gets the data.
 *
 * @return     The data.
 */
std::string PreProcesser::get_Data (void) const {
	return data_;
}

/**
 * @brief      Gets the ready to process.
 *
 * @return     The ready to process.
 */
bool PreProcesser::get_ReadyToProcess (void) const {
	return readyToProcess_;
}

/**
 * @brief      Sets the input file.
 *
 * @param[in]  newInputFile  The new input file
 */
void PreProcesser::set_InputFile (std::string newInputFile) {
	inputFile_ = newInputFile;
	if (get_OutputFile() != "") {
		set_ReadyToProcess(true);
	}
}

/**
 * @brief      Sets the output file.
 *
 * @param[in]  newOutputFile  The new output file
 */
void PreProcesser::set_OutputFile (std::string newOutputFile) {
	outputFile_ = newOutputFile;
	if (get_InputFile() != "") {
		set_ReadyToProcess(true);
	}
}

/**
 * @brief      Sets the data.
 *
 * @param[in]  newData  The new data
 */
void PreProcesser::set_Data (std::string newData) {
	data_ = newData;
}

/**
 * @brief      Sets the ready to process.
 *
 * @param[in]  newReadyToProcess  The new ready to process
 */
void PreProcesser::set_ReadyToProcess (bool newReadyToProcess) {
	readyToProcess_ = newReadyToProcess;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newPreProcesser  The new pre processer
 *
 * @return     The result of the assignment
 */
PreProcesser& PreProcesser::operator= (const PreProcesser& newPreProcesser) {
	this -> set_Data(newPreProcesser.get_Data());
	this -> set_OutputFile(newPreProcesser.get_OutputFile());
	this -> set_InputFile(newPreProcesser.get_InputFile());
	this -> set_ReadyToProcess(newPreProcesser.get_ReadyToProcess());
	return *this;
}

void PreProcesser::convertLowerCase (void) {

}

void PreProcesser::convertUpperCase (void) {

}

void PreProcesser::eraseReservedWords (std::vector<std::string> reservedWords) {

}

void PreProcesser::erasePunctuationSigns (void) {

}

void PreProcesser::eraseEmojis (void) {

}

void PreProcesser::eraseURLs (void) {

}

void PreProcesser::eraseHtml (void) {

}

void PreProcesser::eraseHashtags (void) {

}
