#include <iostream>
#include <fstream>

void replace(std::string sourceFileName, std::string toBeReplaced, std::string toReplaceWith)
{
    std::ifstream sourceFile(sourceFileName.c_str());
    if (sourceFile.is_open())
    {
        std::ofstream targetFile(sourceFileName.append(".replace").c_str());

        std::string line;
        while (getline(sourceFile, line))
        {
            size_t foundIndex = line.find(toBeReplaced);
            if (foundIndex == std::string::npos)
                targetFile << line << std::endl;
            else
            {
                while (1)
                {
                    std::string firstChunk = line.substr(0, foundIndex);
                    std::string secondChunk = line.substr(foundIndex + toBeReplaced.size(), line.size());
                    targetFile << firstChunk << toReplaceWith;

                    line = secondChunk;
                    foundIndex = line.find(toBeReplaced);
                    if (foundIndex == std::string::npos)
                    {
                        targetFile << secondChunk;
                        break;
                    }
                }
                targetFile << std::endl;
            }
        }
        targetFile.close();
    }
    else
        std::cerr << "Error: Unable to open sourceFile" << std::endl;
    sourceFile.close();
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Error: arguments" << std::endl;
        return (1);
    }
    else
        replace(argv[1], argv[2], argv[3]);
    return (0);
}