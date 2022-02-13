Spot sp; // Declare the object
void setup() {
  size(100, 100);
  smooth();
  noStroke();
  sp = new Spot(33, 50, 30, 1.5); // Construct the object
}
void draw() {
  fill(0, 15);
  rect(0, 0, width, height);
  fill(255);
  sp.move();
  sp.display();
}


