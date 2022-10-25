//ProgramaListaSequencialSupermercado.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <locale.h>
#include <Windows.h>

using namespace std;

//defini��o da estrutura
struct NOLLS {
    int id;
    string produto;
    float preco;
    int qtdEmEstoque;
};

//defini��o de constantes e vari�veis globais
const int N=5;
NOLLS lista [N];
NOLLS val;
int fim, k, aux, consultId;
bool sinal;
char conf;
int width=0, height=0;

//prototipa��o das fun��es
void lls_1(); // inserir no fim da lista
void lls_2(); // inserir na posicao K
void lls_3(); // Procurar um no por id e inserir um novo no POSTERIOR ao no encontrado
void lls_4(); // Consultar o no anterior ao no da Posicao K
void lls_5(); // Remover na posicao K+3
void lls_6(); // Procurar um no e remover o segundo no anterior ao no encontrado
void lls_7(); // Consultar um no no inicio da Lista
void lls_8(); // Alterar o conteudo de um no com nome de produto igual a Y
void lls_9(); // Procurar um no por preco e alterar o conteudo do no posterior ao no encontrado
void lls_10(); // Imprimir os nos que possuem valores impares menores que R$60,00
void lls_11(); // Imprimir conteudo da lista em ordem inversa
void lls_12(); // Classificar em ordem crescente de quantidade em estoque
void lls_13(); // imprimir a lista
void get_terminal_size(int& width, int& height);



int main (){
	
::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); // Inicia Modo Tela Cheia

system("color 60"); // Define Cor de fundo e cor de texto
get_terminal_size(width, height); // Detecta o tamanho da tela
    
// Defini��o do tamanho da fonte

     static CONSOLE_FONT_INFOEX  fontex;
     fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     GetCurrentConsoleFontEx(hOut, 0, &fontex);
     fontex.FontWeight = 700;
     fontex.dwFontSize.X = width-25; // Define o tamanho(largura) da fonte conforme o tamanho da tela;
     fontex.dwFontSize.Y = height-25; // Define o tamanho(Altura) da fonte conforme o tamanho da tela;
     SetCurrentConsoleFontEx(hOut, NULL, &fontex);
          
    
setlocale(LC_ALL, "Portuguese");


 fim = -1; // iniciar a lista vazia.

    int op = -1;
    while (op != 0){
        system ("cls");
        cout << "\n\t\t\tTrabalho Lista de Produtos de um Supermercado\n";
cout << "\n\tMatheus Henrique - Fellipe Furtado - Victor Higuchi - Thiago Carvalho Ferreira\n";
        //imprimir op��es do menu
        cout << "\n\t0 - Sair;";
        cout << "\n\t1 - Inserir Fim;";
        cout << "\n\t2 - Inserir na posicao K;";
        cout << "\n\t3 - Procurar um n� por id e inserir um novo n� POSTERIOR ao n� encontrado;";
        cout << "\n\t4 - Consultar o n� anterior ao n� da Posi��o K;";
        cout << "\n\t5 - Remover na posi��o K+3;";
        cout << "\n\t6 - Procurar um n� e remover o segundo n� anterior ao n� encontrado;";
        cout << "\n\t7 - Consultar um n� no inicio da Lista;";
        cout << "\n\t8 - Alterar o conte�do de um n� com nome de produto igual a Y;";
        cout << "\n\t9 - Procurar um n� por pre�o e alterar o conte�do do n� posterior ao n� encontrado;";
        cout << "\n\t10 - Imprimir os n�s que possuem valores �mpares menores que R$60,00;";
        cout << "\n\t11 - Imprimir conte�do da lista em ordem inversa;";
        cout << "\n\t12 - Classificar em ordem CRESCENTE de quantidade em estoque";
		cout << "\n\t13 - Imprimir Lista";
        //demais op��es

        fflush (stdin);
        
        
        cout << "\n\n\t\t\t\t\t\t\t\tEscolha uma op��o: ";
       
       cin >> op;

  

        //chamadas de fun��es
        switch(op){
            case 0: {cout << "\n\t\tAt� a pr�xima !!!...\n";break;}
            case 1: {lls_1(); break;}
            case 2: {lls_2(); break;}
            case 3: {lls_3(); break;}
            case 4: {lls_4(); break;}
            case 5: {lls_5(); break;}
            case 6: {lls_6(); break;}
            case 7: {lls_7(); break;}
            case 8: {lls_8(); break;}
            case 9: {lls_9(); break;}
            case 10: {lls_10(); break;}
            case 11: {lls_11(); break;}
            case 12: {lls_12(); break;}
            case 13: {lls_13(); break;}
            
            //demais op��es do menu
            default: {cout << "\n\t\tOp��o Inv�lida...";break;}
        }
        if (op > 0){
          if (sinal==true)
              cout << "\n\t\tOpera��o " << op << " realizada com sucesso...";
          else cout << "\n\t\tOpera��o " << op << " n�o realizada...";
        }
        cout << "\n\t\t";
        system ("pause");
    }
	
}

void get_terminal_size(int& width, int& height) {
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = (int)(csbi.srWindow.Right-csbi.srWindow.Left+1);
    height = (int)(csbi.srWindow.Bottom-csbi.srWindow.Top+1);
#elif defined(__linux__)
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    width = (int)(w.ws_col);
    height = (int)(w.ws_row);
#endif // Windows/Linux
}


