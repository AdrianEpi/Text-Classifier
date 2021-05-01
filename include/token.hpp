/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     token.hpp                                          =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <cstring>
#include <iostream>
#include <cmath>

/*------------------------------------------------*/

/**
 * @brief      This class describes a token.
 */
class Token {

	private:
		// Attributes
		std::string name_;	// The token name
		unsigned ammount_;	// The ammount of times that the token apears in corpus
		float probability_;	// The probability of the token in corpus

	public:
		// Builders & Destroyer
		Token (void);
		Token (std::string name);
		~Token (void);

		// Getters & Setters
		std::string get_Name(void) const;
		unsigned get_Ammount (void) const;
		float get_Probability (void) const;

		void set_Name (std::string name);
		void set_Ammount (unsigned ammount);
		void set_Probability (float newProbability);

		// Operators overload
		bool operator< (const Token& otherToken) const;
		bool operator<= (const Token& otherToken) const;
		bool operator< (const std::string& str) const;
		bool operator<= (const std::string& str) const;
		bool operator> (const Token& otherToken) const;
		bool operator>= (const Token& otherToken) const;
		bool operator> (const std::string& str) const;
		bool operator>= (const std::string& str) const;
		bool operator== (const Token& otherToken) const;
		bool operator== (const std::string& str) const;
		Token& operator++ (void);
		Token& operator= (const Token& otherToken);

		// Function
		void incrementate (void);
		float generateLogProb (const unsigned& vocSize, const unsigned& tokenAmmount);

		// Write
		void printToken (void) const;
};