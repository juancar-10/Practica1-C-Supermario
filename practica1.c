// García Ventura Juan Carlos
#include "stdio.h"
#include "math.h"
#include "conio.h"

void ejercicio1(){                          //Hace que se ejecute el codigo cuando llamamos la ejercicio 1.

	float x = 0.0 , y = 0.0;				//Controlan la posición donde se encuentra el puntero//
	float radio=0.0;                        //Radio de la circunferencia
	float d1 = 0.0, d2 = 0.0, b1 = 0.0, b2 = 0.0;				//ofrecen un margen para el cálculo de si la posición está en la circunferencia
	float a = 0.0,c = 0.0; 					//para el cálculo de la circunferencia

	printf("Tamanyo?: ");
	scanf("%f", &radio);

	if(radio >=5.0){                               //Condición principal del ejercicio es que el radio que demos sea mayor que 5.
		for (y = 0; y <= radio*2; y=y+0.4){        //Bucle for para que el cursor se mueva por el eje Y de abajo a arriba entre 0 y el punto que es 2 veces el radio.
			for (x = 0; x <= radio; x=x+0.1){      //Bucle anidado for para que el cursor se mueva por el eje X de 0 a el punto que es el valor del radio. 

				a = pow(x-radio, 2)+pow(y-radio, 2);          //
				b1 = pow(radio, 2)+0.5;                       //
				b2 = pow(radio, 2)-0.5;                       //
				c = pow((x-(radio*1.3)), 2)+pow(y-radio, 2);  // Declaramos a, b1, b2, c, d1 y d2 en base a la ecuación de la circunferencia, pero a b1, b2, c1 y
				d1 = pow(radio, 2)+0.5;                       //  c2 les sumamos o restamos 0.5 porque va a ser el rango que vamos a permitir para que
				d2 = pow(radio, 2)-0.5;                       //  si se cumplen las condiciones del if se imprima en pantalla o si no se cumplen que se imprima un 
                                                              //  hueco en blanco.
				if ((a<b1 && a>b2) || (c<d1 && c>d2)){        //
					printf("*");                              //
				}                                             //
				else{                                         //
					printf(" ");                              //
				}                                             //

			}
			printf("\n");                                     // Realizamos un salto de linea cuando ha terminado de realizarse cada ciclo del bucle for para x
		}                                                     //  para que así cuando se cumpla el ciclo del bucle y no se siga imprimiendo en la misma linea.
	}	
	else{                                                     //Si no se cumple la condición del bucle if de que el radio sea mayor que 5,
		printf("No moon");                                    // hacemos que aparezca en pantalla "No moon".
	}
		
}

