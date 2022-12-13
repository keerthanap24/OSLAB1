# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author>
list: main.c list.c list.h
	gcc -o list list.c main.c -I.
