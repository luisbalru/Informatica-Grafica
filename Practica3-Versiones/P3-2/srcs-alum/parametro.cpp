//**********************************************************************************************//
//                                                                                              //
//                            Implementación parametro.hpp                                      //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#include "parametro.hpp"
#include <iostream>

Parametro::Parametro(const std::string & p_descripcion, Matriz4f* p_ptr_mat, const TFuncionCMF p_fcm, const bool p_acotado, const float p_c, const float p_s, const float p_f) : descripcion(p_descripcion), acotado(p_acotado), fun_calculo_matriz(p_fcm), c(p_c), s(p_s), f(p_f)
{

  ptr_mat=p_ptr_mat;
  incremento=1.96;
  aceleracion=0.8;
  velocidad_inicial=1;
  velocidad=velocidad_inicial;
  p=p_c;

}

void Parametro::siguiente_cuadro()
{
  p+=velocidad;
  *ptr_mat=fun_calculo_matriz(leer_valor_actual());
}

void Parametro::reset()
{
  p=c;
  velocidad=velocidad_inicial;
  *ptr_mat=fun_calculo_matriz(leer_valor_actual());
}


void Parametro::incrementar()
{
  p=p+incremento;
  *ptr_mat= fun_calculo_matriz(leer_valor_actual());
}

void Parametro::decrementar()
{
  p-=incremento;
  *ptr_mat=fun_calculo_matriz(leer_valor_actual());
}

void Parametro::acelerar()
{
  velocidad+=aceleracion;
}

void Parametro::decelerar()
{
  velocidad-=aceleracion;
  if(velocidad<0)
    velocidad=0;
}

float Parametro::leer_valor_actual()
{
  float q;
  if(acotado)
  {
    q=c+s*std::sin(f*2*3.141592*p);
  }
  else
  {
    q=c+s*p;
  }
  return q;
}

float Parametro::leer_velocidad_actual()
{
  return velocidad;
}

std::string Parametro::leer_descripcion()
{
  return descripcion;
}
