/*
 * parse.h
 *
 *  Created on: 07.09.2018
 *      Author: guzman
 */

#ifndef PARSE_H_
#define PARSE_H_

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <limits>


	enum class Tokens {
				FUN,		/*fun*/
				RET,		/*return*/
				COMMA,		/*,*/
				OBRA,		/*(*/
				COBRA,		/*)*/
				VAR,		/*var*/
				EQ,			/*=*/
				SEMICOL,	/*;*/
				IF,			/*if*/
				ELSE,		/*else*/
				MAINT,		/*main*/
				PRINT,		/*printLn*/
				FOR,		/*for*/
				BOOLT,		/*bool*/
				BOOTV,		/*true|false*/
				INTT,		/*int*/
				ASYNC,		/*async*/
				ADD,		/*+*/
				SUB,		/*-*/
				MUL,		/* * */
				DIV,		/* / */
				OCURL,		/*{*/
				CCURL,		/*}*/
				ISEQ,		/*==*/
				ISDIFF,		/*!=*/
				LT,			/*!=*/
				LTE,		/*<=*/
				GT,			/*>*/
				GTE,		/*>=*/
				NOT,		/*!*/
				NUMBER,		/*<<([1-9][0-9]*)|0>>*/
				IDEN,		/*<<[a-zA-Z][a-zA-Z0-9]*>>*/
				WHITESPACE,	/*[ \t\n\x0B\f\r| \t\n\r]+*/
				NONE
		};


	class parse {
	public:
		parse();
		parse(char const * fname);
		virtual ~parse();
		bool nextToken();
	private:
		std::ifstream reader;
		std::string tokentype;
		bool isdelim_t(char &c);
		bool isapha_t(char &c);
		bool isdigit_t(char &c);
		bool isspace_t(char &c);
		void consume_token();

	};


#endif /* PARSE_H_ */
