//**********************************************************************************************//
//                                                                                              //
//                            Implementación NodoGrafoEscenaParam.hpp                           //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#include "NodoGrafoEscenaParam.hpp"



int NodoGrafoEscenaParam::numParametros()
{
  return parametros.size();
}

Parametro* NodoGrafoEscenaParam::leerPtrParametro(unsigned i)
{
    return &parametros[i];
}

void NodoGrafoEscenaParam::siguienteCuadro()
{
  int aux = numParametros();
  for(int i=0; i<parametros.size();i++)
    parametros[i].siguiente_cuadro();
}
