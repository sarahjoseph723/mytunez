all: song_library.o linked_list.o
	gcc song_library.o linked_list.o

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

song_library.o: song_library.c song_library.h linked_list.c
	gcc -c song_library.c

clean:
	rm*.~

run:
	./a.out