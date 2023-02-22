#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<string>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){
    string palavras[3]= {"abacaxi","manga","morango"};
    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra,int tamanhoDaPalavra){
    int i=0;
    string palavraComMascara;

    while(i<tamanhoDaPalavra){
        palavraComMascara+="_";
        i++;
    }
    return palavraComMascara;
}

void exibeStatus(string palavraComMascara,int tamanhoDaPalavra,int tentativasRestantes, string letrasJaArriscadas, string mensagem){
    cout<< mensagem;
    cout<<"A palavra: "<<palavraComMascara<<"(Tamanho: "<<tamanhoDaPalavra<<")\n";
    cout<<"\nTentativas Restantes: " << tentativasRestantes;

    cout<<"\nLetras arriscadas:";
    int cont = 0;
    for(cont =0;cont<letrasJaArriscadas.size();cont++){
        cout<<letrasJaArriscadas[cont]<<", ";
    }

}

int jogar(int numeroDeJogadores){
    string palavra;

    if(numeroDeJogadores==1){
        palavra = retornaPalavraAleatoria();

    }else{
        cout<<"\nDigite uma palavra: ";
        cin>>palavra;
    }





    int tamanhoDaPalavra = palavra.size();

    string palavraComMascara = retornaPalavraComMascara(palavra,tamanhoDaPalavra);

    int tentativas = 0, maximoDeTentativas = 10;
    char letra;
    int cont = 0;
    string letrasJaArriscadas;
    bool jaDigitouLetra=false, AcertouLetra = false;
    string mensagem="Bem vindo ao jogo!\n";
    string palavraArriscada;
    int opcao;


    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){
        limpaTela();

        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);

        cout << "\nDigite uma letra(ou digite 1 para arriscar a palavra): ";
        cin >> letra;

        if(letra=='1'){
            cin>>palavraArriscada;
            if(palavraArriscada==palavra){
                palavraComMascara = palavraArriscada;
            }else{
               tentativas = maximoDeTentativas;
            }
        }

        for(cont=0;cont<tentativas;cont++){
            if(letrasJaArriscadas[cont]==letra){
                mensagem = "Essa letra ja foi digitada\n";
                jaDigitouLetra=true;
            }
        }

        if(jaDigitouLetra==false){
            letrasJaArriscadas += tolower(letra);
            for(cont = 0;cont<tamanhoDaPalavra;cont++){
                if(palavra[cont]==tolower(letra)){
                    palavraComMascara[cont]=palavra[cont];

                    AcertouLetra = true;
                }
            }
        if(AcertouLetra == false ){
            mensagem = "Voce errou uma letra\n";
        }else{
            mensagem = "Voce acertou uma letra\n";
            AcertouLetra = false;
        }
            tentativas++;
        }
        jaDigitouLetra=false;
        AcertouLetra = false;

    }

    if(palavra == palavraComMascara){

        limpaTela();
        cout << "Parabens, voce venceu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao\n";
        cin >> opcao;
        return opcao;

    }else{

        limpaTela();
        cout << "Bleh, voce perdeu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao\n";
        cin >> opcao;
        return opcao;
    }

}

void menuInicial(){
    int opcao = 0;

    while(opcao < 1 || opcao>3){
    limpaTela();
    cout << "Bem vindo ao Jogo";
    cout << "\n1 - Jogar Sozinho";
    cout << "\n2 - Jogar em Dupla";
    cout << "\n3 - Sobre";
    cout << "\n4 - Sair";
    cout << "\nEscolha uma opcao e tecle ENTER: ";
    cin >> opcao;

    switch(opcao){
    case 1:
        //cout<<"Jogo iniciado";
        if(jogar(1)==1){
            menuInicial();
        }
        break;
    case 2:
        //cout<<"Jogo iniciado";
        if(jogar(2)==1){
            menuInicial();
        }
        break;
    case 3:
        cout<<"Informacoes do jogo";
        limpaTela();
        cout<<"Jogo desenvolvido por leomitx10 em 2023.";
        cout << "\n1 - Voltar";
        cout << "\n2 - Sair\n";
        cin>>opcao;
        if(opcao==1){
            menuInicial();
        }
        break;
    case 4:
        cout<<"Ate mais";
        break;
    }
    }
}

int main(){
    srand((unsigned)time(NULL));
    menuInicial();
}
