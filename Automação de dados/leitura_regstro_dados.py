import serial as arduino
import serial.tools.list_ports
import matplotlib.pyplot as plt
import statistics

temp = 10 #definir um tempo de coleta
fig1, ax1 = plt.subplots()             # Create a figure containing a single Axes.
fig2, ax2 = plt.subplots()
fig3, ax3 = plt.subplots()

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
temperature = [] #vetor temperatura
humidity = [] #vetro de umidade
tacometro = [] #vetor do rpm
vel = [] #vetor velocidade


while True:
    leituraSerial = conexao.readline() #byte
    conversao_serial = leituraSerial.decode("utf-8") #string 

    tracao = conversao_serial[ : conversao_serial.index(";")]
    rpm = conversao_serial[conversao_serial.index(";") + 1 : conversao_serial.index("@")]
    temperatura = conversao_serial[conversao_serial.index("@") + 1 : conversao_serial.index("#")]
    umidade = conversao_serial[conversao_serial.index("#") + 1 : conversao_serial.index("%")]
    dfpressao = conversao_serial[conversao_serial.index("%") + 1: conversao_serial.index("$")]
    velocidade = conversao_serial[conversao_serial.index("$") + 1 : ]

    dados = [tracao, rpm, temperatura, umidade, dfpressao, velocidade] #extraindo os dados para um vetor
    print(dados)

    Trust.append(dados[0]) #criando o vetor de tração e deixando acumular
    tacometro.append(dados[1])
    temperature.append(dados[2])
    humidity.append(dados[3])
    vel.append(dados[5])
     
    path = "C:/Users/stem/GuitHub/Bancada-de-desempenho/Automação de dados/Registros" + nomeArquivo #definido endereço para o arquivo (mudar conforme o local que deseja)
    with open(path + ".txt", "a") as arquivo: #abre o arquivo para poder escrever
        arquivo.write( conversao_serial) #escreve os dados ja convertidos em Strings

    if len(vel) == temp: 

        fl_temperatura = list(map(float, temperature))
        fl_umidade = list(map(float, humidity))
        fl_tracao = list(map(float, Trust))
        fL_vel = list(map(float, vel))

        with open(path + ".txt", "a") as arquivo:
            arquivo.write("Temperatura media: ")
            arquivo.writelines(str(statistics.mean(fl_temperatura)))

            arquivo.write(" Umidade media: ") 
            arquivo.writelines(str(statistics.mean(fl_umidade)))

            arquivo.write(" Tracao maxima: ")
            arquivo.writelines(str(max(fl_tracao)))

            arquivo.write(" Velocidade maxima:")
            arquivo.writelines(str(max(fL_vel))) #analisa a tracao e a velociade maxima gerada

        break

ax1.set_title('Tração')
ax1.plot(Trust, color='blue')  # Plot do dado de tração no teste estástico (posso adicionar o eixo x também)

ax2.set_title('RPM')
ax2.plot(tacometro, color='green')

ax3.set_title('Velocidade')
ax3.plot(vel, color='red')

plt.show()