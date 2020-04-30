#pragma once
#include <iostream>
#include <complex>

using namespace std;

namespace solver
{

    class RealVariable
    {
        private:
            double varA, varB, varC;

        public:
            RealVariable(const double& A  = 0.0, const double& B  = 0.0 ,const double& C  = 0.0) 
                : varA(A), varB(B), varC(C){}
            double getVarA() const {return varA;}
            double getVarB() const {return varB;}
            double getVarC() const {return varC;}  

            friend const RealVariable operator+ (const RealVariable&, const RealVariable&);
            friend const RealVariable operator+ (const double&, const RealVariable&);
            friend const RealVariable operator+ (const RealVariable&, const double&);
            friend const RealVariable operator- (const RealVariable&, const RealVariable&);
            friend const RealVariable operator- (const double&, const RealVariable&);
            friend const RealVariable operator- (const RealVariable&, const double&);
            friend const RealVariable operator/ (const RealVariable&, const double&);
            friend const RealVariable operator* (const double&, const RealVariable&);
            friend const RealVariable operator* (const RealVariable&, const double&);
            friend const RealVariable operator== (const RealVariable&,const double&);
            friend const RealVariable operator== (const RealVariable&, const RealVariable&);   
            friend RealVariable operator^ (const RealVariable&, const double&);
            friend ostream& operator<< (ostream& os, const RealVariable&);
    };


    class ComplexVariable
    {
        private:
        std::complex<double> comp;

        public:
        ComplexVariable(const double& real= 0.0, const double& imag = 0.0) : comp(real, imag){}
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

        const double solve(RealVariable);
        const std::complex<double> solve(ComplexVariable);

}