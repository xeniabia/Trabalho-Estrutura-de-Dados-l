//XÊNIA BEATRIZ RODRIGUES MARQUES && EDUARDO PATRICK DE ANDRADE PACHÊCO
//fila - estrutura de dados 1

#include <iostream>

using namespace std;

class no{
	
	private:
	int elemento; //elemento
	no *ponteiro; //ponteiro
	
	public:
		no(){
		this-> elemento = elemento;
		this-> ponteiro = NULL;
		}
		no(int valor){
			this-> elemento = valor;
			this-> ponteiro = NULL;
		}
		int getelemento(){ 
			return elemento;
		}
		no *getponteiro(){
			return ponteiro;
		}
		void setelemento(int novoelemento){
			this->elemento = novoelemento;
		}
		void setponteiro(no *novoponteiro){
			this-> ponteiro = novoponteiro;
		}
		
};

class fila{
	
	private:
	  no *noi, *nof; //noi(inicio da fila) nof(final da fila)
	  
     public:
     	fila(){
		   this-> noi = NULL;
		   this-> nof = NULL;	 
		 }
		 
       bool vazia(){ // verifica se uma fila esta vazia
		   if(noi == NULL){
			   return true;
		   } else{
			   return false;
		   }
	   }
	   
	   bool cheia(){ //verifica se a fila esta cheia, como é a fila é encadeada sempre retornará falso
		   return false;
	   }
       
 		void enqueue(int elem){ //inserção na fila - sempre no final da fila
			no *novo = new no(elem);
			if(vazia()){
				//novo->setponteiro(noi);
				noi = novo;
				nof = novo;
			} else{ 
				nof->setponteiro(novo);
				nof = novo;
			}
		}
		
	   
	   int dequeue(){ // remove o 1º elemento da fila
		   int r = noi->getelemento(); //r(remover)
		   noi = noi->getponteiro();
		   return r;
	   }
	   
	   //busca usando enqueue e dequeue
	   int buscar(int elem){ //busca um elemento na fila ; elem(elemento); retorna 0 quando o elemento não é encontrado e 1 quando é encontrado 
	   		fila aux; //fila auxiliar
	   		int num; //guardará o valor retirado do inicio da fila original
	   		int busca = 0; //busca recebe o valor caso o elemento não tenha sido encontrado
	   		
	   		while(noi != NULL){
				   num = dequeue();
				   aux.enqueue(num);
				   if(num == elem){
				   	   busca = 1;
				   }
			   }
			   
			while(aux.noi != NULL){
				enqueue(aux.dequeue()); //os valores sao colocados novamente na fila original
			}   
			return busca;
		}
		
	   int first(){ //retorna o primeiro elemento da fila
	   	   if(vazia()){
				  return NULL;
			  } else{
				 return noi->getelemento(); 
			  }
	   }

};

int main (int argc, char** argv) {
	
	fila f1;
	int op = 1; //escolha da operacao
	int e; //elemento
	
	while(op != 0){
		cout << endl << "--------------- MENU --------------" << endl;
		cout << endl << "--------------* FILA *-------------" << endl <<endl;
		cout << "Escolha a operacao que deseja realizar:" << endl;
		cout << " 1. Inserir um elemento no inicio da fila." << endl;
		cout << " 2. Ler o inicio da fila." << endl;
		cout << " 3. Remover elemento do inicio da fila." << endl;
		cout << " 4. Verificar se um elemento esta ou nao na fila." << endl;
		cout << " 5. Verificar se a fila esta vazia." << endl;
		cout << " 6. Verificar se a fila esta cheia." << endl << endl;
		cin >> op;
		cout << endl;
		
		switch(op){
			
			case 0:
				break;
			
			case 1:
				cout << "Digite o elemento que deseja inserir na fila: ";
				cin >> e;
				f1.enqueue(e);
				cout << endl;
				cout << "O elemento " << e << " foi inserido no inicio da fila." << endl;
				break;
			
			case 2:
				if(f1.vazia()){
					cout << "*** A fila esta vazia! ***" << endl;
				} else{
				cout << endl << f1.first() << endl;
				}
				break;
			
			case 3:
				if(f1.vazia()){
					cout << "*** A fila esta vazia! ***" << endl;
				} else{
				cout << "O elemento " << f1.dequeue() << " foi removido do inicio da fila." << endl;
				}
				break;
			
			case 4:
				cout << "Digite o elemento que deseja buscar na fila: ";
				cin >> e;
				cout << endl << endl;
				if(f1.buscar(e)==1){
					cout << " O elemento esta na fila! (BUSCA == 1)" << endl;
				} else {
					cout << " O elemento NAO esta na fila! (BUSCA == 0)" << endl;
				}
				break; 
			
			case 5:
				if(f1.vazia()){
					cout << " A fila esta vazia!" << endl;
				}else{
					cout << " A fila NAO esta vazia" << endl;
				}
				break;
			
			case 6:
				if(f1.cheia()){
					cout << " A fila esta cheia!" << endl;
				} else{
					cout << " A fila NAO esta cheia!" << endl;
				}
				break;
				
				
			
			default :
       	   	   cout << endl << " *** NUMERO INVALIDO ***" << endl;
       	   	   cin >> e;
       	   	   
		}
	}
	
}
