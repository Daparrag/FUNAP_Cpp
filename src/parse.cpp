#include <parse.h>



/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */
parse::parse() {

	parse::reader.open("C:/Users/guzman/eclipse-workspace/Funproject/src/test_tokens.txt"); /*fixeme*/
	if(!parse::reader){
			std::cout << "Cant open default file"<<std::endl;
		}
}



/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */

parse::parse(char const * fname){

	parse::reader.open(fname);
	if(!parse::reader){
		std::cout << "Cant open "<<fname<<std::endl;
	}
}


/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */
parse::~parse() {
	// TODO Auto-generated destructor stub

}


/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */

bool parse::isdelim_t(char &c)
{

	if(std::strchr(" ,(){}=;+-*/<>!" , c)  || c == '\0'|| c == '\n'
					|| c == '\r' || c == '\t' )
	{
		return true;
	}
	return false;

}

/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */
bool parse::isapha_t(char &c)
{
	if(isalpha(c)){
		return true;
	}

	return false;
}

/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */
bool parse ::isdigit_t(char &c)
{

	if(std::isdigit (c) ){
		return true;
	}

	return false;
}

bool parse::isspace_t(char &c){

	if(std::isspace(c)){

		return true;
	}
	return false;

}

void parse::consume_token()
{
	auto c = '\0';
	parse::reader.get(c);

}

void parse::error_token()
{
	while(true);
}

/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */
bool parse::nextToken(){
	auto c = '\0';
	auto next_c ='\0';
	auto tmp_token = Tokens::NONE;
	parse::reader.get(c);
	if(parse::reader.eof()) return false;
	//while(parse::isspace_t(c))parse::reader.get(c); // Skip over white space.

	if(isdelim_t(c)){

		switch (c){
			case '/':
			{
				next_c = parse::reader.peek();
				switch (next_c){
					case '/':
					{
						/* line comment*/
						parse::reader.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
						std::cout << "Line Comment" << std::endl;
					}
					break;
					case '*':
					{
						/* block comment*/
						while(true){
							parse::reader.ignore(std::numeric_limits<std::streamsize>::max(),'*');
							if((next_c = parse::reader.peek()  ) == '/'
									|| parse::reader.eof())
							{
								if(parse::reader.eof())
								{
									std::cout << "Error Block Comment" << std::endl;
									break;
								}
								std::cout << "Block Comment" << std::endl;
								consume_token();
								break;
							}
						}
					}
					break;
					default:
					{
						tmp_token = Tokens::DIV;
						std::cout<<"TOKEN : DIV" << std::endl;
					}
					break;
				}

			}
			break;
			case '=':
			{
				next_c = parse::reader.peek();

				if(next_c == '='){
					// boolean Equal
					tmp_token = Tokens::ISEQ;
					consume_token();
					std::cout<<"TOKEN : ISEQ" << std::endl;
				}else{
					// Equal
					tmp_token = Tokens::EQ;
					std::cout<<"TOKEN : EQ" << std::endl;
				}
			}
			break;

			case '!':
			{
				next_c = parse::reader.peek();
				if(next_c == '='){
					// IsDiferent
					tmp_token = Tokens::ISDIFF;
					consume_token();
					std::cout<<"TOKEN : ISDIFF" << std::endl;
				}else
				{
					//Not
					tmp_token = Tokens::NOT;
					std::cout<<"TOKEN : NOT" << std::endl;
				}
			}
			break;

			case '<':
			{
				next_c = parse::reader.peek();
				if(next_c == '='){
					//LESS OR EQUAL
					tmp_token = Tokens::LTE;
					consume_token();
					std::cout<<"TOKEN : LTE" << std::endl;
				}else{
					//LESS
					tmp_token = Tokens::LT;
					std::cout<<"TOKEN : LT" << std::endl;
				}
			}
			break;

			case '>':
			{
				next_c = parse::reader.peek();
				if(next_c == '='){
					//GREATER OR EQUAL
					tmp_token = Tokens::GTE;
					consume_token();
					std::cout<<"TOKEN : GTE" << std::endl;
				}else{
					//GREATER
					tmp_token = Tokens::GT;
					std::cout<<"TOKEN : GT" << std::endl;
				}
			}
			break;
			case ',':
			{
				tmp_token = Tokens::COMMA;
				std::cout<<"TOKEN : COMMA" << std::endl;
			}
			break;
			case '(':
			{
				tmp_token = Tokens::OBRA;
				std::cout<<"TOKEN : OBRA" << std::endl;
			}
			break;
			case ')':
			{
				tmp_token = Tokens::CBRA;
				std::cout<<"TOKEN : CBRA" << std::endl;

			}
			break;
			case ';':
			{
				tmp_token = Tokens::SEMICOL;
				std::cout<<"TOKEN : SEMICOL" << std::endl;
			}
			break;
			case '+':
			{
				tmp_token = Tokens::ADD;
				std::cout<<"TOKEN : ADD" << std::endl;
			}
			break;
			case '-':
			{
				tmp_token = Tokens::SUB;
				std::cout<<"TOKEN : SUB" << std::endl;

			}
			break;
			case '*':
			{
				tmp_token = Tokens::MUL;
				std::cout<<"TOKEN : MUL" << std::endl;
			}
			break;
			case '{':
			{
				tmp_token = Tokens::OCURL;
				std::cout<<"TOKEN : OCURL" << std::endl;
			}
			break;
			case '}':
			{
				tmp_token = Tokens::CCURL;
				std::cout<<"TOKEN : CCURL" << std::endl;
			}
			break;
			default:{
				tmp_token = Tokens::NONE;
				//std::cout<<"TOKEN : NONE" << std::endl;
			}




		}



//		if(c=='/'){
//			next_c = parse::reader.peek();
//			if(next_c == '/'){
//					parse::reader.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//					return true;
//			}else if(next_c == '*'){
//				while(true){
//					parse::reader.ignore(std::numeric_limits<std::streamsize>::max(),'*');
//					if((next_c = parse::reader.peek()  ) == '/'
//							|| parse::reader.eof())
//					{
//						consume_token();
//						return true;
//					}
//				}
//			}else{
//
//				std::cout<<"TOKEN : DIV = " << c <<std::endl;
//			}
//		}else if(c ==' ' || c == '\0'|| c == '\n'
//				|| c == '\r' || c == '\t' ){
//			/*ignore*/
//			}
//
//		//std::cout << "DELIMITER : " << c << std::endl;
	}
	return true;
}
