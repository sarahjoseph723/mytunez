#include <stdio.h>
#include <string.h>


char* library[26] = {
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

song_node * search_artist(char *artist){
   char a = *artist;
  int i = list_index(a);
  printf("Search Results for \"%s\":\n", artist);

  if (library[i] != NULL) {
   find_artist_song(library[i], artist);
  } else {
    printf("Song Not Found for Query: %s\n", artist);
  }
}

void print_letter(char c);

void print_artist(char *singer);

void shuffle(int n) {
  int i;
  
  for (i = 0; i < n; i++) {
    random_song(song_node front)
  }
}

song_node * delete_song(char *title);

void delete_list(song_node n);

//finds the index of the letter in the array
int list_index(char c) {
  c = tolower(c);
  char* alpha = "abcdefghijklmnopqrstuvwqyz";
  return strcspn(alpha, &c);
}
