// *********************************************************************
// **
// ** Informática Gráfica, curso 2017-18
// ** Práctica 2  (implementación)
// **
// *********************************************************************


#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica2.hpp"
#include <iostream>
#include <string>

static MallaPLY* objeto_ply = NULL ;
static MallaRevol* objeto_revol=NULL;
static MallaPLY* auxiliar=NULL;
unsigned objeto_activo_practica2=0;
unsigned numero_objetos=3;

void P2_Inicializar(int argc, char* argv[])
{
  // Lee los nombres de los archivos desde el comando de terminal
 // con la sintaxis siguiente:
 //  <archivo PLY> <archivo PLY revolución> <número de perfiles>
 // En caso de error toma parámetros por defecto
 string archivo_ply;
 string archivo_revol;
 string archivo_auxiliar;
 unsigned numero_perfiles;

 archivo_ply = "../plys/ant.ply";
 archivo_revol = "../plys/peon.ply";
 archivo_auxiliar = "../plys/beethoven.ply";
 numero_perfiles = 100;


 // Genera los objetos como mallas leyendo del archivo
 // PLY que se ha obtenido anteriormente
 objeto_ply = new MallaPLY(archivo_ply);
 objeto_revol = new MallaRevol(archivo_revol, numero_perfiles, true, true);
 auxiliar = new MallaPLY(archivo_auxiliar);
}

void P2_DibujarObjetos(ContextoVis& cv)
{
  if (objeto_activo_practica2 == 0)
    objeto_ply->visualizarGL(cv);
  else if (objeto_activo_practica2 == 1)
    objeto_revol->visualizarGL(cv);
  else
    auxiliar->visualizarGL(cv);
}

bool P2_FGE_PulsarTeclaNormal(unsigned char tecla)
{
  if(tecla=='o' || tecla=='O')
  {
    objeto_activo_practica2=(objeto_activo_practica2+1)%numero_objetos;
    return true;
  }
  else
    return false;
}
