CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=sistema_carteirinha 
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include

run: ${OBJ_DIR}/${TARGET} ARQUIVOS
	./${OBJ_DIR}/${TARGET}

ARQUIVOS: Clientes.txt Funcionarios.txt Transacoes.txt

all: $(OBJ_DIR)/$(TARGET) 

${OBJ_DIR}/Pessoa.o: ${INCLUDE_DIR}/Pessoa.hpp ${SRC_DIR}/Pessoa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Pessoa.cpp -o ${OBJ_DIR}/Pessoa.o

${OBJ_DIR}/Funcionario.o: ${INCLUDE_DIR}/Pessoa.hpp ${INCLUDE_DIR}/Data.hpp ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/GerenciamentoDoSistema.hpp ${INCLUDE_DIR}/Funcionario.hpp ${SRC_DIR}/Funcionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Funcionario.cpp -o ${OBJ_DIR}/Funcionario.o

${OBJ_DIR}/Cliente.o: ${INCLUDE_DIR}/Pessoa.hpp ${INCLUDE_DIR}/Data.hpp ${INCLUDE_DIR}/GerenciamentoDoSistema.hpp ${INCLUDE_DIR}/Funcionario.hpp ${INCLUDE_DIR}/Cliente.hpp ${SRC_DIR}/Cliente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Cliente.cpp -o ${OBJ_DIR}/Cliente.o

${OBJ_DIR}/Data.o: ${INCLUDE_DIR}/Data.hpp ${SRC_DIR}/Data.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Data.cpp -o ${OBJ_DIR}/Data.o

${OBJ_DIR}/Caixa.o: ${INCLUDE_DIR}/Funcionario.hpp ${SRC_DIR}/Caixa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Caixa.cpp -o ${OBJ_DIR}/Caixa.o

${OBJ_DIR}/Aluno.o: ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/Aluno.hpp ${SRC_DIR}/Aluno.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Aluno.cpp -o ${OBJ_DIR}/Aluno.o

${OBJ_DIR}/Professor.o: ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/Professor.hpp ${SRC_DIR}/Professor.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Professor.cpp -o ${OBJ_DIR}/Professor.o

${OBJ_DIR}/GerenciamentoDoSistema.o: ${INCLUDE_DIR}/Funcionario.hpp ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/GerenciamentoDoSistema.hpp ${SRC_DIR}/GerenciamentoDoSistema.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/GerenciamentoDoSistema.cpp -o ${OBJ_DIR}/GerenciamentoDoSistema.o

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/Pessoa.hpp ${INCLUDE_DIR}/Data.hpp ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/Funcionario.hpp ${INCLUDE_DIR}/GerenciamentoDoSistema.hpp ${INCLUDE_DIR}/Caixa.hpp ${INCLUDE_DIR}/Aluno.hpp ${INCLUDE_DIR}/Professor.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

${OBJ_DIR}/${TARGET}: ${OBJ_DIR}/Pessoa.o ${OBJ_DIR}/Funcionario.o ${OBJ_DIR}/Cliente.o ${OBJ_DIR}/Caixa.o ${OBJ_DIR}/Aluno.o ${OBJ_DIR}/Professor.o ${OBJ_DIR}/GerenciamentoDoSistema.o ${OBJ_DIR}/Data.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${OBJ_DIR}/${TARGET}

clean:
	rm -f ${OBJ_DIR}/*
