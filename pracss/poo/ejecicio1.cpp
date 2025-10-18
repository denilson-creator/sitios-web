#include<iostream>
using namespace std;

class Suma;
class Resta;

class Numeros{
	private:
		int valor1, valor2;
	public:
		Numeros(int _valor1, int _valor2){
			valor1=_valor1;
			valor2=_valor2;
		}
		friend class Suma;
		friend class Resta;
		
		void mostrarNumeros(){
			cout<<"Valor 1:"<<valor1<<endl;
			cout<<"Valor 2:"<<valor2<<endl;
		}	
};

class Suma{
	private:
		Numeros ejemplo_suma;
	public:
		Suma();
		void insertarNumeros(Numeros*num){	//asignando datos al objeto
			ejemplo_suma.valor1=num->valor1;
			ejemplo_suma.valor2=num->valor2;	
		}
		void mostrarNumeros_s(){
			ejemplo_suma.mostrarNumeros();
		}	
		int sumarNumeros(){
			return ejemplo_suma.valor1+ ejemplo_suma.valor2;
		}
};

class Resta{
	private:
		Numeros ejemplo_resta;
	public:	
		Resta();
		void insertarNumeros_r(Numeros &numero_r){
			ejemplo_resta.valor1=numero_r.valor1;
			ejemplo_resta.valor2=numero_r.valor2;
		}
		void mostrarNumeros_r(){
			ejemplo_resta.mostrarNumeros();
		}
		int restarNumeros(){
			return ejemplo_resta.valor1 - ejemplo_resta.valor2;
		}
};

int main(){
	int sumar, restar;
	Numeros num(7,10);
	Suma suma1;
	Resta resta1;
	
	suma1.insertarNumeros(&num);
	sumar=suma1.sumarNumeros();
	
	resta1.insertarNumeros_r(num);
	restar=resta1.restarNumeros();
	
	cout<<"La suma de ";
	suma1.mostrarNumeros_s();
	cout<<"es: "<<sumar<<endl;
	
	cout<<"La resta de ";
	resta1.mostrarNumeros_r();
	cout<<"es: "<<restar<<endl;
	return 0;
}