void ejercicio2(){                    //Hace que se ejecute el código cuando se llama al ejercicio 2.

	int tooper = 0, harriet = 0, spewart = 0, rango = 0; //Almacenan los códigos
	int resto = 0, resto2 = 0, resto3 = 0, resto4 = 0;	//almacena el resto de la división del código por 10 para aislar cada cifra
	int expo = 0, expo2 = 0, expo3 = 0, expo4 = 0;	//variable auxiliar de cálculo
	int n = 0, i = 0, j = 0, k = 0;                //para controles de bucles 
	int p1 = 0, p1_2 = 0, p2 = 0, p2_2 = 0;        //variables utilizadas para acumular valores en el cálculo del código    
	int acumula1 = 0, acumula2 = 0;					//acumula, sumando, el cálculo hecho para cada posición de cada código
	int p3 = 0, p4 = 0, p3_2 = 0, p4_2 = 0;			//variables utilizadas para acumular valores en el cálculo del código
	int codigo1 = 0, codigo2 = 0;					//variables de los códigos de desactivación
	int mod1 = 0, mod2 = 0, mod3 = 0, mod4 = 0;		//variables auxiliares para guardar el resultado del resto de dividir por 11

	printf("Tooper, introduce el codigo: ");
	scanf("%d", &tooper);                    //Tooper introduce el código y tiene que estarentre 1000 y 9999.
	if(tooper >= 1000 && tooper <= 9999){

		printf("Harriet, introduce el codigo: ");
		scanf("%d", &harriet);                   //Harriet introduce el código y tiene que estar entre 1000 y 9999.
		if(harriet >= 1000 && harriet <= 9999){  

			printf("Spewart, introduce el codigo: ");
			scanf("%d", &spewart);                   //Spewart introduce el código y tiene que estar entre 10000 y 99999.
			if(spewart >= 10000 && spewart <= 99999){

				printf("Rango, introduce el codigo: ");
				scanf("%d", &rango);                   //Rango introduce el código y tiene que estar entre 10000 y 99999.
				if(rango >= 10000 && rango <= 99999){

					for(n = 5, i = 9; n > 1 && i > 5; n-- && i--){ //Bucle for usando 2 variables (que son la posición del dígito) una para Tooper y otra para Harriet.
							                                       
						resto = tooper % 10;          //Almacenamos el resto de la división del codigo de Tooper entre 10 para así poder invertir el número.      
						tooper = tooper / 10;         //Dividimos el valor de tooper entre 10 para que cuando hagamos el modulo entre 10 no sea siempre con el mismo número.        
						resto2 = harriet % 10;        //Almacenamos el resto de Harriet habiendo hecho lo mismo.        
						harriet = harriet / 10;       //Dividimos entre 10 por lo mismo que con tooper.         
						expo = pow(2, n);             //Almacenamos en una variable expo -------> 2^n.           
						mod1 = expo % 11;             //Cogemos el resto de la variable expo entre 11 y la almacenamos en una variable mod1. 
						p1 = resto*mod1;              //Realizamos el primer paso del cálculo del dígito al multiplicar el número invertido por el resto de la división entre 2^posición y 11.              
						acumula1 = acumula1 + p1;     //Creamos una variable para poder ir sumando los valores que obtengamos durante la repetición del bucle con el paso anterior.              
						expo2 = pow(2, i);            //Realizamos lo mismo que los cuatro ultimos pasos pero para harriet (almacenamos todo en distintas variables, menos la final que va a quedar todo almacenado en la variable acumula1).
						mod2 = expo2 % 11;            //""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
						p1_2 = resto2*mod2;           //""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
						acumula1 = acumula1 + p1_2;   //""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

					}					
					for(j = 4, k = 9; j >= 0 && k > 4; j-- && k--){ 
							
						resto3 = spewart % 10;
						spewart = spewart / 10;
						resto4 = rango % 10;
						rango = rango / 10;
						expo3 = pow(2, j);
						mod3 = expo3 % 11;                      //Lo mismo que en el bucle for anterior solo que para Spewart y Rango
						p2 = resto3*mod3;
						acumula2 = acumula2 + p2;
						expo4 = pow(2, k);
						mod4 = expo4 % 11;
						p2_2 = resto4*mod4;
						acumula2 = acumula2 + p2_2;

					}

					p3 = acumula1 % 11;            //El paso 3 que es la suma de todos los numeros obtenidos en el paso 2 almacenados en acumula modulo 11 (resto).
					p4 = 11 - p3;                  //El paso 4 que es 11 menos el valor almacenado en la variable del paso 3.
					p3_2 = acumula2 % 11;          //Igual que el anterior paso 3 solo que para spewart y rango.
					p4_2 = 11 - p3_2;              //Igual que el anterior paso 4 solo que para spewart y rango.

					if(p4 < 10){          //Si el numero obtenido en el 1 er paso 4 es menor que diez el codigo de desactivación es el mismo numero que el paso 4.
						codigo1 = p4;
					}
					else if(p4 == 10){   //Si el numero obtenido en el 1 er paso 4 es igual que 10 el codigo de desactivación es 1. 
						codigo1 = 1;
					}
					else if(p4 == 11){   //Si el numero obtenido en el 1 er paso 4 es igual que 11 el código de desactivación es 0.
						codigo1 = 0;
					}
					printf("El 1er digito es: %d\n", codigo1);     //Imprime en pantalla el valor del 1 er código.

					if(p4_2 < 10){      //Lo mismo que la 1º condición del anterior if solo que para el 2º paso 4.
						codigo2 = p4_2;
					}
					else if(p4_2 == 10){   //Lo mismo que la 2º condición del anterior if solo que para el 2º paso 4.
						codigo2 = 1;
					}
					else if(p4_2 == 11){  //Lo mismo que la 3º condición del anterior if solo que para el 2º paso 4.
						codigo2 = 0;
					}
					printf("El 2 digito es: %d\n\n", codigo2);      //Imprime en pantalla el valor del 2º código.

				}
				else{
					printf("Codigo no valido\n\n");  //Si no se cumple el if de Rango imprime en pantalla "Código no válido" y luego vuelve a pedir el número. 
				}
					
			}
			else{
				printf("Codigo no valido\n\n");    //Si no se cumple el if de Spewart imprime en pantalla "Código no válido" y luego vuelve a pedir el número. 
			}
				
		}
		else{
			printf("Codigo no valido\n\n");   //Si no se cumple el if de Harriet imprime en pantalla "Código no válido" y luego vuelve a pedir el número. 
		}
			
	}
	else{
		printf("Codigo no valido\n\n");   //Si no se cumple el if de Tooper imprime en pantalla "Código no válido" y luego vuelve a pedir el número. 
	}
	
}

