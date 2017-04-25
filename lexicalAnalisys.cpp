#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <regex>
//#include "my_regex.cpp"
#include "classes.h"

using namespace std;
vector < Row > tokensList;
ofstream output("tokenList.txt");


regex importReg ("import");
regex fileNameReg ("([.]?/\\w+)*\\w+[.]\\w+");
regex intReg ("int");
regex floatReg ("float");
regex charReg ("char");
regex stringReg ("string");
regex voidReg ("void");
regex boolReg ("bool");
regex openParenReg ("\\(");
regex closeParenReg ("\\)");
regex openBracketReg ("\\{");
regex closeBracketReg ("\\}");
regex openSqBraReg ("\\[");
regex closeSqBraReg ("\\]");
regex andReg ("&&");
regex orReg ("||");
regex negReg ("!");
regex plusReg ("\\+");
regex minusReg ("-");
regex crossReg ("\\*");
regex divideReg ("/");
regex lessReg ("<");
regex greaterReg (">");
regex lessEqualReg ("<=");
regex greaterEqualReg (">=");
regex differentReg ("!=");
regex equalequalReg ("==");
regex diffStringReg ("!!=");
regex eqeqStringReg ("=\\.=");
regex equalReg ("=");
regex commaReg (",");
regex semiColonReg (";");
regex colonReg (":");
regex returnReg ("return");
regex breakReg ("break");
regex ifReg ("if");
regex elseIfReg ("else\\sif");
regex elseReg ("else");
regex switchReg ("switch");
regex caseReg ("case");
regex mainReg ("main");
regex whileReg ("while");
regex forReg ("for");
regex doReg ("do");
regex IDReg ("[a-zA-Z_]\\w*");
regex floatNReg ("[-]?\\d+(\\.\\d+)?");
regex intNReg ("[-]?\\d+");
regex stringSReg ("\".*\"");
regex charCReg ("'.'");

string IAmA (string me){
	if (regex_match (me, importReg)){
		return "importR";
	}
	else if (regex_match (me, returnReg)){
		return "return";
	}
	else if (regex_match (me, breakReg)){
		return "break";
	}
	else if (regex_match (me, ifReg)){
		return "if";
	}
	else if (regex_match (me, elseIfReg)){
		return "else if";
	}
	else if (regex_match (me, elseReg)){
		return "else";
	}
	else if (regex_match (me, switchReg)){
		return "switch";
	}
	else if (regex_match (me, caseReg)){
		return "case";
	}
	else if (regex_match (me, mainReg)){
		return "main";
	}
	else if (regex_match (me, whileReg)){
		return "while";
	}
	else if (regex_match (me, forReg)){
		return "for";
	}
	else if (regex_match (me, doReg)){
		return "do";
	}
	else if (regex_match (me, intReg)){
		return "intR";
	}
	else if (regex_match (me, floatReg)){
		return "floatR";
	}
	else if (regex_match (me, charReg)){
		return "charR";
	}
	else if (regex_match (me, stringReg)){
		return "stringR";
	}
	else if (regex_match (me, boolReg)){
		return "boolR";
	}
	else if (regex_match (me, voidReg)){
		return "voidR";
	}
	else if (regex_match (me, openParenReg)){
		return "(";
	}
	else if (regex_match (me, closeParenReg)){
		return ")";
	}
	else if (regex_match (me, openBracketReg)){
		return "{";
	}
	else if (regex_match (me, closeBracketReg)){
		return "}";
	}
	else if (regex_match (me, openSqBraReg)){
		return "[";
	}
	else if (regex_match (me, closeSqBraReg)){
		return "]";
	}
	else if (regex_match (me, andReg)){
		return "&&";
	}
	else if (regex_match (me, orReg)){
		return "||";
	}
	else if (regex_match (me, negReg)){
		return "!";
	}
	else if (regex_match (me, plusReg)){
		return "+";
	}
	else if (regex_match (me, minusReg)){
		return "-";
	}
	else if (regex_match (me, crossReg)){
		return "*";
	}
	else if (regex_match (me, divideReg)){
		return "/";
	}
	else if (regex_match (me, lessReg)){
		return "<";
	}
	else if (regex_match (me, greaterReg)){
		return ">";
	}
	else if (regex_match (me, lessEqualReg)){
		return "<=";
	}
	else if (regex_match (me, greaterEqualReg)){
		return ">=";
	}
	else if (regex_match (me, differentReg)){
		return "!=";
	}
	else if (regex_match (me, equalequalReg)){
		return "==";
	}
	else if (regex_match (me, diffStringReg)){
		return "!!=";
	}
	else if (regex_match (me, eqeqStringReg)){
		return "=.=";
	}
	else if (regex_match (me, equalReg)){
		return "=";
	}
	else if (regex_match (me, commaReg)){
		return ",";
	}
	else if (regex_match (me, semiColonReg)){
		return ";";
	}
	else if (regex_match (me, colonReg)){
		return ";";
	}
	else if (regex_match (me, IDReg)){
		return "id";
	}
	else if (regex_match (me, intNReg)){
		return "int";
	}
	else if (regex_match (me, floatNReg)){
		return "float";
	}
	else if (regex_match (me, stringSReg)){
		return "string";
	}
	else if (regex_match (me, charCReg)){
		return "char";
	}
	else if (regex_match (me, fileNameReg)){
		return "fileNameR";
	}
	else{
		return "error";
	}
}




