#include <stdio.h>
#include <string.h>

void add_song(char *title);

song_node * search_song(char *title);

song_node * search_artist(char *artist);

void print_letter(char c);

void print_artist(char *singer);

void shuffle(int n);

song_node * delete_song(char *title);

void delete_list(song_node n);
