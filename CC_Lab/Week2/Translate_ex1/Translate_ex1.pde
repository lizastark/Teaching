void setup() {
  size(600,300);
  background(0);
}

void draw() {
  fill(255,0,0);
  rect(0,0,50,50);
  
  //The translate() function moves the origin from the upper-left corner of the screen to another location
  translate(300,50);
  fill(0,255,0);
  rect(0,0,50,50);
}
