#include <fstream>
#include "Utils.h"
#include <string>
#include <sstream>

ConfigParameters FileUtils::getConfigFromFile()
{
    std::ifstream filestream(FileUtils::configFilePath);

    /// Using 5 as some default value.
    int _numberOfSlownDown, _numberOfObstacles = 5;
    if (filestream.is_open())
    {
        std::string line;
        while (std::getline(filestream, line))
        {
            std::istringstream linestream(line);
            std::string key, value;
            linestream >> key >> value;
            if (key == FileUtils::numberOfSlownDownKey)
            {
                _numberOfSlownDown = std::stoi(value);
            }
            else if (key == FileUtils::numberOfObstaclesKey)
            {
                _numberOfObstacles = std::stoi(value);
            }
        }
    }
    return ConfigParameters(_numberOfSlownDown, _numberOfObstacles);
}
