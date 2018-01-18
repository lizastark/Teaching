void setup() {
  size(200, 200);
  background(0);
}

void draw() {
  pushMatrix();
  translate(20, 0);
  fill(255,0,0);
  rect(0, 10, 70, 20); // Draws at (20, 30)
  popMatrix();


  //no translation applied
  fill(0,255,0);
  rect(0, 50, 70, 20); // Draws at (20, 50)
}

