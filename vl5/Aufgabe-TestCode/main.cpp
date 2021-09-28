#include "Ringspeicher.hpp"
#include "DecimationFilter.hpp"
#include <iostream>
#include <cmath>

//Gibt ein Array auf der Kommandozeile aus. Nur zu Debugzwecken
void printArray(double arr[], int n) {
	for(int i = 0; i < n; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

int main(){

	const int decimation = 2;
	const int windowSize = 5;

	//Sie müssen die Klasse DecimationFilter schreiben!
	DecimationFilter filter(decimation, windowSize);

	//samples erzeugen - dies ist unser gefaketer Messprozess
	const int numSamples = 100;
	double samples[numSamples]; // speichert die "Messdaten"
	for(int i = 0; i < numSamples; i++) {
		samples[i] = sin(0.1*i) + 0.5*sin(0.2*i+10.0);	//zwei überlagerte Sinuskurven
	}

	//samples in Ihren Filter geben
	const int numOutputs = numSamples / decimation;
	double filteroutputs[numOutputs];	// speichert die Ausgabe Ihres Filters
	int j = 0;
	for(int i = 0; i < numSamples; i++) {
		bool outputPresent = filter.addSample(samples[i]);	//addSample gibt true zurück, wenn im Filter ein
															//neuer Output bereit steht
		if(outputPresent) {
			filteroutputs[j++] = filter.getValue();		//auslesen des neuen Outputs, wenn dieser bereit ist
		}
	}

	//debug - ausgabe der "Messdaten" und Ihrer gefilterten Daten auf der Kommandozeile.
	printArray(samples, numSamples);
	printArray(filteroutputs, numOutputs);

	return 0;
}