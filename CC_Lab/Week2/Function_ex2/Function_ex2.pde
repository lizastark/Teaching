/*
We are going to move these GLOBAL variables to the function. There they
will become LOCAL variables.

int x; //declare x position for rect defaults to 0
int y;
int side = 50; // declare and assign a value for the size of the side
*/

int c; //declare a variable where we will store the color value

void setup() {
  size(200, 200);
  colorMode(HSB); //change the color mode so we can use hex
}


void draw() {
  background(0);
  
  display(0,0,50);// call our function to draw the rect to the screen
  display(20,40,100);// call our function to draw the rect to the screen
  
  c=color(#C81DF0); // assign a hex value to c
  fill(c); //fill the rectangle with the color you just assigned to c
}

void display(int x, int y, int side) { //declare your function
  rect(x, y, side, side); // draw the square
}



