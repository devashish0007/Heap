# *****************************************************************************************
# Project:              CS6150 Lab
# Subtree:              /cs21m017/lab 4 & 5/lab5/
# Filename:             Makefile for Lists
# Programmer:           Devashish Dewangan CS21M017
# Host System:          Linux
# Date Created:         27/Sept/2021
# Project:              Implementation of complement using List ADT 
# *****************************************************************************************

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = g++

all: 	$(BINDIR)/CBA 

$(BINDIR)/CBA: $(OBJDIR)/covidBedAllocation.o $(OBJDIR)/HeapFun.o

	$(CC) -g -o $(BINDIR)/CBA $(OBJDIR)/covidBedAllocation.o $(OBJDIR)/HeapFun.o -I$(INCDIR)

$(OBJDIR)/covidBedAllocation.o: 		$(SRCDIR)/covidBedAllocation.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/covidBedAllocation.o $(SRCDIR)/covidBedAllocation.C

$(OBJDIR)/HeapFun.o: 		$(SRCDIR)/HeapFun.C
	$(CC) $(CFLAGS) -o $(OBJDIR)/HeapFun.o $(SRCDIR)/HeapFun.C

clean: 
	rm -fr $(BINDIR)/* $(OBJDIR)/* 




