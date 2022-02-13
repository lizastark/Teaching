int radius = 100;

void setup() {
  size(600,300);
  smooth();
}
void draw() {
  background(0);
  translate(width/2, height/2);
  stroke(0,255,0);
  fill(0,255,0);

  for (int deg = 0; deg < 360; deg+=3) {
    float angle = radians(deg);
    float x = cos(angle) * radius;
    float y = sin(angle) * radius;
    ellipse(x, y, 1, 1);
    //line(0,0,x,y);
   
    
  }
}

