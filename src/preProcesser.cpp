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
* @Last Modified time: 2021-04-25 10:45:19
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
 * @brief      Sets the input file.
 *
 * @param[in]  newInputFile  The new input file
 */
void PreProcesser::set_InputFile (std::string newInputFile) {
	inputFile_ = newInputFile;
}

/**
 * @brief      Sets the output file.
 *
 * @param[in]  newOutputFile  The new output file
 */
void PreProcesser::set_OutputFile (std::string newOutputFile) {
	outputFile_ = newOutputFile;
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
	return *this;
}

/**
 * @brief      Converts all the str into Lower Case
 *
 * @param      str   The string
 */
void PreProcesser::convertLowerCase (std::string& str) {
	set_Data(str);
	convertLowerCase();
	str = get_Data();
}

/**
 * @brief      Converts all the data into Lower Case
 */
void PreProcesser::convertLowerCase (void) {
	std::transform(data_.begin(), data_.end(),data_.begin(), ::tolower);
}

/**
 * @brief      Converts all the str into Upper Case
 *
 * @param      str   The string
 */
void PreProcesser::convertUpperCase (std::string& str) {
	set_Data(str);
	convertUpperCase();
	str = get_Data();
}

/**
 * @brief      Converts all the data into Upper Case
 */
void PreProcesser::convertUpperCase (void) {
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
	set_Data(str);
	erasePunctuationSigns();
	str = get_Data();
}

/**
 * @brief      Erases all punctuation sings into readed data.
 */
void PreProcesser::erasePunctuationSigns (void) {
	std::vector<char> punctuantionSigns = {',', '.', '-', '_', '?', '!', ';', ':', '\'', '\"', '(', ')', '{', '}', '[', ']'};
	for (unsigned i = 0; i < data_.length(); i++) {
		if (!isalpha(data_[i]) && !isdigit(data_[i])) {
			for (unsigned j = 0; j < punctuantionSigns.size(); j++) {
				if (data_[i] == punctuantionSigns[j]) {
					data_[i] = ' ';
					break;
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
	set_Data(str);
	eraseURLs();
	str = get_Data();
}

/**
 * @brief      Erases all URLs into data var, an URL is defined as a '.' between
 *             letters without spaces.
 */
void PreProcesser::eraseURLs (void) {
	for (unsigned i = 0; i < data_.length(); i++) {
		if (data_[i] == '.' && data_[i + 1] != ' ') {
			unsigned k = i;
			while (data_[k] != ' ') {
				data_[k] = ' ';
				k--;
			}
			while (data_[i] != ' ') {
				data_[i] = ' ';
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
	set_Data(str);
	eraseHashtags();
	str = get_Data();
}

/**
 * @brief      Erases all Hashtags into data var.
 *
 */
void PreProcesser::eraseHashtags (void) {
	for (unsigned i = 0; i < data_.length(); i++) {
		if (data_[i] == '#') {
			data_[i] = ' ';
			while (data_[i] != ' ') {
				data_[i] = ' ';
				i++;
			}
		}
	}
}


/**
 * @brief      Loads the data from input file into data var.
 *
 * @param      inputFile  The input file
 */
void PreProcesser::loadData (std::string& inputFile) {
	std::ifstream file(inputFile, std::ios::in);
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
		std::cout << "Error while storing data \"" << outputFile << "\" is not valid document" << std::endl;
		exit(1);
	} 
	else { 
		file << data_;
	}
	file.close();
}