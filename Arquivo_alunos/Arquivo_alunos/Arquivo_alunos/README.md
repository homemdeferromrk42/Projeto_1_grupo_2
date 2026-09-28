# Arquivo alunos Aula 9

Este pacote inicia a atividade com uma estação genérica funcional. O potenciômetro conectado ao Arduino controla o nível do tanque e o volante no navegador. A tarefa do aluno é modelar a própria estação no Autodesk Inventor, exportar o conjunto para GLB e substituir o modelo genérico.

## Conteúdo

- `arduino/Arduino_Aula_09.ino`: programa que deve ser gravado no Arduino;
- `web/`: aplicação Web 3D;
- `web/public/models/`: local reservado para o arquivo GLB do aluno;
- `docs/Manual_Aula_09_Aluno.docx`: roteiro completo de modelagem, montagem, exportação e integração;
- `Dockerfile`, `docker-compose.yml` e `nginx.conf`: execução pelo Docker Desktop.

O modelo final do professor não faz parte deste pacote.

## Etapa 1 Executar o exemplo genérico

### Com Docker Desktop

Abra um terminal nesta pasta e execute:

```powershell
docker compose up --build -d
```

Abra o Chrome ou Edge em:

```text
http://localhost:8080
```

### Sem Docker

```powershell
cd web
npm install
npm run dev
```

Abra o endereço indicado pelo Vite.

## Etapa 2 Preparar o Arduino

1. Monte um potenciômetro com os terminais externos em `5 V` e `GND`.
2. Ligue o terminal central ao pino analógico `A0`.
3. Abra `arduino/Arduino_Aula_09.ino` na Arduino IDE.
4. Selecione a placa e a porta corretas.
5. Grave o programa.
6. Feche o Monitor Serial e a IDE antes de conectar pelo navegador.
7. Na página, clique em `CONECTAR ARDUINO` e selecione a porta.
8. Clique no botão verde da estação quando o modelo final já estiver integrado.

Use o botão `DEMO` para testar a animação sem Arduino.

## Etapa 3 Modelar e exportar

Siga o manual em `docs/Manual_Aula_09_Aluno.docx`. Crie as peças separadamente, monte o conjunto em um arquivo IAM e exporte o conjunto completo para GLB.

Use preferencialmente estes nomes no Inventor:

| Componente | Nome esperado |
|---|---|
| Volume do líquido | `LIQUIDO` |
| Volante | `VOLANTE` |
| Botão de ligar | `BOTAO1` |
| Botão de desligar | `BOTAO2` |
| LED ou sinaleiro | `LEDVM` |

Salve o arquivo exportado como:

```text
web/public/models/MODELO_ALUNO.glb
```

## Etapa 4 Ativar o modelo do aluno

Abra `web/src/main.js`. No início do arquivo, localize `CONFIG_MODELO` e altere:

```javascript
usarModeloInventor: false,
```

para:

```javascript
usarModeloInventor: true,
```

Se o arquivo GLB tiver outro nome, altere a propriedade `arquivo`. Se as peças tiverem nomes diferentes, altere somente o bloco `componentes`.

Exemplo:

```javascript
const CONFIG_MODELO = {
  usarModeloInventor: true,
  arquivo: "MINHA_ESTACAO.glb",
  rotacaoYGraus: -90,
  componentes: {
    liquido: "AGUA",
    volante: "VALVULA_MANUAL",
    botaoLiga: "LIGA",
    botaoDesliga: "DESLIGA",
    led: "SINALEIRO",
  },
};
```

Não altere a lógica de comunicação serial.

## Etapa 5 Inspecionar antes da integração

Depois de copiar o GLB, acesse:

```text
http://localhost:8080/modelo.html
```

Essa página verifica `LIQUIDO` e `VOLANTE` e permite testar o nível e a rotação. Se o modelo não for encontrado, confira o nome, a pasta e a exportação.

## Reconstruir após uma alteração

Se estiver usando Docker:

```powershell
docker compose up --build -d
```

Atualize a página com `Ctrl + F5`.

## Entrega do aluno

Entregue:

- todos os arquivos IPT;
- o conjunto IAM;
- o arquivo `MODELO_ALUNO.glb` ou equivalente;
- a pasta `web` modificada;
- uma captura da estação funcionando com o Arduino;
- uma breve descrição dos nomes utilizados nos componentes.

## Critérios de verificação

- o exemplo genérico funciona antes da troca;
- o GLB carrega sem erro;
- o conjunto aparece centralizado e de frente para o usuário;
- o líquido acompanha o potenciômetro;
- o volante gira no eixo correto;
- os botões de ligar e desligar respondem;
- o LED indica o estado da estação;
- o Arduino funciona sem exigir a execução prévia do modo Demo.
