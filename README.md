### Author Details:
- Megh Bhavesh Jesalpura
- 2024CS10844
- Programming Assignment 1 - COP290

### How to run the program:

### File dependencies and structures:

## Parser:
- Note that I am parsing the tags showing inkscape and g layers and stuff but I am not using that information. Canvas size is also predecided.
- The parsing that we are implementing is just for getting the shapes, corresponding attributes and storing them.

## Qt interactions:
- The functions paintEvent(), mouseReleaseEvent(), etc are called by Qt whenever such events happen on the Canvas widget.
- qt_dialog.cpp - just for the dialogues and maintain modularity of code
- Note that in copy cut paste etc, the shape is pasted considering that the cursor is at the top left corner of the shape's bounding box.

## Qt + OOP:
- In canvas class, I store the state variables. If current_tool is 0 or -1, then we have another mode for move or resize.

## DocManager:
- This set of filles will store the pointers and will be used to do three things: 1) Undo/Redo 2) Cut/Copy/Paste 3) Save/Open files

## OOP Back-end related:
- mainSpace is the namespace used for writing all the OOP back-end related classes
- graphic_class.hpp and graphic_class.cpp - contains the base class with all properties and functions to set and change features
of the shape
- Note that I am implementing move and resize as per the shape and hence defining virtual methods
- circle.hpp and circle.cpp - 

### Git commits:
