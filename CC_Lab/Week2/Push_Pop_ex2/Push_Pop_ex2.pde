void setup() {
  size(200, 200);
  background(0);
}

void draw() {
  pushMatrix();
  translate(20, 0);
  fill(255, 0, 0);
  rect(0, 10, 70, 20); // Draws at (20, 30)

  pushMatrix(); 
  translate(30, 0);
  fill(0, 0, 255);
  rect(0, 30, 70, 20); // Draws at (50, 30)
  popMatrix();

  fill(255, 0, 0);
  //still under first translation, but not second
  rect(0, 50, 70, 20); // Draws at (20, 50)
  popMatrix();

  fill(0, 255, 0);
  //no translation applied
  rect(0, 70, 70, 20); // Draws at (0, 70)
}