void ejercicio3(){             //Hace que se ejecute el código cuando se llama al ejercicio 3.

	int correcto = 0;										//variable auxiliar en decisiones (bandera), vale 0 si la condición no se cumple y 1 si se cumple
	int pasillos = 0, filas = 0, huecos = 0;				//variables para la configuración del almacén
	int pasillo_ini = 0, fila_ini = 1, hueco_ini = 1;		//variables que en cada momento van a guardar la posición del robot
	int pasillo_fin = 0, fila_fin = 0, hueco_fin = 0;       //Variables que van a guardar la posición de entrega
	int pasillo_rec = 0, fila_rec = 0, hueco_rec = 0;		//Variables que guardan la posición para recoger o almacenar
	int opcion_realizar = 0;
	int p = 0, f = 0, h = 0;

	do{
		printf("Numero de pasillos: ");
		scanf("%d", &pasillos);                                                    //Bucle do-while para que se pregunte todo el rato por el numero de pasillos
		if(pasillos < 1){                                                          // y hasta que no se da un numero de pasillos mayor que 1	, no deja de ejecutarse el bucle.
			printf("El numero de pasillos debe ser un positivo mayor que cero\n");
			correcto = 0;                                                          //Si el número de pasillos no es válido se selecciona a 0, si es válido a 1
		}
		else{
			correcto = 1;
		}
	} while (correcto == 0);														//el bucle se ejecuta mientras que no se haya metido un número de pasillos correcto

	do{ 
		printf("Numero de filas: ");                                            //Bucle do-while para que se pregunte todo el rato por el numero de filas 
		scanf("%d", &filas);                                                    // y hasta que no se da un numero de filas mayor que 1, no deja de ejecutarse el bucle.
		if(filas < 1){
			printf("El numero de filas debe ser un positivo mayor que cero\n");
			correcto = 0;                                                       //Si el número de filas no es válido se selecciona a 0, si es válido a 1
		}
		else{
			correcto = 1;
		}
	}while (correcto == 0);														//el bucle se ejecuta mientras que no se haya metido un número de filas correcto

	do{
		printf("Numero de huecos: ");                                         //Bucle do-while para que se pregunte todo el rato por el numero de huecos 
		scanf("%d", &huecos);                                                 // y hasta que no se da un numero de huecos mayor que 1, no deja de ejecutarse el bucle.
		if(huecos < 1){
			printf("El numero de huecos debe ser un positivo mayor que cero\n");
			correcto = 0;                                                     //Si el número de huecos no es válido se selecciona a 0, si es válido a 1
		}
		else{
			correcto = 1;
		}
	}while (correcto == 0);													//el bucle se ejecuta mientras que no se haya metido un número de huecos correcto

	pasillo_fin = pasillos+1;          //El pasillo en el que va a terminar el robot va a ser el numero inicial de pasillos que demos más uno
	fila_fin = 1;                      //La fila en la que va  aterminar el robot va a ser la 1
	hueco_fin = 1;                     //El hueco en el que va a terminar el robot va a ser el

	do{

		printf("Opcion a realizar: \n");
		printf("[1] Recoger \n");
		printf("[2] Almacenar \n");        //Imprime en pantalla un menú y escanea la opción a realizar 
		printf("[3] Salir \n");
		scanf("%d",&opcion_realizar);

		if(opcion_realizar == 1){          //Si la opción a realizar es 1 debe recoger en las coordenadas que le digamos e ir a entregar a las coordenadas de entrega
			printf("Donde recoger: ");     //Imprime en pantalla "Donde recoger"
				
			do{                         //Bucle do que se va a seguir ejecutando a no ser que se cumplan las condiciones del if que se han almacenado en una bandera.
				printf("\n Pasillo: ");  //Imprime en pantalla "Pasillo" y escanea el pasillo introducido, que es el pasillo de donde va a recoger.
				scanf("%d", &pasillo_rec);
				if ((pasillo_rec <= pasillos) && (pasillo_rec > 0)){  //Si el numero del pasillo que hemos introducido en el anterior orden es  
					correcto = 1;                                     // menor o igual que el numero de pasillos del almacén introducido, y mayor que 0 se termina de ejecutar el bucle.
				}
				else{
					correcto = 0;
					printf("Pasillo no valido");    //Si no se cumplen las condiciones del anterior if imprime en pantalla "Pasillo no válido".
				}
			}while(correcto==0);

			do{                       //Bucle do que se va a seguir ejecutando a no ser que se cumplan las condiciones del if que se han almacenado en una bandera.
				printf("\n Fila: ");  //Imprime en pantalla "Fila" y escanea la fila introducida, que es la fila de donde va a recoger.
				scanf("%d", &fila_rec);
				if ((fila_rec <= filas) && (fila_rec > 0)){   //Si el numero de la fila que hemos introducido en el anterior orden es  
					correcto = 1;                             // menor o igual que el numero de filas del almacén introducido, y mayor que 0 se termina de ejecutar el bucle.
				}
				else{
					correcto = 0;
					printf("Fila no valida");    //Si no se cumplen las condiciones del anterior if imprime en pantalla "Fila no válida".
				}
			}while(correcto == 0);

			do{                       //Bucle do que se va a seguir ejecutando a no ser que se cumplan las condiciones del if que se han almacenado en una bandera.
				printf("\n Hueco: "); //Imprime en pantalla "Hueco" y escanea el hueco introducido, que es el hueco de donde va a recoger.
				scanf("%d", &hueco_rec);
				if ((hueco_rec <= pasillos) && (hueco_rec > 0)){   //Si el numero del hueco que hemos introducido en el anterior orden es  
					correcto = 1;                                  // menor o igual que el numero de huecos del almacén introducido, y mayor que 0 se termina de ejecutar el bucle.
				}
				else{
					correcto = 0;
					printf("Hueco no valido");   //Si no se cumplen las condiciones del anterior if imprime en pantalla "Hueco no válida".
				}
			}while(correcto == 0);
			printf("posicion robot %3d , %3d , %3d \n", pasillo_ini,fila_ini,hueco_ini); //Imprime el pasillo, fila y hueco de donde empieza el robot.
			printf("posicion recogida %3d,  %3d,  %3d  \n", pasillo_rec, fila_rec, hueco_rec);  //Imprime el pasillo, fila y hueco donde va a recoger el robot.
			printf("Mov        pasillo        fila         hueco\n");
			printf("--------------------------------------------\n");
				
			if(pasillo_ini == pasillo_rec && fila_ini == fila_rec && hueco_ini == hueco_rec){ //Si el robot ya está en la posición donde hay que recoger, no se mueve y recoge directamente y a continuación va a la posición de entrega
				
				printf("Material recogido; Posicion actual robot %3d , %3d , %3d \n", pasillo_ini,fila_ini,hueco_ini); //Imprime junto a el pasillo, fila y hueco inicial diciendo que ahi es donde está.
				for(h = hueco_ini; h > hueco_fin; h--){                                        //Bucle for con print que se va a ejecutar hasta que el robot no llegue al hueco de entrega.
					printf("L     %3d                %3d               %3d \n",p,f,h);
				}
				for(f = fila_ini; f > fila_fin; f--){                                          //Bucle for con print que se va a ejecutar hasta que el robot no llegue a la fila de entrega.
					printf("D     %3d                %3d               %3d \n",p,f,h);
				}
				for(p = pasillo_ini; p < pasillo_fin+1; p++){                                  //Bucle for con print que se va a ejecutar hasta que el robot no llegue al pasillo de entrega.
					printf("F     %3d                %3d               %3d \n",p,f,h);
				}
				pasillo_ini = p-1;	//
				fila_ini = f;       //Se le asigna a las variables que controlan la posición actual del robot, la posición a la que ha llegado después el bucle.
				hueco_ini = h;      //
				printf("Material entregado; Posicion actual robot %3d , %3d , %3d \n", pasillo_ini,fila_ini,hueco_ini);
			}
			else{                //Si el robot no está en la posición a recoger, va hasta esa posición, recoge y posteriormente entrega
				p=pasillo_ini;	 //
				f=fila_ini;      //Asegura que el bucle empieza a contar desde la posición actual del robot
				h=hueco_ini;    //    
				if(pasillo_ini < pasillo_rec){                                               //Si el pasillo donde inicia el robot es menor que el de donde tiene que recoger:
					for(p = pasillo_ini; p < pasillo_rec; p++){                              // bucle for que hace que el robot se mueva desde el pasillo inical hasta el de recogida (aumentando).
						printf("F     %3d                %3d               %3d \n",p,f,h);   //Imprime el recorrido de pasillos (va aumentando el numero del pasillo)
					}
				}
				else{                                                                        //Si el pasillo donde inicia es mayor que el de donde tiene que recoger:
					for(p = pasillo_ini; p > pasillo_rec; p--){                              // bucle for que hace que el robot se mueva desde el pasillo donde esá hasta el de recogida (disminuyendo). 
						printf("B     %3d                %3d               %3d \n",p,f,h);   //Imprime el recorrido de pasillos (va disminuyendo el numero del pasillo)
					}
				} 
				if(fila_ini < fila_rec){                                                     //Si la fila donde inicia el robot es menor que donde tiene que recoger:
					for(f = fila_ini; f < fila_rec; f++){                                    // bucle for que hace que el robot se mueva desde la fila inicial hasta la de recogida (aumentando).
						printf("U     %3d                %3d               %3d \n",p,f,h);   //Imprime el recorrido de filas (va aumentando el numero de la fila)
					}
				}
				else{                                                                        //Si la fila donde inicia es mayor que la de donde tiene que recoger:
					for(f = fila_ini; f > fila_rec; f--){                                    // bucle for que hace que el robot se mueva desde la fila donde está hasta la de recogida (disminuyendo).
						printf("D     %3d                %3d               %3d \n",p,f,h);   //Imprime el recorrido de filas (va disminuyendo el numero de la fila)
					}					
				}	
				if(hueco_ini < hueco_rec){                                                   //Si el hueco donde inicia el robot es menor que el dedonde tiene que recoger:
					for(h=hueco_ini; h < hueco_rec+1; h++){                                  // bucle for que hace que el robot se mueva desde el hueco inical hasta el de recogida (aumentando).
						printf("R     %3d                %3d               %3d \n",p,f,h);   //Imprime el recorrido de huecos (va aumentando el numero del hueco)
					}					
				}
				else{                                                                        //Si el hueco donde inicia es mayor que el de donde tiene que recoger:
					for(h=hueco_ini; h > hueco_rec+1; h--){                                  // bucle for que hace que el robot se mueva desde el hueco donde está hasta el de recogida (disminuyendo).
						printf("L     %3d                %3d               %3d \n",p,f,h);   //Imprime el recorrido de filas (va disminuyendo el numero de la fila)
					}	
				}
					
				pasillo_ini = p;  //
				fila_ini = f;     //Se le asigna a las variables que controlan la posición actual del robot, la posición a la que ha llegado después el bucle.
				hueco_ini = h-1;  //
				printf("Material recogido; Posicion actual robot %3d , %3d , %3d \n", pasillo_ini,fila_ini,hueco_ini);  //Imprimimos que el material ya ha sido recogido en la posicion ...
				for(h = hueco_ini; h > hueco_fin; h--){                                 //
					printf("L     %3d                %3d               %3d \n",p,f,h);  //
				}                                                                       //
				for(f = fila_ini; f > fila_fin; f--){                                   //El robot va desde la posición actual, donde ha recogido, hasta la posición de entrega
					printf("D     %3d                %3d               %3d \n",p,f,h);  // 
				}                                                                       //
				for(p = pasillo_ini; p < pasillo_fin+1; p++){                           //
					printf("F     %3d                %3d               %3d \n",p,f,h);  //
				}                                                                       //
				pasillo_ini = p-1;  //
				fila_ini = f;       //Se le asigna a las variables que controlan la posición actual del robot, la posición a la que ha llegado después el bucle.
				hueco_ini = h;      //
				printf("Material entregado; Posicion actual robot %3d , %3d , %3d \n", pasillo_ini,fila_ini,hueco_ini);
			}
				
		}

		if(opcion_realizar == 2){       //Si señala la opción 2
			printf("Donde almacenar: ");  //Imprimimos "Donde almacenar"
				
			do{                                                      //
				printf("\n Pasillo: ");                              //                                      
				scanf("%d", &pasillo_rec);                           //
				if ((pasillo_rec < pasillos) && (pasillo_rec > 0)){  //
					correcto = 1;                                    //
				}                                                    //
				else{                                                //
					correcto = 0;                                    //
					printf("Pasillo no valido");                     //
				}                                                    //
			}while(correcto == 0);                                   //3 bucles do:
			do{                                                      // que hacen que mientra no se cumpla que el pasillo, fila y hueco donde vamos a almacenar la sea mayor que 0
				printf("\n Fila: ");                                 // y sea menor que el numero de filas, pasillos y huecos que habíamos introducido para determinar el tamaño     
				scanf("%d", &fila_rec);                              // del almacen se ejecute todo el rato pidiendo el pasillo, fila o hueco (segun donde no hayamos cumplido la condición)
				if ((fila_rec < filas) && (fila_rec > 0)){           //
						correcto = 1;                                // 
				}                                                    //
				else{                                                //
					correcto = 0;                                    //
					printf("Fila no valida");                        //
				}                                                    //
			}while(correcto == 0);                                   //
			do{                                                      //
				printf("\n Hueco: ");                                //                                     
				scanf("%d", &hueco_rec);                             //
				if ((hueco_rec < pasillos) && (hueco_rec > 0)){      //
					correcto = 1;                                    //
				}                                                    //
				else{                                                //
					correcto = 0;                                    //
					printf("Hueco no valido");                       //
				}                                                    //
			}while(correcto == 0);                                   //

			printf("posicion robot %3d , %3d , %3d \n", pasillo_ini,fila_ini,hueco_ini);         //Imprimimos la posición que tiene el robot
			printf("posición almacenaje %3d,  %3d,  %3d  \n", pasillo_rec, fila_rec, hueco_rec); //Imprimimos donde tiene que almacenar
			printf("Mov        pasillo        fila         hueco\n");
			printf("--------------------------------------------\n");

			for(h = hueco_ini; h > 1; h--){                                         //
				printf("L     %3d                %3d               %3d \n",p,f,h);  //
			}                                                                       //
			for(f = fila_ini; f > 1; f--){                                          //El robot antes de ir a donde tiene que ir a recoger tiene que pasar por el punto inicial
				printf("D     %3d                %3d               %3d \n",p,f,h);  // por eso bucles for para que se mueva desde el hueco, fila y pasillo  de donde esta al inicio,
			}                                                                       // en todos disminuyendo el numero del hueco, fila y pasillo.
			for(p = pasillo_ini; p > -1; p--){                                      //
				printf("B     %3d                %3d               %3d \n",p,f,h);  // 
			}                                                                       //

			pasillo_ini = p+1;  //
			fila_ini = f;       //Se le asigna a las variables que controlan la posición actual del robot, la posición a la que ha llegado después el bucle.
			hueco_ini = h;      //

			printf("Recogida de material; Posicion actual robot %3d , %3d , %3d \n", pasillo_ini,fila_ini,hueco_ini);
			for(p = pasillo_ini; p < pasillo_rec; p++){                            //
				printf("F     %3d                %3d               %3d \n",p,f,h); //
			}                                                                      //
			for(f = fila_ini; f < fila_rec; f++){                                  //Bucles for para mover el robot desde el pasillo, fila y hueco inicial al de recogida,
				printf("U     %3d                %3d               %3d \n",p,f,h); // aumentando la posición
			}                                                                      //
			for(h = hueco_ini; h < hueco_rec+1; h++){                              //
				printf("R     %3d                %3d               %3d \n",p,f,h); //
			}                                                                      //

			pasillo_ini = p;  //
			fila_ini = f;     //Se le asigna a las variables que controlan la posición actual del robot, la posición a la que ha llegado después el bucle.
			hueco_ini = h-1;  //
			printf("Material almacenado; Posicion actual robot %3d , %3d , %3d \n", pasillo_ini,fila_ini,hueco_ini); //Imprime la posición final del robot que es donde ha almacenado el material
				
		}

	}while(opcion_realizar == 1 || opcion_realizar == 2); //Condición de que el bucle do del menú se va a seguir ejecutando mientras la opción a elegir sea 1 o 2.

	printf("Saliendo del sistema\n");
	
}

