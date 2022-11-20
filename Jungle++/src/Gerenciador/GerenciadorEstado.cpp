#include "..\..\include\Gerenciador\GerenciadorEstado.hpp"

namespace Jungle {

    namespace Gerenciador {

        GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;

        GerenciadorEstado::GerenciadorEstado():
            pilhaEstados(), construtorEstado()
        {

        }

        GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado(){
            if(pGerenciadorEstado == nullptr){
                pGerenciadorEstado = new GerenciadorEstado();
            }
            return pGerenciadorEstado;
        }

        GerenciadorEstado::~GerenciadorEstado(){
            //deleta todos os estados da minha pilha
            while(!pilhaEstados.empty()){
                delete(pilhaEstados.top());
                pilhaEstados.top() = nullptr;
                pilhaEstados.pop();
            }

            if(pGerenciadorEstado){
                delete(pGerenciadorEstado);
                pGerenciadorEstado = nullptr;
            }
        }

        void GerenciadorEstado::addEstado(const IDs::IDs ID){
            Estado::Estado* estado = construtorEstado.criarEstado(ID);
            if(estado ==  nullptr){
                std::cout << "ERROR::Jungle::Gerenciador::GerenciadorEstado::estado eh nullptr" << std::endl;
                exit(1);
            }
            pilhaEstados.push(estado);
        }

        void GerenciadorEstado::removerEstado(){
            if(pilhaEstados.top() != nullptr){
                delete(pilhaEstados.top());
                pilhaEstados.top() = nullptr;
                pilhaEstados.pop();
            }

            if(pilhaEstados.empty()){
                GerenciadorGrafico* pGrafico = pGrafico->getGerenciadorGrafico();
                pGrafico->fecharJanela(); 
            }
        }

        Estado::Estado* GerenciadorEstado::getEstadoAtual() {
            return pilhaEstados.top();
        }


        void GerenciadorEstado::executar(){
            //executa o estado que está no topo da minha pilha
            if(!pilhaEstados.empty()){
                pilhaEstados.top()->executar();
            }
        }

    }

}