#ifndef IG_MALLAID
#define IG_MALLAID

#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include "aux.hpp"
#include <string>
#include <vector>


class MallaInd : public Objeto3D
{
  protected:
    // Practica 1
    unsigned num_ver; // número de vértices
    unsigned num_tri; // número de triángulos
    vector<Tupla3f> ver; // tabla de vértices (num_ver entradas)
    vector<Tupla3i> tri; // tabla de triángulos (num_tri entradas)
    vector<Tupla3i> tri_pares; // triángulos pares (ajedrez DE)
    vector<Tupla3i> tri_impares; // triángulos impares (ajedrez DE)
    vector<Tupla3f> col_tri; // colores de triángulos (num_tri entradas)
    vector<Tupla3f> col_ver; // colores de vértices (num_ver entradas)

    GLuint id_vbo_ver = 0;
    GLuint id_vbo_tri = 0;
    GLuint id_vbo_tri_par = 0;
    GLuint id_vbo_tri_impar = 0;
    bool VBOs=false;
    bool Ajedrez;
    unsigned tam_ver;
    unsigned tam_tri;
    unsigned tam_tri_par, tam_tri_impar;
    unsigned num_tri_par, num_tri_impar;

    void visualizarBE(); // visualizar (Begin/End)
    void visualizarDE(bool ajedrez); // visualizar (DrawElements)
    void visualizarBEAtrTri(); // BE para ajedrez

  public:
    virtual void visualizarGL(ContextoVis & cv);
    void crearVBOs();
    void visualizarVBOs();

  private:
    GLuint VBO_Crear(GLuint tipo, GLuint size, GLvoid* p);
};

class Cubo : public MallaInd
{
  private:

  public:
    Cubo(){
      nombre_obj="cubo";
      num_ver=8;
      num_tri=12;
      Tupla3f e(1,-1,-1),c(-1,1,-1), b(-1,-1,1), d(-1,1,1), f(1,-1,1), g(1,1,-1), h(1,1,1), a(-1,-1,-1);
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


    } // crea las tablas del cubo y le da nombre
};

class Tetraedro : public MallaInd
{
  public:
    Tetraedro(){
      nombre_obj="tetraedro";
      num_ver=4;
      num_tri=4;
      Tupla3f c1(0.0,0.0,1.0), c2(0.0,1.0,0.0);
      Tupla3f a(1,0,-1/sqrt(2)), b(-1,0,-1/sqrt(2)), c(0,1,1/sqrt(2)), d(0,-1,1/sqrt(2));
      ver.reserve(num_ver);
      ver.push_back(a);
      ver.push_back(b);
      ver.push_back(c);
      ver.push_back(d);
      Tupla3i t1(0,1,2),t2(0,1,3),t3(1,2,3),t4(0,2,3);
      tri.reserve(num_tri);
      tri_pares.reserve(num_tri/2 +1);
      tri_impares.reserve(num_tri/2 +1);
      tri.push_back(t1);
      tri_impares.push_back(t1);
      tri.push_back(t2);
      tri_pares.push_back(t2);
      tri.push_back(t3);
      tri_impares.push_back(t3);
      tri.push_back(t4);
      tri_pares.push_back(t4);
      col_tri.reserve(num_tri);
      this->num_tri_impar=tri_impares.size();
      this->num_tri_par=tri_pares.size();
      int aux=0;
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
    } // crea las tablas del cubo y le da nombre.
};



#endif
