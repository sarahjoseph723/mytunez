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

void * search_song(char *title){

  char n = *name;
  int i = list_index(n);
  printf("Search Results for \"%s\":\n", name);

  for(i = 0; i < 26; i++) {
    find_artist_song(library[i], name);
  }
}

void * search_artist(char *artist){
   char a = *artist;
  int i = list_index(a);
  printf("Search Results for \"%s\":\n", artist);

  if (library[i] != NULL) {
   find_artist_song(library[i], artist);
  } else {
    printf("Song Not Found for Query: %s\n", artist);
  }
}

void print_letter(char c){
  int i = list_index(c);
  print_list(library[i]);
}

void print_artist(char *singer){
  char a = *artist;
  int i = list_index(a);

  printf("Songs by %s\n", artist);

  if (library[i] != NULL) {
    song_node *first = find_artist_song(library[i], artist);
    song_node *top = first;
    while(top != NULL) {
      print_song(top);
      top = find_artist_song(top -> next, artist);
    }
  } else {
    printf("No Songs By %s\n", artist);
  }
}

char rand_char() {
  return rand() % 26;
}

void shuffle(int n) {
  int i;
  for (i = 0; i < n; i++) {
    char x = rand_char();
    while (library[x] == NULL) {
      x = rand_char(x);
    }
    print_song(random_song(library[x]));
  }
}

void * delete_song(char *title, char *artist){
  char a = *artist;
  int i = list_index(a);
  remove_song(library[i], title);
}

void delete_list() {
  int i;
  for(i = 0; i < 26; i++) {
    free_list(library[i]);
    library[i] = NULL;
  }
}

//finds the index of the letter in the array
int list_index(char c) {
  c = tolower(c);
  char* alpha = "abcdefghijklmnopqrstuvwqyz";
  return strcspn(alpha, &c);
}

int main() {
  char title1[] = "Another Brick in the Wall";
  char artist1[] = "Pink Floyd";
  char title2[]= "Is There Anybody Out There?";
  char artist2[] = "Pink Floyd";
  char title3[]= "Kids";
  char artist3[] = "MGMT";
  char title4[]= "Brooklyn Baby";
  char artist4[] = "Lana Del Ray";
  char title5[]= "Kamikaze";
  char artist5[] = "MO";
  char title6[]= "This Side of the Moon";
  char artist6[] = "Gabrielle Aplin";
  char title7[]= "Show Me";
  char artist7[] = "Alina Baraz";
  char title8[]= "Can't Help Falling in Love";
  char artist8[] = "Haley Reinhart";
  char title9[]= "Can't Help Falling in Love";
  char artist9[] = "Elvis Presley";
  char title10[]= "Strange Brew";
  char artist10[] = "Cream";
  
  printf("Adding songs...\n");
  add_song(title1, artist1);
  add_song(title2, artist2);
  add_song(title3, artist3);
  add_song(title4, artist4);
  add_song(title5, artist5);
  add_song(title6, artist6);
  add_song(title7, artist7);
  add_song(title8, artist8);
  add_song(title9, artist9);
  add_song(title10, artist10);

  printf("Search methods...\n");

  char searchSong[] = "";
  printf("Song to find: %s\n", searchSong);
  printf("Result: %p\n",search_song(searchSong));

  char searchArtist[] = "";
  printf("Artist to find: %s\n", searchArtist);
  printf("Result: %p\n", search_artist(searchArtist));


  printf("Printing all p artists: ");
  print_letter('p');

  printf("Printing all songs by %s\n", searchArtist);
  print_artist(searchArtist);

  printf("Shuffle library for 5 songs: \n");
  shuffle(5);

  printf("Deleting methods...\n");

  delete_song(searchSong, searchArtist);
  printf("Result of deleting %s, by %s: \n", searchSong, searchArtist);
  print_all();

  delete_list();
  printf("Result of deleting everything: \n");
  print_all();



}
