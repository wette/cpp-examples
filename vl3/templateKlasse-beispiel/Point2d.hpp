 #include<iostream>
 template <typename T>
 class Point2d {
    private:
 	    T x;
 		T y;
 	public:
 	    Point2d(T x, T y) {
 			this->x = x;
            this->y = y;
        }
        void print() {
            std::cout << this->x << ", " << this->y << std::endl;
        }
    T getX() { return this->x; }
    T getY() { return this->y; }
};
