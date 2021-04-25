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

/*------------------------------------------------*/

/**
 * @brief      This class describes a token.
 */
class Token {

	private:
		// Attributes
		std::string name_;
		unsigned ammount_;

	public:
		// Builders & Destroyer
		Token (void);
		Token (std::string name);
		~Token (void);

		// Getters & Setters
		std::string get_Name(void) const;
		unsigned get_Ammount (void) const;

		void set_Name (std::string name);
		void set_Ammount (unsigned ammount);

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

		// Write
		void printToken (void) const;
};