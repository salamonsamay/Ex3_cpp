#pragma once
#include <iostream>
#include <complex>

using namespace std;

namespace solver
{

    class RealVariable
    {
        private:
            double A, B, C;

        public:
            RealVariable(const double& a  = 0.0, const double& b  = 0.0 ,const double& c  = 0.0) 
                : A(a), B(b), C(c){}
            double getA() const {return A;}
            double getB() const {return B;}
            double getC() const {return C;}  
            void setA(const double& a) {A += a;}
            void setB(const double& b) {B += b;}
            void setC(const double& c) {C += c;}

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
            friend ostream& operator<< (ostream& os, const RealVariable&);
    };
    const double solve(RealVariable);





    class ComplexVariable
    {
        private:
        std::complex<double> comp;
        double A,B,C;
        public:
        ///ComplexVariable(const double& real= 0.0, const double& imag = 0.0) : comp(real, imag){}
        ComplexVariable(const double& a  = 0.0, const double& b  = 0.0 ,const double& c  = 0.0
            ,const double& real= 0.0, const double& imag = 0.0) 
                : A(a), B(b), C(c),comp(real , imag){}

        double getA() const {return A;}
        double getB() const {return B;}
        double getC() const {return C;}  
        void setA(const double& a) {A += a;}
        void setB(const double& b) {B += b;}
        void setC(const double& c) {C += c;}
        std::complex<double> getComplex() const {return comp;} 

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
        friend ostream& operator<< (ostream& os, const ComplexVariable&);
        //friend ComplexVariable operator"" i(unsigned long long);
    };
    const std::complex<double> solve(ComplexVariable);

}