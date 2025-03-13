#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define TAM 10

// Declaración de los vectores
int numeroPago[TAM];
char fecha[TAM][11];
char hora[TAM][6];
char cedula[TAM][20];
char nombre[TAM][50];
char apellido1[TAM][50];
char apellido2[TAM][50];
int numeroCaja[TAM];
int tipoServicio[TAM];
char numeroFactura[TAM][20];
float montoPagar[TAM];
float montoComision[TAM];
float montoDeducido[TAM];
float montoPagaCliente[TAM];
float vuelto[TAM];
int indice = 0; // Indice de pagos registrados

/**
 * @brief Función para posicionar el cursor en la consola
 *
 * @param x
 * @param y
 */
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/**
 * @brief Función encargada de inicializar los vectores
 *
 */
void inicializarVectores()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("Inicializando vectores ");
    for (int i = 0; i < 3; i++) // Simula una barra de carga
    {
        gotoxy(28, 5);
        if (i == 0)
            printf(".  ");
        else if (i == 1)
            printf(".. ");
        else if (i == 2)
            printf("...");
        Sleep(500);
    }
    for (int i = 0; i < TAM; i++)
    {
        numeroPago[i] = 0;
        numeroCaja[i] = 0;
        tipoServicio[i] = 0;
        montoPagar[i] = 0.0;
        montoComision[i] = 0.0;
        montoDeducido[i] = 0.0;
        montoPagaCliente[i] = 0.0;
        vuelto[i] = 0.0;
        fecha[i][0] = '\0';
        hora[i][0] = '\0';
        cedula[i][0] = '\0';
        nombre[i][0] = '\0';
        apellido1[i][0] = '\0';
        apellido2[i][0] = '\0';
        numeroFactura[i][0] = '\0';
    }
    gotoxy(5, 6);
    printf("Vectores inicializados!\n");
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Funcion para realizar pagos
 *
 */
void realizarPagos()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("Realizar Pagos\n");
    if (indice >= TAM)
    {
        gotoxy(13, 20);
        printf("\nVectores llenos, no se pueden agregar mas pagos\n");
        return;
    }
    gotoxy(5, 7);
    printf("Ingrese la fecha (DD/MM/AAAA): ");
    scanf("%s", fecha[indice]);
    gotoxy(5, 8);
    printf("Ingrese la hora (HH:MM): ");
    scanf("%s", hora[indice]);
    gotoxy(5, 9);
    printf("Ingrese la cedula: ");
    scanf("%s", cedula[indice]);
    gotoxy(5, 10);
    printf("Ingrese el nombre: ");
    scanf("%s", nombre[indice]);
    gotoxy(5, 11);
    printf("Ingrese el primer apellido: ");
    scanf("%s", apellido1[indice]);
    gotoxy(5, 12);
    printf("Ingrese el segundo apellido: ");
    scanf("%s", apellido2[indice]);
    gotoxy(5, 13);
    printf("Ingrese el numero de factura: ");
    scanf("%s", numeroFactura[indice]);
    gotoxy(5, 14);
    printf("Ingrese el monto a pagar: ");
    scanf("%f", &montoPagar[indice]);

    gotoxy(5, 15);
    printf("Seleccione el tipo de servicio (1=Electricidad, 2=Telefono, 3=Agua): ");
    scanf("%d", &tipoServicio[indice]);

    // Calcular comisión
    if (tipoServicio[indice] == 1)
    {
        montoComision[indice] = montoPagar[indice] * 0.04;
    }
    else if (tipoServicio[indice] == 2)
    {
        montoComision[indice] = montoPagar[indice] * 0.055;
    }
    else
    {
        montoComision[indice] = montoPagar[indice] * 0.065;
    }

    montoDeducido[indice] = montoPagar[indice] - montoComision[indice];

    gotoxy(5, 16);
    printf("Ingrese el monto pagado por el cliente: ");
    do
    {
        scanf("%f", &montoPagaCliente[indice]);
        if (montoPagaCliente[indice] < montoPagar[indice])
        {
            gotoxy(5, 17);
            printf("Monto insuficiente. Ingrese un monto valido: ");
        }
    } while (montoPagaCliente[indice] < montoPagar[indice]);

    vuelto[indice] = montoPagaCliente[indice] - montoPagar[indice];

    numeroPago[indice] = indice + 1;
    numeroCaja[indice] = (rand() % 3) + 1;

    indice++;
    gotoxy(5, 18);
    printf("Pago registrado correctamente. Numero de Pago: %d\n", numeroPago[indice - 1]);
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Función para consultar pagos
 *
 */
