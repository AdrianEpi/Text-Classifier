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
* @Last Modified time: 2021-05-10 11:52:47
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
	//std::cout << std::endl << data_ << std::endl;
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
std::vector<Vocabulary> Classifier::get_LearnedData (void) const {
	return learnedData_;
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
 * @param[in]  newLearnedData  The new learned data
 */
void Classifier::set_LearnedData (std::vector<Vocabulary> newLearnedData) {
	learnedData_ = newLearnedData;
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
	preProcess(stopWord, tmp);
	std::string helper = "../outputs/preProcesserHelper.txt";
	std::ifstream file(helper, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error 404, corpus_test file not found." << std::endl;
		exit(1);
	}
	
	//preProcess(stopWord, tmp);
/*
	while (!file.eof()) {
		tmp = "";
		std::getline(file, tmp);
		std::cout << tmp;
		std::vector<std::string> sentence; 
		std::string word = "";
		bool isWord = false;
		for (unsigned i = 0; i < tmp.length(); i++) {
			if (tmp[i] != ' ') {
				isWord = true;
				word += tmp[i];
			}
			else if (isWord) {
				isWord = false;
				sentence.push_back(word);
				word = "";
			}
		}
		break;
		std::cout << sentence.size() << std::endl;
		//classify(sentence);
	}*/
	file.close();
}

/**
 * @brief      Classifies a given sentence into the correct type and stores into data
 *
 * @param[in]  sentence  The sentence
 */
void Classifier::classify (std::vector<std::string> sentence) {
	std::vector<float> prob;
	prob.resize(learnedData_.size());
	//data += ""
	for (unsigned i = 0; i < prob.size(); i++) {
		prob[i] = 0.0;
	}
	std::set<Token>::iterator it;
	for (unsigned i = 0; i < sentence.size(); i++) {
		data_ += sentence[i] + " ";
		for (unsigned j = 0; j < learnedData_.size(); j++) {
			it = learnedData_[j].get_Vocabulary().find(sentence[i]);
			prob[j] += it -> get_Probability();
		}
	}
	data_ += ", ";
	unsigned selection = 0;
	for (unsigned i = 0; i < prob.size(); i++) {
		prob[i] += learnedData_[i].get_ClassProbability();
		if (prob[selection] < prob[i]) {
			selection = i;
		}
		data_ += std::to_string(prob[i]);
		data_ += ", ";
	}
	data_ += learnedData_[selection].get_Type();
	data_ += ".\n";
	std::cout << data_;
}

/**
 * @brief      Generates and adds the class probabilities to each class with the
 *             following formula: ln(classLinesAmmount / totalLinesAmmout)
 */
void Classifier::generateClassProbability (void) {
	int totalLines = 0;
	for (unsigned i = 0; i < learnedData_.size(); i++) {
		totalLines += learnedData_[i].get_NLines();
	}
	for (unsigned i = 0; i < learnedData_.size(); i++) {
		learnedData_[i].addClassProbability(totalLines);
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
std::vector<std::string> Classifier::preProcess (std::vector<std::string>& stopWords, std::string& sentence) {
	/*preprocesser.convertLowerCase(sentence);
	preprocesser.erasePunctuationSigns(sentence);
	preprocesser.eraseAllNumbers(sentence);
	sentence = preprocesser.eraseReservedWords(sentence, stopWords);
	std::vector<std::string> preProcessedSentence;
	std::string tmp = "";
	bool isWord = false;
	for (unsigned i = 0; i < sentence.length(); i++) {
		if (sentence[i] != ' ') {
			isWord = true;
			tmp += sentence[i];
		}
		else if (isWord) {
			isWord = false;
			preProcessedSentence.push_back(tmp);
			tmp = "";
		}
	}
	return preProcessedSentence;*/
	std::string bb = "../inputs/corpus_test2.csv";
	PreProcesser preprocesser;
	std::string cc = "../inputs/aaa.txt";
	preprocesser.loadTestData(bb);
	preprocesser.convertLowerCase();
	preprocesser.erasePunctuationSigns();
	preprocesser.eraseAllNumbers();
	preprocesser.storeData(cc, 0);
	//sentence = preprocesser.eraseReservedWords(cc, stopWords);
}

/**
 * @brief      Reads input learned files and store the tokens into the learnedData vector.
 *
 * @param      argv  The arguments array
 * @param      argc  The count of arguments
 */
void Classifier::readInputFiles (char* argv[], int& argc) {
	for (int i = 4; i < argc; i++) {
		std::string tmp = argv[i];
		Vocabulary newVocabulary;
		newVocabulary.readLearnedData(tmp);
		learnedData_.push_back(newVocabulary);
	}
}

void Classifier::storeFile (std::string& outputFile) {

}