int main(){                                         //Llamando a la función principal

	int menu_inicial = 0;

	printf("         U U U U\n");
    printf("         U U U U\n"); 
    printf("        U U U U U U U U\n"); 
    printf("        U U U U U U U U\n"); 
    printf("        D D D . . D .\n"); 
    printf("        D D D . . D .\n"); 
    printf("      D . D . . . D . . .\n"); 
    printf("      D . D . . . D . . .\n"); 
    printf("      D . D D . . . D . . .\n"); 
    printf("      D . D D . . . D . . .\n"); 
    printf("      D D . . . . D D D D\n"); 
    printf("      D D . . . . D D D D\n"); 
    printf("          . . . . . . .\n"); 
    printf("          . . . . . . . \n"); 
    printf("        D D U D D D\n");                 //Dibujo de Mario
    printf("        D D U D D D\n"); 
    printf("      D D D U D D U D D D\n"); 
    printf("      D D D U D D U D D D\n"); 
    printf("    D D D D U U U U D D D D\n"); 
    printf("    D D D D U U U U D D D D\n"); 
    printf("    . . D U . U U . U D . .\n"); 
    printf("    . . D U . U U . U D . .\n"); 
    printf("    . . . U U U U U U . . .\n"); 
    printf("    . . . U U U U U U . . .\n"); 
    printf("    . . U U U U U U U U . .\n"); 
    printf("    . . U U U U U U U U . .\n"); 
    printf("        U U U     U U U\n"); 
    printf("        U U U     U U U\n"); 
    printf("      D D D         D D D\n"); 
    printf("      D D D         D D D\n"); 
    printf("    D D D D         D D D D\n"); 
	printf(" \n");

	do{                                              //Bucle do-while que va a ejecutarse siempre que la opción a elegir no sea 4

		printf("1.- Ejercicio 1\n");
		printf("2.- Ejercicio 2\n");
		printf("3.- Ejercicio 3\n");
		printf("4.- Salir\n");                       //Imprimimos en pantalla el menú
		printf("\n");
		printf("Introduzca una opcion (1-4): ");
		scanf("%d", &menu_inicial);

		switch(menu_inicial){                        //Estructura de condición de casos
			case 1: ejercicio1(); break;             //Si elegimos 1 en el menú se va a llamar a la función void del ejercicio 1 para que lo ejecute
			case 2: ejercicio2(); break;             //Si elegimos 2 en el menú se va a llamar a la función void del ejercicio 2 para que lo ejecute
			case 3: ejercicio3(); break;             //Si elegimos 3 en el menú se va a llamar a la función void del ejercicio 3 para que lo ejecute
			case 4: printf("Saliendo..."); break;    //Si elegimos 4 se va a imprimir en pantalla "Saliendo..." y se va a romper la ejecución del bucle por lo que va a 
		}                                            // terminar de ejecutarse el codigo general
		
		if (menu_inicial > 4 || menu_inicial < 1){
			printf("ERROR: opcion introducida no valida\n");
		}
		
	} while(menu_inicial != 4);

	
	
}