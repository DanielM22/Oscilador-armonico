#include<iostream>
#include<math.h>
#include<cmath>
#define pi 2*acos(0)

using namespace std;

//Función factorial
double factorial(double x){

  double fact=1;
  for (int i=1; i<=x; i++){
    fact=fact*i;
  }
  return fact;
}

//Polinomios de Hermite
double Hermite(int n, double alpha, double x){
  
  double N,H;
  
  if (n % 2==0.0){
    N=n/2.;
  }
  else{
    N=(n-1)/2.;
  }

  for (int s=0; s<=N; s++){

    H+=(pow(-1,s)*factorial(n)*pow((2*alpha*x),(n-2*s)))/(factorial(s)*factorial(n-2*s));
  }

  return H;

}

//Eigenfunción (phi)
double eigen(int n, double alpha, double x, double H){

  double phi=(sqrt(alpha)/sqrt(sqrt(pi)*pow(2,n)*factorial(n)))*H*exp(-(alpha*alpha*x*x)/2);

  return phi;
}

//Densidad de probabilidad oscilador armóncio clásico
double oas(double A, double x){

  double rho=1/(pi*sqrt((A*A)-(x*x)));
  
  return rho;
}
			  
			  
int main(){

  double n=60;  //Estado de la función
  double h=0.0001;  
  double m=0.2;
  double w=0.05;
  double alpha=sqrt((m*w)/(h));
  double A=1.1*sqrt(((2*n)+1)*(h/(m*w)));  //Amplitud de las oscilaciones
  double x=-A;
  
  //Evaluación de los polinomios de Hermite y de la Eigenfunción para diferentes valores de x
  for(int i=0; i<=10000; i++){
    
    double H=Hermite(n,alpha,x);
    double phi=eigen(n,alpha,x,H);
    double phi_2=phi*phi;
    double rho=oas(A/1.1,x);
    cout<<x<<"\t"<<phi_2<<"\t"<<rho<<endl;
    x=x+(2*A*0.0001);  //Actualuzación de los valores x
  }
  
  return 0;
}
