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

using namespace std;


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

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main() {
  Song song;
  loadSongData(song);
  cout << endl;
  cout << endl;
  print(song);
  return 0;
}

// Function implementations (if any)

void print(const Song &song) {
  const int tab_size = 4;
  int col_width_title = strlen(song.title) + tab_size;
  int col_width_artist = strlen(song.artist) + tab_size;
  int col_width_collection = strlen(song.collection) + tab_size;

  cout << left;
  cout << setw(col_width_title) << "TITLE";
  cout << setw(col_width_artist) << "ARTIST";
  cout << setw(col_width_collection) << "COLLECTION";
  cout << endl;

  cout << setw(col_width_title) << song.title;
  cout << setw(col_width_artist) << song.artist;
  cout << setw(col_width_collection) << song.collection;
  cout << endl;
}

void loadSongData(Song &song) {
  cout << "TITLE: ";
  cin.getline(song.title, Song::MAX_CHARACTERS, '\n');

  cout << "ARTIST: ";
  cin.getline(song.artist, Song::MAX_CHARACTERS, '\n');

  cout << "COLLECTION: ";
  cin.getline(song.collection, Song::MAX_CHARACTERS, '\n');
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

