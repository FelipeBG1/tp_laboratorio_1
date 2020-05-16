/*
 * ArrayEmployees.h
 *
 *  Created on: 16 may. 2020
 *      Author: felib
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}eEmployee;

#endif /* ARRAYEMPLOYEES_H_ */


/** \brief llama al menu de opciones y a la funcion elegida por el usuario
 *
 * \param vector de eEmpleado para pasar como parametro a las funciones a llamar
 * \param tamaño del vector para pasar como parametro a las funciones a llamar
 *
 */
void informar(eEmployee vec[], int tam);

/** \brief menu que muestra las opciones de los diferentes informes
 *
 * \return opcion que ingresa el usuario
 *
 */
int menuInformar();

/** \brief menu principal de opciones
 *
 * \return opcion que ingresa el usuario
 *
 */
int mostrarMenu();

/** \brief le da valor 1 al campo isEmpty de cada empleado
 *
 * \param vector de empleados que se va a recorrer
 * \param tamaño del vector de empleados
 *
 */
void inicializarEmpleados(eEmployee vec[],int tam);

/** \brief busca un espacio vacio en un vector de eEmpleado y le carga los datos si el usuario ingresa
 *  bien todos los campos
 *
 * \param id a asignarle al nuevo empleado
 * \param vector de eEmpleado a utilizar para cargar el nuevo empleado
 * \param tamaño del vector de eEmpleado para recorrer
 *
 * \return 1 si pudo cargar los datos, -1 si no lo pudo hacer
 *
 */
int altaEmpleado(int idX,eEmployee vec[], int tam);

/** \brief busca en un vector de eEmpleados si hay un espacio con isEmpty=1
 *
 * \param vector de eEmpleado a recorrer
 * \param tamaño del vector a recorrer
 *
 * \return -1 si no encuentra espacio vacio,sino el indice del espacio vacio encontrado
 *
 */
int buscarLibre(eEmployee vec[],int tam);

/** \brief busca un empleado a partir de un id
 *
 * \param id del empleado a buscar
 * \param vector de empleados
 * \param tamaño del vector de empleados
 * \return -1 si no encontro ningun empleado con ese id, sino devuelve la posicion de ese empleado
 *
 */
int buscarEmpleado(int id, eEmployee vec[], int tam);

/** \brief realiza la baja logica de un empleado
  *
  * \param vector de empleados
  * \param tamaño del vector de empleados
  *
  */
void bajaEmpleado(eEmployee vec[], int tam);

/** \brief ordena el vector de empleados por apellido y sector
 *
 * \param vector de empleados
 * \param tamaño del vector de empleados
 *
 */
void ordenarEmpleados(eEmployee vec[], int tam);

/** \brief muestra los datos de un empleado
 *
 * \param posicion del empleado
 *
 */
void mostrarEmpleado(eEmployee x);

/** \brief muestra a todos los empleados del vector de empleados
 *
 * \param vector de empleados
 * \param tamaño del vector de empleados
 *
 */
 void mostrarEmpleados(eEmployee vec[],int tam);

 /** \brief realiza la modificacion de los datos de un empleado
  *
  * \param vector de empleados
  * \param tamaño del vector de empleados
  *
  */
  void modificarEmpleado(eEmployee vec[],int tam);

  /** \brief informa el total de sueldos junto con el promedio y que empleados superan el promedio
   *
   * \param vector de empleados
   * \param tamaño del vector de empleado
   *
   */
  void informarTotalSueldos(eEmployee vec[], int tam);

  /** \brief menu de las opciones a modificar
     *
     * \return la opcion ingresado por el usuario
     *
     */
   char menuModificar();


   /** \brief Recorre la cadena validando que cada posicion sea una letra
     *
     * \param Cadena a cargar la letra validada
     * \return Retorna 0 si logra validar, o -1 si no
     *
     */
     int isLetras(char*pAux);

    /** \brief Valida que el usuario ingrese una cadena de caracteres.
     *
     * \param Puntero a variable char en la que cargar la cadena validada.
     * \param Limite de caracteres a ingresar
     * \param Numero de reintentos
     * \param Mensaje a mostrar
     * \param Mensaje de error
     * \return 0 si tuvo exito, y -1 si no.
     *
     */
     int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);


    /** \brief  Obtiene una cadena mediante getCadena y valida mediante isFLoat. Pasa la cadena validada a flotante.
     *
     * \param Puntero a flotante donde escribir el resultado de la validacion.
     * \return Retorna 0 si tuvo exito, -1 si no.
     *
     */
     int getFloat(float*pAux);


    /** \brief Recorre la cadena validando que cada posicion sea un numero (0 - 9)
     *
     * \param Cadena a cargar el numero validado
     * \return Retorna 0 si logra validar, o -1 si no.
     *
     */
     int isInt(char *pAux);


   /** \brief pide un valor entero y valida el ingreso
    *
    * \param	puntero a entero en donde se va a guardar el dato
    * \param	reintentos que se le dan al usuario para ingresar de manera correcta
    * \param	mensaje a mostrar para ingresar el dato
    * \param	mensaje de error en caso de que se ingrese de manera erronea lo pedido
    * \param	minimo numero que se puede ingresar
    * \param	maximo numero que se puede ingresar
    *
    * \return	0 si logra tomar el dato, sino -1
    *
    */
   int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int minimo,int maximo);

   /** \brief	pide un valor tipo float y valida el ingreso
    *
    * \param	puntero a flotante en donde se va a guardar el dato
    * \param	reintentos que se le dan al usuario para ingresar de manera correcta
    * \param	mensaje a mostrar para ingresar el dato
    * \param	mensaje de error en caso de que se ingrese de manera erronea lo pedido
    * \param	minimo numero que se puede ingresar
    * \param	maximo numero que se puede ingresar
    *
    * \return	0 si logra tomar el dato, sino -1
    *
    */
   int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float minimo,float maximo);

   /** \brief	toma la cadena que fue ingresada y le saca el '\n' al fgets
    *
    * \param	puntero a char en la que cargar la cadena ya validada}
    *
    * \return	0 si tuvo exito, sino -1
    *
    */
   int getCadena(char* pAux,int limite);

   /** \brief	llama a isInt y a isCadena para validar que sea un entero y pasa la cadana a integer
    *
    * \param	puntero a entero donde se va a cargar el numero validado
    *
    * \return	0 si logra validar, sino -1
    *
    */
   int getInt(int* pAux);

   /** \brief	valida que el parametro que se la pase sea flotante. Cuenta que solo haya un punto
    *
    * \param	cadena donde se carga el numero flotante validado
    *
    * \return	0 si la cadena es de numeros y tiene solo un punto, sino -1
    *
    */
   int isFloat(char* pAux);
