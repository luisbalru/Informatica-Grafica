//**********************************************************************************************//
//                                                                                              //
//                            Implementación Grua.hpp                                           //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//


#include "Grua.hpp"
#include <vector>


MaterialBase::MaterialBase()
{
  textura = NULL;
  Tupla4f azul(0.0, .2, 0.4, 1);
  color[0] = azul * 0.7;
  color[1] = azul * 0.05;
  color[2] = azul * 0.2;
  color[3] = azul * 0.0;
  exponente = 3;
}

MaterialEstructura::MaterialEstructura()
{
  textura = new Textura("hierro.jpg",1);
  Tupla4f blanco(1, 1, 1, 1);
  color[0] = blanco * 0.47;
  color[1] = blanco * 0.05;
  color[2] = blanco * 0.21;
  color[3] = blanco * 0.4;
  exponente = 3;
}

MaterialGancho::MaterialGancho()
{
  textura = new Textura("gancho.jpg",1);
  Tupla4f blanco(0.52, 1, 0.51, 1);
  color[0] = blanco * 0.19;
  color[1] = blanco * 0.25;
  color[2] = blanco * 0.2;
  color[3] = blanco * 0.06;
  exponente = 3;

}



Grua::Grua()
{
  Construccion();
}
