#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool iscompounded(string &word, unordered_set<string> &wordset, unordered_set<string> &compounded_words) {
  int n = word.length();
    for (int i = 1; i < n; i++) { //starting the loop from i=1 so that the prefix is never empty
    string prefix = word.substr(0, i);
    string suffix = word.substr(i);

    if (wordset.count(prefix) &&
        (wordset.count(suffix) || compounded_words.count(suffix) ||
         iscompounded(suffix, wordset, compounded_words))) {
      compounded_words.insert(word);
      return true;
    }
  }
  return false;
}

bool compare(string& a, string& b)
{
    return (a.length() > b.length()); 
}

int main() {
  string fileName;
  cout << "Enter the name of the file: ";
  cin >> fileName;
  ifstream file(fileName);
  string word;
  
  vector<string> words; // for storing the words in order
  unordered_set<string> wordSet; // for checking if the word exist with O(1)
  unordered_set<string> compounded_words; // to use the previously calculated result to avoid recursion inside iscompounded function
  
  auto start = chrono::high_resolution_clock::now();// starting time

  if (!file) {
    cerr << "Error opening file!" << endl;
    return 1;
  }

  while (file >> word) {
    words.push_back(word);
    wordSet.insert(word);
  }
  file.close();

  //sorting the input words in decreaing order of length
  sort(words.begin(), words.end(), compare);
  
  string longest = "", secondLongest = "";

  for (string &word : words) {
    if (iscompounded(word, wordSet, compounded_words)) {
      if (longest.empty()) {
        longest = word;
      } else {
        secondLongest = word;
        break;
      }
    }
  }

  auto end = chrono::high_resolution_clock::now(); // ending time
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start); // total time

  cout << "Longest Compound Word: " << longest << endl;
  cout << "Second Longest Compound Word: " << secondLongest << endl;
  cout << "Time taken to process file "<< fileName<<": " << duration.count() << " milli seconds" << endl;

  return 0;
}
