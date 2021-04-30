/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     main.cpp                                           =
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
* @Date:   2021-04-21 12:55:55
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-04-30 16:35:46
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/vocabulary.hpp"
#include "../include/corpus.hpp"

/*------------------------------------------------*/

void printHelp (void);
void generateVocabulary (int& argc, char* argv[]);
void generateCorpus (int& argc, char* argv[]);

/**
 * @brief      Main function of the program, receives the data file as
 *             parameter.
 *
 * @param[in]  argc  The count of arguments
 * @param      argv  The arguments array
 *
 * @return     0 If program finishes correctly
 */
int main (int argc, char* argv[]) {
	if (argc <= 1) {
		printHelp();
	}
	else {
		std::string flag = argv[1];
		if (flag == "-h" || flag == "--help") {
			printHelp();
		}
		else if (flag == "-v" || flag == "--vocabulary") {
			generateVocabulary(argc, argv);
		}
		else if (flag == "-co" || flag == "--corpus") {
			generateCorpus(argc, argv);
		}
	}
	
	std::cout << std::endl << "Program finished correclty." << std::endl;
	return 0;
}	


/**
 * @brief      Prints help information about how to run and use the program.
 */
void printHelp (void) {
	std::cout << std::endl << "NAME" << std::endl;
	std::cout << "\t textClassifier \t Generates vocabulary, corpus and classifies a text into different types of data." << std::endl;
	
	std::cout << std::endl << "SYNOPSIS" << std::endl;
	std::cout << "\t ./textClassifier [-v | -co | -h] [arg ...]" << std::endl;
	
	std::cout << std::endl << "DESCRIPTION" << std::endl;
	std::cout << "\t Generates vocabulary, corpus and classifies a text into different types of data." << std::endl << std::endl;
	std::cout << "\t Runs the program with the needed flag for generating vocabulary (-v | --vocabulary), generating corpus (-co | --corpus), printin user manual (-h | --help)." << std::endl << std::endl;

	std::cout << "\t Options:" << std::endl;
	std::cout << "\t\t -v \t\t (--vocabulary) generates the vocabulary from the input file into the output file, excluding words in reserved words file." << std::endl;
	std::cout << "\t\t -co\t\t (--corpus) generates one different corpus per each data type received as argument after the input file and the reserved wirds file." << std::endl;
	std::cout << "\t\t -h \t\t (--help) prints the user manual for the program." << std::endl;

	std::cout << "\t Exit Status:" << std::endl;
	std::cout << "\t\t Returns success unless an error occurs" << std::endl << std::endl;

	std::cout << "AUTHOR" << std::endl;
	std::cout << "\t Written by Adrián Epifanio Rodríguez Hernández." << std::endl << std::endl;


	std::cout << "REPORTING BUGS" << std::endl;
	std::cout << "\t Report an issue at <https://github.com/AdrianEpi/Text-Classifier>" << std::endl << std::endl;

	std::cout << "COPYRIGHT" << std::endl;
	std::cout << "\t Copyright (c) 2021 Adrián Epifanio" << std::endl;


    std::cout << "\tPermission is hereby granted, free of charge, to any person obtaining a copy" << std::endl;
    std::cout << "\tof this software and associated documentation files (the \"Software\"), to deal" << std::endl;
    std::cout << "\tin the Software without restriction, including without limitation the rights" << std::endl;
    std::cout << "\tto use, copy, modify, merge, publish, distribute, sublicense, and/or sell" << std::endl;
    std::cout << "\tcopies of the Software, and to permit persons to whom the Software is" << std::endl;
    std::cout << "\tfurnished to do so, subject to the following conditions:" << std::endl << std::endl;

    std::cout << "\tThe above copyright notice and this permission notice shall be included in all" << std::endl;
    std::cout << "\tcopies or substantial portions of the Software." << std::endl << std::endl;

    std::cout << "\tTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR" << std::endl;
    std::cout << "\tIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY," << std::endl;
    std::cout << "\tFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE" << std::endl;
    std::cout << "\tAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER" << std::endl;
    std::cout << "\tLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM," << std::endl;
    std::cout << "\tOUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE" << std::endl;
    std::cout << "\tSOFTWARE." << std::endl << std::endl;	

}

/**
 * @brief      Generates the vocabulary from the first input file and stores it
 *             into second file using the stopwords readed from third file
 *
 * @param      argc  The count of arguments
 * @param      argv  The arguments array
 */
void generateVocabulary (int& argc, char* argv[]) {
	if (argc != 5) {
		std::cout << std::endl << "Error, the program needs 4 arguments to generate the vocabulary:" << std::endl << "\t bin/textClassifier -v originFile outputFile reservedWordsFile" << std::endl;
		exit(1);
	}
	std::string originFile = argv[2];
	std::string outputFile = argv[3];
	std::string reservedWords = argv[4];
	std::string fileHelper = "../outputs/preProcesserHelper.txt";
	Vocabulary vocabulary(originFile, outputFile);
	{
		Chrono chrono;
		chrono.startChrono();
		vocabulary.preProcessData(reservedWords);
		chrono.stopChrono();
		std::cout << std::endl << "Elapsed pre-processing time: " << chrono.get_Seconds(5) << " seconds." << std::endl;
	}
	{
		Chrono chrono;
		chrono.startChrono();
		vocabulary.generateVocabulary(fileHelper, false);
		chrono.stopChrono();
		std::cout << std::endl << "Elapsed generating vocabulary time: " << chrono.get_Seconds(5) << " seconds." << std::endl;
	}
	{
		Chrono chrono;
		chrono.startChrono();
		vocabulary.storeVocabulary(outputFile);
		chrono.stopChrono();
		std::cout << std::endl << "Elapsed storing vocabulary time: " << chrono.get_Seconds(5) << " seconds." << std::endl;
	}
}

/**
 * @brief      Generates one corpus per each type of data received as argument
 *             in console line. The data type must be the first column of the
 *             csv or data file and it should be followed by a ',' on the data
 *             file but not in the command line.
 *
 * @param      argc  The count of arguments
 * @param      argv  The arguments array
 */
void generateCorpus (int& argc, char* argv[]) {
	if (argc < 4) {
		std::cout << std::endl << "Error, the program needs at least 3 arguments to generate the corpus:" << std::endl << "\t bin/textClassifier -co originFile reservedWordsFile CORPUS1 CORPU2 CORPUS3 . . ." << std::endl;
		std::cout << std::endl << "Each \"CORPUS\" represents one data type that wants to be separated into different corpus." << std::endl;
		exit(1);
	}
	std::string originFile = argv[2];
	std::string reservedWords = argv[3];
	PreProcesser preProcesser;
	Vocabulary voc;
	std::vector<std::string> stopWords = voc.loadStopWord(reservedWords);
	for (int i = 4; i < argc; i++) {
		std::string tmp = argv[i];
		Corpus newCorpus(tmp, originFile);
		newCorpus.generateCorpus(stopWords, preProcesser);
	}
}