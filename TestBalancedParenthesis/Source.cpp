#include<stdio.h>
#include<stack>
#include<conio.h>
#include<Windows.h>

#include "Stack.h"

int main()
{
	Stack rpn;
	char c;
	int cont = 0;
	do
	{
		system("cls");
		printf("Ingrese la cadena RPN o POLACA INVERSA\n");
		printf("Utilize teclas 0-9 o * / + -\n");
		printf("Ejemplo- 23*54*+9-=17\n");
		printf("Esta listo? s-si n-no\n");
		c = _getch();
	} while (c != 's');
	system("cls");
	do
	{
		// (40 )41 [91 ]93 {123 }125
		c = _getch();
		printf("%c", c);
		//c == 40 || c == 41 || c == 91||c == 93 || c == 123|| c==125
		if (c == 40 || c == 91 || c == 123)
		{
			rpn.Push(c);
			cont++;
			//printf("\nP%d\n", rpn.Show());
		}

		 if (((rpn.Show() + 1) == c)||((rpn.Show() + 2) == c)||((rpn.Show() + 2) == c))
			rpn.Pop();
		 if (c == 41 || c == 93 || c == 125)
			cont--;
		
		
	} while (c != 13);

	if ((rpn.IsEmpty() == TRUE)&&(cont==0))
	{
		printf("La ecuacion esta balanceada\n");
	}
	else
		printf("La ecuacion NO ESTA BALANCEADA\n");
	printf("\n%d\n",rpn.Show());
	printf("\n%d\n", cont);
}