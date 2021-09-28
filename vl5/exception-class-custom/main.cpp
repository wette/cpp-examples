#include<iostream>
#include<stdexcept>

#include<fstream>

class FileNotFoundException: public std::runtime_error {
    public:
        FileNotFoundException(const std::string& s) : std::runtime_error(s){}
};

class FileStats{
    private:
        int numberOfLines;
        std::fstream f;
    public:
        FileStats(std::string filename) {
            f.open(filename);
            if(!f.is_open()) {
                throw FileNotFoundException("Could not open file " + filename);
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
        } catch(FileNotFoundException e) {
            //fehlerbehandlung hier
            std::cout << "error: " << e.what() << std::endl;
            std::cout << "bitte erneut Dateiname eingeben" << std::endl;
        }
    }
}