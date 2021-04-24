#ifndef UTILS_H
#define UTILS_H

struct ConfigParameters
{
    // Constructor
    ConfigParameters(const int numberOfSlownDown,
                     const int numberOfObstacles)
        : _numberOfSlownDown(numberOfSlownDown),
          _numberOfObstacles(numberOfObstacles){};

    // getters
    int getNumberOfSlownDown() const { return _numberOfSlownDown; }
    int getNumberOfObstacles() const { return _numberOfObstacles; }

private:
    int _numberOfSlownDown;
    int _numberOfObstacles;
};

namespace FileUtils
{
    /// Path
    constexpr char configFilePath[] = "../gameConfig/config.txt";

    /// File Keys

    constexpr char numberOfSlownDownKey[] = "numberOfSlownDown";
    constexpr char numberOfObstaclesKey[] = "numberOfObstacles";

    /// Config Parameters
    ConfigParameters getConfigFromFile();
}

#endif // UTILS_H
