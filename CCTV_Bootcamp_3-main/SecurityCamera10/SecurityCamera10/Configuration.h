#pragma once
#include <nlohmann/json.hpp>
#include "config.h"

struct configData {
	int cameraThreshold;
	int queueSize;
	std::string cameraIP;
	int cameraPort;
	std::string backendIP;
	int backendPort;
};

class configFile
{
private:
	static configFile* instanceJsonFile;
	configFile() { ReadJson(CONFIGFILE); };
	void ReadJson(std::string path);
public:
	configData data;
	static configFile* getInstance();
	configFile(const configFile& obj) = delete;
	void operator=(const configFile&) = delete;
};