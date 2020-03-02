//XÊNIA BEATRIZ RODRIGUES MARQUES && EDUARDO PATRICK DE ANDRADE PACHÊCO
//lista sequencial - estrutura de dados 1

#include <iostream>

using namespace std;
const int MAXTAM = 30;

class lista{
	
	private:
		int eli; //elemento inicial
		int elf; //elemento final
		int *v;  //vetor
		int tam; //tamanho
		
	public: //construtor
     	lista(){
			this-> eli = 0; //elemento inicial
            this-> elf = -1; //elemento final
            this-> v = new int[MAXTAM]; //vetor
			this-> tam = MAXTAM; //tamanho	 
        }
		
		bool vazia(){ //verifica se uma lista está vazia
			if(eli > elf){
		    	return true;
			}else{
			  return false;		
			}
       }
       
       bool cheia(){ //verifica se uma lista está cheia
		   if(elf == tam-1){
			   return true;
		   } else{
			   return false;
		   }
	   }
	    
    	int tamanho(){ //tamanho da lista
		   return elf+1;
	   }
	   
	   void inseririnicio(int elem){//inserção no inicio da lista
			  	int n = tamanho();
			  	elf++;
			  	int i;
				  for(i=n;i>=0;i--){
				  	v[i] = v[i-1];
				  }
				  v[0] = elem;
	   }
        
		void inserir(int elem){ //inserção no final da lista
				  elf++;
				  v[elf] = elem;
	   }
	   
	   
	    void inserir(int elem, int pos){ //inserção de um elemento em uma determinada posição
          //int t = tamanho();
		  if(pos<=tamanho()+1){
			int n = tamanho();
			  	elf++;
			  	int i;
				  for(i=n;i>=pos-1;i--){
				  	v[i] = v[i-1];
				  }
				  v[pos-1] = elem;
			  } else{
				  cout << endl << "Posicao ainda nao disponivel. Escolha uma posicao menor ou igual a " << tamanho()+1 << "." << endl;
			  }
           
       } 
    
     void inserirordenado(int elem){ //inserção em uma lista ordenada
     	 	 if(vazia()){
     	 		inseririnicio(elem);
		  	  } else{
				int i;
				int pos = 0;
				for (i=0; i<tamanho() ;i++){
					if(v[i]<elem){
						pos = i+1;
					}
				}
				inserir(elem, pos+1);
		  	  }
	} 
    
     void remover(int pos){ //remoção do elemento de determinada posição
		   if(vazia()){
			   cout << endl << "A lista esta vazia!" << endl;
		   } else if(pos>tamanho()||pos<1){
			   cout << "Posicao invalida. Tente novamente" << endl;
		   } else{
		   		int i;
			   for(i=pos-1;i<tamanho()-1;i++){
				   v[i] = v[i+1];
			   }
			   elf--;
		   }
    } 
    
    	int aumentarTam(int *vetor, int t){ //aumenta o tamanho max da lista
        	int v[t+1];
        	int i;
        	for(i=0; i<t; i++){
				v[i]=vetor[i];
			}
			vetor = v;
			tam = t+1;
			return tam;
		} 
       
       void imprimir(){ //impressão da lista
       if(vazia()){
		   cout << "A lista esta vazia!" << endl;
	   }
         int tam = tamanho();
         int i;
	     for(i=0; i<tam; i++){
		   cout << v[i] << " ";
	     }
	     cout << endl;
       }
       
		
};

