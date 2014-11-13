#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Shader.h"
#include "Texture.h"
#include <unordered_map>
#include <string>
#include <vector>

class ResourceManager {
private:
	Shader* loadShader(std::string);
};

#endif
