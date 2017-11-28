
#ifndef IG_GRUA
#define IG_GRUA

#include "aux.hpp"
#include "tuplasg.hpp"
#include "MallaRevol.hpp"
#include "NodoGrafoEscenaParam.hpp"


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
      agregar(MAT_Traslacion(6.5,-0.6,0));
      agregar(MAT_Escalado(0.5,0.1,0.5));
      agregar(new Cubo());
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
      agregar(new Gancho());
      agregar(new Contrapeso());
      agregar(new BrazoDer());
      agregar(new BrazoIzq());
      agregar(MAT_Traslacion(0,1,0));
      agregar(new Top());
    }
  public:
    Grua()
    {
      agregar(MAT_Ident());
      parametros.push_back(Parametro("Giro de ángulo n"))
      Construccion();
    }
};


#endif
