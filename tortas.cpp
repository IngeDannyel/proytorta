#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define s scanf
#define p printf

struct menu{
int cantidad,costo;	
};

main()
{
	setlocale(LC_ALL,"esm");
	char sel, cin[100];
	int suma=0,sum_his=0,i,aux,num_ticket=0,sumat=0;
	FILE *arch;
    
	system ("color f0");
	struct menu c[4];
	
	for(i=0;i<4;i++) //Declaración de cantidades del menu
		c[i].cantidad=0;
	
  do
    {                 
     p("\n Total es de: %d\n\n", suma);
             //Esta parte del codigo se hace para la seleccion
        do
          { 
            arch=fopen("datos.txt","r");	//apertura de archivos
	          if (arch==NULL)                 
	    		     p("ERROR");
		        else
			        	{
		        while(feof(arch)==NULL)       //Verificar hasta que termine el archivo
		             {
		             fgets(cin,3,arch);  //hace grupos de dos caracteres
		             aux=atoi(cin); //transformación de char a int
						     if(aux==40)
						       c[0].costo=aux;
						     if(aux==15)
						       c[1].costo=aux;
						     if(aux==55)
						       c[2].costo=aux;
						     if(aux==10)
						       c[3].costo=aux;
					        	p("%s",cin);		   
		             }
		          fclose(arch);
	              }
   
		  p(" \n\nSeleccione que desea en su orden: " );   //Desicion de selección
          fflush(stdin);  
          sel=getchar();
          system("CLS");
          } while(sel!='a'&& sel!='A' && sel!='b'&& sel!='B'&& sel!='c'&& sel!='C'&& sel!='d'&& sel!='D'&& sel!='e'&& sel!='E');                //la seleccion tiene que estar entre 0 y 7 
        
        if(sel=='e' || sel=='E') 
		      { 
		       system("CLS");
		       p("\n\n Tu pedido fue el siguiente:\n");      //Contador del pedido en cuanto al menu
       	   p("-------------------------\n"   );       
           p(" %d Cubana   \n", c[0].cantidad);
           p(" %d Jamon    \n", c[1].cantidad); 
           p(" %d Especial \n", c[2].cantidad); 
		       p(" %d Refresco \n", c[3].cantidad);                   
           p("\n El monto a pagar es de: %d\n\n", suma);
          break;
          }

    switch(sel) //Sel sirve de bandera para tomar desiciones
	      {
		   case 'a': case'A':    
			suma+=c[0].costo;
			c[0].cantidad++;
	        break;
	        
	        case 'b': case'B':
			suma+=c[1].costo;
			c[1].cantidad++;
    		break;
    		
    		case 'c': case'C':
			suma+=c[2].costo;
			 c[2].cantidad++;
			break;
			
			case 'd': case'D':
			suma+=c[3].costo;
			 c[3].cantidad++;
	        break;
	        default:
			break;
	       }
	}while(sel);
	
}
