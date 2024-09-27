encryptafile: main.o readspecs.o keyconvert.o fileprocess.o outputfilename.o v22.h
	gcc -o encryptafile main.o readspecs.o keyconvert.o fileprocess.o outputfilename.o v22.h
main.o: main.c v22.h
	gcc -c main.c
readspecs.o: readspecs.c v22.h
	gcc -c readspecs.c
keyconvert.o: keyconvert.c v22.h
	gcc -c keyconvert.c
fileprocess.o: fileprocess.c
	gcc -c fileprocess.c
outputnamefile.o: outputfilename.c
	gcc -c outputfilename.c
