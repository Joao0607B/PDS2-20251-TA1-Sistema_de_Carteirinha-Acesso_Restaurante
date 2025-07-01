# Sistema Carteirinha e Acesso Restaurante Universitário
**Turma TA1**  
**Membros:**  
Ana Laura Soares Mello,  
Larissa Roncali Faria,   
João Pedro Braga da Silva,  
Matheus Magalhães Caldeira Brant.  

# Introdução
Todo inicio de semestre é observável o crescimento das filas para o acesso dos restaurantes universitários, principalmente as filas referentes ao pagamento com cartões de débito. As longas filas podem intencificar a correria do dia a dia e acrescentar um estresse a mais em um momento que deveria ser para desacelerar. Logo, nosso projeto visa o desenvolvimento de um sistema que complementa a funcionabilidade das carteirinhas universitárias e que tem o objetivo de desenvolver a automatização e organização do processo de pagamento das refeições nos restaurantes.

![image](https://github.com/user-attachments/assets/1988bac3-97a8-46bf-a10a-ae21a7804d34)

# Visão Geral
## Visão Geral da Aquitetura
Nosso sistema é orientado a objetos e organizado em três responsabilidades principais e suas respectivas classes:

**1. Responsabilidade das entidades e dados do programa:**

*Pessoa (classe base):* contém os atributos e métodos comuns a todas as pessoas (nome e CPF).

*Funcionario (herda de Pessoa):* representa os usuários com permissões administrativas. Pode fazer login, trocar senha, deslogar e  principalmente é responsável por liberar as refeições para os clientes.

*Cliente (herda de Pessoa):* representa quem consome as refeições (alunos, professores e visitantes). Possui saldo, estado de bloqueio e histórico de acessos/refeições.

*Aluno (herda de Cliente):* possui informações adicionais como curso e nível Fump(o nível da fump é responsável ´pr influ~enciar o valor da refeição).

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
  
**3. Resposnsabilidade de armazenamento e disponibilidade dos dados (Arquivos)**

Usa três arquivos de texto simples para armazenar os dados:

- Clientes.txt

- Funcionarios.txt

- Transacoes.txt

Estes arquivos são lidos e atualizados pelo sistema via métodos da classe Gerenciamento.

## Visão Geral do Fluxo de Funcionamento do Programa

 **1. Cadastro de Usuários**
 
Um funcionário autorizado usa cadastrarFuncionario() ou cadastrarCliente() para incluir novos usuários no sistema.
Clientes podem ser Aluno ou Professor, definidos conforme os dados fornecidos.

 **2. Login e Autenticação**
 
Funcionários devem fazer login usando fazerLogin(usuario, senha) para acessar as funcionalidades administrativas.
Após autenticação, podem realizar ações como liberar refeições, adicionar créditos e processar as refeições realizadas, que automaticamente registram o acesso. Após ações ele pode deslogar do sistema.

**3. Processamento de Refeições**

O funcionário, já autenticado, pode liberar as refeições(liberarRefeição(Cliente* cliente)) e processar a refeição no sistema. Para liberar a refeição o método verifica se o cliente não está bloqueado, valida se o cliente já realizou uma refeição no mesmo turno e verfica se o cliente possui saldo suficiente para realizar a refeição. Caso tudo esteja correto, desconta o valor da refeição do saldo, libera o acesso e registra o acesso naquele turno.

**4. Gerenciamento de Saldo**

O método depositar() adiciona um valor ao saldo do cliente, utilizando o funcionário responsável.Também há suporte para transferência de saldo entre clientes (transferir()), depósitos (depositar()), bloqueio e desbloqueio.

**5. Controle de Acesso**

Em cada cliente é registrado a data e tipo da última refeição (almoço ou jantar). Isso impede que um cliente repita refeições em um mesmo turno.

**6. Armazenamento de Dados**

Ao fim das operações, o sistema pode chamar salvarDados() para registrar clientes e funcionários nos arquivos .txt.

**Documentação do Código**

O acesso a documentação do código, via Doxygen, está no proprio repositório.

Faça download do repositório, abra a pasta docs, abra a pasta html e abra o arquivo index.html

# Principais dificuldades encontradas

Uma das principais dificuldades encontradas no projeto foi a integração entre os códigos desenvolvidos por diferentes membros do grupo. Com o desenvolvimento acontecendo de forma simultânea, surgiram desafios relacionados à padronização dos nomes, métodos e estrutura das classes. Reforçar a comunicação entre os membros foi uma atitude que ajudou muito a vencer esse desafio e fazer com que as partes do cpodigo se unissem para um único objetivo.



