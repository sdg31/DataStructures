#ifndef IOHELPER_HPP
#define IOHELPER_HPP

#include <fstream>
#include <string>
#include <typeinfo>

// there may be a nicer way to do this but I have these recieving a pointer
// for the type that they must return because making it a template would not
// return the character and string interchangeably

inline std::string get(std::ifstream& ifile, std::string* s) {
	std::string wrd;

	if (std::isalpha(ifile.peek()))
		while (std::isalpha(ifile.peek()))
			wrd += ifile.get();

	else if (std::isdigit(ifile.peek()))
		while (std::isdigit(ifile.peek()))
			wrd += ifile.get();

	else
		wrd += ifile.get();

	return wrd;
}


inline char get(std::ifstream& ifile, char* c) {
	return ifile.get();
}

inline std::string get_terminator(std::string* s) {
	static std::string end(1, (char)0xFF);
	return end;
}

inline char get_terminator(char* c) {
	static char end = 0xFF;
	return end;
}

#endif
