bin/IC_Binary: file_interpretter/interpretter.c test/main.IC
	gcc "file_interpretter/interpretter.c" -o "bin/IC_Binary"
clean:
	rm bin/IC_Binary