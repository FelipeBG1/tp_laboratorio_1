#ifndef EMPRESAS_H_INCLUDED
#define EMPRESAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int cantidadEmpleados;
    int valorMercado;
}Empresa;

/** \brief pedir espacio en memoria dinamica para una empresa
 *
 * \return puntero a empresa
 *
 */
 Empresa* empresa_new();

/** \brief asigna espacio en memoria dinamica para una empresa asignandole los datos
 *
 * \param id a asignar en formato cadena
 * \param el nombre a asignar
 * \param la cantidad de empleados a asignar en formato cadena
 * \param el valor de mercado (millones de dolares) a asignar en formato cadena
 * \return un puntero a empresa
 *
 */
 Empresa* empresa_newParametros(char* idStr,char* nombreStr,char* cantidadEmpleadosStr, char* valorMercadoStr);

 /** \brief libera un espacio de memoria asignado a una empresa
  *
  * \param empresa a la cual borrar de la memoria
  * \return retorna 0 si se pudo borrar la empresa o 1 en caso de no haberla podido borrar
  *
  */
 int empresa_delete(Empresa* empresa);

/** \brief asigna un "id" a una empresa deseada
 *
 * \param la empresa deseada
 * \param id a asignar
 * \return retorna 0 si se pudo asignar el id o 1 en caso de no haberlo podido asignar
 *
 */
 int empresa_setId(Empresa* this,int id);

/** \brief obtiene el id de la empresa deseada
 *
 * \param la empresa deseada
 * \param variable donde guardar el id obtenido
 * \return retorna 0 si se pudo obtener el id o 1 en caso de no haberlo podido obtener
 *
 */
 int empresa_getId(Empresa* this,int* id);

/** \brief asigna un "nombre" a una empresa deseada
 *
 * \param la empresa deseada
 * \param nombre a asignar
 * \return retorna 0 si se pudo asignar el nombre o 1 en caso de no haberlo podido asignar
 *
 */
 int empresa_setNombre(Empresa* this,char* nombre);

/** \brief obtiene el nombre de la empresa deseada
 *
 * \param la empresa deseada
 * \param variable donde guardar el nombre obtenido
 * \return retorna 0 si se pudo obtener el nombre o 1 en caso de no haberlo podido obtener
 *
 */
 int empresa_getNombre(Empresa* this,char* nombre);

/** \brief asigna una cantidad de empleados a una empresa deseada
 *
 * \param la empresa deseada
 * \param cantidad de empleados a asignar
 * \return retorna 0 si se pudo asignar la cantidad de empleados o 1 en caso de no haberla podido asignar
 *
 */
 int empresa_setCantidadEmpleados(Empresa* this,int cantidadEmpleados);

/** \brief obtiene la cantidad de empleados de la empresa deseada
 *
 * \param la empresa deseada
 * \param variable donde guardar la cantidad de empleados obtenida
 * \return retorna 0 si se pudo obtener la cantidad de empleados o 1 en caso de no haberla podido obtener
 *
 */
 int empresa_getCantidadEmpleados(Empresa* this,int* cantidadEmpleados);


/** \brief asigna un valor de mercado(millones de dolares) a una empresa deseada
 *
 * \param la empresa deseada
 * \param valor de mercado(millones de dolares) a asignar
 * \return retorna 0 si se pudo asignar el valor de mercado o 1 en caso de no haberlo podido asignar
 *
 */
 int empresa_setValorMercado(Empresa* this,int valorMercado);

/** \brief obtiene el valor de mercado(millones de dolares) de la empresa deseada
 *
 * \param la empresa deseada
 * \param variable donde guardar el valor de mercado obtenido
 * \return retorna 0 si se pudo obtener el valor de mercado o 1 en caso de no haberlo podido obtener
 *
 */
 int empresa_getValorMercado(Empresa* this,int* valorMercado);

 /** \brief compara el valor del campo id entre dos empresas
 *
 * \param primer empresa
 * \param segunda empresa
 * \return retorna 1 si el id del primero es mayor o -1 si el id del segundo es mayor o 0 si son iguales
 *
 */
 int empresaComparaId(void* a, void* b);

