//Importacion de librerias
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Declaracion de variables globales
char auximaa[1000], auximii[100], desc[1000], posible[1000];
int max, min=1000, iMax = 0, iMin = 0, encontrado = 0, d=0, pr=0;

struct Nodo{ //Creacion del nodo
    char nombre[1000];
    int edad;
    char nacional[1000];

    struct Nodo *mama;
    struct Nodo *papa;
};

//Funcion encargada de la impresion de hoja de presentacion
void paginaPresentacion(){
    printf("\n\t\t\t\t\tUNIVERSIDAD TECNOLOGICA DE PANAMA");
    printf("\n\t\t\t\t Facultad de Ingenieria en Sistemas Computacionales ");
    printf("\n\t\t\t\tDepartamento de computacion y simulacion de sistemas");
    printf("\n\n\n\n\t\t\t\tLicenciatura en Ingenieria en Sistemas y Computacion");
    printf("\n\n\t\t\t\t\t\tEstructura de Datos II");
    printf("\n\n\t\t\t        Proyecto N. 1: Estructuras de Datos No Lineal (ARBOL)");
    printf("\n\n\t\t\t\tProf. Doris Cueto\t\t\t Integrantes:");
    printf("\n\t\t\t\t\t\t                         Davis, Viviana");
    printf("\n\t\t\t\t\t\t                         Gonzalez, Joana");
    printf("\n\t\t\t\t\t\t                         Hincapie, Juan");
    printf("\n\n\t\t\t\t\t\t                         Grupo:");
    printf("\n\t\t\t\t\t\t                         1IL122");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t3 de octubre de 2022\n\n\n");

    system("PAUSE");
}

void crear (struct Nodo *nodo){//Funcion encargada de crear los arboles
    //Declaracion de variables
    char resp[1], ed[15];
    int aux;

    system("cls");//Limpieza de la pantalla
    if(pr != 1){
        fflush(stdin);
        printf("Ingrese su nombre: \n"); //Entrada del nombre
        gets(nodo->nombre);

    }
    while(nodo->edad <= 0){
        fflush(stdin);
        printf("Ingrese su edad: \n"); //Entrada de la edad
        scanf("%d", &nodo->edad);
    }

    fflush(stdin);
    printf("Ingrese su nacionalidad: \n"); //Entrada de nacionalidad
    gets(nodo->nacional);

    fflush(stdin);
    printf("\n\nINSERTANDO ASCENDIENTES DE %s", nodo->nombre);
    printf("\n\nConoce el nombre de la madre de %s ?", nodo->nombre);
    printf("\n1. Si\n2. No\n");
    scanf(" %c", &resp);

    if(resp[0]=='1'){
        pr = 0;
        nodo->mama = malloc(sizeof(struct Nodo)); //creacion del nodo para Mama
        crear(nodo->mama);
    }
    else{
        pr = 0;
        nodo->mama = NULL;
    }

    fflush(stdin);
    printf("\nConoce el nombre del padre de %s?", nodo->nombre);
    printf("\n1. Si\n2. No\n");
    scanf(" %c", &resp);

    if(resp[0]=='1'){
        pr = 0;
        nodo->papa = malloc(sizeof(struct Nodo)); //creacion del nodo para Papa
        crear(nodo->papa);
    }
    else{
        pr = 0;
        nodo->papa = NULL;
    }
}

//Funcion encargada de calcular el progenitor de mayor y menor edad
void edadM(struct Nodo *nodo){
    //Declaracion de variables
    int num, mii, maa;

    if(nodo != NULL){
        if(nodo->edad != NULL){
            if(max < nodo->edad){
                max = nodo->edad;
                strcpy(auximaa, nodo->nombre);
            }
            if(nodo->edad < min){
                //memset(auximii, 0, i);
                min = nodo->edad;
                strcpy(auximii, nodo->nombre);
            }
        }
        //Recursividad
        edadM(nodo->mama);
        edadM(nodo->papa);
    }
}

void Impresion(struct Nodo *nodo){
    if(nodo != NULL){
        if(nodo->mama == NULL){ //Impresion de desconocida para inexistencia de mama
            printf("\nMAMA: Desconocida\t|");
        }
        else{
            printf("\nMAMA: %s\t|",nodo->mama); //Impresion de mama
        }

        if(nodo->papa ==NULL){
            printf("\tPAPA: Desconocido\t|\n");//Impresion de desconocido para inexistencia de papa
        }
        else{
            printf("\tPAPA: %s\t|\n",nodo->papa); //Impresion de papa
        }

        printf("Nombre de hijo/a: %s\t|", nodo->nombre); //Impresion del nombre del hijo
        printf("\t\tEdad: %d |\n\n", nodo->edad);

        //Recursividad
        Impresion(nodo->mama);
        Impresion(nodo->papa);

    }
}


