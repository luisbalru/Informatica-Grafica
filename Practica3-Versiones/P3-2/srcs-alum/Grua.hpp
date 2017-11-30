
#ifndef IG_GRUA
#define IG_GRUA

#include "aux.hpp"
#include "tuplasg.hpp"
#include "MallaRevol.hpp"
#include "NodoGrafoEscenaParam.hpp"
#include <string>


class Base : public NodoGrafoEscena
{
  public:
    Base()
    {
      agregar(MAT_Rotacion(90,1,0,0));
      agregar(MAT_Escalado(2,2,0.2));
      agregar(new Cubo());
    }
};

class Estructura : public NodoGrafoEscena
{
  public:
    Estructura()
    {
      agregar(MAT_Escalado(0.5,0.5,0.5));
      agregar(new Cubo());
    }
};

class Top : public NodoGrafoEscena
{
  public:
    Top()
    {
      agregar(MAT_Rotacion(90,0,0,1));
      agregar(MAT_Escalado(0.5,0.5,0.5));
      agregar(new Piramide());
    }
};

class BrazoDer : public NodoGrafoEscena
{
  public:
    BrazoDer()
    {
      agregar(MAT_Rotacion(-90,0,0,1));
      agregar(MAT_Traslacion(0,0.7,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
    }
};

class BrazoIzq : public NodoGrafoEscena
{
  public:
    BrazoIzq()
    {
      agregar(MAT_Rotacion(90,0,0,1));
      agregar(MAT_Traslacion(0,0.7,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
    }
};

class Gancho : public NodoGrafoEscena
{
  public:
    Gancho()
    {
      agregar(MAT_Ident());
      agregar(MAT_Traslacion(6.5,-0.6,0));
      agregar(MAT_Escalado(0.5,0.1,0.5));
      agregar(new Cubo());
      agregar(MAT_Ident());
      agregar(MAT_Rotacion(90,0,0,1));
      agregar(MAT_Escalado(1,0.11,0.01));
      agregar(new MallaRevol("../plys/cilindro.ply",1000,true,true));
    }
};

class Contrapeso : public NodoGrafoEscena
{
  public:
    Contrapeso()
    {
      agregar(MAT_Traslacion(-2,0.3,0));
      agregar(MAT_Escalado(0.6,0.6,0.6));
      agregar(new Cubo());
    }
};

class Grua : public NodoGrafoEscenaParam
{
  private:
    void Construccion()
    {
      agregar(MAT_Ident());
      parametros.push_back(Parametro("Movimiento total", entradas.back().matriz,std::function< Matriz4f(float)>([](float v){return MAT_Traslacion(0,0,v);}), true , 3, 7, 0.004));
      agregar(new Base());
      agregar(MAT_Traslacion(0,0.7,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Estructura());
      agregar(MAT_Ident());
      std::string cadena= "Rotación del brazo";
      parametros.push_back(Parametro(cadena,entradas.back().matriz, std::function< Matriz4f(float)>([](float v){return MAT_Rotacion(v,0,1,0);}), true, 13,200,0.0015));
      Gancho * gancho = new Gancho();
      std::string mensaje="Movimiento de la pletina";
      parametros.push_back(Parametro(mensaje,gancho->devolver(0).matriz, std::function< Matriz4f(float)>([](float v){return MAT_Traslacion(v,0,0);}),true,-3,3,0.01));
      parametros.push_back(Parametro(std::string("Movimiento del gancho"), gancho->devolver(4).matriz, std::function< Matriz4f(float)>([](float v){return MAT_Escalado(1,v,1)*MAT_Traslacion(0,-v,0);}), true, 2,3.5,0.01));
      agregar(gancho);
      agregar(new Contrapeso());
      agregar(new BrazoDer());
      agregar(new BrazoIzq());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Top());
    }
  public:
    Grua();
};

#endif
