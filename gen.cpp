#include<cctype>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<fstream>

#include "AvlTree.h"
#include "QueueLL.h"
#include "dsexceptions.h"

using namespace std;

class Word {
public:
  int wordCount;
  QueueLL<int> lines;
  char fullWord[50];
  char *printout;
  friend ostream& operator<<(ostream& println, Word& fullWord);

  Word() //constructor
  {
    wordCount = 0;
  }

  void word(char letters, int i) {
    fullWord[i] = letters; //fullWord is an array of characters
  }

  //sorts the classes
  bool operator< (const Word &rhs_word) const {
      return (strcmp(fullWord, rhs_word.fullWord) < 0);
  }
};

ostream& operator<<(ostream& println, Word& fullWord) {

  println << setw(18) << left << fullWord.fullWord;
  println << setw(4) << left << fullWord.wordCount;
  println << fullWord.lines.dequeue();
  while (!fullWord.lines.isEmpty()) {
    println << "," << fullWord.lines.dequeue();

  }
  return println;
};

int main(int argc, char *arg[]) {
  Word letters = Word();
  letters.wordCount=0;
  AvlTree<Word>tree(letters);
  ifstream inf(arg[1]);
  int k=0, l=0, n=0, i=0;
  char s[500], wordchar[l];

  while (inf.good()) {

	//is this necessary?
    if (inf.eof()) {
      i=1;
      break;
    }

    inf.getline(s, 500, '\n');

    n++; //which line in the file we are at

    //finding all the words in the line
    for(k=0;k<=strlen(s);k++) {
      if (isalpha(s[k])) {
        wordchar[l] = tolower(s[k]);
        letters.word(wordchar[l],l);
        l++;
      } else { //character array for word ends
        if (isalpha(s[k-1])) {
          wordchar[l] = NULL;
          letters.word(wordchar[l],l);
          letters.lines.enqueue(n);
          letters.wordCount = 1;

          if ( tree.find(letters).wordCount >= 1) {
            Word &found = tree.find(letters);
            found.wordCount++;
            found.lines.enqueue(n);
            //creating a new word character array for next word
			l=0;
            int wordchar[l];
            letters = Word();
            continue;
          };
		  //word does not yet exist in the tree, so insert it
          tree.insert(letters);
		  //new word character array for next word
          l=0;
          int wordchar[l];
          letters = Word();
        }
      }
    }
  }
  tree.printTree();
}
