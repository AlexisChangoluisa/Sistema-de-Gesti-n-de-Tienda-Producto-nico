#include <stdio.h>

int main() {
    
    int id;
    char nombre[50];
    int stock = 0;
    float precio = 0.0;
    
    int opcion;
    int cantidad;
    float descuento, precio_final, total_venta;
    float ganancias = 0.0;

  
    printf("\n==================================================\n");
    printf("\tREGISTRO INICIAL DEL PRODUCTO\n");
    printf("==================================================\n");
    
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);
    
    
    while ((getchar()) != '\n'); 
    
    printf("Ingrese el nombre del producto: ");
    fgets(nombre, sizeof(nombre), stdin);
    
    for(int i = 0; i < 50; i++) {
        if(nombre[i] == '\n') {
            nombre[i] = '\0';
            break;
        }
    }
    
   
    do {
        printf("Ingrese la cantidad inicial en stock (mayor a 0): ");
        scanf("%d", &stock);
        if (stock < 0) printf("\t[!] Error: El stock no puede ser negativo.\n");
    } while (stock < 0);
    
    do {
        printf("Ingrese el precio unitario (mayor a 0): $");
        scanf("%f", &precio);
        if (precio <= 0) printf("\t[!] Error: El precio debe ser mayor a 0.\n");
    } while (precio <= 0);

    do {
        printf("\n==================================================\n");
        printf("\tSISTEMA DE GESTION DE TIENDA\n");
        printf("==================================================\n");
        printf("\t1. Vender unidades\n");
        printf("\t2. Reabastecer producto\n");
        printf("\t3. Consultar informacion del producto\n");
        printf("\t4. Ver ganancias acumuladas\n");
        printf("\t5. Salir\n");
        printf("==================================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        printf("\n"); 
        
      
        switch(opcion) {
            case 1: 
                printf("--- VENTA DE PRODUCTO ---\n");
                if (stock == 0) {
                    printf("\t[!] Operacion denegada: No hay stock disponible.\n");
                    break;
                }
                
                printf("Unidades a vender (Stock actual: %d): ", stock);
                scanf("%d", &cantidad);
                
                
                if (cantidad <= 0) {
                    printf("\t[!] Error: Debe ingresar una cantidad valida mayor a 0.\n");
                } else if (cantidad > stock) {
                    printf("\t[!] Error: Stock insuficiente. Solo dispone de %d unidades.\n", stock);
                } else {
                    
                    printf("Ingrese el porcentaje de descuento a aplicar (0 si no hay descuento): ");
                    scanf("%f", &descuento);
                    
                    if (descuento < 0 || descuento > 100) {
                        printf("\t[!] Error: Descuento invalido. Se aplicara 0%%.\n");
                        descuento = 0;
                    }
                    
                   
                    precio_final = precio - (precio * (descuento / 100));
                    total_venta = cantidad * precio_final;
                    
                    stock -= cantidad; 
                    ganancias += total_venta; 
                    
                    printf("\t[+] Venta procesada exitosamente.\n");
                    printf("\t    Total a cobrar:\t$%.2f (Descuento del %.0f%%)\n", total_venta, descuento);
                }
                break;
                
            case 2: 
                printf("--- REABASTECIMIENTO ---\n");
                printf("Unidades a agregar al stock: ");
                scanf("%d", &cantidad);
                
                if (cantidad <= 0) {
                    printf("\t[!] Error: Debe ingresar una cantidad mayor a 0.\n");
                } else {
                    stock += cantidad; 
                    printf("\t[+] Reabastecimiento exitoso. Nuevo stock: %d\n", stock);
                }
                break;
                
            case 3: 
                printf("--- INFORMACION DEL PRODUCTO ---\n");
                printf("\tID:\t\t%d\n", id);
                printf("\tNombre:\t\t%s\n", nombre);
                printf("\tPrecio base:\t$%.2f\n", precio);
                printf("\tStock actual:\t%d unidades\n", stock);
                break;
                
            case 4:
                printf("--- REPORTE FINANCIERO ---\n");
                printf("\tGanancias totales acumuladas:\t$%.2f\n", ganancias);
                break;
                
            case 5: 
                printf("\tSaliendo del sistema... \n\t¡Ejecucion finalizada!\n");
                break;
                
            default:
                printf("\t[!] Error: Opcion no valida. Intente de nuevo.\n");
        }
    } while(opcion != 5); 
    return 0;
}