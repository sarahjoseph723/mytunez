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
    printf("Song Not Found for: %s\n", artist);
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

void print_all() {
  char c;
  int i = 0;
  for(c='A'; c<='Z'; i++, c++) {
    printf("\n%c : ",c);
    print_list(library[i]);
  }
}

//finds the index of the letter in the array
int list_index(char c) {
  c = tolower(c);
  char* alpha = "abcdefghijklmnopqrstuvwqyz";
  return strcspn(alpha, &c);
}

int main() {
  char title1[] = "another brick in the wall";
  char artist1[] = "pink floyd";
  char title2[]= "is there anybody out there?";
  char artist2[] = "pink floyd";
  char title3[]= "kids";
  char artist3[] = "mgmt";
  char title4[]= "brooklyn baby";
  char artist4[] = "lana del ray";
  char title5[]= "kamikaze";
  char artist5[] = "mo";
  char title6[]= "this side of the moon";
  char artist6[] = "gabrielle aplin";
  char title7[]= "show me";
  char artist7[] = "alina baraz";
  char title8[]= "can't help falling in love";
  char artist8[] = "haley reinhart";
  char title9[]= "can't help falling in love";
  char artist9[] = "elvis presley";
  char title10[]= "strange brew";
  char artist10[] = "cream";
  
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

  char searchSong[] = "kamikaze";
  printf("Song to find: %s\n", searchSong);
  printf("Result: %p\n",search_song(searchSong));

  char searchArtist[] = "mo";
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
