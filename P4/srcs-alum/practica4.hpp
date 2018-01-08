//**********************************************************************************************//
//                                                                                              //
//                            Definición practica4.hpp                                          //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//


#ifndef IG_PRACTICA4_HPP
#define IG_PRACTICA4_HPP

#include "MallaInd.hpp"
#include "practicas.hpp"
#include "NodoGrafoEscena.hpp"

void P4_Inicializar();
void P4_DibujarObjetos(ContextoVis & cv);
bool P4_FGE_PulsarTeclaNormal(unsigned char tecla);

class Escena : public NodoGrafoEscena {
public:
  Escena();
};

class Lata : public NodoGrafoEscena {
public:
  Lata();
};

class LateralLata : public NodoGrafoEscena {
public:
  LateralLata();
};

class BaseInfLata : public NodoGrafoEscena {
public:
  BaseInfLata();
};

class BaseSupLata : public NodoGrafoEscena {
public:
  BaseSupLata();
};

class Peon : public NodoGrafoEscena {
public:
  Peon(bool usar_textura = false);
};

#endif
