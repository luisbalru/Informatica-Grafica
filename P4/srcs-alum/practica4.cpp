

#include "practica4.hpp"
#include "FuenteLuz.hpp"
#include "ColeccionFL.hpp"
#include "MallaRevol.hpp"
#include "MaterialesPractica.hpp"




static NodoGrafoEscena* p4_escena = NULL;
static ColeccionFL* p4_luces = NULL;
static unsigned current_longi = 1;
int angulo_activo=0;

Escena::Escena() {
  agregar(new Lata());

  agregar(new MaterialPeonMadera());
  agregar(MAT_Traslacion(-3, 1.4, 3));
  agregar(new Peon(true));

  agregar(new MaterialPeonBlanco());
  agregar(MAT_Traslacion(3, 0, 0));
  agregar(new Peon());

  agregar(new MaterialPeonNegro());
  agregar(MAT_Traslacion(3, 0, 0));
  agregar(new Peon());
}

Lata::Lata() {
  agregar(MAT_Escalado(4, 4, 4));

  agregar(new MaterialTapasLata());
  agregar(new BaseInfLata());
  agregar(new BaseSupLata());

  agregar(MAT_Rotacion(90, 0, 1, 0));
  agregar(new MaterialLata());
  agregar(new LateralLata());
}

LateralLata::LateralLata() {
  // La malla de revolución para el cuerpo de la lata la
  // generamos sin bases y con una textura, invirtiendo
  // el cálculo de las coordenadas de textura:
  agregar(new MallaRevol("../plys/lata-pcue.ply", 100, false, false, true));
}

BaseInfLata::BaseInfLata() {
  agregar(new MallaRevol("../plys/lata-pinf.ply", 100, true,true,false));
}

BaseSupLata::BaseSupLata() {
  agregar(new MallaRevol("../plys/lata-psup.ply", 100, true,true,false));
}

Peon::Peon(bool usar_textura) {
  agregar(new MallaRevol("../plys/peon.ply", 40,true, true, usar_textura));
}

void P4_Inicializar()
{
  p4_escena = new Escena();
  p4_luces = new ColeccionFuentesP4();
  p4_luces->activar();
}

void P4_DibujarObjetos(ContextoVis& cv)
{
  glEnable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
   glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
  p4_escena->visualizarGL(cv);
  glDisable(GL_LIGHTING);
}

bool P4_FGE_PulsarTeclaNormal(unsigned char tecla) {
  if (toupper(tecla) == 'G') {
    current_longi = !current_longi;
    return true;
  } else if (tecla == '<') {
    static_cast<FuenteDireccional*>(p4_luces->fuentes.at(0))->variarAngulo(current_longi, -10);
    return true;
  } else if (tecla == '>') {
    static_cast<FuenteDireccional*>(p4_luces->fuentes.at(0))->variarAngulo(current_longi, 10);
    return true;
  }

  return false;
}
