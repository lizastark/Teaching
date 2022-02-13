int numEl = 20;
float[] elX = new float [numEl];
float[] elY = new float [numEl];

float[] speed = new float [numEl];

int c;

void setup() {
  background(0);
  size(200, 200);
  smooth();
  colorMode(HSB);

  //Initialize all the elements of the array using a for loop
  for (int i=0; i<numEl; i++) { 
    elX[i] = random(width); //assign it a random value between 0-200
    elY[i] = random(height);
    speed[i] = random(0.95);
  }
}


void draw() {
  c=color(#C81DF0);
  fill(c);

  if (keyPressed == true) {
    for (int i=0; i<elY.length; i++) {
      elY[i] += speed[i];  //Update position
      ellipse(elX[i], elY[i], 20, 20); //Draw the circle
    }
  }
}

