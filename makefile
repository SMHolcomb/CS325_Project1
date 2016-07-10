#  makefile.
#
#  g++ is the compiler.
#  -o sets the executable name
#
#  program     		-  MSS
#  main.cpp   		-  main function


program: 
	g++ -o MSS main.cpp
clean:
	rm MSS