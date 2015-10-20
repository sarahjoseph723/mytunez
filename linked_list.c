#include <stdio.h>
#include <stblib.h>
#include <string.h>
#include <time.h>
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

int hasData(song_node n) {
  if (n.name[0]) {
    return 1;
  }
  else {
    return 0;
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
}

void print_song(song_node* s) {
  if (s != NULL) {
    printf("%s by %s\n", s-> name, s-> artist);
  }
}

void print_list(song_node n){
  song_node *curr = &n;
  while (hasData(*curr)) {
    print_song(*curr);
    curr = *curr.next;
  }
}

song_node * find_song(song_node* top, char* song){
   while (top != NULL) {
     if (top -> song = song) {
       print_song(top);
     }
     top = top -> next;
   }
   return NULL;
 }
}

song_node * find_artist_song(song_node* top, char* artist){
   while (top != NULL) {
     if (top -> artist = artist) {
       print_song(top);
     }
     top = top-> next;
   }
   return NULL;
 }
}

int get_length(song_node front) {
  song_node *curr = &front;
  int ctr = 0;
  while (hasData(*curr)) {
    ctr ++;
    curr = *curr.next;
  }
  return ctr;
}

song_node * random_song(song_node front){
  int len = get_length(front);
  int x = rand() % len;
  song_node *curr = front;
  int ctr = 0;
  while (ctr < x) {
    curr = *curr.next;
    ctr ++;
  }
  return curr;
}

song_node * remove_song(song_node *top, char *song){
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
  song_node *top = &n;
  while (top != null) {
    song* curr = top;
    top = top -> next;
    free(curr);
  }
}
