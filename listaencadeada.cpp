//XÊNIA BEATRIZ RODRIGUES MARQUES && EDUARDO PATRICK DE ANDRADE PACHÊCO
//lista encadeada - estruturas de dados 1

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

class lista{
	
	private:
	no *noi, *nof; //noi(inicio da lista) nof(final da lista)
	
	public:
		lista(){
			this-> noi=NULL;
			this-> nof=NULL;
		}
		
		bool vazia(){ //verifica se a lista esta vazia
			if(noi == NULL){
				return true;
			} else{
				return false;
			}
		}
		
		int tamanho(){ //tamanho da lista
			int t = 0; // t(tamanho da lista)
			no *pc = noi; //pc(percorrer)
			while(pc!=NULL){
				pc = pc->getponteiro();
				t++;
			}
			return t;
		}
		
		void imprimir(){ //impressão uma lista encadeada, percorre a lista e imprime
			no *pc = noi; //pc(percorrer)
			if(vazia()){
				cout << "A lista esta vazia";
				
            } else{
				while(pc!=NULL){
					cout<< pc->getelemento();
					cout<< " ";
					pc = pc->getponteiro();
				}
			}
			cout<<endl;
		}
		
		void inserir(int elem){ //inserção no final da lista
		if(vazia()){
			inseririnicio(elem);
			nof = noi;
		} else{
			no *novo = new no(elem); 
			nof->setponteiro(novo);
			nof = novo;
			}
		}
		
		void inseririnicio(int elem){ //inserção no inicio da lista
			no *novo = new no(elem);
			novo->setponteiro(noi);
			noi = novo;
		}
		
		void inserir(int elem, int pos){ //inserção de um elemento em uma determinada posição
			if(pos>tamanho()+1){
				cout << endl << "Posicao ainda nao disponivel. Escolha uma posicao menor ou igual a " << tamanho()+1 << "." << endl;
			} else{
			if(vazia()){
				inseririnicio(elem);
				nof=noi;
			}else{
				no *novo = new no(elem);
				no *noa = NULL; //no anterior a posição
				no *pc = noi; //pc(percorrer)
				int cont = 1;
				if(pos==cont){ //pos==1
					inseririnicio(elem);
					
				} else if(pos==tamanho()+1){
					inserir(elem);
				} else{
				while(cont < pos){ //pos maior do que 1 
				   noa = pc;
				   pc = pc->getponteiro();
				   cont++;	
				}
				novo->setponteiro(noa->getponteiro());
				noa->setponteiro(novo);
				}
			}
			}
		}
		
		void inserirordenado(int elem){ //inserção em uma lista ordenada
			if(vazia()){
				inseririnicio(elem);
				nof=noi;
			} else{
				if(elem < noi->getelemento()){
					inserir(elem, 1);
				} else if(elem > nof->getelemento()){
					inserir(elem, tamanho()+1);
				} else {
					no *pc = new no; //pc(percorrer)
					pc = noi;
					int pos = 1;
					while(elem > pc->getelemento()){ //percorre a lista ate encontrar a posicao ideal na ordenacao para acrescentar o elemento
						pc = pc->getponteiro();
						pos++;
					}
					inserir(elem, pos);
				}
				
			}
		}
		
		void remover(int pos){ //remoção //pos(posição) 
			if(pos<=0||pos>tamanho()){
				cout << endl << "*** Posicao invalida! ***";
			} else{
				no *noa = NULL; //no anterior a posição
				no *pc = noi; //pc(percorrer)
				int cont = 1;
				if(pos==cont){ //pos==1 
				noi = noi->getponteiro();
				pc->setponteiro(pc);
				delete pc;
				} else{
				while(cont < pos){ //pos maior do que 1 
				   noa = pc;
				   pc = pc->getponteiro();
				   cont++;	
				}
				noa->setponteiro(pc->getponteiro());
				pc->setponteiro(pc);
				delete pc;
			}
			}
		}
		