//Funcion encargada de imprimir la nacionalidad de los descendientes
void nacionDesc(struct Nodo *nodo){
    if(nodo != NULL){
        nacionDesc(nodo->mama);
        nacionDesc(nodo->papa);
        if(nodo->mama == NULL){
            printf("\nPROGENITORA: Desconocida\t|"); //Impresion de desconocida para inexistencia de mama
        }
        else{
            printf("\nPROGENITORA: %s\t|",nodo->mama);//Impresion de mama
        }

        if(nodo->papa ==NULL){
            printf("\tPROGENITOR: Desconocido\t|\n");//Impresion de desconocido para inexistencia de papa
        }
        else{
            printf("\tPROGENITOR: %s\t|\n",nodo->papa);//Impresion de papa
        }

        printf("- Su descendiente, %s, es %s\n\n", nodo->nombre,nodo->nacional);//Impresion de descendiente
    }
}

//Funcion encargada de imprimir el arbol de forma grafica
void imGrafico(struct Nodo *nodo, int t){
    int aux;

	if(nodo != NULL){
		imGrafico(nodo->papa, t+2);
		//printf("\n\n");
		if(nodo->papa!= NULL){
            for(aux=0;aux<t;aux++){
                printf("     ");
            }
            printf("        /\n");
            for(aux=0;aux<t;aux++){
                printf("     ");
            }
            printf("       /\n");
            for(aux=0;aux<t;aux++){
                printf("     ");
            }
            printf("      /\n");
		}
		for(aux=0;aux<t;aux++){
			printf("     ");
		}
        printf("  ------------\n");
        for(aux=0;aux<t;aux++){
			printf("     ");
		}
		printf("|   %s   |\n",nodo->nombre);
		for(aux=0;aux<t;aux++){
			printf("     ");
		}
		printf("     %d\n",nodo->edad);
		for(aux=0;aux<t;aux++){
			printf("     ");
		}
        printf("  ------------\n");
		if(nodo->mama!= NULL){
    		for(aux=0;aux<t;aux++){
			printf("     ");
            }
            printf("      \\\n");
            for(aux=0;aux<t;aux++){
                printf("     ");
            }
            printf("       \\\n");
            for(aux=0;aux<t;aux++){
                printf("     ");
            }
            printf("        \\\n");
		}
		imGrafico(nodo->mama, t+2);
	}

}

//Funcion encargada de imprimir a todas las madres
void iMom(struct Nodo *nodo){

    if(nodo != NULL){
        if(nodo->mama != NULL){
            printf("\nLa Mama de %s es %s.", nodo->nombre, nodo->mama);
        }
        else{
            printf("\nLa Mama de %s es Desconocida.", nodo->nombre);
        }
        iMom(nodo->mama);
        iMom(nodo->papa);
    }
}

//Funcion encargada de imprimir a todos los padres
void iDad(struct Nodo *nodo){

    if(nodo != NULL){
        if(nodo->mama != NULL){
            printf("\nEl Padre de %s es %s.", nodo->nombre, nodo->papa);
        }
        else{
            printf("\nEl Padre de %s es Desconocido.", nodo->nombre);
        }

        //recursividad
        iDad(nodo->mama);
        iDad(nodo->papa);
    }
}

//Funcion encargada de imprimir los nombres de quienes no tienen progenitores
void bNul(struct Nodo *nodo){
    if(nodo != NULL){
        if(nodo->papa == NULL && nodo->mama == NULL){
            printf("\n- %s (no tiene padre ni madre)", nodo->nombre); //en caso de que le falten ambos padres
        }
        else if(nodo->papa == NULL){
            printf("\n- %s (no tiene padre)", nodo->nombre);//en caso de que le falte papa
        }
        else if(nodo->mama == NULL){
            printf("\n- %s (no tiene madre)", nodo->nombre);//en caso de que le falte mama
        }
        //recursividad
        bNul(nodo->mama);
        bNul(nodo->papa);
    }
}

void buscandoPadre(struct Nodo *nodo){

    //Declaracion de variables
    char resp[100], desi[100];

    if(nodo!= NULL){
        if(strcmp(nodo->nombre,posible) == 0){
            printf("\n\nSe ha encontrado a la persona escogida"); //en caso de que se encuentre a la persona solicitada
            encontrado = 1;
            while(desi[0] != '1' && desi[0] != '2'){
                printf("\nA quien desea insertar?\n1. Padre\n2. Madre\n");//Opcion de insertar mama o papa
                fflush(stdin);
                scanf(" %c", &desi);
            }

            if(desi[0]=='1'){
                if(nodo->papa == NULL){
                    printf("\nIngresando datos del padre de %s\n", nodo->nombre);
                    nodo->papa = malloc(sizeof(struct Nodo));//creacion de nodo para papa
                    system("PAUSE");
                    crear(nodo->papa);
                }
                else{
                    printf("\n\n%s ya tiene un padre existente en el arbol.\n\n", nodo->nombre);//en caso de que ya exista
                }
            }
            else if(desi[0]=='2'){
                if(nodo->mama == NULL){
                    printf("\nIngresando datos de la madre de %s\n", nodo->nombre);
                    nodo->mama = malloc(sizeof(struct Nodo));//creacion de nodo para mama
                    system("PAUSE");
                    crear(nodo->mama);
                }
                else{
                    printf("\n\n%s ya tiene una madre existente en el arbol.\n\n", nodo->nombre);//en caso de que ya exista
                }

            }
        }
        else{
            //recursividad
            buscandoPadre(nodo->mama);
            buscandoPadre(nodo->papa);
        }
    }
}

