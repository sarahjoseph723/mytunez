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

void free_list(song_node n);
