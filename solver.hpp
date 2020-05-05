#pragma once
#include <iostream>
#include <complex>

using namespace std;

namespace solver
{

    class RealVariable
    {
        private:
            double A, B, C;    //Ax^2+B*x+C
            bool start;        //true if the var after init

        public:

            //Default constructor
            RealVariable(const double& a=0.0, const double& b=0.0 ,const double& c=0.0
                        ,bool afterInit=false) 
                        : A(a), B(b), C(c),start(afterInit){}

            //Getters && Setters for using in solve method
            double getA() const {return A;}
            double getB() const {return B;}
            double getC() const {return C;}  
            void setA(const double& a) {A += a;}
            void setB(const double& b) {B += b;}
            void setC(const double& c) {C += c;}
            bool getStart() const {return start;} 

            //friend const RealVariable operators
            friend const RealVariable operator+ (const RealVariable&, const RealVariable&);
            friend const RealVariable operator+ (const double&, const RealVariable&);
            friend const RealVariable operator+ (const RealVariable&, const double&);
            friend const RealVariable operator- (const RealVariable&, const RealVariable&);
            friend const RealVariable operator- (const double&, const RealVariable&);
            friend const RealVariable operator- (const RealVariable&, const double&);
            friend const RealVariable operator/ (const RealVariable&, const double&);
            friend const RealVariable operator* (const double&, const RealVariable&);
            friend const RealVariable operator* (const RealVariable&, const double&);
            friend const RealVariable operator* (const RealVariable&, const RealVariable&);
            friend const RealVariable operator== (const RealVariable&,const double&);
            friend const RealVariable operator== (const RealVariable&, const RealVariable&);
            friend const RealVariable operator== (const double&, const RealVariable&);
            friend RealVariable operator^ (const RealVariable&, const double&);
    };
    const double solve(RealVariable);





    class ComplexVariable
    {
        private:
        std::complex<double> comp;   
        double A,B,C;       //Ax^2+B*x+C
        bool start;

        public:
        //Default constructor
        ComplexVariable(const double& a  = 0.0, const double& b  = 0.0 ,const double& c  = 0.0
            ,const double& real= 0.0, const double& imag = 0.0, bool afterInit=false) 
                : A(a), B(b), C(c), comp(real , imag), start(afterInit){}


        //Getters && Setters for using in solve method
        double getA() const {return A;}
        double getB() const {return B;}
        double getC() const {return C;}  
        void setA(const double& a) {A += a;}
        void setB(const double& b) {B += b;}
        void setC(const double& c) {C += c;}
        bool getStart() const {return start;}
        std::complex<double> getComplex() const {return comp;} 

        //friend const RealVariable operators
        friend const ComplexVariable operator+ (const ComplexVariable&, const ComplexVariable&);
        friend const ComplexVariable operator+ (const double&, const ComplexVariable&);
        friend const ComplexVariable operator+ (const ComplexVariable&, const double&);
        friend const ComplexVariable operator+ (const ComplexVariable&, std::complex<double>);
        friend const ComplexVariable operator+ (std::complex<double>, const ComplexVariable&);
        friend const std::complex<double> operator+ (const double&, std::complex<double>);
        friend const std::complex<double> operator+ (std::complex<double>, const double&);
        friend const ComplexVariable operator- (const ComplexVariable&, const ComplexVariable&);
        friend const ComplexVariable operator- (const double&, const ComplexVariable&);
        friend const ComplexVariable operator- (const ComplexVariable&, const double&);
        friend const ComplexVariable operator- (const ComplexVariable&, std::complex<double>);
        friend const ComplexVariable operator- (std::complex<double>, const ComplexVariable&);
        friend const std::complex<double> operator- (const double&, std::complex<double>);
        friend const std::complex<double> operator- (std::complex<double>, const double&);
        friend const ComplexVariable operator/ (const ComplexVariable&, const double&);
        friend const ComplexVariable operator* (const double&, const ComplexVariable&);
        friend const ComplexVariable operator* (const ComplexVariable&, const double&);
        friend const ComplexVariable operator* (const ComplexVariable&, std::complex<double>);
        friend const ComplexVariable operator* (std::complex<double>, const ComplexVariable&);
        friend const std::complex<double> operator* (const double&, std::complex<double>);
        friend const std::complex<double> operator* (std::complex<double>, const double&);
        friend const ComplexVariable operator* (const ComplexVariable&, const ComplexVariable&);
        friend const ComplexVariable operator== (const ComplexVariable&,const double&);
        friend const ComplexVariable operator== (const ComplexVariable&, const ComplexVariable&);        
        friend ComplexVariable operator^ (const ComplexVariable&, const double&);
    };
    const std::complex<double> solve(ComplexVariable);


}