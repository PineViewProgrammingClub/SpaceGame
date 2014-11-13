#include <iostream>

void Resource::loadShader(std::string fileName){
	std::cout << "Loading shader: " << fileName << "..." << std::endl;
	std::string line;
	std::string vertString;
	std::ifstream vertFile(globalPrefix + shaderPrefix + fileName + vertSuffix + shaderSuffix);
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
	std::ifstream fragFile(globalPrefix + shaderPrefix + fileName + fragSuffix + shaderSuffix);
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
	shaders[fileName] = new Shader(vertString.c_str(), fragString.c_str());
	shaderNames.push_back(fileName);
}