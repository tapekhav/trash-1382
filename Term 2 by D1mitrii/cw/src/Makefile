all: main.o Read_Write.o Draw_Funcs.o RGB_Filter.o Turn_Funcs.o Help_Info.o
	gcc main.o Read_Write.o Draw_Funcs.o RGB_Filter.o Turn_Funcs.o Help_Info.o -o editor

main.o: structs.h headers.h main.c Read_Write.h Draw_Funcs.h RGB_Filter.h Turn_Funcs.h Help_Info.h
	gcc -c main.c

Read_Write.o: structs.h headers.h Read_Write.c
	gcc -c Read_Write.c	

Draw_Funcs.o: structs.h headers.h Read_Write.h Draw_Funcs.c	
	gcc -c Draw_Funcs.c	

RGB_Filter.o: structs.h headers.h RGB_Filter.c
	gcc -c RGB_Filter.c		

Help_Info.o: structs.h headers.h Help_Info.c
	gcc -c Help_Info.c		

Turn_Funcs.o: structs.h headers.h Draw_Funcs.h Read_Write.h Turn_Funcs.c
	gcc -c Turn_Funcs.c

clean:
	rm -rf *.o editor