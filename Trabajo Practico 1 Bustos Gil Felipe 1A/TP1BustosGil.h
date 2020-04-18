#ifndef TP1BUSTOSGIL_H_INCLUDED
#define TP1BUSTOSGIL_H_INCLUDED



#endif // TP1BUSTOSGIL_H_INCLUDED
/** \brief recibe dos numeros y los suma
 *
 * \param a primer número a sumar
 * \param b segundo número a sumar
 * \return resultado de la suma
 *
 */
    int sumar (int a,int b);



/** \brief recibe dos numeros y los resta
 *
 * \param a primer número a restar
 * \param b segundo número a restar
 * \return resultado de la resta
 *
 */
    int restar(int a,int b);



/** \brief recibe dos numeros y los divide
 *
 * \param a es el dividendo
 * \param b es el divisor
 * \return resultado de la divisíon
 *
 */
    float dividir(int a,int b);



/** \brief recibe dos numeros y los multiplica
 *
 * \param a primer número a multiplicar
 * \param b segundo número a multiplicar
 * \return resultado de la multiplicación
 *
 */
    int multiplicar(int a,int b);



/** \brief recibe un numero y calcula su factorial
 *
 * \param numero al cual le calculara el factorial
 * \return el factorial de ese numero
 *
 */
  int factorial(int a);



/** \brief muestra una serie de opciones
 *
 * \param a primer operando
 * \param b segundo operando
 * \param flag1 bandera correspondiente al ingreso del primer operando
 * \param flag2 bandera correspondiente al ingreso del segundo operando
 * \return la opcion elegida
 *
 */
  int mostrarMenu(int a,int b,int flag1,int flag2);



/** \brief resetea el valor que esta guardado en la direccion de memoria de la variable
 *
 * \param direccion de memoria de la varible
 *
 */
    void reset(int*p);
