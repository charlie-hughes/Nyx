#pragma once

#include <string>
#include <fstream>
#include <sstream>

static std::string GetFileContents(std::string filepath) {
    std::ifstream in(filepath, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}