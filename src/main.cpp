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
* @Last Modified time: 2021-04-25 10:41:37
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/vocabulary.hpp"


/*------------------------------------------------*/

std::vector<std::string> loadStopWord (void);

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
	Vocabulary test("../inputs/ecom-train.csv", "../outputs/vocabulary.txt");
	PreProcesser aaa;
	test.preProcessData(aaa, "../inputs/stopWords.txt");
	/*test.loadData();
	std::string aaa = test.get_Data();
	std::vector<std::string> stopWords = loadStopWord();
	test.convertLowerCase(aaa);
	test.erasePunctuationSigns(aaa);
	test.set_Data(aaa);
	std::string www = "../outputs/vocabulary.txt";
	test.storeData(www);
	test.eraseReservedWords(stopWords, www);
	//test.erasePunctuationSigns();
	//test.convertUpperCase();	
	//test.printData();*/
	return 0;
}	

std::vector<std::string> loadStopWord (void) {
	std::vector<std::string> stopWords;
	std::ifstream file("../inputs/stopWords.txt", std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error 404, stopWords file not found." << std::endl;
		exit(1);
	}
	std::string aux = "";
	while (!file.eof()) {
		file >> aux;
		stopWords.push_back(aux);
	}
	file.close();
	return stopWords;
}

