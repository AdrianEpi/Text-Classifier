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
* @Last Modified time: 2021-04-25 17:38:52
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
	set_VocabularyCounter(0);	
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
	set_VocabularyCounter(0);
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
 * @brief      Gets the VocabularyCounter.
 *
 * @return     The VocabularyCounter.
 */
int Vocabulary::get_VocabularyCounter (void) const {
	return vocabularyCounter_;
}

/**
 * @brief      Gets the tokens.
 *
 * @return     The tokens.
 */
int Vocabulary::get_Tokens (void) const {
	return tokens_;
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
 * @param[in]  newVocabularyCounter  The new counter
 */
void Vocabulary::set_VocabularyCounter (int newVocabularyCounter) {
	vocabularyCounter_ = newVocabularyCounter;
}

/**
 * @brief      Sets the tokens.
 *
 * @param[in]  newTokens  The new tokens
 */
void Vocabulary::set_Tokens (int newTokens) {
	tokens_ = newTokens;
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
	this -> set_VocabularyCounter(newVocabulary.get_VocabularyCounter());
	this -> set_OutpuFile(newVocabulary.get_OutpuFile());
	this -> set_InputFile(newVocabulary.get_InputFile());
	this -> set_Tokens(newVocabulary.get_Tokens());
	return *this;
}

/**
 * @brief      Preprocess the data for the program, erases punctuation signs,
 *             converts all to lowercase and erases reserved words.
 *
 * @param      preProcesser  The pre processer
 * @param[in]  stopWordFile  The stop word file
 */
void Vocabulary::preProcessData (PreProcesser& preProcesser, std::string stopWordFile) {
	std::string outputFile = "../outputs/preProcesserHelper.txt";
	std::vector<std::string> stopWords = loadStopWord(stopWordFile);
	Chrono preProcessChrono;
	preProcessChrono.startChrono();
	preProcesser.loadData(inputFile_);
	preProcesser.convertLowerCase();
	preProcesser.erasePunctuationSigns();
	preProcesser.storeData(outputFile);
	preProcesser.eraseReservedWords(stopWords, outputFile);
	preProcessChrono.stopChrono();
	std::cout << std::endl << "Elapsed pre-processing time: " << preProcessChrono.get_Seconds(5) << " seconds." << std::endl;
}

/**
 * @brief      Loads the stop words (reserved words).
 *
 * @param[in]  inputFile  The input file
 *
 * @return     stop words vector
 */
std::vector<std::string> Vocabulary::loadStopWord (std::string inputFile) {
	std::vector<std::string> stopWords;
	std::ifstream file(inputFile, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error 404, stopWords file not found." << std::endl;
		exit(1);
	}
	std::string word = "";
	while (!file.eof()) {
		file >> word;
		stopWords.push_back(word);
	}
	file.close();
	return stopWords;
}
