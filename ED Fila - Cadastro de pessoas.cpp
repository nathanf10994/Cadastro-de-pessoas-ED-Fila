#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstring>

using namespace std;

struct date{
	int dia, ano;
	string mes;
	
	date readDate(){
		date d;
		
		cout<<"\nDigite o dia -> ";
		cin>>d.dia;
		cin.ignore();
		bool aux = false;
			do{
				cout<<"\nDigite o mês -> ";
				getline(cin, d.mes);
					if(d.mes == "1" || d.mes == "01" || d.mes == "janeiro" || d.mes == "Janeiro"){
						d.mes="Janeiro"; aux = true;
					} else if (d.mes == "2" || d.mes == "02" || d.mes == "fevereiro" || d.mes == "Fevereiro"){
						d.mes="Fevereiro"; aux = true;
					} else if (d.mes == "3" || d.mes == "03" || d.mes == "marco" || d.mes == "março"|| d.mes == "Marco" || d.mes == "Março"){
						d.mes="Março"; aux = true;
					} else if (d.mes == "4" || d.mes == "04" || d.mes == "abril" || d.mes == "Abril"){
						d.mes="Abril"; aux = true;
					} else if (d.mes == "5" || d.mes == "05" || d.mes == "maio" || d.mes == "Maio"){
						d.mes="Maio"; aux = true;
					} else if (d.mes == "6" || d.mes == "06" || d.mes == "junho" || d.mes == "Junho"){
						d.mes="Junho"; aux = true;
					} else if (d.mes == "7" || d.mes == "07" || d.mes == "julho" || d.mes == "Julho"){
						d.mes="Julho"; aux = true;
					} else if (d.mes == "8" || d.mes == "08" || d.mes == "agosto" || d.mes == "Agosto"){
						d.mes="Agosto"; aux = true;
					} else if (d.mes == "9" || d.mes == "09" || d.mes == "setembro" || d.mes == "Setembro"){
						d.mes="Setembro"; aux = true;
					} else if (d.mes == "10" || d.mes == "outubro" || d.mes == "Outubro"){
						d.mes="Outubro"; aux = true;
					} else if (d.mes == "11" || d.mes == "novembro" || d.mes == "Novembro"){
						d.mes="Novembro"; aux = true;
					} else if (d.mes == "12" || d.mes == "dezembro" || d.mes == "Dezembro"){
						d.mes="Dezembro"; aux = true;
					} else cout<<"\n** Mês digitado inválido **\n";
			}while(aux == false);
		cout<<"\nDigite o ano -> ";
		cin>>d.ano;
		
		return d;
	}
	
	void printDate(){
		cout<<dia<<" de "<<mes<<" de "<<ano<<endl;
	}
};

struct adress{
	char rua[50];
	char bairro[50];
	char cidade[50];
	char estado[50];
	char pais[50];
	int numero, cep;
	
	adress readAdress(){
		adress ad;
		
		cout << "\nDigite a Rua -> ";
	    cin.ignore(); 
	    cin.getline(ad.rua, 50);
	    cout << "\nDigite o número -> ";
	    cin >> ad.numero;
	    cout << "\nDigite o Bairro -> ";
	    cin.ignore(); 
	    cin.getline(ad.bairro, 50);
	    cout << "\nDigite a Cidade -> "; 
	    cin.getline(ad.cidade, 50);
	    cout << "\nDigite o Estado -> ";
	    cin.getline(ad.estado, 50);
	    cout << "\nDigite o País -> ";
	    cin.getline(ad.pais, 50);
	    cout << "\nDigite o CEP -> ";
	    cin >> ad.cep;
		
		return ad;
	}
	
	void printAdress(){
		cout<<"Rua/Av:\t\t"<<rua<<", nº "<<numero<<endl;
		cout<<"Bairro:\t\t"<<bairro<<endl;
		cout<<"Cidade:\t\t"<<cidade<<endl;
		cout<<"Estado:\t\t"<<estado<<endl;
		cout<<"País:\t\t"<<pais<<endl;
		cout<<"CEP:\t\t"<<cep<<endl;
	}
};

struct contract{
	int codigo;
	date dataAssinatura;
	char cargo[50];
	float salario;
	
