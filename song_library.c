#include <stdio.h>
#include <string.h>


song* library[26] = {
  NULL,NULL,NULL,NULL,NULL,
  NULL,NULL,NULL,NULL,NULL,
  NULL,NULL,NULL,NULL,NULL,
  NULL,NULL,NULL,NULL,NULL,
  NULL,NULL,NULL,NULL,NULL,
  NULL
};

void add_song(char *title, char *artist){
char a  = *artist;
int i = list_index(a);

song_node c = make_new_node(title, artist);

if (library[i] != null) {
  insert_in_order(library[i], c);  
  }
}

song_node * search_song(char *title){

  char n = *name;
  int i = list_index(n);
  printf("Search Results for \"%s\":\n", name);

  for(i = 0; i < 26; i++) {
    find_artist_song(library[i], name);
  }
}

song_node * search_artist(char *artist);

void print_letter(char c);

void print_artist(char *singer);

void shuffle(int n);

song_node * delete_song(char *title);

void delete_list(song_node n);

//finds the index of the letter in the array
int list_index(char c) {
  c = tolower(c);
  char* alpha = "abcdefghijklmnopqrstuvwqyz";
  return strcspn(alpha, &c);
}
