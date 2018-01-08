//**********************************************************************************************//
//                                                                                              //
//                            Definición MaterialesPractica.hpp                                 //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//


#ifndef IG_MATERIALES_PRACTICA_HPP
#define IG_MATERIALES_PRACTICA_HPP


#include "Material.hpp"
#include "Textura.hpp"

class MaterialLata : public MaterialEstandar
{
  public:
    MaterialLata();
};

class MaterialTapasLata : public MaterialEstandar
{
  public:
    MaterialTapasLata();
};

class MaterialPeonMadera : public MaterialEstandar
{
  public:
    MaterialPeonMadera();
};

class MaterialPeonBlanco : public MaterialEstandar
{
  public:
    MaterialPeonBlanco();
};

class MaterialPeonNegro : public MaterialEstandar
{
  public:
    MaterialPeonNegro();
};

#endif