		int buscar(int elem){ //busca elemento na lista, retorna -1 quando o elemento não é encontrado e a posição quando ele é encontrado
			int aux = tamanho();
			int pos = 1; //pos(posição)
			no *pc = noi; //pc(percorrer)			
			while(pos<=aux){ 
				if((pc->getelemento()) == elem){
					return pos; //posição onde está localizado o elemento na lista
					}
				pc = pc->getponteiro();
				pos++;
			}
				return -1; //retorno quando o elemento não é encontrado
		}
		
		bool equivalente(lista l1, lista l2){ //verifica se duas listas são iguais, retorna true quando são e false se não são iguais
			no *pc1 = l1.noi; //pc1(percorrer lista 1)
			no *pc2 = l2.noi; //pc2(percorrer lista 2)
			int tam1 = l1.tamanho();
			int tam2 = l2.tamanho();
			int pos = 1;
			if(tam1 != tam2){ //se as listas possuirem tamanhos diferentes, não podem ser iguais, logo retornará falso
				return false;
			} else{
				while(pos<tam1){
					if(pc1->getelemento() != pc2->getelemento()){
						return false;
					}
					pc1 = pc1->getponteiro();
					pc2 = pc2->getponteiro();
					pos++;
				}
				return true;
			}
		}
		
		
		
};

