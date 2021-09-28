#pragma once

/*
    compile to shared lib (on MacOS and Linux) with
    g++ -c Geometrie.hpp Kreis.hpp Rechteck.hpp Kreis.cpp Rechteck.cpp
    g++ -shared -o libgeo.dylib Kreis.o Rechteck.o (g++ -shared -o libgeo.so Kreis.o Rechteck.o under linux)

    Anleitung für Visual Studio: https://docs.microsoft.com/de-de/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-160
*/
namespace fhbi {

class Geometrie {
    public:
        virtual double umfang() = 0;
        virtual double inhalt() = 0;
};

}