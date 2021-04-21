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
* @Last Modified time: 2021-04-21 14:16:40
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/vocabulary.hpp"


/*------------------------------------------------*/


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
	PreProcesser test("../inputs/ecom-train.csv", "../outputs/vocabulary.txt");
	test.loadData();
	//test.printData();
	return 0;
}	

