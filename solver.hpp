#pragma once
#include <iostream>
using namespace std;
#include <complex>

namespace solver
{

    class RealVariable
    {
        private:
            double varA;
            //double varB , varC;

        public:
            RealVariable(const double& num  = 0.0) : varA(num){}
            double getVarA() const {return varA;}   

            const RealVariable operator+(const RealVariable& other) const 
            {
                return RealVariable(varA);
            }

            const RealVariable operator-(const RealVariable& other) const 
            {
                return RealVariable(varA);
            }

            const RealVariable operator== (const RealVariable& other) const
            {
                return RealVariable(varA);
            }

            friend const RealVariable operator+ (const double&, const RealVariable&);
            friend const RealVariable operator+ (const RealVariable&, const double&);
            friend const RealVariable operator- (const double&, const RealVariable&);
            friend const RealVariable operator- (const RealVariable&, const double&);
            friend const RealVariable operator/ (const RealVariable&, const double&);
            friend const RealVariable operator* (const double&, const RealVariable&);
            friend const RealVariable operator* (const RealVariable&, const double&);

            //////////////////////later!!!///////////////////////////////////////
            friend const RealVariable operator== (const RealVariable&,const double&);        
            friend RealVariable operator^ (const RealVariable&, const double&);
            friend ostream& operator<< (ostream& os, const RealVariable&);
            //double operator() (const RealVariable&);
		    //double operator()();
    };


    class ComplexVariable
    {
        private:
        std::complex<double> comp;

        public:
        ComplexVariable(const double& real= 0.0, const double& imag = 0.0) : comp(real, imag){}
        std::complex<double> getComplex() const {return comp;} 

        const ComplexVariable operator+(const ComplexVariable& other) const 
        {
            return other;
        }

        const ComplexVariable operator-(const ComplexVariable& other) const 
        {
            return other;
        }

        const ComplexVariable operator== (const ComplexVariable& other) const
        {
            return other;
        }
        
        friend const ComplexVariable operator+ (const double&, const ComplexVariable&);
        friend const ComplexVariable operator+ (const ComplexVariable&, const double&);
        friend const ComplexVariable operator+ (const ComplexVariable&, std::complex<double>);
        friend const ComplexVariable operator+ (std::complex<double>, const ComplexVariable&);
        friend const ComplexVariable operator- (const double&, const ComplexVariable&);
        friend const ComplexVariable operator- (const ComplexVariable&, const double&);
        friend const ComplexVariable operator/ (const ComplexVariable&, const double&);
        friend const ComplexVariable operator* (const double&, const ComplexVariable&);
        friend const ComplexVariable operator* (const ComplexVariable&, const double&);
        friend const ComplexVariable operator== (const ComplexVariable&,const double&);        
        friend ComplexVariable operator^ (const ComplexVariable&, const double&);
        friend ostream& operator<< (ostream& os, const ComplexVariable&);
        //double operator() (const ComplexVariable&);
		//double operator()();
        //friend ComplexVariable operator"" i(unsigned long long);
    };

    const double solve(RealVariable);
    const std::complex<double> solve(ComplexVariable);
    
}