int main (int argc, char** argv) {
	
	lista l1;
	lista l2;
	
	int ord = 1; //opção de escolher se o vetor é ordenado ou não 
	int op = 1; //opção para escolher a operação
	
	while(ord!=0){
		cout << endl << "--------------- MENU --------------" << endl;
		cout << endl << "--------- LISTA SEQUENCIAL ---------" << endl <<endl;
		cout << "Escolha o tipo da sua lista:" << endl;
		cout << " 1. Lista aleatoria" << endl;
		cout << " 2. Lista ordenada" << endl;
		cout << " 0. Sair" << endl << endl;
		cin >> ord;
		if(ord > 2 || ord < 0){
			cout << endl << "*** Numero invalido ***" << endl << endl;
		} 
		if(ord == 1){
			op = 1;
			while(op != 0){
				cout << endl << "--------- LISTA ALEATORIA ---------" << endl;
				cout << "Escolha a operacao que deseja realizar:" << endl;
				cout << " 1. Inserir elemento no final da lista." << endl;
				cout << " 2. Inserir elemento em determinada posicao da lista." << endl;
				cout << " 3. Imprimir a lista." << endl;
				cout << " 4. Remover elemento da lista." << endl;
				cout << " 5. Retornar o tamanho da lista." << endl;
				cout << " 6. Retornar se a lista esta vazia ou nao." << endl;
				cout << " 7. Retornar se a lista esta cheia ou nao." << endl;
				cout << " 0. Voltar ao menu." << endl << endl;
				cin >> op;
				if(op > 7 || op < 0){
					cout << endl << "*** Numero invalido ***" << endl << endl;
				} else if(op == 1){
					
					if(l1.cheia()){
						int a; //aumentar
						cout << endl << "A lista esta cheia! Aumente o tamanho max da lista ou remova um elemento!" << endl << "DIGITE 1 caso queira aumentar o tamanho da lista." << endl << "Digite qualquer outro numero para retornar ao menu." << endl;
						cin >> a;
						if(a == 1){
							int v[l1.tamanho()];
							cout << endl << "O tamanho max da lista agora eh: " <<endl;
							cout << endl << l1.aumentarTam(v, l1.tamanho()) << endl;
						}
						
					}else{
						int e; //elemento
						cout << endl << "Insira um elemento: ";
						cin >> e;
						l1.inserir(e);
						cout << endl << "--- O elemento foi inserido! ---" << endl;
					}
					
				} else if(op == 2){
					
					if(l1.cheia()){
						int a; //aumentar
						cout << endl << "A lista esta cheia! Aumente o tamanho max da lista ou remova um elemento!" << endl << "DIGITE 1 caso queira aumentar o tamanho da lista." << endl << "Digite qualquer outro numero para retornar ao menu." << endl;
						cin >> a;
						if(a == 1){
							int v[l1.tamanho()];
							cout << endl << "O tamanho max da lista agora eh: " << endl;
							cout << endl << l1.aumentarTam(v, l1.tamanho()) << endl;
						}
					}
						else{
							int e; //elemento
							int pos;
							cout << endl << "Insira um elemento: ";
							cin >> e;
							cout << endl << "Insira uma posicao: ";
							cin >> pos;
							l1.inserir(e, pos);
							if(e <= l1.tamanho()+1){
							cout << endl << "--- O elemento foi inserido! ---" << endl;
							}
						}
					
				} else if(op == 3){
					cout << endl;
					l1.imprimir();
				} else if(op == 4){
					int pos;
					cout << endl << "Insira a posicao do elemento que deseja remover: ";
					cin >> pos;
					l1.remover(pos);
					//cout << endl << "O elemento da posicao " << pos << " foi removido!" << endl;
				} else if(op == 5){
					cout << endl <<"O tamanho da lista eh: ";
					cout << l1.tamanho() << endl;
				} else if(op == 6){
					if(l1.vazia()){
						cout << endl << "A lista esta vazia!" << endl;
					} else{
						cout << endl << "A lista NAO esta vazia!" << endl;
					}
				} else if(op == 7){
					if(l1.cheia()){
						cout << endl << "A lista esta cheia!" << endl;
					} else{
						cout << endl << "A lista NAO esta cheia!" << endl;
					}
				}
				
			}
		} else if(ord == 2){
			op = 1;
			while(op != 0){
				cout << endl << "--------- LISTA ORDENADA ---------" << endl;
				cout << "Escolha a operacao que deseja realizar:" << endl;
				cout << " 1. Inserir elemento ordenadamente na lista." << endl;
				cout << " 2. Imprimir a lista." << endl;
				cout << " 3. Remover elemento da lista." << endl;
				cout << " 4. Retornar o tamanho da lista." << endl;
				cout << " 5. Retornar se a lista esta vazia ou nao." << endl;
				cout << " 6. Retornar se a lista esta cheia ou nao." << endl;
				cout << " 0. Voltar ao menu." << endl << endl;
				cin >> op;
				if(op > 7 || op < 0){
					cout << endl << "*** Numero invalido ***" << endl << endl;
				} else if(op == 1){
					
					if(l2.cheia()){
						int a; //aumentar
						cout << endl << "A lista esta cheia! Aumente o tamanho max da lista ou remova um elemento!" << endl << "DIGITE 1 caso queira aumentar o tamanho da lista." << endl << "Digite qualquer outro numero para retornar ao menu." << endl;
						cin >> a;
						if(a == 1){
							int v[l2.tamanho()];
							cout << endl << "O tamanho max da lista agora eh: " << endl;
							cout << endl << l2.aumentarTam(v, l2.tamanho()) << endl;
						} 
					}
						
						else {
							int e;
							cout << endl << "Insira o elemento: ";
							cin >> e;
							l2.inserirordenado(e);
							cout << endl << "--- O elemento foi inserido! ---" << endl;
						}
						
				} else if(op == 2){
					cout << endl;
					l2.imprimir();
				} else if(op == 3){
					int pos;
					cout << endl <<"Insira a posicao do elemento que deseja remover: ";
					cin >> pos;
					l2.remover(pos);
					//cout << endl << "O elemento da posicao " << pos << " foi removido!" << endl;
				} else if(op == 4){
					cout << endl <<"O tamanho da lista eh: ";
					cout << l2.tamanho() << endl;
				} else if(op == 5){
					if(l2.vazia()){
						cout << endl << "A lista esta vazia!" << endl;
					} else{
						cout << endl << "A lista NAO esta vazia!" << endl;
					}
				} else if(op == 6){
					if(l2.cheia()){
						cout << endl << "A lista esta cheia!" << endl;
					} else{
						cout << endl << "A lista NAO esta cheia!" << endl;
					}
				}
			}
		}
	}
	
	
}