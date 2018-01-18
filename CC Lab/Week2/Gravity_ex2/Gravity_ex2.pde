
//Based on D. Shiffman's code from Learning Processing
float y = 0;
float speed = 1;
float gravity = 0.1;
float direction = -1;

void setup() {
  size(200, 200);
  smooth();
}

void draw() {
  background(0);
  move();
  bounce();
  display();
}

void move() {  //Change y by the speed
  y = y + speed;
  speed = speed + gravity; //Add acceleration
}

void bounce() {
  //If you reach the edge, reverse the speed
  if ((y>height) || (y<0)) { 
    speed = speed*direction;
  }
}

void display() {
  //Display the cirle at y location  
  colorMode(HSB);
  fill(#C81DF0);
  ellipse(100, y, 32, 32);
}

