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
* @Last Modified time: 2021-04-28 14:08:48
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
 * @brief      Gets the tokens number.
 *
 * @return     The tokens number.
 */
int Vocabulary::get_NTokens (void) const {
	return nTokens_;
}

/**
 * @brief      Gets the vocabulary.
 *
 * @return     The vocabulary.
 */
std::set<Token> Vocabulary::get_Vocabulary (void) const {
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
 * @brief      Sets the tokens number.
 *
 * @param[in]  newTokens  The new tokens number
 */
void Vocabulary::set_NTokens (int newTokens) {
	nTokens_ = newTokens;
}

/**
 * @brief      Sets the vocabulary.
 *
 * @param[in]  newVocabulary  The new vocabulary
 */
void Vocabulary::set_Vocabulary (std::set<Token> newVocabulary) {
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
	this -> set_NTokens(newVocabulary.get_NTokens());
	return *this;
}

/**
 * @brief      Preprocess the data for the program, erases punctuation signs,
 *             converts all to lowercase and erases reserved words.
 *
 * @param[in]  stopWordFile  The stop word file
 */
void Vocabulary::preProcessData (std::string& stopWordFile) {
	PreProcesser preProcesser;
	std::string outputFile = "../outputs/preProcesserHelper.txt";
	std::vector<std::string> stopWords = loadStopWord(stopWordFile);
	std::string empty = "";
	preProcesser.loadData(inputFile_, empty);
	preProcesser.convertLowerCase();
	preProcesser.erasePunctuationSigns();
	preProcesser.eraseAllNumbers();
	preProcesser.storeData(outputFile);
	preProcesser.eraseReservedWords(stopWords, outputFile);
	return;
}

/**
 * @brief      Loads the stop words (reserved words).
 *
 * @param[in]  inputFile  The input file
 *
 * @return     stop words vector
 */
std::vector<std::string> Vocabulary::loadStopWord (std::string& inputFile) {
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

/**
 * @brief      Generates vocabulary file
 *
 * @param      inputFile  The input file
 */
void Vocabulary::generateVocabulary (std::string& inputFile) {
	std::ifstream file(inputFile, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error 404, generateVocabulary file not found." << std::endl;
		exit(1);
	}
	set_NTokens(0);
	set_VocabularyCounter(0);
	std::set<Token> v_;
	Token token;
	token.set_Ammount(1);
	std::string word;
	std::set<Token>::iterator it;
	while (!file.eof()) {
		file >> word;
		if (!vocabulary_.count(word)) {
			Token newToken(word);
			vocabulary_.insert(newToken);
		}
		/*else {
			it = vocabulary_.find(word);
			Token newToken = *it;
			newToken.incrementate();
			vocabulary_.erase(word);
			vocabulary_.insert(newToken);
		}*/
		nTokens_++;
	}
	file.close();
	set_VocabularyCounter(vocabulary_.size());
}

/**
 * @brief      Stores the vocabulary into the given file.
 *
 * @param      outputFile  The output file
 */
void Vocabulary::storeVocabulary (std::string& outputFile) {
	std::ofstream file(outputFile, std::ios::in);
	if (file.fail()) {
		std::cout << "Error while storing data \"" << outputFile << "\" is not valid document" << std::endl;
		exit(1);
	} 
	else { 
		file << "Numero de palabras: " << get_VocabularyCounter();
		for (auto i : vocabulary_) {
			file << std::endl << i.get_Name();
		}
	}
	file.close();
}