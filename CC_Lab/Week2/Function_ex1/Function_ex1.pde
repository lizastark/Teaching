int x; //declare x position for rect defaults to 0
int y;
int side = 50; // declare and assign a value for the size of the side

int c; //declare a variable where we will store the color value

void setup() {
  size(200, 200);
  colorMode(HSB);
}


void draw() {
  c=color(#C81DF0);
  fill(c);
  rect(x, y, side, side); // draw the square
}

