# Impledge Coding Round-1 question

## Overview
This program
1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
word per line, no spaces, all lower case).
2. Identifies & display below given data in console
o longest compounded word
o second longest compounded word
o time taken to process the input file

Note: A compounded word is one that can be constructed by combining (concatenating) shorter words
also found in the same file.

## Steps to Run
1. Click on the link to open this in replit.
2. Fork the replit and hit run.
3. Input the file name (Input_01.txt or Input_02.txt) and hit enter.
Note:- You can create/upload your own input file inside or modify either of the input file.

## Design Decisions & Approach
1. All words in input file are added to the Vector "Word" and Unordered set "Wordset".
2. Vector Word is sorted in descending order, i used this to reduce the time taken in checking all compounded words in the vector, Now we will start checking compounded word from longest in the vector and stop as soon as we find positive result for two words.
3. I have also stored all the words in the input inside a Wordset, this is to check if a perticular word exists in the input or not in O(1) where vector would take O(n).
4. Compounded_word set is use to store the intermediate results to avoid unnecesary recursion.
5. isCompund function returns true or false based upon if the given word is compounded or not. It starts comparing combination of prefix and sufix to find:-
if both prefix and suffix exists in wordset or if prefix exists in wordset and suffix is a compounded word(recursively). in these two cases the input word will be compounded and it will return true. else it will return false.

