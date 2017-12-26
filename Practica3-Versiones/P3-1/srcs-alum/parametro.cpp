//**********************************************************************************************//
//                                                                                              //
//                            Implementación parametro.hpp                                      //
//                          IG Curso 2016-2017. Autor: Luis Balderas Ruiz                       //
//                                                                                              //
//**********************************************************************************************//

#include "parametro.hpp"

Parametro::Parametro(const std::string & p_descripcion, Matriz4f* p_ptr_mat, TFuncionCMF p_fcm, bool p_acotado, float p_c, float p_s, float p_f)
{
  descripcion=p_descripcion;
  acotado=p_acotado;
  fun_calculo_matriz=p_fcm;
  ptr_mat=p_ptr_mat;
  c=p_c;
  s=p_s;
  f=p_f;
}

void Parametro::siguiente_cuadro()
{
  p+=velocidad;
  ptr_mat=fun_calculo_matriz(leer_valor_actual());
}

void Parametro::reset()
{
  p=0;
  c=0;
  s=0;
  f=0;
  velocidad=velocidad_inicial;
  acotado=false;
  ptr_mat=fun_calculo_matriz(leer_valor_actual());
}

void Parametro::incrementar()
{
  p+=incremento;
  ptr_mat=fun_calculo_matriz(leer_valor_actual());
}

void Parametro::decrementar()
{
  p-=incremento;
  ptr_mat=fun_calculo_matriz(leer_valor_actual());
}

void Parametro::acelerar()
{
  velocidad+=aceleracion;
  ptr_mat=fun_calculo_matriz(leer_valor_actual());
}

void Parametro::decelerar()
{
  velocidad+=aceleracion;
  if(velocidad<0)
    velocidad=0;
  ptr_mat=fun_calculo_matriz(leer_valor_actual());
}

float Parametro::leer_valor_actual()
{
  float q;
  if(acotado)
  {
    q=c+s*sin(f*2*M_PI*p);
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
