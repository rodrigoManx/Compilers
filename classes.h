#include <string>
using namespace std;

struct Row {
	Row(string t, string l, int li){
		token = t;
		lexema = l;
		line = li;
	}
	string token;
	string lexema;
	int line;
};