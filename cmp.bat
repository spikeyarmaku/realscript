@REM tcc -o bin\rsc.exe src\main.c src\parse.c src\stack.c src\expr.c src\env.c src\rational.c src\alint.c src\global.c
gcc -o bin\rsc.exe -g src\main.c src\parse.c src\stack.c src\expr.c src\env.c src\rational.c src\alint.c src\global.c