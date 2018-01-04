//**********************************************************************************************//
//                                                                                              //
//                            Definición FuenteLuz.hpp                                          //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#ifndef IG_FUENTE_LUZ_HPP
#define IG_FUENTE_LUZ_HPP

#include <vector>
#include "aux.hpp" //Constantes GL_LIGHT0, GL_LIGHT0+i
#include "tuplasg.hpp"
#include "matrices-tr.hpp"

class FuenteLuz
{
public:
    Tupla4f  posvec ;       // posición (si w=1) o vector (w=0)
    Tupla4f  colores[3] ;   // colores: 0=ambiental, 1=difuso, 2=especular.
    float    longitud,latitud;      // ángulos de rotación (fuente direccional modificable interactivamente)

    void activar(int i) ; // activa la fuente de luz (con número GL_LIGHT0+i)
} ;

// ---------------------------------------------------------------------
// Fuente de luz que parte desde el infinito en una direccion (rayos paralelos)
// ---------------------------------------------------------------------
class FuenteDireccional : public FuenteLuz
{
public:
    FuenteDireccional( float alpha_inicial, float beta_inicial ) ;
    void variarAngulo( unsigned angulo, float incremento ) ;  // angulo=0 --> variar alpha, angulo=1 --> variar beta
};

// ---------------------------------------------------------------------
// Fuente de luz que parte de un punto concreto en todas las direcciones
// ---------------------------------------------------------------------
class FuentePosicional : public FuenteLuz
{
public:
    FuentePosicional( const Tupla3f & posicion ) ;
};



#endif
