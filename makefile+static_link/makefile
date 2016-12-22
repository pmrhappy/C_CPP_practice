
#FILE = ciao hello

all:clean main

clean:
	if [ -a main.exe ] ; \
	then \
		 rm main.exe ; \
	fi;
	

main: 
	g++ -std=c++11 -o main main.c ciao.c hello.c 