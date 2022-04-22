bin/IC_Binary: compiler/compiler.c test/main.IC
	gcc "compiler/compiler.c" -o "bin/IC_Binary"
clean:
	rm bin/IC_Binary