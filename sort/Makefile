sort_fun.o: sort_fun.asm
	/usr/local/bin/nasm -f macho64 sort_fun.asm
main.o: main.cpp
	clang++ -g -std=c++14 -c main.cpp
sort_cpp: sort_fun.o main.o
	clang++ -g main.o sort_fun.o -o sort_cpp

sort_asm:
	/usr/local/bin/nasm -f macho64 sort.asm && ld -macosx_version_min 10.7.0 -lSystem -o sort sort.o