void main(){
    //Declaracion de variables
    char desi, a[100], e[100];
    struct Nodo *nodo;
    int i=0;

    //Creacion de nodo raiz
    nodo = malloc(sizeof(struct Nodo));

    //Ingreso del nombre del usuario
    printf("Antes de iniciar....");
    printf("\nIngrese su nombre: ");
    gets(nodo->nombre);

    pr = 1;

    while(desi != '6'){
        system("cls");
        //TITULO
        printf("\n\t\t\tArbol genealogico de %s", nodo->nombre);

        //Menu de proyecto
        printf("\n\n1. Hoja de presentacion\n2. Crear arbol genealogico\n3. Insertar en arbol ascendientes\n4. Imprimir Arbol(Graficamente)\n5. Generar reportes\n6. Salir del programa\n");
        scanf(" %c", &desi);

        while(desi != '1'&& desi != '2' && desi !='3' && desi != '4' && desi != '5' && desi != '6'){
            printf("ERROR. Opcion no valida, ingrese un numero valido:");
            scanf(" %c", &desi);
        }
        //validacion de entrada de opciones
        if(desi=='1'){//Opcion para acceder a la hoja de presentacion
            system("cls");
            paginaPresentacion();
            system("cls");
        }
        if(desi=='2'){//Opcion para crear arbol genealogico
            crear(nodo);
            printf("\n\nUsted ha terminado de crear su arbol genealogico en memoria\n\n");

            system("PAUSE");
        }
        if(desi=='3'){//Opcion para insertar ascendientes en el arbol genealogico
            if(nodo->edad == 0){
                printf("ERROR. No se puede insertar ya que no hay un arbol existente.\n");
                printf("Se recomienda elegir la opcion 2\n");

                system("PAUSE");
            }
            else{
                do{
                    system("cls");
                    encontrado = 0;
                    printf("\nPERSONAS SIN ASCENDIENTES: \n");
                    bNul(nodo);
                    printf("\n");
                    fflush(stdin);
                    printf("\n\nIngrese el nombre de la persona a la que desea insertarle ascendientes: ");
                    gets(posible);

                    buscandoPadre(nodo);

                    if(encontrado == 0){
                        printf("\n\nEsta persona no existe en este arbol genealogico\n\n");
                    }

                    d = 0;
                    while(d != 1 && d != 2){
                       printf("\n\nDesea seguir insertando?\n1. Si 2. No\n");
                       scanf("%d", &d);

                    }
                    system("PAUSE");
                }while(d==1);
            }
        }
        else if(desi=='4'){//Opcion para imprimir el arbol genealogico de forma grafica
            if(nodo->edad == 0){
                printf("ERROR. No se puede insertar ya que no hay un arbol existente.\n");
                printf("Se recomienda elegir la opcion 2\n");

                system("PAUSE");
            }
            else{
                printf("\nGenerando arbol grafico\n\n");
                imGrafico(nodo, i);
                printf("\n");
                system("PAUSE");

            }
        }
        else if(desi=='5'){//Opcion para imprimir los reportes del arbol genealogico
            if(nodo->edad == 0){
                printf("ERROR. No se puede insertar ya que no hay un arbol existente.\n");
                printf("Se recomienda elegir la opcion 2\n");

                system("PAUSE");
            }
            else{
                strcpy(a, nodo->nombre);
                for (int i = 0; a[i] != '\0'; i++){
                    a[i] = toupper(a[i]);
                }
                printf("\n\t\t\t\tARBOL GENEALOGICO DE %s", a);
                printf("\n\n\t\t\tNOMBRES DE TODOS LOS PROGENITORES FEMENINOS\n");
                iMom(nodo);

                printf("\n\n\t\t\tNOMBRES DE TODOS LOS PROGENITORES MASCULINOS\n");
                iDad(nodo);

                printf("\n\n\t\t\tTODOS LOS PADRES CON SUS HIJOS\n");
                Impresion(nodo);

                printf("\n\n\tNACIONALIDAD DE LOS DESCENDIENTES\n");
                nacionDesc(nodo);

                printf("\n\n\t\tPROGENITOR DE MAYOR EDAD Y MENOR EDAD\n");
                fflush(stdin);
                edadM(nodo->mama);
                edadM(nodo->papa);

                printf("\n\nEl/la progenitor/a con mayor edad es %s y tiene %d",auximaa, max);
                printf("\nEl/la progenitor/a con menor edad es %s y tiene %d\n\n", auximii, min);

                system("PAUSE");
            }
        }
        else if(desi=='6'){//Opcion para finalizar el programa
            printf("\n\nUsted ha finalizado su recorrido en este proyecto");
            printf("\n\nDesarrollado por Viviana Davis, Joana Gonzalez y Juan Hincapie");
        }
    }
}
