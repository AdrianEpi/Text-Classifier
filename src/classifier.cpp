/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     classifier.cpp                                     =
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
* @Date:   2021-05-06 08:37:08
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-05-11 23:43:24
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/classifier.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Classifier::Classifier (void) {
	set_Data("");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param      argv  The arguments array
 * @param      argc  The count of arguments
 */
Classifier::Classifier (char* argv[], int& argc) {
	set_Data("");
	readInputFiles(argv, argc);
	generateClassProbability();
	std::string input = argv[2];
	std::string stopWords = argv[3];
	classifyFile(input, stopWords);
	std::cout << std::endl << data_ << std::endl;
}

/**
 * @brief      Destroys the object.
 */
Classifier::~Classifier (void) {
}

/**
 * @brief      Gets the input files.
 *
 * @return     The input files.
 */
std::vector<std::string> Classifier::get_InputFiles (void) const {
	return inputFiles_;
}

/**
 * @brief      Gets the learned data.
 *
 * @return     The learned data.
 */
std::vector<Vocabulary> Classifier::get_Class (void) const {
	return class_;
}

/**
 * @brief      Gets the data.
 *
 * @return     The data.
 */
std::string Classifier::get_Data (void) const {
	return data_;
}

/**
 * @brief      Sets the input files.
 *
 * @param[in]  newInputFiles  The new input files
 */
void Classifier::set_InputFiles (std::vector<std::string> newInputFiles) {
	inputFiles_ = newInputFiles;
}

/**
 * @brief      Sets the learned data.
 *
 * @param[in]  newClass  The new learned data
 */
void Classifier::set_Class (std::vector<Vocabulary> newClass) {
	class_ = newClass;
}

/**
 * @brief      Sets the data.
 *
 * @param[in]  newData  The new data
 */
void Classifier::set_Data (std::string newData) {
	data_ = newData;
}

void Classifier::classifyFile (std::string& inputFile, std::string& stopWordsFile) {

	Vocabulary voc;
	std::vector<std::string> stopWord;
	stopWord = voc.loadStopWord(stopWordsFile);
	std::string tmp;
	std::vector<std::vector<std::string>> data = preProcess(stopWord, inputFile);

	std::string helper = "../outputs/preProcesserHelper.txt";
	std::ifstream file(helper, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error 404, preProcesserHelper.txt file not found in /outputs." << std::endl;
		exit(1);
	}
	while (!file.eof()) {
		std::vector<std::string> sentence; 
		std::string tmp = "";
		while (!file.eof()) {
			file >> tmp;
			if (tmp == "preprocesserendl") {
				break;
			}
			sentence.push_back(tmp);
		}
		classify(sentence);
	}
	file.close();


	
}

/**
 * @brief      Classifies a given sentence into the correct type and stores into data
 *
 * @param[in]  sentence  The sentence
 */
void Classifier::classify (std::vector<std::string> sentence) {
	std::vector<float> prob;
	prob.resize(inputFiles_.size());
	for (unsigned i = 0; i < prob.size(); i++) {
		prob[i] = 0.0;
	}
	std::set<Token>::iterator it;
	for (unsigned i = 0; i < sentence.size(); i++) {
		it = learnedData_.find(sentence[i]);
		for (unsigned j = 0; j < prob.size(); j++) {
			prob[j] += it -> get_MultiClass(j);
		}
	}

	data_ += ", ";
	unsigned selection = 0;
	for (unsigned i = 0; i < prob.size(); i++) {
		prob[i] += class_[i].get_ClassProbability();
		if (prob[selection] < prob[i]) {
			selection = i;
		}
		data_ += std::to_string(prob[i]);
		data_ += ", ";
	}
	data_ += class_[selection].get_Type();
	data_ += ".\n";
}

/**
 * @brief      Generates and adds the class probabilities to each class with the
 *             following formula: ln(classLinesAmmount / totalLinesAmmout)
 */
void Classifier::generateClassProbability (void) {
	int totalLines = 0;
	for (unsigned i = 0; i < class_.size(); i++) {
		totalLines += class_[i].get_NLines();
	}
	for (unsigned i = 0; i < class_.size(); i++) {
		class_[i].addClassProbability(totalLines);
	}
}

/**
 * @brief      Preprocess the given sentence using the same pre-processing
 *             method as the vocabulary
 *
 * @param      preprocesser  The preprocesser
 * @param      stopWords     The stop words
 * @param      sentence      The sentence
 *
 * @return     A vector with each word of the sentence per vector's place
 */
std::vector<std::vector<std::string>> Classifier::preProcess (std::vector<std::string>& stopWords, std::string& fileName) {
	PreProcesser preprocesser;
	std::string helper = "../outputs/preProcesserHelper.txt";
	preprocesser.loadTestData(fileName);
	preprocesser.convertLowerCase();
	preprocesser.erasePunctuationSigns();
	preprocesser.eraseAllNumbers();
	preprocesser.storeData(helper, 0);
	preprocesser.eraseReservedWords(stopWords, helper);
	std::vector<std::vector<std::string>> preProcessedSentence;
	/*std::ifstream file(helper, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error 404, preProcesserHelper.txt file not found in /outputs." << std::endl;
		exit(1);
	}
	while (!file.eof()) {
		std::vector<std::string> sentence; 
		std::string tmp = "";

		while (!file.eof() && tmp != "preprocesserendl") {
			file >> tmp;
			sentence.push_back(tmp);
		}
		preProcessedSentence.push_back(sentence);
	}
	file.close();*/
	return preProcessedSentence;
}

/**
 * @brief      Reads input learned files and store the tokens into the Class vector.
 *
 * @param      argv  The arguments array
 * @param      argc  The count of arguments
 */
void Classifier::readInputFiles (char* argv[], int& argc) {
	std::vector<Token> v_;
	for (int k = 4; k < argc; k++) {
		std::string fileName = argv[k];
		inputFiles_.push_back(fileName);
		std::string type = "";
		type += fileName[fileName.length() - 5];
		std::ifstream file(fileName, std::ios::in);
		if (file.fail()) {
			std::cout << std::endl << "Error 404," << fileName << " file not found." << std::endl;
			exit(1);
		}
		else if (k == 4) {
			std::string reader = "";
			file >> reader >> reader >> reader >> reader >> reader >> reader;
			Vocabulary newVoc;
			newVoc.set_NLines(std::stoi(reader));
			newVoc.set_Type(type);
			class_.push_back(newVoc);
			std::getline(file, reader);
			while (!file.eof()) {
				file >> reader >> reader;
				Token newToken(reader);
				file >> reader >> reader >> reader >> reader;
				newToken.addClassProb(std::stof(reader), type);
				newToken.set_Type(type);
				v_.push_back(newToken);
			}
		}
		else {
			int i = 0;
			std::string reader = "";
			file >> reader >> reader >> reader >> reader >> reader >> reader;
			Vocabulary newVoc;
			newVoc.set_NLines(std::stoi(reader));
			newVoc.set_Type(type);
			class_.push_back(newVoc);
			std::getline(file, reader);
			while (!file.eof()) {
				file >> reader >> reader >> reader >> reader >> reader >> reader;
				v_[i].addClassProb(std::stof(reader), type);
				i++;
			}
		}
		file.close();
	}
	for (unsigned i = 0; i < v_.size(); i++) {
		learnedData_.insert(v_[i]);
	}
}

void Classifier::storeFile (std::string& outputFile) {

}