void consultarPagos()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("Consultar Pagos\n");
    int numPago, localIndice = -1;
    gotoxy(5, 7);
    printf("Ingrese el numero de pago a consultar: ");
    scanf("%d", &numPago);

    for (int i = 0; i < indice; i++)
    {
        if (numeroPago[i] == numPago)
        {
            localIndice = i;
            break;
        }
    }

    if (localIndice == -1)
    {
        printf("\nPago no encontrado.\n");
        return;
    }

    gotoxy(5, 8);
    printf("Pago encontrado:\n");
    gotoxy(5, 9);
    printf("Fecha: %s\n", fecha[localIndice]);
    gotoxy(5, 10);
    printf("Hora: %s\n", hora[localIndice]);
    gotoxy(5, 11);
    printf("Cedula: %s\n", cedula[localIndice]);
    gotoxy(5, 12);
    printf("Nombre: %s %s %s\n", nombre[localIndice], apellido1[localIndice], apellido2[localIndice]);
    gotoxy(5, 13);
    printf("Numero de Factura: %s\n", numeroFactura[localIndice]);
    gotoxy(5, 14);
    printf("Monto a Pagar: %.2f\n", montoPagar[localIndice]);
    gotoxy(5, 15);
    printf("Monto Comision: %.2f\n", montoComision[localIndice]);
    gotoxy(5, 16);
    printf("Monto Deducido: %.2f\n", montoDeducido[localIndice]);
    gotoxy(5, 17);
    printf("Monto Pagado: %.2f\n", montoPagaCliente[localIndice]);
    gotoxy(5, 18);
    printf("Vuelto: %.2f\n", vuelto[localIndice]);
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Función para modificar pagos
 *
 */
void modificarPagos()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("Modificar Pagos\n");
    int numPago, localIndice = -1;
    gotoxy(5, 7);
    printf("Ingrese el numero de pago a modificar: ");
    scanf("%d", &numPago);

    for (int i = 0; i < indice; i++)
    {
        if (numeroPago[i] == numPago)
        {
            localIndice = i;
            break;
        }
    }

    if (localIndice == -1)
    {
        gotoxy(23, 20);
        printf("Pago no encontrado.\n");
        return;
    }

    gotoxy(5, 8);
    printf("Ingrese la nueva fecha (DD/MM/AAAA): ");
    scanf("%s", fecha[localIndice]);
    gotoxy(5, 9);
    printf("Ingrese la nueva hora (HH:MM): ");
    scanf("%s", hora[localIndice]);
    gotoxy(5, 10);
    printf("Ingrese la nueva cedula: ");
    scanf("%s", cedula[localIndice]);
    gotoxy(5, 11);
    printf("Ingrese el nuevo nombre: ");
    scanf("%s", nombre[localIndice]);
    gotoxy(5, 12);
    printf("Ingrese el nuevo primer apellido: ");
    scanf("%s", apellido1[localIndice]);
    gotoxy(5, 13);
    printf("Ingrese el nuevo segundo apellido: ");
    scanf("%s", apellido2[localIndice]);
    gotoxy(5, 14);
    printf("Ingrese el nuevo numero de factura: ");
    scanf("%s", numeroFactura[localIndice]);
    gotoxy(5, 15);
    printf("Ingrese el nuevo monto a pagar: ");
    scanf("%f", &montoPagar[localIndice]);

    gotoxy(5, 16);
    printf("Seleccione el nuevo tipo de servicio (1=Electricidad, 2=Telefono, 3=Agua): ");
    scanf("%d", &tipoServicio[localIndice]);

    // Recalculo comisiones y deducciones
    if (tipoServicio[localIndice] == 1)
    {
        montoComision[localIndice] = montoPagar[localIndice] * 0.04;
    }
    else if (tipoServicio[localIndice] == 2)
    {
        montoComision[localIndice] = montoPagar[localIndice] * 0.055;
    }
    else
    {
        montoComision[localIndice] = montoPagar[localIndice] * 0.065;
    }

    montoDeducido[localIndice] = montoPagar[localIndice] - montoComision[localIndice];

    gotoxy(5, 17);
    printf("Ingrese el nuevo monto pagado por el cliente: ");
    do
    {
        scanf("%f", &montoPagaCliente[localIndice]);
        if (montoPagaCliente[localIndice] < montoPagar[localIndice])
        {
            gotoxy(5, 18);
            printf("Monto insuficiente. Ingrese un monto valido: ");
        }
    } while (montoPagaCliente[localIndice] < montoPagar[localIndice]);

    vuelto[localIndice] = montoPagaCliente[localIndice] - montoPagar[localIndice];

    gotoxy(5, 19);
    printf("Pago modificado correctamente.\n");
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Función para eliminar pagos
 *
 */
