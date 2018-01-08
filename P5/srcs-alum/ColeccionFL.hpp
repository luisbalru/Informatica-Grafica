//**********************************************************************************************//
//                                                                                              //
//                            Definición ColeccionFL.hpp                                        //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//


#include <vector>
#include "aux.hpp" //Constantes GL_LIGHT0, GL_LIGHT0+i
#include "tuplasg.hpp"
#include "FuenteLuz.hpp"

#ifndef IG_COLECCIONFL_HPP
#define IG_COLECCIONFL_HPP

// ---------------------------------------------------------------------
// Colección de (hasta 8) fuentes de luz.
// ---------------------------------------------------------------------

class ColeccionFL
{
public:
    std::vector<FuenteLuz *> fuentes ;  // vector de fuentes de luz
    void activar() ;                  // activa todas las fuentes de luz en el cauce fijo
    //   (antes de eso activa iluminación y la configura)
} ;



class ColeccionFuentesP4 : public ColeccionFL
{
public:
    ColeccionFuentesP4() ;
};



#endif
