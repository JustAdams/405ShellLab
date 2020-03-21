shellLab: src/main.c src/user_input.c
	gcc -I./includes/ src/main.c src/user_input.c -lreadline -o shellLab