void wordProcessor(string word, int lineN, vector < Row > &tokensList) {
	//cout << "\t" << "word: " << " ==> |" << word << "|" << endl;
	int length = word.size();
	for (; length > 0; --length) {
		string lexeme = word.substr(0,length);
		string token = IAmA(lexeme);
		//cout << "\t\t" << "lexeme: " << " ==>" << lexeme << endl;
		if (token != "error") {
			//cout << "\t\t\t" << "lexeme: " << lexeme << "  token: " << token << endl;
			Row newRow(token, lexeme, lineN);
			tokensList.push_back(newRow);
			word = word.substr(length);
			length = word.size();
			++length;
			int r = 40 - token.size();
			string tokenToFile = token + string(r, ' ');
			r = 40 - lexeme.size();
			string lexemeToFile = lexeme + string(r, ' ');
			string item = tokenToFile + lexemeToFile + to_string(lineN) + '\n';
			output << item; 
			//cout << "\t\t\t\t" << "word: " << word << endl;
		}
	}
}

void lineProcessor(string line, int lineN, vector < Row > &tokensList) {
	string word;
	//cout << "line: " << lineN << " ==>" << line << endl; 
	size_t p;
	for ( ;line != ""; line = line.substr(p + 1)) {
		p = line.find(" ");
		if (p != string::npos) {
			word = line.substr(0 , p);
			if (word != "")	wordProcessor(word, lineN, tokensList);
		}
		else {
			wordProcessor(line, lineN, tokensList);
			break;
		}
	}
}

void showTable(){
	for(int i=0; i<tokensList.size(); i++){
		cout <<"line:<" <<tokensList[i].line<<">";
		cout <<" token:<" <<tokensList[i].token<<">";
		cout <<" lexema:<" <<tokensList[i].lexema<<">"<< endl;
	}
}

string preProcess(string line) {
	for (int i = 0; i < line.size(); ++i) {
		if (line[i] == '\t') {
			line[i] = ' ';
		}
	}
	return line;
}

void readFile (string file){
	ifstream input(file);
	int lineN = 1;
	for(string line; getline(input, line); lineN++){
		line = preProcess(line);
	    lineProcessor(line, lineN, tokensList);
	}
}

int main(int argc, char const *argv[]) {
	if (argc < 2)
	{
		return 1;
	}
	string file(argv[1]);
	readFile(file);
	showTable();
	return 0;
}