int main (){
	
	lista l1; //lista aleatoria 1
	lista l2; //lista aleatoria 2
	lista o1; //lista ordenada 1
	lista o2; //lista ordenada 2
	
	int ord = 1; //opção de escolher se o vetor é ordenado ou não 
	int op = 1; //opção para escolher a operação
	
	while(ord!=0){
		cout << endl << "--------------- MENU --------------" << endl;
		cout << endl << "--------- LISTA ENCADEADA ---------" << endl;
		cout << "Escolha o tipo da sua lista:" << endl;
		cout << " 1. Lista aleatoria" << endl;
		cout << " 2. Lista ordenada" << endl;
		cout << " 0. Sair" << endl << endl;
		cin >> ord;
		switch(ord){
			case 0:
				break;
			
			case 1 :
				op = 1;
				while(op!=0){
					
					cout << endl << "                                       --------- LISTA ALEATORIA ---------" << endl;
					cout << endl << "Escolha a operacao que deseja realizar:" << endl << endl;
					cout << " 1. Inserir elemento no final da lista 1.";
					cout << "               ||      8. Inserir elemento no final da lista 2." << endl;
					cout << " 2. Inserir elemento em determinada posicao da lista 1.";
					cout << " ||      9. Inserir elemento em determinada posicao da lista 2." << endl;
					cout << " 3. Imprimir a lista 1.";
					cout << "                                 ||      10. Imprimir a lista 2." << endl;
					cout << " 4. Remover elemento da lista 1.";
					cout << "                        ||      11. Remover elemento da lista 2." << endl;
					cout << " 5. Retornar o tamanho da lista 1.";
					cout << "                      ||      12. Retornar o tamanho da lista 2." << endl;
					cout << " 6. Buscar um elemento na lista 1.";
					cout << "                      ||      13. Buscar um elemento na lista 2." << endl;
					cout << " 7. Retornar se a lista 1 esta vazia ou nao.";
					cout << "            ||      14. Retornar se a lista 2 esta vazia ou nao." << endl;
					cout << "                                    15. Verificar se as duas listas sao iguais." << endl;
					cout << "                                                0. Voltar ao menu." << endl << endl;
					cin >> op;
					
					switch(op){
						case 0:
							
							break;
						
						case 1:
							int e; //elemento
							cout << endl << "Insira um elemento: ";
							cin >> e;
							l1.inserir(e);
							cout << endl << "--- O elemento foi inserido na lista 1! ---" << endl;
							break;
						
						case 2:
							int pos;
							cout << endl << "Insira um elemento: ";
							cin >> e;
							cout << endl << "Insira uma posicao: ";
							cin >> pos;
							l1.inserir(e, pos);
							if(e <= l1.tamanho()+1){
							cout << endl << "--- O elemento foi inserido na lista 1! ---" << endl;
							}
							break;
						
						case 3:
							cout << endl;
							l1.imprimir();
							break;
						
						case 4:
							cout << endl << "Insira a posicao do elemento que deseja remover: ";
							cin >> pos;
							if(pos<=l1.tamanho()){
								cout << endl << "O elemento foi removido!" << endl;
							}
							l1.remover(pos);
							break;
						
						case 5:
							cout << endl << "O tamanho da lista eh: ";
							cout << l1.tamanho() << endl;
					 		break;
					 	
					 	case 6:
					 		cout << endl << "Insira o elemento que deseja buscar: ";
					 		cin >> e;
					 		if (l1.buscar(e) != -1){
								 cout << endl << "O elemento esta na posicao: " << l1.buscar(e) << endl;
							 } else{
								 cout << endl << "O elemento nao existe nesta lista." << endl;
							 }
					 		break;
					 	
					 	case 7:
					 		if(l1.vazia()){
								cout << endl << "A lista esta vazia!" << endl;
							} else{
								cout << endl << "A lista NAO esta vazia!" << endl;
							}
					 		break;
					 	
					 	case 8:
							cout << endl << "Insira um elemento: ";
							cin >> e;
							l2.inserir(e);
							cout << endl << "--- O elemento foi inserido na lista 2! ---" << endl;
					 		break;
					 	
					 	case 9:
							cout << endl << "Insira um elemento: ";
							cin >> e;
							cout << endl << "Insira uma posicao: ";
							cin >> pos;
							l2.inserir(e, pos);
							if(e <= l2.tamanho()+1){
							cout << endl << "--- O elemento foi inserido na lista 2! ---" << endl;
							}
					 		break;
					 	
					 	case 10:
					 		cout << endl;
							l2.imprimir();
					 		break;
					 	
					 	case 11:
					 		cout << endl << "Insira a posicao do elemento que deseja remover: ";
							cin >> pos;
							if(pos<=l2.tamanho()){
								cout << endl << "O elemento foi removido!" << endl;
							}
							l2.remover(pos);
					 		break;
					 	
					 	case 12:
					 		cout << endl << "O tamanho da lista eh: ";
							cout << l2.tamanho() << endl;
					 		break;
					 	
					 	case 13:
					 		cout << endl << "Insira o elemento que deseja buscar: ";
					 		cin >> e;
					 		if (l2.buscar(e) != -1){
								 cout << endl << "O elemento esta na posicao: " << l2.buscar(e) << endl;
							 } else{
								 cout << endl << "O elemento nao existe nesta lista." << endl;
							 }
					 		break;
					 	
					 	case 14:
					 		if(l2.vazia()){
								cout << endl << "A lista esta vazia!" << endl;
							} else{
								cout << endl << "A lista NAO esta vazia!" << endl;
							}
					 		break;
					
						
						case 15:
							if(l2.equivalente(l1, l2)){
								cout << endl << "As duas listas sao iguais!" << endl;
							} else{
								cout << endl << "As listas NAO sao iguais!" << endl;
							}
						break;
					
						default :
       	   	   	   	   	   cout << endl << " *** NUMERO INVALIDO ***" << endl;
       	   	   	   	   	   
					}
				}
     	 	 break;
 
     	 	 case 2 :
     	 	 	op = 1;
     	 	 	while(op != 0){
     	 	 		
					   cout << endl << "                                       --------- LISTA ORDENADA ---------" << endl;
					   cout << endl << "Escolha a operacao que deseja realizar:" << endl << endl;
					   cout << " 1. Inserir elemento ordenadamente na lista 1.";
					   cout << "          ||      7. Inserir elemento ordenadamente na lista 2." << endl;
					   cout << " 2. Imprimir a lista 1.";
						cout << "                                 ||      8. Imprimir a lista 2." << endl;
						cout << " 3. Remover elemento da lista 1.";
						cout << "                        ||      9. Remover elemento da lista 2." << endl;
						cout << " 4. Retornar o tamanho da lista 1.";
						cout << "                      ||      10. Retornar o tamanho da lista 2." << endl;
						cout << " 5. Buscar um elemento na lista 1.";
						cout << "                      ||      11. Buscar um elemento na lista 2." << endl;
						cout << " 6. Retornar se a lista 1 esta vazia ou nao.";
						cout << "            ||      12. Retornar se a lista 2 esta vazia ou nao." << endl;
						cout << "                                    13. Verificar se as duas listas sao iguais." << endl;
						cout << "                                                0. Voltar ao menu." << endl << endl;
					   cin >> op;
					   
					   switch(op){
					   	
						   case 0:
						   	break;
						   
						   case 1:
						   	int e;
						   	cout << endl << "Insira o elemento: ";
							cin >> e;
							o1.inserirordenado(e);
							cout << endl << "--- O elemento foi inserido na lista 1! ---" << endl;
						   	break;
						   
						   case 2:
						   	cout << endl;
							o1.imprimir();
							break;

						   case 3:
							int pos;
							cout << endl << "Insira a posicao do elemento que deseja remover: ";
							cin >> pos;
							if(pos<=o1.tamanho()){
								cout << endl << "O elemento foi removido!" << endl;
							}
							o1.remover(pos);
							break;
						
						case 4:
							cout << endl << "O tamanho da lista eh: ";
							cout << o1.tamanho() << endl;
					 		break;
					 	
					 	case 5:
					 		cout << endl << "Insira o elemento que deseja buscar: ";
					 		cin >> e;
					 		if (o1.buscar(e) != -1){
								 cout << endl << "O elemento esta na posicao: " << o1.buscar(e) << endl;
							 } else{
								 cout << endl << "O elemento nao existe nesta lista." << endl;
							 }
					 		break;
					 	
					 	case 6:
					 		if(o1.vazia()){
								cout << endl << "A lista esta vazia!" << endl;
							} else{
								cout << endl << "A lista NAO esta vazia!" << endl;
							}
					 		break;
					 	
					 	case 7:
						   	cout << endl << "Insira o elemento: ";
							cin >> e;
							o2.inserirordenado(e);
							cout << endl << "--- O elemento foi inserido na lista 2! ---" << endl;
						   	break;
						   
						   case 8:
						   	cout << endl;
							o2.imprimir();
							break;

						   case 9:
							cout << endl << "Insira a posicao do elemento que deseja remover: ";
							cin >> pos;
							if(pos<=o2.tamanho()){
								cout << endl << "O elemento foi removido!" << endl;
							}
							o2.remover(pos);
							break;
						
						case 10:
							cout << endl << "O tamanho da lista eh: ";
							cout << o2.tamanho() << endl;
					 		break;
					 	
					 	case 11:
					 		cout << endl << "Insira o elemento que deseja buscar: ";
					 		cin >> e;
					 		if (o2.buscar(e) != -1){
								 cout << endl << "O elemento esta na posicao: " << o2.buscar(e) << endl;
							 } else{
								 cout << endl << "O elemento nao existe nesta lista." << endl;
							 }
					 		break;
					 	
					 	case 12:
					 		if(o2.vazia()){
								cout << endl << "A lista esta vazia!" << endl;
							} else{
								cout << endl << "A lista NAO esta vazia!" << endl;
							}
					 		break;
					 	
					 	case 13:
					 		if(o2.equivalente(o1, o2)){
								cout << endl << "As duas listas sao iguais!" << endl;
							} else{
								cout << endl << "As listas NAO sao iguais!" << endl;
							}
						break;
					 	
					 	
						
						   default :
  	   	   	   	   	   	   	   cout << endl << " *** NUMERO INVALIDO ***" << endl;
						   
					   }
				   }
       	   
     	 	 break;
 
     	 	 default :
       	   	   cout << endl << " *** NUMERO INVALIDO ***" << endl;
		}
	}
	
}