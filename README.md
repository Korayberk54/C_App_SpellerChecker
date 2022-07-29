# C_App_SpellerChecker

This program is a spell-checker. It can take a text and take every word in that text and check to see if it is spelled correctly or not.

*Remember this project was made for cs50's Problem Set. So to run this, you are going to need to download cs50.h and some other libraries to your system.*

Explanation of each individual script and folder:

-speller.c : Contains the code that does the spell-checking, calling upon functions that declared in dictionary.h

-dictionary.h : Contains the function prototypes that are writen in dictionary.c
-dictionary.c : Contains functions and hashtables to compare the correct usage of words in Dictionaries Folder against given text samples

-Makefile : Contains the commands to compile all our files

-Dictionaries Folder : Contains large and small dictionary of words

-Texts Folder : Contains sample files to run spell-checker agains

-Keys Folder : Contains the solutions, misspelled words in each of the sample texts

Usage:

./speller [dictionary] text

Example Usage:

./speller texts/lalaland.txt
