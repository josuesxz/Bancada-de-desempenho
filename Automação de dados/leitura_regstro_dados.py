import serial as arduino
import serial.tools.list_ports
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()             # Create a figure containing a single Axes.

port = arduino.tools.list_ports.comports() #realiza a leitura das COMs
print("Portas COM disponiveis:")
for port in port:
    print("- ", port.device)

com = str(input("Digite qual a COM "))

Baudrate = 9600
nomeArquivo = str(input("Digite o nome para o arquivo em txt: "))

porta = "COM" + com
conexao = arduino.Serial(porta, Baudrate)
arquivo = open(nomeArquivo + ".txt", "a")

Trust = [] #vetor do eixo tracao

while True:
    leituraSerial = conexao.readline() #byte
    conversao_serial = leituraSerial.decode("utf-8") #string 

    tracao = conversao_serial[ : conversao_serial.index(";")]
    rpm = conversao_serial[conversao_serial.index(";") + 1 : conversao_serial.index("@")]
    temperatura = conversao_serial[conversao_serial.index("@") + 1 : conversao_serial.index("#")]
    dfpressao = conversao_serial[conversao_serial.index("#") + 1: conversao_serial.index("$")]
    velocidade = conversao_serial[conversao_serial.index("$") + 1 : ]

    dados = [tracao, rpm, temperatura, dfpressao, velocidade] #extraindo os dados para um vetor
    print(dados)

    Trust.append(dados[0]) #criando o vetor de tração e deixando acumular 

    path = "C:/Users/stem/GuitHub/Bancada-de-desempenho/Automação de dados/" + nomeArquivo #definido endereço para o arquivo (mudar conforme o local que deseja)
    with open(path + ".txt", "a") as arquivo: #abre o arquivo para poder escrever
        arquivo.write( conversao_serial) #escreve os dados ja convertidos em Strings

    if len(Trust) == 60: break

ax.plot(Trust)  # Plot do dado de tração no teste estástico
plt.show()