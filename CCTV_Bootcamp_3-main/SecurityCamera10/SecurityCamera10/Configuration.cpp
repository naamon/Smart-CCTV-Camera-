#include "Configuration.h"
#include "Logger.h"
#include <fstream>

using json = nlohmann::json;

configFile* configFile::instanceJsonFile = nullptr;

configFile* configFile::getInstance() {
    if (instanceJsonFile == nullptr) {
        instanceJsonFile = new configFile();
    }
    return instanceJsonFile;
}

void configFile::ReadJson(std::string path) {
    json jsonFile;
    std::ifstream file(path);
    if (!file.is_open())
    {
        logger->error("Don't success to find or open json file");
        return;
    }

    else {
        logger->info("try to convert file to json");
        file >> jsonFile;
        logger->info("success to convert file to json");
        file.close();
    }
    json defult = {
        {"cameraThreshold", 3},
        {"queueSize", 5}, 
        {"cameraIP" , "192.168.1.100"},
        {"cameraPort", 8080},
        {"backendIP" , "192.168.1.200"},
        {"backendPort" , 3000}
    };

    data.cameraThreshold = jsonFile.value("cameraThreshold", defult["cameraThreshold"]);
    data.queueSize = jsonFile.value("queueSize", defult["queueSize"]);
    data.cameraIP = jsonFile.value("cameraIP", defult["cameraIP"]);
    data.cameraPort = jsonFile.value("cameraPort", defult["cameraPort"]);
    data.backendIP = jsonFile.value("backendIP", defult["backendIP"]);
    data.backendPort = jsonFile.value("backendPort", defult["backendPort"]);

    logger->info("The config was read from a json file");
}