void lls_1(){
	sinal = false;
    system("cls");
    cout << "\n\t\t\tInserir Novo N� Fim da Lista\n";
    if (fim < N-1){
       cout << "\n\t\tInforme o ID: ";
       cin >> val.id;
       fflush(stdin);
       cout << "\n\t\tInforme o nome do Produto: ";
       //cin >> val.info;
       getline (cin, val.produto);
       fflush(stdin);
           cout << "\n\t\tInforme o Pre�o: ";
       cin >> val.preco;
       fflush(stdin);
           cout << "\n\t\tInforme a Quantidade em Estoque: ";
       cin >> val.qtdEmEstoque;
       fflush(stdin);
       cout << "\n\t\tConfirma a Inser��o de dados(S/N): ";
       cin >> conf;
       fflush(stdin);
       conf = toupper(conf);
       if (conf =='S') {
          fim++;
          lista[fim] = val;
          sinal = true;
       }
       else cout << "\n\n\t\tDados n�o confirmados...";
    }
    else cout << "\n\n\t\tLista Cheia - Overflow\n";
    cout << "\n\t\t";
	
}
// unserir na posicao K
void lls_2(){
	sinal = false;
	system("cls");
	cout << "\n\t\t\tInserir Novo N� na posi��o K\n";
	if (fim < N-1){
		cout << "\n\t\tinforme a posi��o: ";
		cin >> k;
		if(k >= 0 && k <= fim){
			cout << "\n\t\tInforme o ID: ";
			cin >> val.id;
			fflush(stdin);
			cout << "\n\t\tInforme o nome do Produto: ";
			//cin >> val.info;
			getline (cin, val.produto);
			fflush(stdin);
			cout << "\n\t\tInforme o Pre�o: ";
			cin >> val.preco;
			fflush(stdin);
			cout << "\n\t\tInforme a Quantidade em Estoque: ";
			cin >> val.qtdEmEstoque;
			fflush(stdin);
			cout << "\n\t\tConfirma a Inser��o de dados(S/N): ";
			cin >> conf;
			fflush(stdin);
			conf = toupper(conf);
			if (conf =='S'){
				fim++;
				aux = fim;
				while(aux > k){
					lista[aux] = lista[aux - 1];
					aux--;
				}
			lista[aux] = val;
			sinal = true;
			}
			else cout << "\n\n\t\tDados n�o confirmados...";
		}
		else cout << "\n\n\t\tn�o pertence a lista";
	}
	else cout << k << "\n\n\t\tLista Cheia - Overflow\n";
	cout << "\n\t\t";
}

// procurar n� por id e inserir um novo n� posterior ao encontrado
void lls_3(){
	sinal = false;
	system("cls");
	cout << "\n\t\t\tProcurar um n� por id e inserir um novo n� POSTERIOR ao n� encontrado";
	if (fim > -1){
		if (fim < N-1){
			fim++;
			cout << "\n\t\tConsultar ID: ";
			cin >> consultId;
			fflush(stdin);
			aux = 0;
			while(aux != fim && lista[aux].id != consultId){
				aux++;
			}
			if (lista[aux].id == consultId){
				cout << "\n\t\t\t\t\t ID encontrado !";
				cout << "\n\t\t Digite os dados do novo produto";
				fflush(stdin);
				cout << "\n\t\tInforme o ID: ";
				cin >> val.id;
				fflush(stdin);
				cout << "\n\t\tInforme o nome do Produto: ";
				//cin >> val.info;
				getline (cin, val.produto);
				fflush(stdin);
				cout << "\n\t\tInforme o Pre�o: ";
				cin >> val.preco;
				fflush(stdin);
				cout << "\n\t\tInforme a Quantidade em Estoque: ";
				cin >> val.qtdEmEstoque;
				fflush(stdin);
				cout << "\n\t\tConfirma a Inser��o de dados(S/N): ";
				cin >> conf;
				fflush(stdin);
				conf = toupper(conf);
				if (conf == 'S'){
					int k2 = aux;
					aux = fim;
					while (aux >= k2){
						lista[aux] = lista[aux - 1];
						aux--;
					}
					lista[k2] = val;
					sinal  = true;
				}
				else cout <<"\n\n\t\tDados n�o confirmados.";
			}
			else cout <<"\n\n\t\tID n�o existe na lista atual";
		}
		else cout << "\n\n\tLista Cheia - Overflow";
	}
	else cout << "\n\n\tLista vazia.";
	
}

void lls_4(){
	
	
}

void lls_5(){
	
	
}

void lls_6(){
	
	
}

void lls_7(){
	
	
}

void lls_8(){
	
	
}


void lls_9(){
	
	
}

void lls_10(){
	
	
}

void lls_11(){
	
	
}

void lls_12(){
	
	
}



void lls_13(){
	
	aux;
    sinal = false;
    system ("cls");
    cout << "\n\t\tImprimir Lista de Produtos\n";
    if (fim > -1){
        cout << "\t\t" << setw(7) << "ID" << setw(30) << "Produto"<< setw(15) << "Pre�o" << setw(20) << "QTD em Estoque" << endl;
        aux = 0;
        while (aux <= fim){
             val = lista[aux];
             cout << "\t\t" << setw(7) << val.id << setw(30) << val.produto << setw(15) << val.preco << setw(20) << val.qtdEmEstoque << endl;
             aux = aux + 1;
        }
        sinal = true;
    }
    else cout << "\n\n\t\tLista Vazia...";
    cout << "\n\t\t";
	
}
