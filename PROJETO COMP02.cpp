#include <iostream>
#include <string>
#include <list>
#include <queue> // este é o certo 2
#include <set>
#include <stack>
#include <stdlib.h>
#include <time.h>
using namespace std; 			// deixar que o jogador digite um nome talvez?

class personagem_guerreiro{		// Declaração da classe guerreiro e dos seus atributos
	public: 					
		int dano = 10;			
		int vida = 45;
		int mana = 20;
		int defesa = 30;
		int dinheiro = 10;
		int exp = 0;
		int aux;
		int apg;
		
		stack<int> Bonus_vida;		// Declaração de uma pilha para implementar um bonus de vida com a experiencia


		void ROTA_guerreiro(int dano, int mana, int defesa, int vida,int dinheiro,int exp){
		
		Bonus_vida.push(100);			// Inserção de elementos na pilha
		Bonus_vida.push(80);
		Bonus_vida.push(60);
		Bonus_vida.push(40);
		Bonus_vida.push(20);
		

			int escolher;			// Declaração de auxiliares e vida
			int vida2;
			int vida_inimigo = 100;
			int cont = 0;
			int loja_escolher;

															//Mostrar atributos ao usuario
			cout << "Voce tem os seguintes status:" << endl;	
			cout << "Dano: " << dano << endl;      // o jogo teste se divide em 4 rotas diferentes(mago/guerreiro/ladino e paladino)
			cout << "Defesa: " << defesa << endl;  // para cada rota selecionada tera uma historia diferente podendo ou não ter modos de se jogar cada uma diferentemente
			cout << "Vida: " << vida << endl;// ou seja cada rota tera um jeito de jogar novo sendo esse "novo" o modo de luta, status dos personagens, finais e etc.
			//cout << "Mana: " << mana << endl;
			cout << "Dinheiro:" << dinheiro << endl;
			cout << "Experiencia: " << exp << endl;
			cout << endl;
			

			cout << " Inimigo numero " << cont + 1 << endl << endl;
	
	
			while(vida >= 0){
														//Menu para a rota do guerreiro para atacar, verificar atributos
			cout << "1- Atacar "<< dano << " de dano" << endl;
			cout << "2- Voltar para o menu" << endl;
			cout << "3- Verificar status" << endl;
			
			cin >> escolher;
			cout << endl; 
			
			if(escolher == 1){
				
				srand(time(NULL));						// Função para criar um sistema em que o inimigo erra e acerta de forma aleatoria
			    if( (rand() % 10) > 5){												
       				printf("O inimigo acertou (-5)");    
       				vida = vida - 5;
    			}else{
       				printf("O inimigo errou");        
    			}
    			cout << endl; 
    													// A vida do inimigo diminui de acordo com o ataque do personagem
				vida_inimigo = vida_inimigo - dano;
				cout << "Sua nova vida: " << vida << endl;         		
			    cout << "Vida do inimigo: " << vida_inimigo << endl;		
				
			system("pause");
			system("cls");					
			}
			
			if(escolher == 2){

				break;					
				
				
			}
			
			if(escolher == 3){
				
			
		
			cout << "Dano: " << dano << endl;          // Opção do menu para mostrar os atributos foi selecionada
			cout << "Defesa: " << defesa << endl;  
			cout << "Vida: " << vida << endl;
		//cout << "Mana: " << mana << endl;
			cout << "Dinheiro: " << dinheiro << endl;
			cout << "Experiencia: " << exp << endl;
				
				
			system("pause");
			system("cls");					
			}
			
			if(vida_inimigo <= 0){
				cout << "--Inimigo derrotado--" << endl << endl;
				
					srand(time(NULL));						// Função para criar um sistema em que o inimigo erra e acerta de forma aleatoria
			    if( (rand() % 10) > 5){	
				cout << "Seu ataque aumentou" << endl;											
       			//	printf("O inimigo acertou (-5)");    
       				dano = dano + 7;
    			}
				
				dinheiro= dinheiro + 15;				// Apos derrotar o inimigo o usuario irá ganhar aumento em alguns atributos
				exp = exp + 10;
				vida_inimigo = 100;						// reinicialização da vida do inimigo
				
				
				
				if(exp == 10){  		// Um sistema de bonus de vida a cada experiencia atingida, com o uso da pilha
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida = vida + Bonus_vida.top() ;
						Bonus_vida.pop();
				}
				if(exp == 30 ){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida = vida + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				if(exp == 60){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida = vida + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				
				if(exp == 80){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida = vida + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				if(exp == 110){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida = vida + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				
				cont++;
			}
			
			if (vida <= 0){							// Vida do usuario ou personagem chegou ao zero, ou seja
				cout << "---Voce perdeu---" << endl;
				cout << "Inimigos derrotados: " << cont - 1 << endl;
			
				
			}
				
			}
		}
						//Irá existir lojas para alguns atributos, as quais seguirão todas a mesma lógica
		void Loja_GuerreiroVIDA(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item[0] = 10;    // Busca linear utlizada para a loja
			escolher_item[1] = 20;
			escolher_item[2] = 30; 
			int regenerar;
			
																		//Mostra o seu dinheiro atual
			cout << "Seu dinheiro atual: " << dinheiro << endl;       // Menu da loja com as 3 opçoes de Poção
			cout << "Qual pocao de vida gostaria de comprar" << endl;
			cout << "1- Pocao pequena -> +" << escolher_item[0] << endl;
			cout << "2- Pocao media -> +" << escolher_item[1] << endl;
			cout << "3- Pocao grande -> +" << escolher_item[2] << endl;
			
			cin >> regenerar;									
			if(regenerar == 1){
				if(dinheiro < 5){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 5){
				vida = vida + escolher_item[0];            // A cada compra o Dinheiro será descrecido
				cout << "Nova vida = " << vida << endl;
				dinheiro = dinheiro - 5;
			}
			}
			
			if(regenerar == 2){
					if(dinheiro < 10){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 10){
				vida = vida + escolher_item[1];
				cout << "Nova vida = " << vida << endl;
				dinheiro = dinheiro - 10;
			}
			}
			
			if(regenerar == 3){
					if(dinheiro < 15){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 15){
				vida = vida + escolher_item[2];
				cout << "Nova vida = " << vida << endl;
				dinheiro = dinheiro - 15;
			}
			}
			
			
			
		}
					// Loja para o atributo dano
			void Loja_GuerreiroDANO(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item[3] = 10;
			escolher_item[4] = 20;
			escolher_item[5] = 30; 
			int regenerar;
			
			
			cout << "Seu dinheiro atual: " << dinheiro << endl;
			cout << "Qual pocao de dano gostaria de comprar" << endl;
			cout << "4- Pocao pequena -> +" << escolher_item[3] << endl;
			cout << "5- Pocao media -> +" << escolher_item[4] << endl;
			cout << "6- Pocao grande -> +" << escolher_item[5] << endl;
			
			
			cin >> regenerar;
			if(regenerar == 1){
					if(dinheiro < 5){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 5){
				dano = dano + escolher_item[3];
				cout << "Novo dano = " << dano << endl;
				dinheiro = dinheiro - 5;
			}
			}
			
			if(regenerar == 2){
					if(dinheiro < 10){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 10){
				dano = dano + escolher_item[4];
				cout << "Novo dano = " << dano << endl;
				dinheiro = dinheiro - 10;
			}	
			}
			
			if(regenerar == 3){
					if(dinheiro < 15){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 15){
				dano = dano + escolher_item[5];
				cout << "Novo dano = " << dano << endl;
				dinheiro = dinheiro - 15;				
			}
			}
			
			
			
		}
		
											// Loja para o atributo Defesa
			void Loja_GuerreiroDEFESA(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item[6] = 10;
			escolher_item[7] = 20;
			escolher_item[8] = 30; 
			int regenerar;
			
			
			cout << "Seu dinheiro atual: " << dinheiro << endl;			
			cout << "Qual pocao de defesa gostaria de comprar" << endl;
			cout << "4- Pocao pequena -> +" << escolher_item[6] << endl;
			cout << "5- Pocao media -> +" << escolher_item[7] << endl;
			cout << "6- Pocao grande -> + " << escolher_item[8] << endl;
			
			cin >> regenerar;
			if(regenerar == 1){
					if(dinheiro < 5){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 5){
				defesa = defesa + escolher_item[6];
				cout << "Novo defesa = " << defesa << endl;
				dinheiro = dinheiro - 5;
			}	
			}
			
			if(regenerar == 2){
					if(dinheiro < 10){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 10){
				defesa = defesa + escolher_item[7];
				cout << "Novo defesa = " << defesa << endl;
				dinheiro = dinheiro - 10;
			}					
			}
			
			if(regenerar == 3){
					if(dinheiro < 15){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro >= 15){
				defesa = defesa + escolher_item[8];
				cout << "Novo defesa = " << defesa << endl;
				dinheiro = dinheiro - 15;
			}
			}
			
			
			
		}


};
				//Inicialização da classe mago
class personagem_mago{
	public:						// Declaração dos atributos da classe mago
		int dano_M = 20;
		int vida_M = 35;
		int mana_M = 45; 
		int defesa_M = 30;
		int dinheiro_M = 0;
		int exp = 0;
		int aux;
		int apg;
		
		stack<int> Bonus_vida;				// Declaração da pilha utilizada para o sistema de bonus de vida

		void ROTA_mago(int dano, int mana, int defesa, int vida,int dinheiro,int exp){ // Metodo para a rota do mago, para se jogar com o mago
				
		Bonus_vida.push(100);		//	Preenchimento da pilha
		Bonus_vida.push(80);
		Bonus_vida.push(60);
		Bonus_vida.push(40);
		Bonus_vida.push(20);
		
		
		
		
			int vida_inimigo_M = 100;				// declaração da vida do inimigo e de alguns auxiliares 
			int escolher_M;
			int cont;							// Contador utiilizado na contagem dos inimigos 
						
		

			cout << "Seus atributos sao--" << endl;				//Mostragem dos atributos
			cout << "Dano: " << dano_M << endl;
			cout << "Defesa: " << defesa_M << endl;
			cout << "Vida: " << vida_M << endl;
			cout << "Mana: " << mana_M << endl;
			cout << "Dinheiro:" << dinheiro_M << endl;
			cout << "Experiencia: " << exp << endl;
			cout << endl;
			

			
			cout << " Inimigo numero " << cont + 1 << endl << endl;
	
	
			while(vida_M >= 0){
																// Menu para se jogar com o mago, ou seja, atacar com o mago, verificar status, 
																//voltar para o menu para utilizar a loja
			cout << "1- Atacar -" << dano_M << " de mana" << endl;			
			cout << "2- Voltar para o menu" << endl;
			cout << "3- Verificar status" <<endl;
			
			cin >> escolher_M;
			cout << endl;
											// Função para o acerto ou não do ataque inimigo 
			if(escolher_M == 1){

				srand(time(NULL));
			    if( (rand() % 10) > 5){
       				printf("O inimigo acertou (-5)");    
       				vida_M = vida_M - 5;
    			}else{
       				printf("O inimigo errou");        
    			}
    			cout << endl; 


														// Inimigo sofrendo o dano do mago
				vida_inimigo_M = vida_inimigo_M - 20;
				cout << "Sua nova vida: " << vida_M << endl;         // aqui fica um pequeno exemplo de como as batalhas vão ocorrer sendo que isso é so exemplo e o codigo
			    cout << "Vida do inimigo: " << vida_inimigo_M << endl;
				
			system("pause");
			system("cls");					
			}
			
			if(vida_inimigo_M <= 0){							// Apos derrotar o inimigo, alguns atributos serão atualizados e a vida do inimimo reinicia
				cout << "Voce derrotou o inimigo, podera avancar" << endl << endl;
				dinheiro_M= dinheiro_M + 15;
				exp = exp + 10;
				vida_inimigo_M = 100;
				
									// Sistema para ganho de um bonus de vida após atingir certa experiencia, com a utilização de pilha e seus metódos
			if(exp == 10){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_M = vida_M + Bonus_vida.top() ;
						Bonus_vida.pop();
				}
				if(exp == 30 ){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_M = vida_M + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				if(exp == 60){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_M = vida_M + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				
				if(exp == 80){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_M = vida_M + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				if(exp == 110){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_M = vida_M + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				
				
				cont++;
			}
								// O usuario perdeu o jogo, pois sua vida zerou, irá aparecer a quantidade de inimigos derrotados
			if (vida_M <= 0){
				cout << "---Voce perdeu---" << endl;
				cout << "Inimigos derrotados: " << cont - 1<< endl;
			
				
			}
			
									//Opção para sair desse  menu e voltar ao principal
			
			if(escolher_M == 2){

				break;
				
				
			}
									//Opção do menu para verificar os atributos
			if(escolher_M == 3){
			cout << "Dano: " << dano_M << endl;      // o jogo teste se divide em 4 rotas diferentes(mago/guerreiro/ladino e paladino)
			cout << "Defesa: " << defesa_M << endl;  // para cada rota selecionada tera uma historia diferente podendo ou não ter modos de se jogar cada uma diferentemente
			cout << "Vida: " << vida_M << endl;// ou seja cada rota tera um jeito de jogar novo sendo esse "novo" o modo de luta, status dos personagens, finais e etc.
			cout << "Mana: " << mana_M << endl;
			cout << "Dinheiro: " << dinheiro_M << endl;
			cout << "Experiencia: " << exp << endl;
				
			system("pause");
			system("cls");				
			}
			
			
		}
		
		
			
		
}
				//Loja para a compra de vida
	void Loja_MAGOVIDA(int escolher_item_M[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
											
			escolher_item_M[0] = 10;		// Utilização da busca linear para os items
			escolher_item_M[1] = 20;
			escolher_item_M[2] = 30; 
			int regenerar_M;
			
			cout << "Seu dinheiro atual: " << dinheiro_M << endl;	// O dinheiro atual e as opções de poções disponiveis e seus preços
			cout << "Qual pocao de vida gostaria de comprar" << endl << endl;
			cout << "1- Pocao pequena -> +" << escolher_item_M[0] << endl;
			cout << "2- Pocao media -> +" << escolher_item_M[1] << endl;
			cout << "3- Pocao grande -> +" << escolher_item_M[2] << endl;
			
			cin >> regenerar_M;
			if(regenerar_M == 1){
					if(dinheiro_M < 5){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro_M){
				vida_M = vida_M + escolher_item_M[0];		// Vida acrescida e dinheiro descrecido de acordo com a poção e seu preço
				cout << "Nova vida = " << vida_M << endl;
				dinheiro_M = dinheiro_M - 5;
			}
			}
			
			if(regenerar_M == 2){
					if(dinheiro_M < 10){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro_M){
				vida_M = vida_M + escolher_item_M[1];		// Vida acrescida e dinheiro descrecido de acordo com a poção e seu preço
				cout << "Nova vida = " << vida_M << endl;
				dinheiro_M = dinheiro_M - 10;
			}
				
			}
			
			if(regenerar_M == 3){
				if(dinheiro_M < 15){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro_M){
				vida_M = vida_M + escolher_item_M[2];		// Vida acrescida e dinheiro descrecido de acordo com a poção e seu preço
				cout << "Nova vida = " << vida_M << endl;
				dinheiro_M = dinheiro_M - 15;
			}
			}
		
			
			
		}
					// loja para mana do mago
			void Loja_MAGOMANA(int escolher_item_M[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item_M[3] = 10;
			escolher_item_M[4] = 20;
			escolher_item_M[5] = 30; 
			int regenerar_M;
			
			cout << "Seu dinheiro atual: " << dinheiro_M << endl;
			cout << "Qual pocao de mana gostaria de comprar" << endl;
			cout << "1- Pocao pequena -> + " << escolher_item_M[3] << endl;
			cout << "2- Pocao media -> + " << escolher_item_M[4] << endl;
			cout << "3- Pocao grande -> + " << escolher_item_M[5] << endl;
			
			cin >> regenerar_M;
			if(regenerar_M == 1){
				if(dinheiro_M < 5){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro_M){
				vida_M = vida_M + escolher_item_M[3];		// Vida acrescida e dinheiro descrecido de acordo com a poção e seu preço
				cout << "Nova vida = " << vida_M << endl;
				dinheiro_M = dinheiro_M - 5;
			}
				
			}
			
			if(regenerar_M == 2){
				if(dinheiro_M < 10){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro_M){
				vida_M = vida_M + escolher_item_M[4];		// Vida acrescida e dinheiro descrecido de acordo com a poção e seu preço
				cout << "Nova vida = " << vida_M << endl;
				dinheiro_M = dinheiro_M - 10;
			}
				
			}
			
			if(regenerar_M == 3){
				if(dinheiro_M < 15){
					cout << "voce nao tem dinheiro suficiente" << endl;
				}
				if(dinheiro_M){
				vida_M = vida_M + escolher_item_M[5];		// Vida acrescida e dinheiro descrecido de acordo com a poção e seu preço
				cout << "Nova vida = " << vida_M << endl;
				dinheiro_M = dinheiro_M - 15;
			}
				
			}
			
			
			
		}
		
};

							// Inicialização da classe do paladinno
class personagem_paladino{
	public: 
		int dano_P = 15;		// Declaração dos atributos do paladino
		int vida_P = 50;
		int mana_P = 15;
		int defesa_P = 37;
		int dinheiro_P = 0;
		int exp = 0;
		int aux;
		int apg;

		stack<int> Bonus_vida;			//Pilha para o sistema de bonus de vida

		void ROTA_paladino(int dano, int mana, int defesa, int vida,int dinheiro,int exp){ // Metodo para a opção do paladino
			
			
		Bonus_vida.push(100);			//Preenchimento da pilha
		Bonus_vida.push(80);
		Bonus_vida.push(60);
		Bonus_vida.push(40);
		Bonus_vida.push(20);

			int escolher;				// Alguns auxiliares e declaração da vida do inimigo
			int vida2;
			int vida_inimigo = 100;
			int cont = 0;
			int loja_escolher;

		
											//Mostrar os atributos do personagem
			cout << "Seus atributos sao--" << endl;
			cout << "Dano: " << dano_P << endl;      // o jogo teste se divide em 4 rotas diferentes(mago/guerreiro/ladino e paladino)
			cout << "Defesa: " << defesa_P << endl;  // para cada rota selecionada tera uma historia diferente podendo ou não ter modos de se jogar cada uma diferentemente
			cout << "Vida: " << vida_P << endl;// ou seja cada rota tera um jeito de jogar novo sendo esse "novo" o modo de luta, status dos personagens.
		//	cout << "Mana: " << mana_P << endl;
			cout << "Dinheiro: " << dinheiro_P << endl;
			cout << "Experiencia: " << exp << endl;
			cout << endl;
			


			cout << " inimigo numero" << cont + 1 << endl << endl;
	
			while(vida >= 0){
													//Menu para o paladino, com a opção de atacar, verificar atributos e voltar ao menu anterior
			cout << "1- Atacar -" << dano_P << " de dano" << endl;
			cout << "2- Voltar para o menu" << endl;
			cout << "3- Verificar status" <<endl;
			
			cin >> escolher;
			cout << endl;
			
			if(escolher == 1){				// Função para o acerto ou erro de forma aletoria do ataque inimigo

				srand(time(NULL));
			    if( (rand() % 10) > 5){
       				printf("O inimigo acertou (-5)");
       				vida_P = vida_P - 5;
       				defesa_P = defesa_P - 5;
       			
       				
    			}else{
       				printf("O inimigo errou");        
    			}
					if(defesa_P <= 0){
       					vida_P = vida_P - 5;
					   }
    			cout << endl; 


										// Vida do inimigo descrecida de acordo com o dano do personagem
				vida_inimigo = vida_inimigo - 15;
				cout << "Sua nova vida: " << vida_P << endl;        
			    cout << "Vida do inimigo: " << vida_inimigo << endl;


			system("pause");
			system("cls");					
			}
			
			if(escolher == 2){
											//Voltar ao menu anterior
				break;
				
				
			}
			
			if(escolher == 3){
										//Opção de mostrar os atributos atualmente

			cout << "Dano: " << dano_P << endl;      // o jogo teste se divide em 4 rotas diferentes(mago/guerreiro/ladino e paladino)
			cout << "Defesa: " << defesa_P << endl;  // para cada rota selecionada tera uma historia diferente podendo ou não ter modos de se jogar cada uma diferentemente
			cout << "Vida: " << vida_P << endl;// ou seja cada rota tera um jeito de jogar novo sendo esse "novo" o modo de luta, status dos personagens, finais e etc.
			cout << "Mana: " << mana_P << endl;
			cout << "Dinheiro: " << dinheiro_P << endl;
			cout << "Experiencia: " << exp << endl;
				
			system("pause");
			system("cls");					
			}
			
			if(vida_inimigo <= 0){					//Voce Derrotou o inimigo, alguns dos seus atributos serão atualizados, vida do inimigo reinicia
				cout << "Voce derrotou o inimigo, podera avancar" << endl << endl;
				
					srand(time(NULL));
			    if( (rand() % 10) > 5){
       				cout << "sua defesa aumentou" << endl;   
       				defesa_P = defesa_P + 8;
    			}
				dinheiro_P= dinheiro_P + 15;		
				exp = exp + 10;		
				vida_inimigo = 100;
				
								// sistema para o bonus de  vida ganho após algum alcançar certa experiencia, feito com if e pilha
				if(exp == 10){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_P = vida_P + Bonus_vida.top() ;
						Bonus_vida.pop();
				}
				if(exp == 30 ){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_P = vida_P + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				if(exp == 60){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_P = vida_P + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				
				if(exp == 80){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_P = vida_P + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				if(exp == 110){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_P = vida_P + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				
				
				
				
				cont++;				// contador para atualizar o numero de inimigos derrotados
			}
			
			if (vida_P <= 0){								//O usuario perdeu, pois sua vida zerou, mostra os inimigos derrotados
				cout << "---Voce perdeu---" << endl;
				vida_P = 35;
				defesa_P = 5;
				cout << "Inimigos derrotados: " << cont - 1 << endl;
			
				
			}
				
			}
		}
								
		void Loja_paladinoVIDA(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item[0] = 10;
			escolher_item[1] = 20;			//Loja para a vida do paladino feito com busca linear
			escolher_item[2] = 30;
			int regenerar;
											
			cout << "Seu dinheiro atual: " << dinheiro_P << endl;					//Mostrar o dinheiro atual
			cout << "Qual pocao de vida gostaria de comprar" << endl;				//Tipos de Poções e seus preços
			cout << "1- Pocao pequena -> + " << escolher_item[0] << endl;
			cout << "2- Pocao media -> + " << escolher_item[1] << endl;
			cout << "3- Pocao grande -> + " << escolher_item[2] << endl;
			
			cin >> regenerar;
			if(regenerar == 1){								// Vida acrescida de acordo a poção
				vida_P = vida_P + escolher_item[0];			// Dinheiro descrescido de acordo com o preço
				cout << "Nova vida = " << vida_P << endl;
				dinheiro_P = dinheiro_P - 5;
			}
			
			if(regenerar == 2){
				vida_P = vida_P + escolher_item[1];
				cout << "Nova vida = " << vida_P << endl;
				dinheiro_P = dinheiro_P - 10;
				
			}
			
			if(regenerar == 3){
				vida_P = vida_P + escolher_item[2];
				cout << "Nova vida = " << vida_P << endl;
				dinheiro_P = dinheiro_P - 15;
			}

			
			
		}
					// Loja para o dano
			void Loja_paladinoDANO(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item[3] = 10;
			escolher_item[4] = 20;
			escolher_item[5] = 30;
			int regenerar;
			
			cout << "Seu dinheiro atual: " << dinheiro_P << endl;
			cout << "Qual pocao de dano gostaria de comprar" << endl;
			cout << "4- Pocao pequena -> + " << escolher_item[3] << endl;
			cout << "5- Pocao media -> + " << escolher_item[4] << endl;
			cout << "6- Pocao grande -> + " << escolher_item[5] << endl;
			
			cin >> regenerar;
			if(regenerar == 1){
				dano_P = dano_P + escolher_item[3];
				cout << "Novo dano = " << dano_P << endl;
				dinheiro_P = dinheiro_P - 5;
			}
			
			if(regenerar == 2){
				dano_P = dano_P + escolher_item[4];
				cout << "Novo dano = " << dano_P << endl;
				dinheiro_P = dinheiro_P - 10;
				
			}
			
			if(regenerar == 3){
				dano_P = dano_P + escolher_item[5];
				cout << "Novo dano = " << dano_P << endl;
				dinheiro_P = dinheiro_P - 15;
			}
		
			
			
		}
		
				//Loja para a defesa
			void Loja_paladinoDEFESA(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item[6] = 10;
			escolher_item[7] = 20;
			escolher_item[8] = 30; 
			int regenerar;
			
			cout << "Seu dinheiro atual: " << dinheiro_P << endl;
			cout << "Qual pocao de defesa gostaria de comprar" << endl;
			cout << "4- Pocao pequena -> + " << escolher_item[6] << endl;
			cout << "5- Pocao media -> + " << escolher_item[7] << endl;
			cout << "6- Pocao grande -> + " << escolher_item[8] << endl;
			
			cin >> regenerar;
			if(regenerar == 1){
				defesa_P = defesa_P + escolher_item[6];
				cout << "Novo defesa = " << defesa_P << endl;
				dinheiro_P = dinheiro_P - 5;
			}
			
			if(regenerar == 2){
				defesa_P = defesa_P + escolher_item[7];
				cout << "Novo defesa = " << defesa_P << endl;
				dinheiro_P = dinheiro_P - 10;
				
			}
			
			if(regenerar == 3){
				defesa_P = defesa_P + escolher_item[8];
				cout << "Novo defesa = " << defesa_P << endl;
				dinheiro_P = dinheiro_P - 15;
			}
			
			
			
		}


};



class personagem_ladino{
	public: 
		int dano_L = 20;
		int vida_L = 30;
		int mana_L = 15;
		int defesa_L = 20;
		int dinheiro_L = 0;
		int exp = 0;
		int aux;
		int apg;


		stack<int> Bonus_vida;

		void ROTA_ladino(int dano, int mana, int defesa, int vida,int dinheiro, int exp){
					
			
		Bonus_vida.push(100);
		Bonus_vida.push(80);
		Bonus_vida.push(60);
		Bonus_vida.push(40);
		Bonus_vida.push(20);
			

			int escolher;
			int vida2;
			int vida_inimigo = 100;
			int cont = 0;
			int loja_escolher;

		

			cout << "Seus atributos sao--" << endl;
			cout << "Dano: " << dano_L << endl;      // o jogo teste se divide em 4 rotas diferentes(mago/guerreiro/ladino e paladino)
			cout << "Defesa: " << defesa_L << endl;  // para cada rota selecionada tera uma historia diferente podendo ou não ter modos de se jogar cada uma diferentemente
			cout << "Vida: " << vida_L << endl;// ou seja cada rota tera um jeito de jogar novo sendo esse "novo" o modo de luta, status dos personagens, finais e etc.
		//	cout << "Mana: " << mana_L << endl;
			cout << "Dinheiro: " << dinheiro_L << endl;
			cout << "Experiencia: " << exp << endl;
			
			cout << endl;
			

			cout << " Inimigo numero " << cont + 1 << endl << endl;
	
	
			while(vida >= 0){
				
			cout << "1- Atacar - " << dano_L << " de dano"<< endl;
			cout << "2- Voltar para o menu" << endl;
			cout << "3- Verificar status" <<endl;
			
			cin >> escolher;
			cout << endl;
			
			if(escolher == 1){

				srand(time(NULL));
			    if( (rand() % 10) > 7){
       				printf("O inimigo acertou (-5)");    // funcao para saber se eu recebo ou não um ataque
       				vida_L = vida_L - 5;
    			}else{
       				printf("O inimigo errou");        
    			}
    			cout << endl; 


				vida_inimigo = vida_inimigo - 20;
				cout << "Sua nova vida: " << vida_L << endl;         
			    cout << "Vida do inimigo: " << vida_inimigo << endl;
				
			system("pause");
			system("cls");					
			}
			
			if(escolher == 2){

				break;
				
				
			}
			
			if(escolher == 3){
				

		//	cout << "Seus atributos sao--" << endl;
			cout << "Dano: " << dano_L << endl;      // o jogo teste se divide em 4 rotas diferentes(mago/guerreiro/ladino e paladino)
			cout << "Defesa: " << defesa_L << endl;  // para cada rota selecionada tera uma historia diferente podendo ou não ter modos de se jogar cada uma diferentemente
			cout << "Vida: " << vida_L << endl;// ou seja cada rota tera um jeito de jogar novo sendo esse "novo" o modo de luta, status dos personagens, finais e etc.
		//	cout << "Mana: " << mana_L << endl;
			cout << "Dinheiro :" << dinheiro_L << endl;
			cout << "Experiencia: " << exp << endl;
				
			system("pause");
			system("cls");					
			}
			
			if(vida_inimigo <= 0){
				cout << "Voce derrotou o inimigo, podera avancar" << endl << endl;
				dinheiro_L= dinheiro_L + 15;
				exp = exp + 10;
				vida_inimigo = 100;
				
				if(exp == 10){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_L = vida_L + Bonus_vida.top() ;
						Bonus_vida.pop();
				}
				if(exp == 30 ){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_L = vida_L + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				if(exp == 60){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_L = vida_L + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				
				if(exp == 80){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_L = vida_L + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				if(exp == 110){
					cout << "Voce ganhou um bonus de vida de " << Bonus_vida.top() << endl << endl;
					
					vida_L = vida_L + Bonus_vida.top() ;
					Bonus_vida.pop();
				}
				
				
				
				cont++;
			}
			
			if (vida <= 0){
				cout << "---Voce perdeu---" << endl;
				cout << "Seus inimigos derrotados foram: " << cont << endl;
			
				
			}
				
			}
		}
		
		void Loja_ladinoVIDA(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item[0] = 10;
			escolher_item[1] = 20;
			escolher_item[2] = 30; 
			int regenerar;
			
			cout << "Seu dinheiro atual: " << dinheiro_L << endl;
			cout << "Qual pocao de vida gostaria de comprar" << endl;
			cout << "1- Pocao pequena -> + " << escolher_item[0] << endl;
			cout << "2- Pocao media -> + " << escolher_item[1] << endl;
			cout << "3- Pocao grande -> + " << escolher_item[2] << endl;
			
			cin >> regenerar;
			if(regenerar == 1){
				vida_L = vida_L + escolher_item[0];
				cout << "Nova vida = " << vida_L << endl;
				dinheiro_L = dinheiro_L - 5;
			}
			
			if(regenerar == 2){
				vida_L = vida_L + escolher_item[1];
				cout << "Nova vida = " << vida_L << endl;
				dinheiro_L = dinheiro_L - 10;
				
			}
			
			if(regenerar == 3){
				vida_L = vida_L + escolher_item[2];
				cout << "Nova vida = " << vida_L << endl;
				dinheiro_L = dinheiro_L - 15;
			}
		
			
			
		}
		
			void Loja_ladinoDANO(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO" que ainda irei criar
			
			escolher_item[3] = 10;
			escolher_item[4] = 20;
			escolher_item[5] = 30; 
			int regenerar;
		
			cout << "Seu dinheiro atual: " << dinheiro_L << endl;
			cout << "Qual pocao de dano gostaria de comprar" << endl;
			cout << "4- Pocao pequena -> + " << escolher_item[3] << endl;
			cout << "5- Pocao media -> + " << escolher_item[4] << endl;
			cout << "6- Pocao grande -> + " << escolher_item[5] << endl;
			
			cin >> regenerar;
			if(regenerar == 1){
				dano_L = dano_L + escolher_item[3];
				cout << "Novo dano = " << dano_L << endl;
				dinheiro_L = dinheiro_L - 5;
			}
			
			if(regenerar == 2){
				dano_L = dano_L + escolher_item[4];
				cout << "Novo dano = " << dano_L << endl;
				dinheiro_L = dinheiro_L - 10;
				
			}
			
			if(regenerar == 3){
				dano_L = dano_L + escolher_item[5];
				cout << "Novo dano = " << dano_L << endl;
				dinheiro_L = dinheiro_L - 15;
			}
			
			
			
		}
		
		
			void Loja_ladinoDEFESA(int escolher_item[]){ // aqui vai ficar a quantidade de vida que voce vai regenerar, o valor dos itens sera dado na variavel "DINHEIRO"
			
			escolher_item[6] = 10;
			escolher_item[7] = 20;
			escolher_item[8] = 30; 
			int regenerar;
			
			cout << "Seu dinheiro atual: " << dinheiro_L << endl;
			cout << "Qual pocao de defesa gostaria de comprar" << endl;
			cout << "4- Pocao pequena -> + " << escolher_item[6] << endl;
			cout << "5- Pocao media -> + " << escolher_item[7] << endl;
			cout << "6- Pocao grande -> + " << escolher_item[8] << endl;
			
			cin >> regenerar;
			if(regenerar == 1){
				defesa_L = defesa_L + escolher_item[6];
				cout << "Novo defesa = " << defesa_L << endl;  // aqui fica a loja, tendo sempre que verificar se o jogador tem ou não dinheiro
				dinheiro_L = dinheiro_L - 5;                   // se não tiver não podera comprar e uma mensagem sera
			}
			
			if(regenerar == 2){
				defesa_L = defesa_L + escolher_item[7];
				cout << "Novo defesa = " << defesa_L << endl;
				dinheiro_L = dinheiro_L - 10;
				
			}
			
			if(regenerar == 3){
				defesa_L = defesa_L + escolher_item[8];
				cout << "Novo defesa = " << defesa_L << endl;
				dinheiro_L = dinheiro_L - 15;
			}
			
			
			
		}


};

	

int main(){
						            // aqui na main é que definimos as variaveis que vão para as classes, separamos os valores dela e jogamos o jogo
	personagem_guerreiro guerreiro;
	personagem_mago mago;
	personagem_paladino paladino;
	personagem_ladino ladino;
	
	string nome;
	int aux;
	int escolha;
	int ataque;
	int selecionar_G;
	int selecionar_M;
	int selecionar_P;
	int selecionar_L;
	

	cout << "--| Boas vindas viajante me chamo Tirion e eu serei seu mercador, guia e ajudante nesta aventura" << endl;
	cout << "--| Antes de mais nada por favor me diga seu nome: ";
	cin >> nome;
	//system("pause");
	system("cls");	
	
	cout << "Muito prazer " << nome << " antes de continuarmos escolha uma classe" << endl << endl;
	//cout << endl;
	
	//cout<<" " << endl << endl;
	
	cout << "Selecao de classe:"<< endl;
	cout << "1-Guerreiro" << endl;
	cout << "2-Mago" << endl;
	cout << "3-Paladino" << endl;
	cout << "4-ladino" << endl; // um metodo de confirmação de escolha
	
	cin >> escolha;
	
	
	system("pause");
	system("cls");	
	
	switch (escolha){            // switch para escolha de um personagem
		
		case 1:{
			
			cout << "-----|Voce selecionou o guerreiro, esta classe tem a chance de seu ataque aumentar a cada inimigo derrotado|-----" << endl;
			cout << endl;
		
			
			while(3){
				cout << "1- Historia Guerreiro" << endl;
				cout << "2- Loja do Tirion-Guerreiro" << endl;
				cout << "3- Encerrar jogo" << endl; 
				cin >> selecionar_G;
				
			if(selecionar_G == 1){
				

			
			guerreiro.ROTA_guerreiro(guerreiro.dano, guerreiro.mana, guerreiro.defesa, guerreiro.vida, guerreiro.dinheiro, guerreiro.exp);
			
			system("pause");
			system("cls");			
			
		}
		
		    if(selecionar_G == 2){
		    	
		    while(4){
		    	
		    	cout << "minha loja e a carroca puxada pelo meu cavalo plotka e nela tem de tudo, pocoes de vida, mana e defesa" << endl;
		    	cout << "garanto que tudo que tem aqui dentro e de qualidade e se quebrar vai pagar" << endl;
		    	
		    //	cout << "Meu caro " << nome << " aqui na minha mochila tem de tudo pocoes de vida, defesa e dano" << endl;
		    	system("pause");
		    	system("cls");
		    	cout << "Por favor nao se acanhe escolha uma pocao e eu lhe darei ela(pelo preco certo)" << endl << endl;
				cout << "Preco das pocoes: " << endl;
				cout << "Pequena = 5" << endl;
				cout << "Media = 10" << endl;
				cout << "Grande = 15" << endl << endl;
				cout << "1- Comprar Vida" << endl;
		    	cout << "2- Comprar Dano" << endl;
		    	cout << "3- Comprar Defesa" << endl;
		    	cout << "4- Sair da loja" << endl;
		    	
				int escolher_item[9];
		    	int i;
		    	
				cin >> i;
		    	
		    	if(i==1){
				
				guerreiro.Loja_GuerreiroVIDA(escolher_item);  // para poder acessas as classes que definimos acima
				
				system("pause");
				system("cls");				
				}
				
				if(i==2){
				
		    	guerreiro.Loja_GuerreiroDANO(escolher_item);
		    	
				system("pause");
				system("cls");		    	
		    	
		    	}
		    	
		    	if(i==3){
				
		    	guerreiro.Loja_GuerreiroDEFESA(escolher_item);
		    	
				system("pause");
				system("cls");		    	
		    	
		    	}
		    	
		    	if(i==4){
		    		break;
				}
		        			
				
				}
			system("pause");
			system("cls");					
				
				}
				
				
				if(selecionar_G == 3){           // para poder finalizar o programa 
					
					exit(3);
					break;
				}
			
				}
		}
			
			
		case 2:{
			
			cout << "Voce selecionou o mago, os ataques dele sao baseados em sua mana(quanto mais mana mais dano voce da)" << endl;
			cout << endl;
			
			while(3){
				cout << "1- Historia Mago" << endl;
				cout << "2- Loja do Tirion-Mago" << endl;
				cout << "3- Encerrar jogo" << endl;
				cin >> selecionar_M;
				
				if(selecionar_M == 1){
			mago.ROTA_mago(mago.dano_M, mago.mana_M, mago.defesa_M, mago.vida_M,mago.dinheiro_M,mago.exp);
		
			system("pause");
			system("cls");		
		
		}
		
		
		        if(selecionar_M == 2){
		        	int escolher_item_M[6];
		        
			while(3){
				
				cout << "Aqui nesta mochila tem as pocoes que quiser mas e curioso nunca vi um mago dando dano usando sua mana" << endl;
				system("pause");
				system("cls");
				cout << "vamos escolha uma tenho mais cliente pra procurar" << endl;
				cout << "Preco das pocoes: " << endl;
				cout << "Pequena = 5" << endl;
				cout << "Media = 10" << endl;
				cout << "Grande = 15" << endl << endl;			
				cout << "1- Comprar Vida" << endl;
		    	cout << "2- Comprar Mana" << endl;
		    	cout << "3- Sair da loja" << endl;
		    	
				int escolher_item[6];
		    	int i;
		    	
				cin >> i;
		    	
		    	if(i==1){
				
				mago.Loja_MAGOVIDA(escolher_item_M);
				
				system("pause");
				system("cls");				
				}
				
				if(i==2){
				
				mago.Loja_MAGOMANA(escolher_item_M);		    	
				
				system("pause");
				system("cls");		    	
		    	
		    	}
		    	
		    	if(i==3){
		    		break;
				}
		        	
		        				
				
				}
			system("pause");
			system("cls");					
				
				}
				
				
				if(selecionar_M == 3){
					exit(3);
					break;
				}
			
				}
		}
		
		case 3:{
			cout << "Voce selecionou o paladino, esta classe tem a chance de aumentar sua defesa a cada inimigo derrotado" << endl;
			cout << endl;			

			while(3){
				cout << "1- Historia paladino" << endl;
				cout << "2- Loja do Tirion-Paladino" << endl;
				cout << "3- Encerrar jogo" << endl; 
				cin >> selecionar_P;
				
			if(selecionar_P == 1){
				

			
			paladino.ROTA_paladino(paladino.dano_P, paladino.mana_P, paladino.defesa_P, paladino.vida_P, paladino.dinheiro_P, paladino.exp);
			
			system("pause");
			system("cls");			
			
		}
		
		    if(selecionar_P == 2){
		    	
		    while(4){
		    	
		    	cout << "Um Paladino ein...soube que voces gostam de uma boa defesa, entre, eu tenho algumas opcoes pra voce " << endl;
		    	system("pause");
		    	system("cls");
				cout << "entao, vamos levar quantas hoje?" << endl;
				cout << "Preco das pocoes: " << endl;
				cout << "Pequena = 5" << endl;
				cout << "Media = 10" << endl;
				cout << "Grande = 15" << endl << endl;
				cout << "1- Comprar Vida" << endl;
		    	cout << "2- Comprar Dano" << endl;
		    	cout << "3- Comprar Defesa" << endl;
		    	cout << "4- Sair da loja" << endl;
		    	
				int escolher_item[9];
		    	int i;
		    	
				cin >> i;
		    	
		    	if(i==1){
				
				paladino.Loja_paladinoVIDA(escolher_item);
				
				system("pause");
				system("cls");				
				}
				
				if(i==2){
				
		    	paladino.Loja_paladinoDANO(escolher_item);
		    	
				system("pause");
				system("cls");		    	
		    	
		    	}
		    	
		    	if(i==3){
				
		    	paladino.Loja_paladinoDEFESA(escolher_item);
		    	
				system("pause");
				system("cls");		    	
		    	
		    	}
		    	
		    	if(i==4){
		    		break;
				}
		        			
				
				}
			system("pause");
			system("cls");					
				
				}
				
				
				if(selecionar_P == 3){
					exit(3);
					break;
				}
			
				}
		}
			break;
		
		
		case 4:{
			cout << "Voce selecionou o ladino, esta classe tem maior chance de se esquivar de ataques inimigos" << endl;
			
			cout << endl;
			
			
			while(3){
				cout << "1- Historia ladino" << endl;
				cout << "2- Loja do Tirion-Ladino" << endl;
				cout << "3- Encerrar jogo" << endl;
				cin >> selecionar_L;
				
			if(selecionar_L == 1){
				

			
			ladino.ROTA_ladino(ladino.dano_L, ladino.mana_L, ladino.defesa_L, ladino.vida_L, ladino.dinheiro_L, ladino.exp);
			
			system("pause");
			system("cls");			
			
		}
		
		    if(selecionar_L == 2){
		    	
		    while(4){
		    	
		    	cout << "Aqui eu tenho tudo que precisar, vamos, venha ver" << endl;
		    	system("pause");
		    	system("cls");
		    	cout << "Com o preco certo voce compra o que quiser, o que vai ser hoje?" << endl;
				cout << "Preco da pocao: " << endl;
				cout << "Pequena = 5" << endl;
				cout << "Media = 10" << endl;
				cout << "Grande = 15" << endl << endl;
				cout << "1- Comprar Vida" << endl;
		    	cout << "2- Comprar Dano" << endl;
		    	cout << "3- Comprar Defesa" << endl;
		    	cout << "4- Sair da loja" << endl;
		    	
				int escolher_item[9];
		    	int i;
		    	
				cin >> i;
		    	
		    	if(i==1){
				
				ladino.Loja_ladinoVIDA(escolher_item);
				
				system("pause");
				system("cls");				
				}
				
				if(i==2){
				
		    	ladino.Loja_ladinoDANO(escolher_item);
		    	
				system("pause");
				system("cls");		    	
		    	
		    	}
		    	
		    	if(i==3){
				
		    	ladino.Loja_ladinoDEFESA(escolher_item);
		    	
				system("pause");
				system("cls");		    	
		    	
		    	}
		    	
		    	if(i==4){
		    		break;
				}
		        			
				
				}
			system("pause");
			system("cls");					
				
				
				}
				
						if(selecionar_L == 3){
					exit(3);
					break;
				}
				
				
		}
			break;
		}
	}
	
	return 0;
}






