#pragma once 

#include "..\Estado\EstadoJogar.hpp"

#include "..\Construtor\ConstrutorFase.hpp"

namespace Jungle {

    namespace Construtor {

        class ConstrutorEstado {
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado::Estado* criarEstado(const IDs::IDs ID);
        private:
            Estado::Estado* criarEstadoJogar(const IDs::IDs ID);
            //Estado::Estado* criarMenuPrinciapal();
            //Estado::Estado* criarMenuPausar();
            //Estado::Estado* criarMenuSalvar();
            //Estado::Estado* criarMenuOpcao();
            //Estado::Estado* criarColocao();
        };

    }

}