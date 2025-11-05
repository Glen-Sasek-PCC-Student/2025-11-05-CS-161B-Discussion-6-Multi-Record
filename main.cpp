// ------------- FILE HEADER -------------
// Author ✅: 
// Assignment ✅:
// Date ✅:
// Citations: 


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 
// Participation ✅: 
// Challenge ✅:
// Labs ✅:


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅:
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: 
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: 
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;



const int MAX_SONGS = 500;
const char DATAFILE[] = "songs.csv"; 

struct Song {
  static const int MAX_CHARACTERS = 255;
  char title[MAX_CHARACTERS] = {0};
  char artist[MAX_CHARACTERS] = {0};
  char collection[MAX_CHARACTERS] = {0};
};

// Pass the variable by reference to a function and prompt the user for the member information. Make sure to validate all input.
void loadSongData(Song &song);

// Pass the variable by constant reference to a function to print the members of the struct variable.
void print(const Song &song);

void print(const Song song[], int count);

void loadDataFile(Song songs[], int &count);

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main() {
  Song songs[MAX_SONGS];
  int count = 0;
  //loadSongData(song);

  loadDataFile(songs, count);

  cout << endl;
  cout << endl;
  //print(song);
  print(songs, count);
  return 0;
}

// Function implementations (if any)

void printHeading(int col_width_title, int col_width_artist, int col_width_collection) {
  cout << left;
  cout << setw(col_width_title) << "TITLE";
  cout << setw(col_width_artist) << "ARTIST";
  cout << setw(col_width_collection) << "COLLECTION";
  cout << endl;
}

void printSong(int col_width_title, int col_width_artist, int col_width_collection, Song song) {
  cout << left;
  cout << setw(col_width_title) << song.title;
  cout << setw(col_width_artist) << song.artist;
  cout << setw(col_width_collection) << song.collection;
  cout << endl;
}

void print(const Song &song) {
  const int tab_size = 4;
  int col_width_title = strlen(song.title) + tab_size;
  int col_width_artist = strlen(song.artist) + tab_size;
  int col_width_collection = strlen(song.collection) + tab_size;

  printHeading(col_width_title, col_width_artist, col_width_collection);
  printSong(col_width_title, col_width_artist, col_width_collection, song);
  cout << endl;
}

void print(const Song songs[], int count) {
  const int tab_size = 4;
  int col_width_title = 0;
  int col_width_artist = 0;
  int col_width_collection = 0;
  for(int i = 0; i < count; i++) {
    int n = strlen(songs[i].title);
    if(n > col_width_title) {
      col_width_title = n;
    }

    n = strlen(songs[i].artist);
    if(n > col_width_artist) {
      col_width_artist = n;
    }

    n = strlen(songs[i].collection);
    if(n > col_width_title) {
      col_width_collection = n;
    }
  }
  col_width_title += tab_size;  
  col_width_artist += tab_size;
  col_width_collection += tab_size;

  for(int i = 0; i < count; i++) {
    printSong(col_width_title, col_width_artist, col_width_collection, songs[i]);
  }
}

void loadSongData(Song &song) {
  cout << "TITLE: ";
  cin.getline(song.title, Song::MAX_CHARACTERS, '\n');

  cout << "ARTIST: ";
  cin.getline(song.artist, Song::MAX_CHARACTERS, '\n');

  cout << "COLLECTION: ";
  cin.getline(song.collection, Song::MAX_CHARACTERS, '\n');
}


void loadDataFile(Song songs[], int &count) {
  ifstream fin(DATAFILE);

  fin.ignore(numeric_limits<streamsize>::max(), '\n');

  char buffer[Song::MAX_CHARACTERS * 3 + 1] = {0};
  while(fin.getline(buffer, Song::MAX_CHARACTERS * 3)) {
    stringstream sin(buffer);
    sin.getline(songs[count].title, Song::MAX_CHARACTERS, ',');
    sin.getline(songs[count].artist, Song::MAX_CHARACTERS, ',');
    sin.getline(songs[count].collection, Song::MAX_CHARACTERS, '\n');
    count++;
  }

}


// ------------- DESIGN -------------
/* 
Program Name:

Program Description:

Design:
A. INPUT
  char title[];
  char artist[];
  char collection[];

B. OUTPUT
Same as input 

C. CALCULATIONS
NONE

D. LOGIC and ALGORITHMS
DECLARE Song song
CALL loadSongData
CALL print

FUNCTION void loadSongData
  PROMPT: "TITLE: "
  INPUT: title

  PROMPT: "ARTIST: "
  INPUT: artist

  PROMPT: "COLLECTION: "
  INPUT: collection
END FUNCTION

FUNCTION void print
  LABEL: "TITLE: "
  DATA: title

  LABEL: "ARTIST: "
  DATA: artist

  LABEL: "COLLECTION: "
  DATA: collection
END FUNCTION

SAMPLE RUNS
TITLE: The Best Song
ARTIST: Frank Itt
COLLECTION: Bass Itt

TITLE            ARTIST       COLLECTION
The Best Song    Frank Itt    Bass Itt

*/

