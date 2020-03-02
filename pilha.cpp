//XÊNIA BEATRIZ RODRIGUES MARQUES && EDUARDO PATRICK DE ANDRADE PACHÊCO
//pilha - estrutura de dados 1

#include <iostream>

using namespace std;
int const MAXTAM = 30;

class pilha{
	
	private :
		int p[MAXTAM]; //pilha
        int topo; // topo da pilha
	
   	public: //construtor
   		
		pilha(){
			this ->topo= -1;
			p[0] = NULL;
		}
		
		bool vazia(){ //verifica se uma lista está vazia
			if(topo == -1){
				return true;
			} else{
				return false;
			}
		}
		
		
		bool cheia(){ //verifica se a pilha esta cheia
			if(topo == MAXTAM-1){
				return true;
			} else{
				return false;
			}
		}
		
		void push(int elem){ //inserção na pilha - sempre no topo
			if(cheia()){
				cout << endl << " *** A pilha esta cheia! *** " << endl << endl;
			}else{
			   p[topo+1] = elem;
			    topo++;	
			}
        }
        
        int pop(){ //remove um elemento e retorna este elemento
         int r; //remover
		 if(vazia()){
		 	return NULL;
			} else{
			  r = p[topo];
			  p[topo] = NULL;
			  topo--;
			}
			return r;
		}
        
		//busca usando push e pop
		int buscar(int elem){ //busca um elemento na pilha ; elem(elemento); retorna 0 quando o elemento não é encontrado e 1 quando é encontrado 
		   
		   pilha aux; //pilha auxiliar
		   int num; //numero auxiliar que recebera o numero retirado da pilha e posteriormente será colocado na pilha auxiliar para retornar a pilha normal no fim da busca
		    
		   while(topo != -1){
		   	
		   		num = pop(); //num recebe elemento retirado da pilha original
		   		
		   		aux.push(num); //o elemento retirado da pilha original é empilhado na auxiliar
		   		
		   		if(num == elem){
					   while(aux.topo != -1){
						   push(aux.pop()); //apos o elemento ser encontrado a pilha volta a ser empilhada com seus valores
					   }
					   return 1; 
				   }
		   	
		   }
		   
		   while(aux.topo != -1){
		   	   push(aux.pop()); //apos o elemento nao ser encontrado a pilha volta a ser empilhada com seus valores 
		   }
		   return 0; 
		   
		}

        int top(){ //retorna o topo da pilha
			if(vazia()){
				return NULL;
			} else{
				return p[topo];
			}
		}
		
};

int main (int argc, char** argv) {
	
	pilha p1;
	int op = 1; //escolha da operacao
	int e; //elemento
	
	while(op != 0){
		cout << endl << "--------------- MENU --------------" << endl;
		cout << endl << "-------------* PILHA *-------------" << endl <<endl;
		cout << "Escolha a operacao que deseja realizar:" << endl;
		cout << " 1. Inserir um elemento no topo da pilha." << endl;
		cout << " 2. Ler o topo da pilha." << endl;
		cout << " 3. Remover elemento do topo da pilha." << endl;
		cout << " 4. Verificar se um elemento esta ou nao na pilha." << endl;
		cout << " 5. Verificar se a pilha esta vazia." << endl;
		cout << " 6. Verificar se a pilha esta cheia." << endl << endl;
		cin >> op;
		cout << endl;
		switch(op){
			case 0:
				break;
			
			case 1:
				if(p1.cheia()){
					cout << "    *** A pilha esta cheia! ***" << endl << "Remova um elemento e tente novamente!" << endl;
				} else {
				cout << "Digite o elemento que deseja inserir na pilha: ";
				cin >> e;
				p1.push(e);
				cout << endl << "O elemento " << e << " foi inserido no topo da pilha." << endl;
				}
				break;
			
			case 2:
				if(p1.vazia()){
					cout << "*** A pilha esta vazia! ***" << endl;
				} else{
				cout << endl << p1.top() << endl;
				}
				break;
			
			case 3:
				if(p1.vazia()){
					cout << "*** A pilha esta vazia! ***" << endl;
				} else{
				cout << "O elemento " << p1.pop() << " foi removido do topo da pilha." << endl;
				}
				break;
			
			case 4:
				cout << "Digite o elemento que deseja buscar na pilha: ";
				cin >> e;
				cout << endl << endl;
				if(p1.buscar(e)==1){
					cout << " O elemento esta na pilha! (BUSCA == 1)" << endl;
				} else {
					cout << " O elemento NAO esta na pilha! (BUSCA == 0)" << endl;
				}
				break;
			
			case 5:
				if(p1.vazia()){
					cout << " A pilha esta vazia!" << endl;
				}else{
					cout << " A pilha NAO esta vazia!" << endl;
				}
				break;
			
			case 6:
				if(p1.cheia()){
					cout << " A pilha esta cheia!" << endl;
				} else{
					cout << " A pilha NAO esta cheia!" << endl;
				}
				break;
				
				
			
			default :
       	   	   cout << endl << " *** NUMERO INVALIDO ***" << endl;
       	   	   cin >> e;
       	   	   
		}
	}
	
}
