### Author Details:
- Megh Bhavesh Jesalpura
- 2024CS10844
- Programming Assignment 1 - COP290

### How to run the program:

### File dependencies and structures:

## Qt interactions:
- The functions paintEvent(), mouseReleaseEvent(), etc are called by Qt whenever such events happen on the Canvas widget.
- qt_dialog.cpp - just for the dialogues and maintain modularity of code

## Qt + OOP:
- In canvas class, I store the state variables. If current_tool is 0 or -1, then we have another mode for move or resize.

## OOP Back-end related:
- mainSpace is the namespace used for writing all the OOP back-end related classes
- graphic_class.hpp and graphic_class.cpp - contains the base class with all properties and functions to set and change features
of the shape
- Note that I am implementing move and resize as per the shape and hence defining virtual methods
- circle.hpp and circle.cpp - 

### Git commits:
