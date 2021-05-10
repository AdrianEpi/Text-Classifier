/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     learner.cpp                                        =
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
* @Date:   2021-05-01 12:27:32
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-05-09 16:50:24
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/learner.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Learner::Learner (void) {
	set_VocabularyFile("");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param      argv  The arguments array
 * @param      argc  The count of arguments
 */
Learner::Learner (char* argv[], int& argc) {
	// Vocabulary file must be in 3rd place as shown in manual
	set_VocabularyFile(argv[2]);
	for (int i = 3; i < argc; i++) {
		Chrono chrono;
		chrono.startChrono();
		std::string tmp = "../outputs/corpus_";
		tmp += argv[i];
		tmp += ".txt";
		Vocabulary newVoc;
		newVoc.readVocabulary(vocabularyFile_);
		newVoc.generateVocabulary(tmp, true);
		learners_.push_back(newVoc);
		inputCorpusFiles_.push_back(argv[i]);
		chrono.stopChrono();
		std::cout << std::endl << "Elapsed generating tokens and vocabulary time: " << chrono.get_Seconds(5) << " seconds for " << argv[i] << " data type." << std::endl;
	}
	learnAndStoreData();
}

/**
 * @brief      Destroys the object.
 */
Learner::~Learner (void) {
}

/**
 * @brief      Gets the learners.
 *
 * @return     The learners.
 */
std::vector<Vocabulary> Learner::get_Learners (void) const {
	return learners_;
}

/**
 * @brief      Gets the input corpus files.
 *
 * @return     The input corpus files.
 */
std::vector<std::string> Learner::get_InputCorpusFiles (void) const {
	return inputCorpusFiles_;
}

/**
 * @brief      Gets the vocabulary file.
 *
 * @return     The vocabulary file.
 */
std::string Learner::get_VocabularyFile (void) const {
	return vocabularyFile_;
}

/**
 * @brief      Sets the learners.
 *
 * @param[in]  newLearners  The new learners
 */
void Learner::set_Learners (std::vector<Vocabulary> newLearners) {
	learners_ = newLearners;
}

/**
 * @brief      Sets the input corpus files.
 *
 * @param[in]  newInputCorpusFiles  The new input corpus files
 */
void Learner::set_InputCorpusFiles (std::vector<std::string> newInputCorpusFiles) {
	inputCorpusFiles_ = newInputCorpusFiles;
}

/**
 * @brief      Sets the vocabulary file.
 *
 * @param[in]  newVocabularyFile  The new vocabulary file
 */
void Learner::set_VocabularyFile (std::string newVocabularyFile) {
	vocabularyFile_ = newVocabularyFile;
}

/**
 * @brief      Generates the proabilities of all the tokens in vocabulary and
 *             stores them in a file called "aprendizaje_DATATYPE.txt".
 *             The file format is:
 *             Number of corpus documents: <integer>
 *             Number of words in corpus: <integer>
 *             Word:<string> Frec:<int> LogProb:<float>
 *             Word:<string> Frec:<int> LogProb:<float>
 *             Word:<string> Frec:<int> LogProb:<float>
 */
void Learner::learnAndStoreData (void) {
	for (unsigned i = 0; i < learners_.size(); i++) {
		Chrono chrono;
		chrono.startChrono();
		std::string fileName = "../outputs/aprendizaje";
		fileName += inputCorpusFiles_[i][0];
		fileName += ".txt";
		//std::string fileName = "../outputs/aprendizaje_" + inputCorpusFiles_[i] + ".txt";
		std::fstream file(fileName, std::ios::out);
		if (file.fail()) {
			std::cout << "Error while storing learned data \"" << fileName << "\" is not valid document" << std::endl;
			exit(1);
		} 
		else {
			int tokenAmmount = learners_[i].get_NTokens();
			int vocSize = learners_[i].get_VocabularyCounter();
			std::string data = "Numero de documentos del corpus: " + std::to_string(learners_[i].get_NLines());
			data += "\nNumero de palabras del corpus: " + std::to_string(tokenAmmount);
			for (auto tmp : learners_[i].get_Vocabulary()) {
				std::string line =  "\nPalabra: " + tmp.get_Name();
				// Tabs for columns
				/*
				while (line.length() < 50) {
					line += " ";
				}
				data += line + "\t\tFrec: " + std::to_string(tmp.get_Ammount()) + "  \t\tLogProb: " + std::to_string(tmp.generateLogProb(vocSize, tokenAmmount));
				*/
				// Without tabs
				data += line + " Frec: " + std::to_string(tmp.get_Ammount()) + " LogProb: " + std::to_string(tmp.generateLogProb(vocSize, tokenAmmount));
			}
			file << data;
			file.close();
		}
		chrono.stopChrono();
		std::cout << std::endl << "Elapsed time for calculating probabilities: " << chrono.get_Seconds(5) << " seconds for " << inputCorpusFiles_[i] << " data type." << std::endl;
	}
}
