#include <stdio.h>
#include <stblib.h>
#include <string.h>
#include <"linked_list.h">

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node make_new_node(char *title, char *singer) {
  song_node n;
  n.name = title;
  n.artist = singer;
  //doesn't have a "next" pointer (NULL)
  return n;
}

song_node * insert_at_front(song_node fresh, song_node og){
  fresh.next = &og;
  song_node *start_of_list = &fresh;
  return start_of_list;
}

song_node * insert_in_order(song_node fresh, song_node og){
  song_node *start_of_list = &og;
  song_node *curr = &og;
  //comparing the name of the songs for alphabetical
  if (strcmp(fresh.name, *curr.name) < 0) { //thing youre inserting is before first element
    return insert_at_front(fresh, *curr);
  }
  else { //thing to insert comes after first element
    while (*curr.next & strcmp(fresh.name, *curr.name) < 0 ){
      curr = *curr.next;
    }
    song_node *newNext = *curr.next;
    *curr.next = &fresh;
    fresh.next = newNext;
    return start_of_list;
}

void print_list(song_node n){

}

song_node * search_by_title(char *title){

}

song_node * search_by_artist(char *artist){

}

song_node * random_song(){

}

song* remove_song(song* top, char* song){
  song* temp = top;
  song* prev;

    if (top -> song = song) {
      top = temp ->next;
      free(temp);
      return NULL;
    }
      while (top != NULL && temp-> song != song) {
	prev = temp;
	temp = tem-> next;
    }
    
      if (temp == NULL) {
	return NULL;
      }
      prev->next = temp->next;

      free(temp);
}

void free_list(song_node n){

}
