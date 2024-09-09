#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/// Quest�o 1.
// Fun��o para calcular a soma dos n�meros de 1 at� o valor de `indice`.
void soma(int indice = 13, int soma = 0, int k = 0) {
    while(k < indice) {
        soma += ++k;
    }
    cout << soma << endl;
}
/// Quest�o 1.

/// Quest�o 2.
// Fun��o para verificar se um n�mero pertence � sequ�ncia de Fibonacci.
bool fibonacci(int num = 0) {
    if(num == 0 || num == 1) return true; // 0 e 1 pertencem � sequ�ncia de Fibonacci.
    int a = 0, b = 1, prox = 1;

    while(prox <= num) {
        if(prox == num) return true; // N�mero � encontrado.
        a = b;
        b = prox;
        prox = a + b; // Calcula o pr�ximo n�mero na sequ�ncia.
    }

    return false; // O n�mero n�o � encontrado.
}
/// Quest�o 2.

/// Quest�o 3.
// Fun��o para processar os dados de faturamento a partir de um arquivo JSON.
double extrairValor(const string& linha) {
    size_t pos1 = linha.find(":"); // Encontra a posi��o do caractere ':'.
    size_t pos2 = linha.find(","); // Encontra a posi��o do caractere ','.
    if(pos1 != string::npos) {
        if (pos2 == string::npos) {
            pos2 = linha.find("}"); // Se n�o encontrar ',', procura por '}'.
        }
        return stod(linha.substr(pos1 + 1, pos2 - pos1 - 1)); // Extrai e converte o valor para double.
    }
    return 0; // Retorna 0 se n�o encontrar o valor.
}
void faturamento() {
    ifstream file("dados.json"); // Abre o arquivo JSON para leitura.

    vector<double> faturamentos;
    string linha;

    while(getline(file, linha)) { // L� o arquivo linha por linha.
        if(linha.find("\"valor\"") != string::npos) {
            double valor = extrairValor(linha);
            if(valor > 0) { // Adiciona o valor ao vetor se for positivo.
                faturamentos.push_back(valor);
            }
        }
    }

    file.close();

    double menor_faturamento = faturamentos[0];
    double maior_faturamento = faturamentos[0];
    double soma_faturamento = 0;

    for (double faturamento : faturamentos) {
        if (faturamento < menor_faturamento) {
            menor_faturamento = faturamento;
        }
        if (faturamento > maior_faturamento) {
            maior_faturamento = faturamento;
        }
        soma_faturamento += faturamento;
    }

    double media_faturamento = soma_faturamento / faturamentos.size();

    int dias_acima_da_media = 0;
    for (double faturamento : faturamentos) {
        if (faturamento > media_faturamento) {
            dias_acima_da_media++;
        }
    }

    cout << "Menor valor de faturamento: " << menor_faturamento << endl;
    cout << "Maior valor de faturamento: " << maior_faturamento << endl;
    cout << "Numero de dias com faturamento acima da media: " << dias_acima_da_media << endl;
}
/// Quest�o 3.

/// Quest�o 4.
// Fun��o para calcular o percentual de faturamento por estado.
void faturamentoPorEstado() {
    double sp = 67836.43;
    double rj = 36678.66;
    double mg = 29229.88;
    double es = 27165.48;
    double outros = 19849.53;

    double total = sp + rj + mg + es + outros;

    // Calcula o percentual de cada estado.
    double perc_sp = (sp / total) * 100;
    double perc_rj = (rj / total) * 100;
    double perc_mg = (mg / total) * 100;
    double perc_es = (es / total) * 100;
    double perc_outros = (outros / total) * 100;

    cout << "Percentual de representacao por estado:" << endl;
    cout << "SP: " << perc_sp << "%" << endl;
    cout << "RJ: " << perc_rj << "%" << endl;
    cout << "MG: " << perc_mg << "%" << endl;
    cout << "ES: " << perc_es << "%" << endl;
    cout << "Outros: " << perc_outros << "%" << endl;
}
/// Quest�o 4.

/// Quest�o 5.
// Fun��o para inverter uma string.
string inverterString(const string& input) {
    string invertida = input;
    int n = invertida.length();

    for(int i = 0; i < n / 2; ++i) {
        char temp = invertida[i];
        invertida[i] = invertida[n - i - 1]; // Troca os caracteres das extremidades.
        invertida[n - i - 1] = temp;
    }

    return invertida;
}
/// Quest�o 5.

int main()
{
    // 1) Chamada da fun��o soma.
    soma();

    // 2) Chamada da fun��o fibonacci passando o n�mero 1597.
    cout << fibonacci(1597) << endl;

    // 3) Chamada da fun��o faturamento.
    faturamento();

    // 4) Chamada da fun��o faturamentoPorEstado.
    faturamentoPorEstado();

    // 5) Chamada da fun��o inverterString.
    string texto = "hello";
    string invertida = inverterString(texto);
    cout << "String invertida: " << invertida << endl;

    return 0;
}
