#include "jogador.h"
using namespace std;

//a alterar

void Jogador::adicionaAposta(const Aposta & ap)
{
    apostas.insert(ap);
}

//a alterar
unsigned Jogador::apostasNoNumero(unsigned num) const
{
    int count = 0;
    tabHAposta::const_iterator it;
    for (it=apostas.begin(); it!=apostas.end(); it++)
        if (it->contem(num))
            count++;
    return count;
}

//a alterar
tabHAposta Jogador::apostasPremiadas(const tabHInt &sorteio) const
{
    tabHAposta money;
    tabHAposta::const_iterator aposta;
    for (aposta=apostas.begin(); aposta!=apostas.end(); aposta++) {
        int aux = 0;
        tabHInt::const_iterator key;
        for (key=sorteio.begin(); key!=sorteio.end(); key++)
            if (aposta->contem(*key)) {
                aux++;
            }
        if (aux > 3)
            money.insert(*aposta);
    }
    return money;
}