void eliminarPagos()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("ELIMINAR PAGOS\n");
    int numPago, localIndice = -1;
    gotoxy(5, 7);
    printf("Ingrese el numero de pago a eliminar: ");
    scanf("%d", &numPago);

    for (int i = 0; i < indice; i++)
    {
        if (numeroPago[i] == numPago)
        {
            localIndice = i;
            break;
        }
    }

    if (localIndice == -1)
    {
        printf("\nPago no encontrado.\n");
        return;
    }

    gotoxy(5, 8);
    printf("Esta seguro de eliminar el pago? (S/N): ");
    char confirmacion;
    scanf(" %c", &confirmacion);

    if (confirmacion == 'S' || confirmacion == 's')
    {
        for (int i = localIndice; i < indice - 1; i++)
        {
            numeroPago[i] = numeroPago[i + 1];
            montoPagar[i] = montoPagar[i + 1];
            montoComision[i] = montoComision[i + 1];
            montoDeducido[i] = montoDeducido[i + 1];
            montoPagaCliente[i] = montoPagaCliente[i + 1];
            vuelto[i] = vuelto[i + 1];
        }
        indice--;
        gotoxy(5, 9);
        printf("La informacion ya fue eliminada.\n");
    }
    else
    {
        gotoxy(5, 10);
        printf("La informacion no fue eliminada.\n");
    }
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Función para ver todos los pagos
 *
 */
void verTodosLosPagos()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("Ver Todos los Pagos\n");
    gotoxy(5, 7);
    printf("Lista de todos los pagos:\n");
    for (int i = 0; i < indice; i++)
    {
        gotoxy(5, 8);
        printf("Pago #%d - Fecha: %s, Monto: %.2f\n", numeroPago[i], fecha[i], montoPagar[i]);
    }
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Función para ver pagos por tipo de servicio
 *
 */
void verPagosPorTipoServicio()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("VER PAGOS POR TIPO DE SERVICIO\n");
    int tipo;
    gotoxy(5, 7);
    printf("Ingrese el tipo de servicio a buscar (1=Electricidad, 2=Teléfono, 3=Agua): ");
    scanf("%d", &tipo);
    gotoxy(5, 8);
    printf("Pagos del tipo seleccionado:\n");
    for (int i = 0; i < indice; i++)
    {
        if (tipoServicio[i] == tipo)
        {
            gotoxy(5, 9);
            printf("Pago #%d - Fecha: %s, Monto: %.2f\n", numeroPago[i], fecha[i], montoPagar[i]);
        }
    }
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Función para ver pagos por código de caja
 *
 */
void verPagosPorCodigoCaja()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("VER PAGOS POR CODIGO DE CAJA\n");
    int codigo;
    gotoxy(5, 7);
    printf("Ingrese el codigo de caja a buscar (1, 2 o 3): ");
    scanf("%d", &codigo);
    gotoxy(5, 8);
    printf("Pagos registrados en la caja %d:\n", codigo);
    for (int i = 0; i < indice; i++)
    {
        if (numeroCaja[i] == codigo)
        {
            gotoxy(5, 9);
            printf("Pago #%d - Fecha: %s, Monto: %.2f\n", numeroPago[i], fecha[i], montoPagar[i]);
        }
    }
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Función para ver el dinero comisionado por servicios
 *
 */
