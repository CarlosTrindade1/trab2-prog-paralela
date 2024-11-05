# README - Compilação e Execução do Projeto em C++

Este README fornece instruções sobre como compilar e executar o projeto em C++. 

## Pré-requisitos

Certifique-se de que você tem o `make` e um compilador C++ (como `g++`) instalados no seu sistema.

## Compilação

Para compilar o projeto, siga estas etapas:

1. Abra o terminal.
2. Navegue até o diretório onde o código-fonte do projeto está localizado.
3. Execute o seguinte comando:

   ```bash
   make
   ```

Esse comando irá compilar todos os arquivos necessários e gerar o executável.

## Execução

Após a compilação, você pode executar o programa usando o seguinte comando:

```bash
./main <DATASET> <QUANTIDADE_DE_CLICKS [k]> <ALGORITMO> <scheduling_type [OPCIONAL]> <r | chunk [OPCIONAL]>
```

### Parâmetros

- `<DATASET>`: O caminho para o arquivo de dataset que será utilizado.
- `<QUANTIDADE_DE_CLICKS [k]>`: O número de cliques que o programa deve processar.
- `<ALGORITMO>`: O algoritmo que você deseja usar para o processamento, onde:
  - `1`: Paralelo com escalonador do OMP
  - `2`: Paralelo com roubo de carga
- `<scheduling_type [OPCIONAL]>: O tipo de escalonamento que você deseja utilizar (apenas para o algoritmo 1):`
    - `static`
    - `dynamic`
    - `guided`
- `<r [OPCIONAL]>`: Um parâmetro opcional que pode ser utilizado dependendo da implementação do algoritmo.
- `<chunk [OPCIONAL]>`: O número de chunks que você deseja utilizar (somente para o algoritmo 1).

### Exemplos de Execução

```bash
./main dataset.txt 3 1 dynamic 10
```
Esse comando executaria o programa utilizando o dataset `dataset.txt`, processando 3 cliques com o algoritmo 1.

```bash
./main dataset.txt 3 2 500
```
Esse comando executaria o programa utilizando o dataset `dataset.txt`, processando 3 cliques com o algoritmo 2.

---

Se tiver alguma dúvida ou encontrar problemas, sinta-se à vontade para abrir uma issue!