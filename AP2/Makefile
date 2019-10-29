CC = g++ #compilador

CPPFLAGS = -Wall -std=c++11 #flags

#executavel
AP2: automovel.o gerenciar.o concessionaria.o carro.o moto.o caminhao.o mainAP.o 
	@$(CC) $(CPPFLAGS) -Iinclude automovel.o gerenciar.o concessionaria.o carro.o moto.o caminhao.o mainAP.o -o AP2											
		
	@mv *.o build/ #enviando os .o para pasta objects
	
# o -I include diz que a biblioteca está nessa pasta


automovel.o: src/automovel.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/automovel.cpp
	@echo "Instalando..."

gerenciar.o: src/gerenciar.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/gerenciar.cpp
	@echo "Instalando..."

concessionaria.o: src/concessionaria.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/concessionaria.cpp
	@echo "Instalando..."

carro.o: src/carro.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/carro.cpp
	@echo "Instalando..."

moto.o: src/carro.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/moto.cpp
	@echo "Instalando..."

caminhao.o: src/carro.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/caminhao.cpp
	@echo "Instalando..."

mainAP.o: src/mainAP.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/mainAP.cpp
	@echo "Aguarde..."
	@echo "Pronto!!!Para mais informações digite o comando --> ./AP2\n "
clean:
	@rm -rf AP2
	@echo "Diretorio limpo"
