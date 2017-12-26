#ifndef IG_EXAM
#define IG_EXAM


#include "aux.hpp"
#include "tuplasg.hpp"
#include "MallaRevol.hpp"
#include "NodoGrafoEscenaParam.hpp"
#include <string>

class Prisma : public NodoGrafoEscena
{
  public:
    Prisma()
    {
      agregar(MAT_Escalado(0,2,0));
      agregar(new Cubo());
    }
};

class Figura : public NodoGrafoEscenaParam
{
  private:
    void Construccion_Figura()
    {
      agregar(new Prisma());
      agregar(MAT_Traslacion(0,2,0));
      agregar(MAT_Ident());
      parametros.push_back(Parametro("Movimiento 1",entradas.back().matriz,std::function< Matriz4f(float)>([](float v){return MAT_Rotacion(v,0,0,1);}),true,-50,40,0.004);
      agregar(new Prisma());
      agregar(MAT_Traslacion(0,2,0));
      agregar(MAT_Ident());
      parametros.push_back(Parametro("Movimiento 2",entradas.back().matriz, std::function< Matriz4f(float)>([](float v){return MAT_Rotacion(v,1,0,0);}),true, -50,40,0.004);
      agregar(new Prisma());
    }
  public:
    Figura();
}
