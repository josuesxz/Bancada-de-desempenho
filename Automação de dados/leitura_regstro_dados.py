import serial as arduino
import serial.tools.list_ports

port = arduino.tools.list_ports.comports() #realiza a leitura das COMs
print("Portas COM disponiveis:")
for port in port:
    print("- ", port.device)

com = str(input("Digite qual a COM"))
velSerial = [9600, 115200]
print("1 - 9600")
print("2 - 115200")

choose = int(input("Qual a Baudrate: "))
if choose == 1: Baudrate = velSerial[0]
elif choose == 2: Baudrate = velSerial[1]
nomeArquivo = str(input("Digite o nome para o arquivo em txt: "))

porta = "COM" + com
conexao = arduino.Serial(porta, Baudrate)
arquivo = open(nomeArquivo + ".txt", "a")


while True:
    leituraSerial = conexao.readline()
    conversao_serial = leituraSerial.decode("utf-8")
    print(conversao_serial)
    path = "C:/Users/stem/GuitHub/Bancada-de-desempenho/Automação de dados/" + nomeArquivo #definido endereço para o arquivo (mudar conforme o local que deseja)
    with open(path + ".txt", "a") as arquivo: #abre o arquivo para poder escrever
        arquivo.write(conversao_serial) #escreve os dados ja convertidos em Strings