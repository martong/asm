all:
	/usr/local/bin/nasm -f macho64 sort.asm && ld -macosx_version_min 10.7.0 -lSystem -o sort sort.o
