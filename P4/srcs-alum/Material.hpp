//**********************************************************************************************//
//                                                                                              //
//                            Definición material.hpp                                           //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#ifndef IG_MATERIAL_HPP
#define IG_MATERIAL_HPP

#include "Textura.hpp"
#include "tuplasg.hpp"
#include "aux.hpp"

class Material
{
  public:
    virtual void activar(ContextoVis& cv)=0;
};


class MaterialEstandar : public Material
{
  public:
    Textura * textura; // Puntero a textura (NULL si no hay)
    Tupla4f color[4]; // 0=Me, 1=Ma, 2=Md, 3=Ms
    float exponente; // exponente

    virtual void activar(ContextoVis& cv); // activa material
};














#endif
