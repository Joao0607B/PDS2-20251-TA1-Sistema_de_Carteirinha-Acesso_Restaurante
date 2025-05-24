# Sistema Carteirinha e Acesso Restaurante
Membros:  
Ana Laura Soares Mello,  
Larissa Roncali Faria,   
João Pedro Braga da Silva  
Matheus Magalhães Caldeira Brant.  

# User Stories 

**1. Descrição**  
Eu como aluno gostaria de ver o saldo do meu cartão para me planejar para a próxima recarga.  

**Critérios de Aceitação:**
 * Visualizar saldo
 * Calcular quantas refeições são possíveis com esse saldo
  
**2. Descrição**  
Eu como aluno gostaria de colocar crédito no meu cartão para poder almoçar/jantar.  

**Critérios de Aceitação:**
 * Alterar o valor do saldo
 * Transferir crédito

**3. Descrição**  
Eu como aluno gostaria de alterar dados no meu cadastro para atualizar as informações.  

**Critérios de Aceitação:**
 * Alterar o saldo
 * Alterar o nível FUMP
 * Bloquear cartão
 * Anexar documentos

**4. Descrição**  
Eu como caixa do bandejão gostaria de gerenciar o acesso ao bandejão para que o cliente possa fazer sua refeição.  

**Critérios de Aceitação:**
 * Acessar o valor a pagar
 * Liberar o acesso e registrar a entrada
 * Bloquear o acesso
 * Selecionar qual RU está sendo acessado

**5. Descrição**  
Eu como caixa do bandejão gostaria de acessar como operador para restringir o acesso a certas informações.  

**Critérios de Aceitação:**
 * Fazer login
 * Trocar senha

**6. Descrição**  
Eu como FUMP gostaria de acessar informações sobre o restaurante para gerenciar os custos.  

**Critérios de Aceitação:**
 * Acessar saldo total
 * Acessar o número de clientes
 * Acessar o número de refeições servidas no dia por restaurante
 * Acessar o número de alunos por nível da FUMP

**7. Descrição**  
Eu como FUMP gostaria de acessar como administrador para restringir o acesso a certas informações.  

**Critérios de Aceitação:**
 * Fazer login
 * Trocar senha
 * Cadastrar novos clientes (aluno, visitante, funcionário)

**8. Descrição**  
Eu como visitante gostaria de ver meu saldo para poder fazer a refeição.  

**Critérios de Aceitação:**
 * Acessar saldo
 * Transferir saldo

**9. Descrição**  
Eu como funcionário da UFMG gostaria de colocar crédito no meu cartão para poder almoçar/jantar.  

**Critérios de Aceitação:**
 * Alterar o valor do saldo
 * Alterar o departamento
 * Transferir crédito

**10. Descrição**  
Eu como funcionário da UFMG gostaria de alterar dados no meu cadastro para atualizar as informações.  

**Critérios de Aceitação:**
 * Alterar o saldo
 * Bloquear cartão

# Guia de Estilo
**1. Formatação Básica** 
* Indentação: Use tab
* Limite de linha: 80-100 caracteres
* Chaves: Estilo 1TBS (One True Brace Style)
Ex: 

```c++
if (condicao) {
    // código
} else {
    // código
}
```

**2. Nomenclatura** 
* Classes: PascalCase (MinhaClasse)
* Funções/métodos: camelCase (minhaFuncao())
* Variáveis: camelCase (minhaVariavel)
* Constantes: UPPER_CASE (MINHA_CONSTANTE)
* Membros de classe: prefixo m_ (m_meuMembro)

**3. Documentação**

Considere Doxygen para documentação formal:
```c++
/// \brief Função que faz algo importante
/// \param valor Entrada para processamento
/// \return Resultado do processamento
int processar(int valor);
```
