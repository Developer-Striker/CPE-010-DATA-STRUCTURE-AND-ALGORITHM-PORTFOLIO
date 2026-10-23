    #include <iostream>

    class Triangle {
        private:
            double totalAngle, angleA, angleB, angleC;

        public:
            Triangle(double A, double B, double C);
            const bool validateTriangle();
            void setAngles(double A, double B, double C);
    };

    int main() {

    Triangle setl(40, 20, 110);
        if(setl.validateTriangle()) {
            std::cout << "------------------------------" << std::endl;
            std::cout << "the shape is a valid triangle.\n";
            std::cout << "------------------------------" << std::endl;
        } else {
            std::cout << "----------------------------------" << std::endl;
            std::cout << "The shape is NOT a valid triangle. \n";
            std::cout << "----------------------------------" << std::endl;
        }

        return 0;
    }

    Triangle::Triangle(double A, double B, double C){
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A + B + C;
    }

    void Triangle::setAngles(double A, double B, double C){
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A+B+C;
    }

    const bool Triangle::validateTriangle(){
        return (totalAngle <= 180);
    }



