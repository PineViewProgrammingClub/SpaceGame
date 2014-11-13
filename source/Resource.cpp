#define _CRT_SECURE_NO_DEPRECATE
#include "Resource.h"
#include "lodepng.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Shader* loadShader(std::string fileName){
	std::cout << "Loading shader: " << fileName << "..." << std::endl;
	std::string line;
	std::string vertString;
	std::ifstream vertFile(fileName + ".vert");
	std::cout << "\tLoading vertex shader...\t";
	if (vertFile.is_open())
	{
		while (getline(vertFile, line))
		{
			vertString.append(line);
			vertString.append("\n");
		}
		vertFile.close();
		std::cout << "Done." << std::endl;
	} else {
		std::cout << "Unable to open vert file";
	}
	std::string fragString;
	std::ifstream fragFile(fileName + ".frag");
	std::cout << "\tLoading fragment shader...\t";
	if (fragFile.is_open())
	{
		while (getline(fragFile, line))
		{
			fragString.append(line);
			fragString.append("\n");
		}
		fragFile.close();
		std::cout << "Done." << std::endl;
	} else {
		std::cout << "Unable to open frag file";
	}
	std::cout << "Done." << std::endl;
	return new Shader(vertString.c_str(), fragString.c_str());
}
