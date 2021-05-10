/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     token.cpp                                          =
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
* @Date:   2021-04-25 21:00:43
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-05-06 09:03:59
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/token.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Token::Token (void) {
	set_Name("");
	set_Ammount(0);
	set_Probability(0);
	set_Type("");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  name  The name
 */
Token::Token (std::string name) {
	set_Name(name);
	set_Ammount(1);
	set_Probability(0);
	set_Type("");
}

/**
 * @brief      Destroys the object.
 */
Token::~Token (void) {
}

/**
 * @brief      Gets the name.
 *
 * @return     The name.
 */
std::string Token::get_Name(void) const {
	return name_;
}

/**
 * @brief      Gets the ammount.
 *
 * @return     The ammount.
 */
unsigned Token::get_Ammount (void) const {
	return ammount_;
}

/**
 * @brief      Gets the probability.
 *
 * @return     The probability.
 */
float Token::get_Probability (void) const {
	return probability_;
}

/**
 * @brief      Gets the type.
 *
 * @return     The type.
 */
std::string Token::get_Type (void) const {
	return type_;
}

/**
 * @brief      Sets the name.
 *
 * @param[in]  name  The name
 */
void Token::set_Name (std::string name) {
	name_ = name;
}

/**
 * @brief      Sets the ammount.
 *
 * @param[in]  ammount  The ammount
 */
void Token::set_Ammount (unsigned ammount) {
	ammount_ = ammount;
}

/**
 * @brief      Sets the probability.
 *
 * @param[in]  newProbability  The new probability
 */
void Token::set_Probability (float newProbability) {
	probability_ = newProbability;
}

/**
 * @brief      Sets the type.
 *
 * @param[in]  newType  The new type
 */
void Token::set_Type (std::string newType) {
	type_ = newType;
}

/**
 * @brief      Less-than comparison operator.
 *
 * @param[in]  otherToken  The other token
 *
 * @return     The result of the less-than comparison
 */
bool Token::operator< (const Token& otherToken) const {
	return (get_Name() < otherToken.get_Name());
}

/**
 * @brief      Less-than-or-equal comparison operator.
 *
 * @param[in]  otherToken  The other token
 *
 * @return     The result of the less-than-or-equal comparison
 */
bool Token::operator<= (const Token& otherToken) const {
	return (get_Name() <= otherToken.get_Name());
}

/**
 * @brief      Less-than comparison operator.
 *
 * @param[in]  str   The string
 *
 * @return     The result of the less-than comparison
 */
bool Token::operator< (const std::string& str) const {
	return (get_Name() < str);
}

/**
 * @brief      Less-than-or-equal comparison operator.
 *
 * @param[in]  str   The string
 *
 * @return     The result of the less-than-or-equal comparison
 */
bool Token::operator<= (const std::string& str) const {
	return (get_Name() <= str);
}

/**
 * @brief      Greater-than comparison operator.
 *
 * @param[in]  otherToken  The other token
 *
 * @return     The result of the greater-than comparison
 */
bool Token::operator> (const Token& otherToken) const {
	return (get_Name() > otherToken.get_Name());
}

/**
 * @brief      Greater-than-or-equal comparison operator.
 *
 * @param[in]  otherToken  The other token
 *
 * @return     The result of the greater-than-or-equal comparison
 */
bool Token::operator>= (const Token& otherToken) const {
	return (get_Name() >= otherToken.get_Name());
}

/**
 * @brief      Greater-than comparison operator.
 *
 * @param[in]  str   The string
 *
 * @return     The result of the greater-than comparison
 */
bool Token::operator> (const std::string& str) const {
	return (get_Name() > str);
}

/**
 * @brief      Greater-than-or-equal comparison operator.
 *
 * @param[in]  str   The string
 *
 * @return     The result of the greater-than-or-equal comparison
 */
bool Token::operator>= (const std::string& str) const {
	return (get_Name() >= str);
}

/**
 * @brief      Equality operator.
 *
 * @param[in]  otherToken  The other token
 *
 * @return     The result of the equality
 */
bool Token::operator== (const Token& otherToken) const {
	return (get_Name() == otherToken.get_Name());
}

/**
 * @brief      Equality operator.
 *
 * @param[in]  str   The string
 *
 * @return     The result of the equality
 */
bool Token::operator== (const std::string& str) const {
	return (get_Name() == str);
}

/**
 * @brief      Increment operator.
 *
 * @return     The result of the increment
 */
Token& Token::operator++ (void) {
	this -> set_Ammount(get_Ammount() + 1);
	return *this;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  otherToken  The other token
 *
 * @return     The result of the assignment
 */
Token& Token::operator= (const Token& otherToken) {
	this -> set_Name(otherToken.get_Name());
	this -> set_Ammount(otherToken.get_Ammount());
	this -> set_Probability(otherToken.get_Probability());
	this -> set_Type(otherToken.get_Type());
	return *this;
}

/**
 * @brief      Incremetates the ammount in 1.
 */
void Token::incrementate (void) {
	ammount_++;
}

/**
 * @brief      Generates the ln probability of the token.
 *
 * @param[in]  vocSize       The voc size
 * @param[in]  tokenAmmount  The token ammount
 *
 * @return     The ln probability
 */
float Token::generateLogProb (const unsigned& vocSize, const unsigned& tokenAmmount) {
	probability_ = (ammount_ + 1);
	int divider = (vocSize + tokenAmmount);
	probability_ /= divider;
	return std::log(probability_);
}

/**
 * @brief      Prints a token.
 */
void Token::printToken (void) const {
	std::cout << std::endl << "Token Info:" << std::endl << "\t - Name: " << get_Name() << std::endl << "\t - Ammount: " << get_Ammount() << std::endl << "\t - Type: " << get_Type() << std::endl << "\t - Prob: " << get_Probability();
}
