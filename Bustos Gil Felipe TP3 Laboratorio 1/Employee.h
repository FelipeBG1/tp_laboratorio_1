#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief pedir espacio en memoria dinamica para un employee
 *
 * \return puntero a employee
 *
 */
 Employee* employee_new();

/** \brief asigna espacio en memoria dinamica para un employee asignandole los datos
 *
 * \param id a asignar en formato cadena
 * \param el nombre a asignar
 * \param las horas trabajadas a asignar en formato cadena
 * \param el sueldo a asignar en formato cadena
 * \return un puntero a employee
 *
 */
 Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

 /** \brief libera un espacio de memoria asignado a un employee
  *
  * \param employee al cual borrarlo de la memoria
  * \return retorna 0 si se pudo borrar al employee o 1 en caso de no haberlo podido borrar
  *
  */
 int employee_delete(Employee* employee);

/** \brief asigna un "id" a un employee deseado
 *
 * \param el employee deseado
 * \param id a asignar
 * \return retorna 0 si se pudo asignar el id o 1 en caso de no haberlo podido asignar
 *
 */
 int employee_setId(Employee* this,int id);

/** \brief obtiene el id del employee deseado
 *
 * \param el employee deseado
 * \param variable donde guardar el id obtenido
 * \return retorna 0 si se pudo obtener el id o 1 en caso de no haberlo podido obtener
 *
 */
 int employee_getId(Employee* this,int* id);

/** \brief asigna un "nombre" a un employee deseado
 *
 * \param el employee deseado
 * \param nombre a asignar
 * \return retorna 0 si se pudo asignar el nombre o 1 en caso de no haberlo podido asignar
 *
 */
 int employee_setNombre(Employee* this,char* nombre);

/** \brief obtiene el nombre del employee deseado
 *
 * \param el employee deseado
 * \param variable donde guardar el nombre obtenido
 * \return retorna 0 si se pudo obtener el nombre o 1 en caso de no haberlo podido obtener
 *
 */
 int employee_getNombre(Employee* this,char* nombre);

/** \brief asigna unas "horas trabajadas" a un employee deseado
 *
 * \param el employee deseado
 * \param horas trabajadas a asignar
 * \return retorna 0 si se pudo asignar las horas trabajadas o 1 en caso de no haberlas podido asignar
 *
 */
 int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief obtiene las horas trabajadas del employee deseado
 *
 * \param el employee deseado
 * \param variable donde guardar las horas trabajadas obtenidas
 * \return retorna 0 si se pudo obtener las horas trabajadas o 1 en caso de no haberlas podido obtener
 *
 */
 int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief asigna un "sueldo" a un employee deseado
 *
 * \param el employee deseado
 * \param sueldo a asignar
 * \return retorna 0 si se pudo asignar el sueldo o 1 en caso de no haberlo podido asignar
 *
 */
 int employee_setSueldo(Employee* this,int sueldo);

/** \brief obtiene el sueldo del employee deseado
 *
 * \param el employee deseado
 * \param variable donde guardar sueldo obtenido
 * \return retorna 0 si se pudo obtener el sueldo o 1 en caso de no haberlo podido obtener
 *
 */
 int employee_getSueldo(Employee* this,int* sueldo);

 /** \brief compara el valor del campo id entre dos employees
 *
 * \param primer employee
 * \param segundo employee
 * \return retorna 1 si el id del primero es mayor o -1 si el id del segundo es mayor o 0 si son iguales
 *
 */
 int employeeComparaId(void* a, void* b);

/** \brief compara el valor del campo nombre entre dos employees
 *
 * \param primer employee
 * \param segundo employee
 * \return retorna 1 si el nombre del primero es mayor o -1 si el nombre del segundo es mayor o 0 si son iguales
 *
 */
 int employeeComparaNombre(void* a, void* b);

/** \brief compara el valor del campo horas trabajadas entre dos employees
 *
 * \param primer employee
 * \param segundo employee
 * \return retorna 1 si las hs. trabajadas del primero es mayor o -1 si las hs. trabajadas del segundo es mayor o 0 si son iguales
 *
 */
 int employeeComparaHT(void* a, void* b);

/** \brief compara el valor del campo sueldo entre dos employees
 *
 * \param primer employee
 * \param segundo employee
 * \return retorna 1 si el sueldo del primero es mayor o -1 si el sueldo del segundo es mayor o 0 si son iguales
 *
 */
 int employeeComparaSueldo(void* a, void* b);

/** \brief muestra la lista de employees
 *
 * \param lista de employees
 * \return retorna 0 si se pudo mostrar la lista o 1 en caso de no haberla podido mostrar
 *
 */
 int mostrarEmployees( LinkedList* lista);

/** \brief muestra a un employee de la lista
 *
 * \param lista de employees
 * \param indice donde se encuentra ese employee
 *
 */
 void mostrarEmployee( LinkedList* lista,int indice);

/** \brief da de alta a un employee en la lista
 *
 * \param lista de employees
 * \return retorna 0 si se pudo realizar el alta o 1 en caso de no haber podido hacer el alta
 *
 */
 int altaEmployee(LinkedList* lista);

/** \brief busca a un employee en la lista
 *
 * \param id del employee a buscar
 * \param lista de employees
 * \return retorna 0 si se encontro al employee en la lista o 1 en caso de no haberlo encontrado
 *
 */
 int buscarEmployee(int id, LinkedList* lista);

/** \brief realiza la baja de un employee de la lista
 *
 * \param lista de employees
 * \return retorna 0 si se pudo realizar la baja o 1 en caso de no haberla podido hacer
 *
 */
 int bajaEmployee(LinkedList* lista);

/** \brief busca el id solicitado en la lista de employees
 *
 * \param lista de employees
 * \param id a buscar
 * \return retorna 0 si se encontro el id en la lista o 1 en caso de no haberlo encontrado
 *
 */
 int buscarId(LinkedList* lista, int id);

/** \brief modifica el campo elejido por el usuario
 *
 * \param la lista de employees

 * \return retorna 0 si se pudo realizar la modificacion o 1 en caso de no poderla realizar
 *
 */
 int modificarEmployee(LinkedList* lista);




/** \brief compara el sueldo entre dos employees
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si se pudo realizar el ordenamiento o 1 en caso de no poderlo realizar
 *
 */
 int employeeComparaSueldo(void* a, void* b);


/** \brief ordena la lista de employee
 *
 * \param lista de employees
 * \return retorna 0 si se pudo realizar el ordenamiento o 1 en caso de no poderlo realizar
 *
 */
 int ordenarEmployees(LinkedList* lista);





#endif // employee_H_INCLUDED