/** \brief compara el valor del campo nombre entre dos empresas
 *
 * \param primer empresa
 * \param segunda empresa
 * \return retorna 1 si el nombre del primero es mayor o -1 si el nombre del segundo es mayor o 0 si son iguales
 *
 */
 int empresaComparaNombre(void* a, void* b);

/** \brief compara el valor del campo cantidad de empleados entre dos empresas
 *
 * \param primer empresa
 * \param segunda empresa
 * \return retorna 1 si las hs. trabajadas del primero es mayor o -1 si las hs. trabajadas del segundo es mayor o 0 si son iguales
 *
 */
 int empresaComparaCE(void* a, void* b);

/** \brief compara el valor del campo valor de mercado entre dos empresas
 *
 * \param primer empresa
 * \param segunda empresa
 * \return retorna 1 si el sueldo del primero es mayor o -1 si el sueldo del segundo es mayor o 0 si son iguales
 *
 */
 int empresaComparaVM(void* a, void* b);

/** \brief muestra la lista de empresas
 *
 * \param lista de empresas
 * \return retorna 0 si se pudo mostrar la lista o 1 en caso de no haberla podido mostrar
 *
 */
 int mostrarEmpresas( LinkedList* lista);

/** \brief muestra a un empresa de la lista
 *
 * \param lista de empresas
 * \param indice donde se encuentra esa empresa
 *
 */
 void mostrarEmpresa( LinkedList* lista,int indice);

/** \brief da de alta a un empresa en la lista
 *
 * \param lista de empresas
 * \return retorna 0 si se pudo realizar el alta o 1 en caso de no haber podido hacer el alta
 *
 */
 int altaEmpresa(LinkedList* lista);

/** \brief busca a un empresa en la lista
 *
 * \param id de la empresa a buscar
 * \param lista de empresas
 * \return retorna 0 si se encontro a la empresa en la lista o 1 en caso de no haberla encontrado
 *
 */
 int buscarEmpresa(int id, LinkedList* lista);

/** \brief realiza la baja de una empresa de la lista
 *
 * \param lista de empresas
 * \return retorna 0 si se pudo realizar la baja o 1 en caso de no haberla podido hacer
 *
 */
 int bajaEmpresa(LinkedList* lista);

/** \brief busca el id solicitado en la lista de empresas
 *
 * \param lista de empresas
 * \param id a buscar
 * \return retorna 0 si se encontro el id en la lista o 1 en caso de no haberlo encontrado
 *
 */
 int buscarId(LinkedList* lista, int id);

/** \brief modifica el campo elegido por el usuario
 *
 * \param la lista de empresas
 * \return retorna 0 si se pudo realizar la modificacion o 1 en caso de no poderla realizar
 *
 */
 int modificarEmpresa(LinkedList* lista);


/** \brief ordena la lista de empresas
 *
 * \param lista de empresas
 * \return retorna 0 si se pudo realizar el ordenamiento o 1 en caso de no poderlo realizar
 *
 */
 int ordenarEmpresas(LinkedList* lista);

 /** \brief muestra opciones con diferentes modificacciones que se pueden realizar
  *
  * \return la opcion elegida por el usuario
  *
  */
 char menuModificar();

/** \brief muestra opciones con diferentes ordenamientos que se pueden realizar
  *
  * \return la opcion elegida por el usuario
  *
  */
 char menuOrdenar();

 /** \brief va actualizando en un archivo el ultimo id de la lista
  *
  * \param id a actualizar
  * \return 0 si se actualizo y -1 si no se pudo actualizar
  *
  */
 int actualizarId(int id);

 /** \brief obtiene el ultimo id del archivo
  *
  * \param variable donde guarda el id obtenido
  * \return 0 si se obtuvo y -1 si no se pudo obtener
  *
  */
 int obtenerId(int* id);
#endif // EMPRESAS_H_INCLUDED
