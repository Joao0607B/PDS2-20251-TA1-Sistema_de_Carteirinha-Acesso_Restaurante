# Sistema Carteirinha e Acesso Restaurante Universitário
**Membros:**  
Ana Laura Soares Mello,  
Larissa Roncali Faria,   
João Pedro Braga da Silva,  
Matheus Magalhães Caldeira Brant.  

## Introdução
Todo inicio de semestre é observável o crescimento das filas para o acesso dos restaurantes universitários, principalmente as filas referentes ao pagamento com cartões de débito. As longas filas podem intencificar a correria do dia a dia e acrescentar um estresse a mais em um momento que deveria ser para desacelerar. Logo, nosso projeto visa o desenvolvimento de um sistema que complementa a funcionabilidade das carteirinhas universitárias e que tem o objetivo de desenvolver a automatização e organização do processo de pagamento das refeições nos restaurantes.

//imagem de uma fila(lembrar de adicionar as referencias)

## Visão Geral
## Visão Geral da Aquitetura
Nosso sistema é orientado a objetos e organizado em três responsabilidades principais e suas respectivas classes:

**1. Responsabilidade das entidades e dados do programa:**

*Pessoa (classe base):* contém os atributos e métodos comuns a todas as pessoas (nome e CPF).

*Funcionario (herda de Pessoa):* representa os usuários com permissões administrativas. Pode fazer login, trocar senha, deslogar e  principalemente é responsável por liberar as refeições para os clientes.

*Cliente (herda de Pessoa):* representa quem consome as refeições (alunos e professores). Possui saldo, estado de bloqueio e histórico de acessos/refeições.

*Aluno (herda de Cliente):* possui informações adicionais como curso e nível Fump.

*Professor (herda de Cliente):* possui o atributo adicional “departamento”.

*Caixa (herda de Funcionario):* funcionários responsáveis pela gestão do restaurante e movimentações financeiras.

**2. Responsabilidade do controle do sistema e armazenamento de dados**
É composta principalmente pela classe Gerenciamento do Sistema, que organiza as funcionalidades centrais:

- Armazena vetores de Cliente* e Funcionario*.

- Controla o cadastro de clientes e funcionários.

- Autentica funcionários com base em usuario e senha.

- Permite busca de cliente por CPF.

- Processa refeições (valida se o cliente pode comer e registra acesso).

- Controla adição de crédito para clientes.

- Arquiva os dados (clientes e funcionários) nos arquivos .txt.
- 
**3. Resposnsabilidade de armazenamento e disponibilidade dos dados (Arquivos)**
Usa três arquivos de texto simples para armazenar os dados:

- Clientes.txt

- Funcionarios.txt

- Transacoes.txt

Estes arquivos são lidos e atualizados pelo sistema via métodos da classe Gerenciamento.
## Visão Geral do Fluxo de Funcionamento do Programa


//Detalhamento disponível no link da documentação via Doxygen

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
