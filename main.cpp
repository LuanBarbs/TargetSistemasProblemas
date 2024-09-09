#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/// Questão 1.
// Função para calcular a soma dos números de 1 até o valor de `indice`.
void soma(int indice = 13, int soma = 0, int k = 0) {
    while(k < indice) {
        soma += ++k;
    }
    cout << soma << endl;
}
/// Questão 1.

/// Questão 2.
// Função para verificar se um número pertence à sequência de Fibonacci.
bool fibonacci(int num = 0) {
    if(num == 0 || num == 1) return true; // 0 e 1 pertencem à sequência de Fibonacci.
    int a = 0, b = 1, prox = 1;

    while(prox <= num) {
        if(prox == num) return true; // Número é encontrado.
        a = b;
        b = prox;
        prox = a + b; // Calcula o próximo número na sequência.
    }

    return false; // O número não é encontrado.
}
/// Questão 2.

/// Questão 3.
// Função para processar os dados de faturamento a partir de um arquivo JSON.
double extrairValor(const string& linha) {
    size_t pos1 = linha.find(":"); // Encontra a posição do caractere ':'.
    size_t pos2 = linha.find(","); // Encontra a posição do caractere ','.
    if(pos1 != string::npos) {
        if (pos2 == string::npos) {
            pos2 = linha.find("}"); // Se não encontrar ',', procura por '}'.
        }
        return stod(linha.substr(pos1 + 1, pos2 - pos1 - 1)); // Extrai e converte o valor para double.
    }
    return 0; // Retorna 0 se não encontrar o valor.
}
void faturamento() {
    ifstream file("dados.json"); // Abre o arquivo JSON para leitura.

    vector<double> faturamentos;
    string linha;

    while(getline(file, linha)) { // Lê o arquivo linha por linha.
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
/// Questão 3.

/// Questão 4.
// Função para calcular o percentual de faturamento por estado.
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
/// Questão 4.

/// Questão 5.
// Função para inverter uma string.
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
/// Questão 5.

int main()
{
    // 1) Chamada da função soma.
    soma();

    // 2) Chamada da função fibonacci passando o número 1597.
    cout << fibonacci(1597) << endl;

    // 3) Chamada da função faturamento.
    faturamento();

    // 4) Chamada da função faturamentoPorEstado.
    faturamentoPorEstado();

    // 5) Chamada da função inverterString.
    string texto = "hello";
    string invertida = inverterString(texto);
    cout << "String invertida: " << invertida << endl;

    return 0;
}
