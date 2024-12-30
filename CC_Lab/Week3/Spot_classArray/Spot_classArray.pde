int numSpots = 6;

// Declare and assign the array
Spot[] spots = new Spot[numSpots];

void setup() {
  size(100, 100);
  smooth();
  noStroke();
  
  //use a for loop to create each object - much easier than doing it 6 times!
  for (int i = 0; i < spots.length; i++) {
    float x = 10 + i*16;
    float rate = 0.5 + i*0.05;
    // This is where each object is created
    spots[i] = new Spot(x, 50, 16, rate);
  }
}
void draw() {
  fill(0, 12);
  rect(0, 0, width, height);
  fill(255);
  for (int i = 0; i < spots.length; i++) {
    
    //Call your methods 
    spots[i].move(); // Move each object
    spots[i].display(); // Display each object
  }
}


