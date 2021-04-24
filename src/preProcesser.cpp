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
* @Last Modified time: 2021-04-24 23:10:54
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

/**
 * @brief      Converts all the data into Lower Case
 *
 * @param      str   The string
 */
void PreProcesser::convertLowerCase (std::string& str) {
	std::transform(data_.begin(), data_.end(),data_.begin(), ::tolower);
}

/**
 * @brief      Converts all the data into Upper Case
 *
 * @param      str   The string
 */
void PreProcesser::convertUpperCase (std::string& str) {
	std::transform(data_.begin(), data_.end(),data_.begin(), ::toupper);
}

/**
 * @brief      Deletes all the words from the vector in the given file and stores them into the same file.
 *
 * @param[in]  reservedWords  The reserved words vector
 * @param[in]  fileName       The file name
 */
void PreProcesser::eraseReservedWords (std::vector<std::string>& reservedWords, std::string& fileName) {
	std::ifstream file(fileName, std::ios::in);
	data_ = "";
	if (file.fail()) {
		std::cout << std::endl << "Error 404, file not found in eraseReservedWords function." << std::endl;
		exit(1);
	}
	std::string aux = "";
	while (!file.eof()) {
		file >> aux;
		bool push = true;
		for (unsigned i = 0; i < reservedWords.size(); i++) {
			if (aux == reservedWords[i]) {
				push = false;
				break;
			}
		}
		if (push) {
			data_ += '\n' + aux;
		}
	}
	file.close();
	storeData(fileName);
}

/**
 * @brief      Erases all punctuation sings into readed data.
 *
 * @param      str   The string
 */
void PreProcesser::erasePunctuationSigns (std::string& str) {
	std::vector<char> punctuantionSigns = {',', '.', '-', '_', '?', '!', ';', ':', '\'', '\"'};
	for (unsigned i = 0; i < str.length(); i++) {
		if (!isalpha(str[i]) && !isdigit(str[i])) {
			for (unsigned j = 0; j < punctuantionSigns.size(); j++) {
				if (str[i] == punctuantionSigns[j]) {
					str[i] = ' ';
				}
			}
		}
	}
}

/**
 * @brief      Erases all URLs into data var, an URL is defined as a '.' between
 *             letters without spaces.
 *
 * @param      str   The string
 */
void PreProcesser::eraseURLs (std::string& str) {
	for (unsigned i = 0; i < str.length(); i++) {
		if (str[i] == '.' && str[i + 1] != ' ') {
			unsigned k = i;
			while (str[k] != ' ') {
				str[k] = ' ';
				k--;
			}
			while (str[i] != ' ') {
				str[i] = ' ';
				i++;
			}
		}
	}
}

/**
 * @brief      Erases all Hashtags into data var.
 *
 * @param      str   The string
 */
void PreProcesser::eraseHashtags (std::string& str) {
	for (unsigned i = 0; i < str.length(); i++) {
		if (str[i] == '#') {
			str[i] = ' ';
			while (str[i] != ' ') {
				str[i] = ' ';
				i++;
			}
		}
	}
}

/**
 * @brief      Loads the data from input file into data var.
 */
void PreProcesser::loadData (void) {
	if (!get_ReadyToProcess()) {
		std::cout << std::endl << "Error while loading data, intput and output files has not been loaded to the preprocesser" << std::endl;
		exit(1);
	}
	std::ifstream file(inputFile_, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error 404, file not found in loadData function." << std::endl;
		exit(1);
	}
	std::string aux = "";
	while (!file.eof()) {
		file >> aux;
		if (isalpha(aux[0])) {
			data_ += aux + " ";
		}
	}
	file.close();
}

/**
 * @brief      Prints data var.
 */
void PreProcesser::printData  (void) {
	std::cout << data_;
}

/**
 * @brief      Stores the data into the given file
 *
 * @param      outputFile  The output file
 */
void PreProcesser::storeData(std::string& outputFile) {
	std::ofstream file(outputFile, std::ios::in);
	if (file.fail()) {
		std::cout << "Error while storing data, not valid document" << std::endl;
		exit(1);
	} 
	else { 
		file << data_;
	}
	file.close();
}