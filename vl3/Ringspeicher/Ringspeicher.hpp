#pragma once
#include<vector>
#include <iostream>

template <class T, int N>
class Ringspeicher {
	private:
		std::vector<T> buffer;
		int i = 0;
    public:
        Ringspeicher() {
          this->buffer = std::vector<T>(N);
	        this->i = 0;
        }
        T operator[](int i) {
          return this->buffer[i];
        }
        void operator+=(T op) {
          this->zahlHinzufuegen(op);
        }
        void zahlHinzufuegen(T zahl) {
          std::cout << "zahl hinzugefügt: " << zahl << std::endl;
	        this->buffer[i] = zahl;
	        this->i = (this->i + 1) % N;
        }
        double gibDurchschnitt() {
          T sum = 0;
          for(int i = 0; i < N; i++) {
            sum += this->buffer[i];
          }
          return sum/double(N);
        }
        T getMinimum() {
          T mini = this->buffer[0];
          for(int i = 1; i < N; i++){
            if(this->buffer[i] < mini) {
              mini = this->buffer[i];
            }
          }
	        return mini;
        }
        T getMaximum() {
          T maxi = this->buffer[0];
          for(int i = 1; i < N; i++){
            if(this->buffer[i] > maxi) {
              maxi = this->buffer[i];
            }
          }
          return maxi;
        }
        void zahlenAusgeben() {
          for(int i = 0; i < N; i++){
		        std::cout << this->buffer[i] << std::endl;
	        }
        }
};