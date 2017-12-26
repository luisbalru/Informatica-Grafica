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
#include "NodoGrafoEscena.hpp"


class Paralelepipedo : public MallaInd
{
  public:
    Paralelepipedo()
    {
      nombre_obj="Bloque";

      num_ver=8;
      num_tri=12;
      Tupla3f e(1,-1,-1),c(-1,0.5,-1), b(-1,-0.5,1), d(-1,0.5,1), f(1,-1,1), g(1,1,-1), h(1,1,1), a(-1,-0.5,-1);
      Tupla3f c1(0.0,0.0,1.0), c2(0.0,1.0,0.0);
      Tupla3i t1(0,1,3),t2(0,2,3),t3(1,3,5),t4(3,7,5),t5(2,3,7),t6(2,6,7),t7(4,5,7),t8(4,6,7),t9(0,2,4),t10(2,4,6),t11(0,1,5),t12(0,4,5);
      ver.reserve(num_ver);
      ver.push_back(a);
      ver.push_back(b);
      ver.push_back(c);
      ver.push_back(d);
      ver.push_back(e);
      ver.push_back(f);
      ver.push_back(g);
      ver.push_back(h);
      tri_pares.reserve(num_tri/2 +1);
      tri_impares.reserve(num_tri/2 +1);
      tri.reserve(num_tri);
      tri.push_back(t1);
      tri_impares.push_back(t1);
      tri.push_back(t2);
      tri_pares.push_back(t2);
      tri.push_back(t3);
      tri_impares.push_back(t3);
      tri.push_back(t4);
      tri_pares.push_back(t4);
      tri.push_back(t5);
      tri_impares.push_back(t5);
      tri.push_back(t6);
      tri_pares.push_back(t6);
      tri.push_back(t7);
      tri_impares.push_back(t7);
      tri.push_back(t8);
      tri_pares.push_back(t8);
      tri.push_back(t9);
      tri_impares.push_back(t9);
      tri.push_back(t10);
      tri_pares.push_back(t10);
      tri.push_back(t11);
      tri_impares.push_back(t11);
      tri.push_back(t12);
      tri_pares.push_back(t12);
      col_tri.reserve(num_tri);
      int aux=0;
      this->num_tri_impar=tri_impares.size();
      this->num_tri_par=tri_pares.size();
      for(unsigned i=0; i<num_tri; ++i)
      {
        if(aux==0)
        {
          col_tri.push_back(c1);
          aux=1;
        }
        else{
          col_tri.push_back(c2);
          aux=0;
        }
      }
    }
};

class BloquePlano : public MallaInd
{
  public:
    BloquePlano()
    {
      nombre_obj="Bloque plano";
      Tupla3f p0(-0.35, 0, 0), p1(0.35, 0, 0);

      //Color
      Tupla3f color1(0.0,0.0,1.0), color2(0.0,1.0,0.0);

      //Vertices de la tapa
      Tupla3f p2(-0.35, 0.7, -0.35), p3(-0.35, 0.7, 0.35), p4(0.35, 0.7, 0.35), p5(0.35, 0.7, -0.35);

      ver.push_back(p0);
      ver.push_back(p1);
      ver.push_back(p2);
      ver.push_back(p3);
      ver.push_back(p4);
      ver.push_back(p5);

      //Cara Izda
      Tupla3i c1( 0,2,3 );
      tri.push_back(c1);

      //Cara Dcha
      Tupla3i c2( 1,5,4 );
      tri.push_back(c2);

      //Cara Frontal
      Tupla3i c3( 0,3,4 ), c4( 0,4,1 );
      tri.push_back(c3);
      tri.push_back(c4);

      //Cara Trasera
      Tupla3i c5( 0,5,2 ), c6(0,1,5);
      tri.push_back(c5);
      tri.push_back(c6);

      //Tapa
      Tupla3i c7(2,4,3), c8(2,5,4);
      tri.push_back(c7);
      tri.push_back(c8);

      col_tri.reserve(tam_tri);
      int aux=0;
      for(unsigned i=0; i<tam_tri; ++i)
      {
        if(aux==0)
        {
          col_tri.push_back(color1);
          aux=1;
        }
        else{
          col_tri.push_back(color2);
          aux=0;
        }
      }
    }
};

class Cabeza : public NodoGrafoEscena
{
  protected:

  public:
    Cabeza()
    {
      agregar(MAT_Traslacion(0,1.5,0));
      //agregar(MAT_Rotacion(90,0,1,0));
      agregar(MAT_Escalado(0.5,0.5,0.5));
      agregar(new Cubo());
    }
};

class Brazo : public NodoGrafoEscena
{
  protected:

  public:
    Brazo()
    {
      agregar(MAT_Rotacion(60,0,0,1));
      agregar(MAT_Traslacion(1,1,0));
      agregar(MAT_Escalado(0.5,1,0.5));
      agregar(new Cubo());
    }
};

class Pierna : public NodoGrafoEscena
{
  protected:

  public:
    Pierna()
    {
      agregar(MAT_Traslacion(0.22,-0.3,0.1));
      agregar(MAT_Escalado(2, -0.1,0.9 ));
      agregar(MAT_Rotacion(0, 1,0,0)); // entradas[2]
      agregar(MAT_Rotacion(-5, 0,0,1));
      agregar(MAT_Escalado(0.01,1,0.01));
      agregar(new MallaRevol("../plys/cilindro.ply",10000,true,true));
    }
};

class Cuerpo : public NodoGrafoEscena{
public:
    Cuerpo(){
        //agregar(MAT_Traslacion(0.5,0,0));
        //agregar(MAT_Escalado(0.2,0.2,0.2));
        agregar(MAT_Rotacion(90,0,0,1));
        agregar(new Paralelepipedo());
    }
};

class muneco : public NodoGrafoEscena
{
  protected:

  public:
    muneco(){
        agregar(MAT_Escalado(0.2,0.2,0.2));
        agregar(new Cabeza());
        agregar(new Cuerpo());
        //agregar(new Brazo());
        agregar(new Pierna()); //entradas[4]
        /*agregar(MAT_Escalado(-1, 1, 1));
        agregar(new Brazo());
        agregar(new Pierna()); ////entradas[7]*/
    }
};

static muneco* hombre = NULL;
static Cabeza* cabeza = NULL;
static Pierna* pierna = NULL;
static Tetraedro* tetraedro = NULL;
static Cuerpo* body = NULL;
static Paralelepipedo* p=NULL;

void P3_Inicializar()
{
  hombre = new muneco();
  cabeza = new Cabeza();
  pierna = new Pierna();
  tetraedro = new Tetraedro();
  body = new Cuerpo();
  p = new Paralelepipedo();

}


void P3_DibujarObjetos(ContextoVis & cv)
{
    hombre->visualizarGL(cv);
    //cabeza -> visualizarGL(cv);
    //tetraedro -> visualizarGL(cv);
    //body -> visualizarGL(cv);
    //p -> visualizarGL(cv);
    pierna -> visualizarGL(cv);
}


bool P3_FGE_PulsarTeclaNormal(unsigned char tecla)
{

}
