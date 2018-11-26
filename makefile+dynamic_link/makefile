
#FILE = ciao hello

all:clean main

clean:
	if [ -a main.exe ] ; \
	then \
		 rm main.exe ; \
	fi;
	

main: 
	g++ -c -fPIC hello.c -o hello.o
	g++ hello.o -shared -o libhello.so
	g++ -c -fPIC ciao.c -o ciao.o
	g++ ciao.o -shared -o libciao.so
	g++ -o main main.c  -lhello -lciao -L.
	# export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:<someplace_to_put_so_files>
