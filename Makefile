# this is a very simple makefile for modules
TOP_DIR=../..

# define the module name - make sure name is max 8 characters
MODULE_NAME=ressel
MODULE_OBJS=ressel.o

# include modules environment
include $(TOP_DIR)/modules/Makefile.modules
