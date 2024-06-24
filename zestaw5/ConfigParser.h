#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include <vector>

struct FigureConfig {
    std::string type;
    int x;
    int y;
    int size1;
    int size2;
    char symbol;
};

class ConfigParser {
public:
    ConfigParser(const std::string &filename);
    void parse();
    int getCanvasWidth() const;
    int getCanvasHeight() const;
    std::string getOutputFile() const;
    char getEmptyPixelSymbol() const;
    const std::vector<FigureConfig>& getFigures() const;

private:
    std::string filename;
    int canvasWidth;
    int canvasHeight;
    std::string outputFile;
    char emptyPixelSymbol;
    std::vector<FigureConfig> figures;
};

#endif // CONFIGPARSER_H
