#ifndef LINK_LIST_H
#define LINK_LIST_H


typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * insert_at_front(song_node n);

song_node * insert_in_order(song_node n, int i);

void print_list(song_node n);

song_node * search_by_title(char *title);

song_node * search_by_artist(char *artist);

song_node * random_song();

song_node * remove_song(song_node* top, char* song);

void free_list(song_node n);
