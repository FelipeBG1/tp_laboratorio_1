int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmpresa(LinkedList* pArrayListEmployee);
int controller_editEmpresa(LinkedList* pArrayListEmployee);
int controller_removeEmpresa(LinkedList* pArrayListEmployee);
int controller_ListEmpresas(LinkedList* pArrayListEmployee);
int controller_sortEmpresas(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
void controller_copiaDeSeguridadTxt(LinkedList* pArrayListEmpresas);
void controller_copiaDeSeguridadBin(LinkedList* pArrayListEmpresas);
void controller_copiaDeSeguridadGral(LinkedList* pArrayListEmpresas);
int menuCopiaSeguridad();
void controller_MoverEmpresaAlaPosicionDeseada(LinkedList* pArrayListEmpresas);



