shellLab: src/main.c src/user_input.c src/built_functions.c src/input_handler.c
	gcc -I./includes/ src/main.c src/user_input.c src/built_functions.c src/input_handler.c -lreadline -o shellLab

clean:
	rm -f shellLab