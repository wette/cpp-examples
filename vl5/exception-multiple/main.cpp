#include<iostream>
#include<stdexcept>

#include<fstream>

class FileNotFoundException: public std::runtime_error {
    public:
        FileNotFoundException(const std::string& s) : std::runtime_error(s){}
};

class DivisionByZeroException: public std::runtime_error {
    public:
        DivisionByZeroException() : std::runtime_error("Division by Zero."){}
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

double computeSomeStatistics(int no) {
    /* durch Null teilen ist nit gut */
    if(no == 0) {
        throw DivisionByZeroException();
    }
    return 1000.0/no;
}

int main() {
    std::string x;
    std::cout << "bitte Dateiname eingeben" << std::endl;
    while(true) {
        std::cin >> x;
        try{
            FileStats fs(x);
            std::cout << "Anzahl Zeilen: " << fs.getNumberOfLines() << std::endl;
            std::cout << "Statistik: " << computeSomeStatistics(fs.getNumberOfLines()) << std::endl;
        } catch(FileNotFoundException &e) {
            //fehlerbehandlung hier
            std::cout << "error: " << e.what() << std::endl;
            std::cout << "bitte erneut Dateiname eingeben" << std::endl;
        } catch(DivisionByZeroException &e) {
            std::cout << "error: Not sufficient data in inputfile to compute statistics!" << std::endl;
        } catch(...) {
            /* hier würden beliebige andere Exceptions behandelt werden! */
            std::cout << "error: Unexpected Exception occured." << std::endl;
        }
    }
}