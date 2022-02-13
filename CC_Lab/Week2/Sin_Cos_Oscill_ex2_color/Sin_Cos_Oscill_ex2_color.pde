float theta = 0.0;

void setup() {
  size(200, 200);
  smooth();
}
void draw() {
  background(255);
  // Get the result of the sine function
  // Scale so that values oscillate between 0 and width
  float x = (sin(theta) + 1) * width/2;
  //Add one to get values between 0 and 2 instead of -1 and 1

  // With each cycle, increment theta
  theta += 0.05;

  // Draw the ellipse at the value produced by sine
  //fill(0);
  //stroke(0);

  fill(x);
  stroke(x);
  line(width/2, 0, x, height/2);
  noStroke();
  ellipse(x, height/2, 30, 30);
}

