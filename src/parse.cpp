#include <parse.h>



/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */
parse::parse() {

	parse::reader.open("C:/Users/guzman/eclipse-workspace/Funproject/src/test_comments.txt"); /*fixeme*/
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

	if(std::strchr(" (){}=;+-*/<>!" , c)  || c == '\0'|| c == '\n'
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

/**
* @brief  parse::parse(): parse constructor.
  * @param none.
  * param tClockTime * time_cpy> clock to send
  * @retval none
  */
bool parse::nextToken(){
	auto c = '\0';
	auto next_c ='\0';
	parse::reader.get(c);
	if(parse::reader.eof()) return false;
	//while(parse::isspace_t(c))parse::reader.get(c); // Skip over white space.

	if(isdelim_t(c)){
		if(c=='/'){
			next_c = parse::reader.peek();
			if(next_c == '/'){
					parse::reader.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					return true;
			}else if(next_c == '*'){
				while(true){
					parse::reader.ignore(std::numeric_limits<std::streamsize>::max(),'*');
					if((next_c = parse::reader.peek()  ) == '/'
							|| parse::reader.eof())
					{
						consume_token();
						return true;
					}
				}
			}else{

				std::cout<<"TOKEN : DIV = " << c <<std::endl;
			}
		}else if(c ==' ' || c == '\0'|| c == '\n'
				|| c == '\r' || c == '\t' ){
			/*ignore*/
			}

		//std::cout << "DELIMITER : " << c << std::endl;
	}
	return true;
}