void verDineroComisionado()
{
    system("cls");
    gotoxy(23, 2);
    printf("CENTRO DE PAGO DE SERVICIOS\n");
    gotoxy(5, 3);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 22);
    printf("-----------------------------------------------------------\n");
    gotoxy(5, 5);
    printf("VER DINERO COMISIONADO\n");
    float comisionElectricidad = 0, comisionTelefono = 0, comisionAgua = 0;
    int transaccionesElectricidad = 0, transaccionesTelefono = 0, transaccionesAgua = 0;

    for (int i = 0; i < indice; i++)
    {
        if (tipoServicio[i] == 1)
        {
            comisionElectricidad += montoComision[i];
            transaccionesElectricidad++;
        }
        else if (tipoServicio[i] == 2)
        {
            comisionTelefono += montoComision[i];
            transaccionesTelefono++;
        }
        else if (tipoServicio[i] == 3)
        {
            comisionAgua += montoComision[i];
            transaccionesAgua++;
        }
    }

    gotoxy(5, 7);
    printf("Resumen de dinero comisionado:\n");
    gotoxy(5, 8);
    printf("Electricidad: %.2f (Transacciones: %d)\n", comisionElectricidad, transaccionesElectricidad);
    gotoxy(5, 9);
    printf("Telefono: %.2f (Transacciones: %d)\n", comisionTelefono, transaccionesTelefono);
    gotoxy(5, 10);
    printf("Agua: %.2f (Transacciones: %d)\n", comisionAgua, transaccionesAgua);
    gotoxy(16, 21);
    printf("Presiona la tecla espacio para continuar");
}

/**
 * @brief Función para mostrar el submenu de reportes
 *
 */
void mostrarSubmenuReportes()
{
    int opcion;
    do
    {
        system("cls");
        gotoxy(23, 2);
        printf("CENTRO DE PAGO DE SERVICIOS\n");
        gotoxy(5, 3);
        printf("-----------------------------------------------------------\n");
        gotoxy(5, 22);
        printf("-----------------------------------------------------------\n");
        gotoxy(5, 5);
        printf("SUBMENU REPORTES\n");
        gotoxy(5, 7);
        printf("1. Ver todos los Pagos\n");
        gotoxy(5, 8);
        printf("2. Ver Pagos por tipo de Servicio\n");
        gotoxy(5, 9);
        printf("3. Ver Pagos por codigo de Caja\n");
        gotoxy(5, 10);
        printf("4. Ver Dinero Comisionado por servicios\n");
        gotoxy(5, 11);
        printf("5. Regresar al Menu Principal\n");
        gotoxy(5, 13);
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            verTodosLosPagos();
            break;
        case 2:
            verPagosPorTipoServicio();
            break;
        case 3:
            verPagosPorCodigoCaja();
            break;
        case 4:
            verDineroComisionado();
            break;
        case 5:
            gotoxy(5, 14);
            printf("Regresando al menu principal...");
            break;
        default:
            gotoxy(22, 21);
            printf("Opcion invalida, intente de nuevo");
        }
        _getch(); // Pausa para ver el resultado
    } while (opcion != 5);
}

int main()
{
    int opcion;
    do
    {
        system("cls");
        gotoxy(23, 2);
        printf("CENTRO DE PAGO DE SERVICIOS\n");
        gotoxy(5, 3);
        printf("-----------------------------------------------------------\n");
        gotoxy(5, 22);
        printf("-----------------------------------------------------------\n");
        gotoxy(5, 5);
        printf("MENU PRINCIPAL\n");
        gotoxy(5, 7);
        printf("1. Inicializar Vectores\n");
        gotoxy(5, 8);
        printf("2. Realizar Pagos\n");
        gotoxy(5, 9);
        printf("3. Consultar Pagos\n");
        gotoxy(5, 10);
        printf("4. Modificar Pagos\n");
        gotoxy(5, 11);
        printf("5. Eliminar Pagos\n");
        gotoxy(5, 12);
        printf("6. Submenu Reportes\n");
        gotoxy(5, 13);
        printf("7. Salir\n");
        gotoxy(5, 15);
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            inicializarVectores();
            break;
        case 2:
            realizarPagos();
            break;
        case 3:
            consultarPagos();
            break;
        case 4:
            modificarPagos();
            break;
        case 5:
            eliminarPagos();
            break;
        case 6:
            mostrarSubmenuReportes();
            break;
        case 7:
            system("cls");
            gotoxy(25, 11);
            printf("Saliendo");
            for (int i = 0; i < 3; i++)
            {
                gotoxy(34, 11);
                if (i == 0)
                    printf(".  ");
                else if (i == 1)
                    printf(".. ");
                else if (i == 2)
                    printf("...");
                Sleep(500);
            }
            break;
        default:
            gotoxy(22, 21);
            printf("Opcion invalida, intente de nuevo");
        }
        _getch();
    } while (opcion != 7);

    return 0;
}