	contract readContract(){
		contract c;
		
		cout<<"\nDigite o Código do contrato -> ";
		cin>>c.codigo;
		cout<<"\nDigite o cargo -> ";
		cin.ignore();
		cin.getline(c.cargo,50);
		cout<<"\nDigite o salário -> ";
		cin>>c.salario;
		cout<<"\n\n--  Data de Admissão  --\n";
		c.dataAssinatura = c.dataAssinatura.readDate();
			
		return c;
	}
	
	void printContract(){
		cout<<"Contrato:\t"<<codigo<<endl;
		cout<<"Cargo:\t\t"<<cargo<<endl;
		cout<<"Salário:\tR$"<<salario<<endl;
		cout<<"Admissão:\t";
		dataAssinatura.printDate();
	}
};

struct person{
	char nome[50];
	date dataNascimento;
	adress ad;
	contract c;
	
	person readPerson(){
		person p;
		
		cout<<"\nDigite o nome -> ";
		cin.ignore();
	    cin.getline(p.nome, 50);
		cout<<"\n---   Data de nascimento   ---\n";
		p.dataNascimento = p.dataNascimento.readDate();
		cout<<"\n---   Endereço   ---\n";
		p.ad = p.ad.readAdress();
		cout<<"\n---   Dados profissionais   ---\n";
		p.c = p.c.readContract();
		
		return p;
	}
	
	void printPerson(){
		cout<<"\nNome:\t\t"<<nome<<endl;
		cout<<"Nascimento:\t";
		dataNascimento.printDate();
		cout<<"\n---   Endereço   ---\n";
		ad.printAdress();
		cout<<"\n---   Dados Profissionais\n";
		c.printContract();
	}
};

struct node{ 
	person p;
	node *proximo;
};

struct queue{
	node *primeiro;
	int tamanho;
	
	void iniciate(){
		primeiro = NULL;
		tamanho = 0;
	}
	
	void pushQueue(){ 
		node *aux, *novo = new node;
		if(novo){
			novo->p = novo->p.readPerson();
			novo->proximo = NULL; 
			if(primeiro == NULL){
				primeiro = novo;
			}
			else{
				aux=primeiro; 
				while(aux->proximo){ 
					aux = aux->proximo; 
				}
				aux->proximo = novo;
			}
		}
		else{
			cout<<"\n** Erro na alocação **\n";
		}
	}

	node* popQueue(){
		node *remover = NULL;
		if(primeiro){
			remover = primeiro;
			primeiro = remover->proximo;
		}
		else cout<<"\n** Sem dados para excluir **\n";
		return remover;
	}
	
	void printQueue(){
		node *aux = primeiro;
		if(aux){
			cout<<"\n==========   FILA   ==========";
			while(aux){
				aux->p.printPerson();
				if(aux->proximo) cout<<"\n------------------------------\n";
				aux = aux->proximo; 
			}
			cout<<"\n==============================\n";
		}
		else cout<<"\n** Sem dados para mostrar ** \n";
		
	}
};




int main(){
	
	setlocale(LC_ALL,"");
	
	node *remover;
	queue q;
	int option;
	
	q.iniciate();
	
	do{
		
		cout<<"\n-----   CADASTRO   -----\n";
		cout<<"\n1 - Inserir.";
		cout<<"\n2 - Excluir.";
		cout<<"\n3 - Mostrar.";
		cout<<"\n0 - Sair.";
		cout<<"\n\nSelecione a opção desejada: ";
		cin>>option;
		
			switch(option){
				
				case 1:
					system("cls");
					q.pushQueue();
					system("cls");
					break;
				
				case 2:
					system("cls");
					remover = q.popQueue();
					if(remover){
						cout<<"\nRemovido com sucesso.\n--------------------\n";
						remover->p.printPerson();
						cout<<"\n--------------------\n";
						delete(remover);
					}
					break;
				
				case 3:
					system("cls");
					q.printQueue();
					break;
				
				case 0:
					break;
				
				default:
					system("cls");
					cout<<"\n** Opção inválida **\n";								
			}
		
		
	}while(option != 0);
	
return 0;
	
}