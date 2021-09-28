#include<iostream>
#include<stdexcept>

#include<fstream>

class FileStats{
    private:
        int numberOfLines;
        int isBinary;
        std::fstream f;
    public:
        FileStats(std::string filename) {
            f.open(filename);
            if(!f.is_open()) {
                throw std::runtime_error("Could not open file " + filename);
            }
        }
        int getNumberOfLines() { 
            return numberOfLines; 
        }
};

int main() {
    std::string x;
    std::cout << "bitte Dateiname eingeben" << std::endl;
    while(true) {
        std::cin >> x;
        try{
            FileStats fs(x);
            std::cout << "Anzahl Zeilen: " << fs.getNumberOfLines() << std::endl;
        } catch(std::runtime_error e) {
            //fehlerbehandlung hier
            std::cout << "error: " << e.what() << std::endl;
            std::cout << "bitte erneut Dateiname eingeben" << std::endl;
        }
    }
}