/*
    main.cpp - Multilayer Perceptron Main
    Created by Alberto Tudela, March 13 2013
    Under license GPLv3
*/

#include <iostream>
#include <vector>
#include "MLP.hpp"

using namespace std;

int main(){
MLP perce(3, 2, 2, 1);
//MLP perce("redxor.sinapsis");

double errorT;
vector<vector<double> > pentrada(4,vector<double>(2)) , psalida(4,vector<double>(2));
vector<double> yp;


pentrada[0][0]=0; pentrada[0][1]=0; psalida[0][0]=0;
pentrada[1][0]=0; pentrada[1][1]=1; psalida[1][0]=1;
pentrada[2][0]=1; pentrada[2][1]=0; psalida[2][0]=1;
pentrada[3][0]=1; pentrada[3][1]=1; psalida[3][0]=0;

//perce.MostrarPesos(); perce.MostrarUmbrales();
//perce.MostrarActivaciones(); perce.MostrarDeltas();

int rep = perce.Entrenar(pentrada, psalida, errorT, 0.00001);
perce.Guardar("redxor.sinapsis");
perce.MostrarPesos(); perce.MostrarUmbrales();
perce.MostrarActivaciones(); perce.MostrarDeltas();

cout<<"El error Total cometido es: "<<errorT<<" y se ha alcanzado en "<<rep<<" repeticiones."<<endl;
pentrada[0][0]=0; pentrada[0][1]=0; psalida[0][0]=0; yp=perce.Activar(pentrada[0]);
cout<<"Para el vector ("<<pentrada[0][0]<<","<<pentrada[0][1]<<") -> y= "<<(yp[0])<<endl;
pentrada[1][0]=0; pentrada[1][1]=1; psalida[1][0]=1; yp=perce.Activar(pentrada[1]);
cout<<"Para el vector ("<<pentrada[1][0]<<","<<pentrada[1][1]<<") -> y= "<<(yp[0])<<endl;
pentrada[2][0]=1; pentrada[2][1]=0; psalida[2][0]=1; yp=perce.Activar(pentrada[2]);
cout<<"Para el vector ("<<pentrada[2][0]<<","<<pentrada[2][1]<<") -> y= "<<(yp[0])<<endl;
pentrada[3][0]=1; pentrada[3][1]=1; psalida[3][0]=0; yp=perce.Activar(pentrada[3]);
cout<<"Para el vector ("<<pentrada[3][0]<<","<<pentrada[3][1]<<") -> y= "<<(yp[0])<<endl;

//system ("pause");
return 0;
}
