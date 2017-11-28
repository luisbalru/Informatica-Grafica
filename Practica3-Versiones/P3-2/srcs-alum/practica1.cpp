// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 1  (implementación)
// **
// *********************************************************************


#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica1.hpp"
#include <iostream>

unsigned objeto_activo = 1 ; // objeto activo: cubo (0), tetraedro (1), otros....
unsigned num_objetos=2;


// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

Cubo* cubo;
Tetraedro* tetraedro;


// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
  cubo = new Cubo();
  tetraedro = new Tetraedro();
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   if(tecla=='o' || tecla=='O'){
      objeto_activo=(objeto_activo+1)%num_objetos;
      return true;
   }
  else
   return false ;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// se debe de usar el modo de dibujo que hay en el parámetro 'cv'
// (se accede con 'cv.modoVisu')

void P1_DibujarObjetos( ContextoVis & cv )
{
  if(objeto_activo==0)
    cubo->visualizarGL(cv);
  else
    tetraedro->visualizarGL(cv);
}
