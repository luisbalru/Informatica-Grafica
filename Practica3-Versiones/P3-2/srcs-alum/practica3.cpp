//**********************************************************************************************//
//                                                                                              //
//                            Implementación practica3.hpp                                      //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//
#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica3.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "Objeto3D.hpp"
#include "Grua.hpp"



static Grua* grua = NULL;
void P3_Inicializar()
{
  grua = new Grua();

}


void P3_DibujarObjetos(ContextoVis & cv)
{
  //brazo -> visualizarGL(cv);
  grua ->visualizarGL(cv);
}


bool P3_FGE_PulsarTeclaNormal(unsigned char tecla)
{

}
